package sk.breviar.android;

/*
import android.app.Activity;
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
import android.view.View;
import android.view.Window;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import java.io.IOException;
import sk.breviar.android.Server;
*/

import android.support.v4.app.DialogFragment;

import android.app.Dialog;
import android.app.TimePickerDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.text.format.DateFormat;
import android.widget.CheckBox;
import android.widget.TimePicker;

import sk.breviar.android.Util;

public class AlarmTimePickerFragment extends DialogFragment 
    implements TimePickerDialog.OnTimeSetListener{

  final Util.EventInfo event;
  final CheckBox box;

  public AlarmTimePickerFragment(Util.EventInfo event_, CheckBox box_) {
    event = event_;
    box = box_;
  }

  @Override
  public Dialog onCreateDialog(Bundle savedInstanceState) {
    Util.AlarmTime t = event.getTime(getActivity());
    TimePickerDialog d = new TimePickerDialog(getActivity(), this,
        t.hour, t.minute, DateFormat.is24HourFormat(getActivity()));

    /*
    d.setButton(DialogInterface.BUTTON_NEGATIVE, getString(android.R.string.cancel),
        new TimePickerDialog.OnClickListener() {
          public void onClick(DialogInterface dialog, int which) {
            event.disable(getActivity());
//            box.setChecked(true); // will be toggled to false
          }
        });

    d.setOnDismissListener(new TimePickerDialog.OnDismissListener() {
          public void onDismiss(DialogInterface dialog) {
//            box.setChecked(!box.isChecked());
          }
        });
        */

    return d;
  }

  public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
    // box.setChecked(true);
    event.setTime(getActivity(), hourOfDay, minute);
    event.updateBox(box, new Util.AlarmTime(minute, hourOfDay, true));
  }
}
