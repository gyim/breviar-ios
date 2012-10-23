package sk.breviar.android;

import android.support.v4.app.NotificationCompat;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

import sk.breviar.android.Util;

public class AlarmReceiver extends BroadcastReceiver {
  @Override
  public void onReceive(Context ctx, Intent in) {
    Log.v("breviar", "AlarmReceiver onReceive");
    if (in.getAction().equals("sk.breviar.android.NOTIFY")) {
      int id = in.getIntExtra("id", -1);
      Log.v("breviar", "notification id " + id);
      if (id != -1) {
        PendingIntent pi = PendingIntent.getActivity(ctx, 0, 
          new Intent("sk.breviar.android.action.SHOW")
              .putExtra("id", id), 0);

        ((NotificationManager)ctx.getSystemService(ctx.NOTIFICATION_SERVICE)).notify(1, 
          new NotificationCompat.Builder(ctx)
            .setContentTitle(ctx.getString(Util.events[id].notify_text))
            .setSmallIcon(R.drawable.icon)
            .setAutoCancel(true)
            .setContentIntent(pi)
            .setDefaults(Notification.DEFAULT_ALL)
            .build()
        );
      }
    }
    Util.setAlarm(ctx);
  }
}
