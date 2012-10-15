package sk.breviar.android;

import android.support.v4.app.NotificationCompat;

import android.app.Notification;
import android.app.NotificationManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

import sk.breviar.android.Util;
/*
import android.content.ComponentName;
import android.os.Bundle;
import android.telephony.SmsMessage;

import sk.ksp.riso.whereiam.replySms;
*/

public class AlarmReceiver extends BroadcastReceiver {
  @Override
  public void onReceive(Context ctx, Intent in) {
    Log.v("breviar", "AlarmReceiver onReceive");
    if (in.getAction().equals("sk.breviar.android.NOTIFY")) {
      int id = in.getIntExtra("id", -1);
      Log.v("breviar", "notification id " + id);
      if (id != -1) {
        ((NotificationManager)ctx.getSystemService(ctx.NOTIFICATION_SERVICE)).notify(1, 
          new NotificationCompat.Builder(ctx)
            .setContentTitle(ctx.getString(Util.events[id].notify_text))
            .setSmallIcon(R.drawable.icon)
            .setAutoCancel(true)
// Todo: sound/vibration, intent
//            .setContentIntent(pi)
            .setDefaults(Notification.DEFAULT_ALL)
            .build()
        );
      }
    }
    Util.setAlarm(ctx);
  }
}
