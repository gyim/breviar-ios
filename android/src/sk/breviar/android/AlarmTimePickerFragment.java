package sk.breviar.android;

import android.support.v4.app.DialogFragment;

import android.app.Dialog;
import android.app.TimePickerDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.text.format.DateFormat;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.TimePicker;

import sk.breviar.android.Util;

public class AlarmTimePickerFragment extends DialogFragment 
    implements TimePickerDialog.OnTimeSetListener{

  int eventId() {
    return Integer.parseInt(getTag().substring(6));
  }

  Util.EventInfo event() {
    return Util.events[eventId()];
  }

  CheckBox box() {
    return (CheckBox)getActivity().findViewById(Util.events[eventId()].id);
  }

  @Override
  public Dialog onCreateDialog(Bundle savedInstanceState) {
    Util.AlarmTime t = event().getTime(getActivity());
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
        */

    Button b;
    b = d.getButton(DialogInterface.BUTTON_NEGATIVE);
    if (b != null) b.setEnabled(false);

    b = d.getButton(DialogInterface.BUTTON_NEUTRAL);
    if (b != null) b.setEnabled(false);

    /*
    d.setOnDismissListener(new TimePickerDialog.OnDismissListener() {
          public void onDismiss(DialogInterface dialog) {
            box().setChecked(!box().isChecked());
          }
        });

    d.setOnCancelListener(new TimePickerDialog.OnCancelListener() {
          public void onCancel(DialogInterface dialog) {
            box().setChecked(!box().isChecked());
          }
        });
    */

    return d;
  }

  public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
    // box.setChecked(true);
    Util.EventInfo e = event();
    e.setTime(getActivity(), hourOfDay, minute);
    e.updateBox(box(), new Util.AlarmTime(minute, hourOfDay, true));
  }
}
