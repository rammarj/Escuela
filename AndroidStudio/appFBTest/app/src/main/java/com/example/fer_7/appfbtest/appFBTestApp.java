package com.example.fer_7.appfbtest; /**
 * Created by fer_7 on 30/01/2017.
 */

import android.app.Application;
import com.facebook.FacebookSdk;
import com.facebook.appevents.AppEventsLogger;

public class appFBTestApp extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        FacebookSdk.sdkInitialize(getApplicationContext());
        AppEventsLogger.activateApp(this);
    }
}
