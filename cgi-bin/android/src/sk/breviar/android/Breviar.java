package sk.breviar.android;

import android.app.Activity;
import android.content.Intent;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.net.Uri;
import android.net.Uri;
import android.os.Bundle;
import android.text.Html;
import android.util.Log;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.Window;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import java.io.IOException;
import sk.breviar.android.Server;

public class Breviar extends Activity
{
    WebView wv;
    int scale;
    Server S = null;
    static String scriptname = "cgi-bin/l.cgi";
    String language;
    static final String prefname = "BreviarPrefs";
    boolean initialized;

    void goHome() {
      wv.loadUrl("http://localhost:" + S.port + "/" + scriptname + "?qt=pdnes" + Html.fromHtml(S.getOpts()));
    }

    void resetLanguage() {
      S.setLanguage(language);
      // musime zahodit aj nastavenia, mozu byt ine. A zresetovalo by to aj jazyk spat.
      wv.loadUrl("http://localhost:" + S.port + "/" + scriptname + "?qt=pdnes" );
    }

    public boolean tryOpenBible(String url) {
      try {
        startActivity(new Intent("sk.ksp.riso.svpismo.action.SHOW", Uri.parse(url)));
      } catch (android.content.ActivityNotFoundException e) {
        return false;
      }
      return true;
    }

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
      super.onCreate(savedInstanceState);

      requestWindowFeature(Window.FEATURE_NO_TITLE);

      // Restore preferences
      SharedPreferences settings = getSharedPreferences(prefname, 0);
      language = settings.getString("language", "sk");
      scale = settings.getInt("scale", 100);
      String opts = settings.getString("params", "");

      if (S==null) {
        try {
          S = new Server(this, scriptname, language, opts);
        } catch (IOException e) {
          Log.v("breviar", "Can not initialize server!");
          finish();
          return;
        }
        S.start();
      }
      setContentView(R.layout.breviar);

      wv = (WebView)findViewById(R.id.wv);
      wv.getSettings().setBuiltInZoomControls(true);
      wv.setInitialScale(scale);
      initialized = false;
      //Log.v("breviar", "setting scale = " + scale);
      if (wv.restoreState(savedInstanceState) == null) goHome();

      final Breviar parent = this;
      wv.setWebViewClient(new WebViewClient() {
        @Override
        public boolean shouldOverrideUrlLoading(WebView view, String url) {
          if (url.startsWith("mailto:")) {
            String[] blah_email = url.split(":");
            Intent emailIntent = new Intent(android.content.Intent.ACTION_SEND);
            emailIntent.setType("text/plain");
            emailIntent.putExtra(android.content.Intent.EXTRA_EMAIL, new String[]{blah_email[1]});
            emailIntent.putExtra(android.content.Intent.EXTRA_SUBJECT, "Komentár k breviáru");
            startActivity(emailIntent);
            return true;
          }
          if (url.startsWith("http://dkc.kbs.sk")) {
            if (tryOpenBible(url)) return true;
          }
          if (url.startsWith("svpismo:")) {
            if (tryOpenBible(url)) return true;
          }

          //Log.v("breviar", "sync in overrideurlloading");
          parent.syncScale();
          view.loadUrl(url);
          return true;
        }

        @Override
        public void onScaleChanged(WebView view, float oldSc, float newSc) {
          parent.scale = (int)(newSc*100);
          //Log.v("breviar", "onScaleChanged: setting scale = " + scale);
          view.setInitialScale(parent.scale);
        }

        @Override
        public void onPageStarted(WebView view, String url, Bitmap favicon) {
          //Log.v("breviar", "onPageStarted");
          if (parent.initialized) parent.syncScale();
          parent.initialized = true;
        }
      } );

      ((Button)findViewById(R.id.forwardBtn)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          parent.syncScale();
          wv.goForward();
        }
      });
 
      ((Button)findViewById(R.id.pgupBtn)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          wv.pageUp(false);
        }
      });
 
      ((Button)findViewById(R.id.todayBtn)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          parent.syncScale();
          goHome();
        }
      });
 
      ((Button)findViewById(R.id.pgdnBtn)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          wv.pageDown(false);
        }
      });
 
    }

    protected void onSaveInstanceState(Bundle outState) {
      //Log.v("breviar", "onSaveInstanceState");
      syncScale();
      wv.saveState(outState);
      syncPreferences();
    }

    void syncPreferences() {
      // We need an Editor object to make preference changes.
      // All objects are from android.context.Context
      SharedPreferences settings = getSharedPreferences(prefname, 0);
      SharedPreferences.Editor editor = settings.edit();
      editor.putString("language", language);
      editor.putInt("scale", scale);
      if (S != null) {
        editor.putString("params", S.getOpts());
      }

      // Commit the edits!
      editor.commit();
    }

    protected void syncScale() {
      scale = (int)(wv.getScale()*100);
      wv.setInitialScale(scale);
      //Log.v("breviar", "syncScale "+scale);
    }

    protected void onStop(){
      //Log.v("breviar", "onStop");
      syncScale();
      super.onStop();
      syncPreferences();
    }

    @Override
    public void onDestroy() {
      if (S != null) S.stopServer();
      super.onDestroy();
    }

    @Override
    public boolean onCreateOptionsMenu( Menu menu ) {
      // Inflate the currently selected menu XML resource.
      MenuInflater inflater = getMenuInflater();
      inflater.inflate( R.menu.menu, menu );
      return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
      // Handle item selection
      switch (item.getItemId()) {
        case R.id.lang_sk:
          language = "sk";
          resetLanguage();
          return true;
        case R.id.lang_cz:
          language = "cz";
          resetLanguage();
          return true;
        default:
          return super.onOptionsItemSelected(item);
      }
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
      if ((keyCode == KeyEvent.KEYCODE_BACK) && wv.canGoBack()) {
        wv.goBack();
        return true;
      }
      return super.onKeyDown(keyCode, event);
    }
}
