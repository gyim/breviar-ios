package sk.breviar.android;

/*
import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.content.Intent;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.DialogInterface;
import android.app.Dialog;
import android.graphics.Bitmap;
import android.net.Uri;
import android.net.Uri;
import android.text.Html;
import android.util.Log;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.Window;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import java.io.IOException;
import sk.breviar.android.Server;
*/

import android.support.v4.app.FragmentActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import sk.breviar.android.Util;

public class Alarms extends FragmentActivity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
      super.onCreate(savedInstanceState);

      setContentView(R.layout.alarms);

      for (int i = 0; i < Util.events.length; ++i) {
        final CheckBox box = ((CheckBox)findViewById(Util.events[i].id));
        Util.events[i].updateBox(box, Util.events[i].getTime(this));
        final int j = i;
        box.setOnClickListener(new View.OnClickListener() {
          public void onClick(View v) {
            if (((CheckBox)v).isChecked()) {
              AlarmTimePickerFragment f = new AlarmTimePickerFragment();
              f.show(getSupportFragmentManager(), "event-" + j);
            } else {
              Util.events[j].updateBox(box, new Util.AlarmTime(0, 0, false));
              Util.events[j].disable(box.getContext());
            }
          }
        });
      }
    }
}
