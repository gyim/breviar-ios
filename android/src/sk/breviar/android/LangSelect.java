package sk.breviar.android;

import android.app.Activity;
/*
import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.DialogInterface;
import android.app.Dialog;
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
import sk.breviar.android.Util;
import sk.breviar.android.Alarms;
*/

public class LangSelect extends Activity {

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
      super.onCreate(savedInstanceState);
      setContentView(R.layout.langselect);

      ((Button)findViewById(R.id.langSk)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          v.getActivity().setResult
          parent.syncScale();
          wv.goForward();
        }
      });
    }
}
