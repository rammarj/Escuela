package com.rammarj.recetas;

/**
 * Created by RAMMARJ on 25/04/2017.
 */
import android.app.Activity;
import android.os.AsyncTask;
import android.util.Log;
import com.google.api.client.extensions.android.http.AndroidHttp;
import com.google.api.client.googleapis.extensions.android.gms.auth.GoogleAccountCredential;
import com.google.api.client.http.HttpTransport;
import com.google.api.client.json.JsonFactory;
import com.google.api.client.json.jackson2.JacksonFactory;
import com.google.api.client.util.DateTime;
import com.google.api.services.calendar.model.Event;
import com.google.api.services.calendar.model.Events;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**google calendar magic*/
class ListarRecetasCalendarTask extends AsyncTask<Void, Void, List<String>> {
    private com.google.api.services.calendar.Calendar mService = null;
    private Exception mLastError = null;
    private Inicio activity;

    ListarRecetasCalendarTask(GoogleAccountCredential credential, Activity activity) {
        HttpTransport transport = AndroidHttp.newCompatibleTransport();
        JsonFactory jsonFactory = JacksonFactory.getDefaultInstance();
        this.activity = (Inicio) activity;
        mService = new com.google.api.services.calendar.Calendar.Builder(
                transport, jsonFactory, credential)
                .setApplicationName("Google Calendar API")
                .build();
    }
    /**
     * Background task to call Google Calendar API.
     * @param params no parameters needed for this task.
     */
    @Override
    protected List<String> doInBackground(Void... params) {
        try {
            //Log.e(activity.getString(R.string.log),"obteniendo datos");
            return getDataFromApi();
        } catch (Exception e) {
            mLastError = e;
            Log.e(activity.getString(R.string.log), e.toString());
            cancel(true);
            return null;
        }
    }
    /**
     * Fetch a list of the next 10 events from the primary calendar.
     * @return List of Strings describing returned events.
     * @throws IOException
     */
    private List<String> getDataFromApi() throws IOException {
        // List the next 10 events from the primary calendar.
        DateTime now = new DateTime(System.currentTimeMillis());
        List<String> eventStrings = new ArrayList<String>();

        Events events = mService.events().list(activity.getString(R.string.calendar_recetas_id))
                .setMaxResults(10)
                .setTimeMin(now)
                .setOrderBy("startTime")
                //.setSingleEvents(true)
                .execute();


        Log.e(activity.getString(R.string.log),"terminado metodo getDataFromApi()");
        List<Event> items = events.getItems();

        for (Event event : items) {
            DateTime start = event.getStart().getDateTime();
            if (start == null) {
                // All-day events don't have start times, so just use
                // the start date.
                start = event.getStart().getDate();
            }
            eventStrings.add(String.format("%s (%s)", (event.getSummary()==null)?"Sin titulo":event.getSummary(), start));

        }
        return eventStrings;
    }
    @Override
    protected void onPreExecute() {
        activity.onPreExecuteCargarCalendar();
    }
    @Override
    protected void onPostExecute(List<String> output) {
        activity.onPostExecuteCargarCalendar(output);
    }
    @Override
    protected void onCancelled() {
        activity.onCancelledCargarCalendar();
    }

}