package i0akinsec.wordpress.com.practicarocio;

import android.app.PendingIntent;
import android.appwidget.AppWidgetManager;
import android.appwidget.AppWidgetProvider;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.widget.RemoteViews;
import android.widget.Toast;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

public class Widget extends AppWidgetProvider {
    private static final String SYNC_CLICKED    = "automaticWidgetSyncButtonClick";
    @Override
    public void onUpdate(Context context, AppWidgetManager appWidgetManager, int[] appWidgetIds) {
        RemoteViews remoteViews = new RemoteViews(context.getPackageName(), R.layout.activity_main);
        ComponentName watchWidget = new ComponentName(context, Widget.class);
        remoteViews.setOnClickPendingIntent(R.id.actionButton, getEstePendingIntent(context, SYNC_CLICKED));
        appWidgetManager.updateAppWidget(watchWidget, remoteViews);
    }
    protected PendingIntent getEstePendingIntent(Context context, String action) {
        Intent intent = new Intent(context, getClass());
        intent.setAction(action);
        return PendingIntent.getBroadcast(context, 0, intent, 0);
    }
    @Override
    public void onReceive(final Context context, Intent intent) {
        super.onReceive(context, intent);
        if (SYNC_CLICKED.equals(intent.getAction())) {
            Toast.makeText(context, "Comenzando", Toast.LENGTH_SHORT).show();
            new Thread(new Runnable() {
                public void run() {
                    try{
                        Socket socket = new Socket("192.168.42.141", 5000);
                        PrintWriter salida = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()), true);
                        salida.println("apagar");
                        socket.close();
                    } catch(Exception e){ }
                }
            }).start();
        }
    }
}
