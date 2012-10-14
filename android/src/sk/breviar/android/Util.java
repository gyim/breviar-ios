package sk.breviar.android;

import android.content.Context;
import android.content.SharedPreferences;
import android.widget.CheckBox;

public class Util {
  static final String prefname = "BreviarPrefs";

  static class AlarmTime {
    AlarmTime(int minute_, int hour_, boolean enabled_) {
      minute = minute_;
      hour = hour_;
      enabled = enabled_;
    }
    int minute, hour;
    boolean enabled;
  };

  static class EventInfo {
    EventInfo(int id_, int cap_, String tag_, int hr, int min) {
      id = id_;
      caption = cap_;
      tag = tag_;
      defaultTime = new AlarmTime(min, hr, false);
    };

    AlarmTime getTime(Context ctx) {
      SharedPreferences settings = ctx.getSharedPreferences(prefname, 0);
      int min = settings.getInt(tag + "-min", defaultTime.minute);
      int hr = settings.getInt(tag + "-hr", defaultTime.hour);
      boolean e = settings.getBoolean(tag + "-e", defaultTime.enabled);
      return new AlarmTime(min, hr, e);
    }

    void setTime(Context ctx, int hour, int minute) {
      SharedPreferences settings = ctx.getSharedPreferences(prefname, 0);
      SharedPreferences.Editor editor = settings.edit();
      editor.putInt(tag + "-min", minute);
      editor.putInt(tag + "-hr", hour);
      editor.putBoolean(tag + "-e", true);
      editor.commit();
    }

    void disable(Context ctx) {
      SharedPreferences settings = ctx.getSharedPreferences(prefname, 0);
      SharedPreferences.Editor editor = settings.edit();
      editor.putBoolean(tag + "-e", false);
      editor.commit();
    }

    void updateBox(CheckBox box, AlarmTime t) {
      String s = box.getContext().getString(caption);
      if (t.enabled) {
        s += String.format(": %d:%02d", t.hour, t.minute);
      } else {
        s += ": " + box.getContext().getString(R.string.alarmOff);
      }
      box.setText(s);
      box.setChecked(t.enabled);
    }

    int id, caption;
    String tag;
    AlarmTime defaultTime;
  };

  static final EventInfo events[] = {
    new EventInfo(R.id.inv_check,   R.string.inv,   "alarm-inv",    8, 00),
    new EventInfo(R.id.rch_check,   R.string.rch,   "alarm-rch",    9, 00),
    new EventInfo(R.id.vesp_check,  R.string.vesp,  "alarm-vesp",  18, 00),
    new EventInfo(R.id.kompl_check, R.string.kompl, "alarm-kompl", 22, 00)
  };
}
