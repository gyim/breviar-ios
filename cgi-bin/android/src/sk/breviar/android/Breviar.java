package sk.breviar.android;

import android.app.Activity;
import android.os.Bundle;
import sk.breviar.android.Server;
import android.webkit.WebView;
import java.io.IOException;
import android.webkit.WebViewClient;
import android.webkit.WebSettings;
import android.content.Intent;
import android.net.Uri;
import android.widget.Button;
import android.view.View;
import android.view.Window;
import android.content.SharedPreferences;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MenuInflater;
import android.util.Log;
import android.text.Html;

public class Breviar extends Activity
{
    WebView wv;
    Server S = null;
    static String scriptname = "cgi-bin/l.cgi";
    String language;
    static final String prefname = "BreviarPrefs";

    void goHome() {
      wv.loadUrl("http://localhost:" + S.port + "/" + scriptname + "?qt=pdnes" + Html.fromHtml(S.getOpts()));
    }

    void resetLanguage() {
      S.setLanguage(language);
      // musime zahodit aj nastavenia, mozu byt ine. A zresetovalo by to aj jazyk spat.
      wv.loadUrl("http://localhost:" + S.port + "/" + scriptname + "?qt=pdnes" );
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
      String opts = settings.getString("params", "");

      if (S==null) {
        try {
          S = new Server(this, scriptname, language, opts);
        } catch (IOException e) {
          finish();
        }
        S.start();
      }
      setContentView(R.layout.breviar);

      wv = (WebView)findViewById(R.id.wv);
      if (wv.restoreState(savedInstanceState) == null) goHome();

      wv.getSettings().setBuiltInZoomControls(true);
      wv.getSettings().setDefaultZoom(WebSettings.ZoomDensity.FAR);

      wv.setWebViewClient(new WebViewClient() {
        @Override
        public boolean shouldOverrideUrlLoading(WebView view, String url) {
          view.loadUrl(url);
          return true;
        }
      } );

      ((Button)findViewById(R.id.backBtn)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          wv.goBack();
        }
      });
 
      ((Button)findViewById(R.id.forwardBtn)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          wv.goForward();
        }
      });
 
      ((Button)findViewById(R.id.todayBtn)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
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
      wv.saveState(outState);
    }

    protected void onStop(){
      super.onStop();

      // We need an Editor object to make preference changes.
      // All objects are from android.context.Context
      SharedPreferences settings = getSharedPreferences(prefname, 0);
      SharedPreferences.Editor editor = settings.edit();
      editor.putString("language", language);
      if (S != null) {
        editor.putString("params", S.getOpts());
      }

      // Commit the edits!
      editor.commit();
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
}
