package com.rammarj.recetas;

import android.accounts.Account;
import android.app.AlertDialog;
import android.app.DatePickerDialog;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;

import com.google.android.gms.common.GoogleApiAvailability;
import com.google.api.client.extensions.android.http.AndroidHttp;
import com.google.api.client.googleapis.extensions.android.gms.auth.GoogleAccountCredential;
import com.google.api.client.googleapis.extensions.android.gms.auth.GooglePlayServicesAvailabilityIOException;
import com.google.api.client.googleapis.extensions.android.gms.auth.UserRecoverableAuthIOException;
import com.google.api.client.http.HttpTransport;
import com.google.api.client.json.JsonFactory;
import com.google.api.client.json.jackson2.JacksonFactory;
import com.google.api.client.util.DateTime;
import com.google.api.services.calendar.CalendarScopes;
import com.google.api.services.calendar.model.Event;
import com.google.api.services.calendar.model.EventDateTime;

import java.io.IOException;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;


public class RecetaActivity extends AppCompatActivity implements View.OnClickListener {

    private String url;
    private Receta receta;
    private ProgressDialog mProgress;
    private static final int REQUEST_GOOGLE_PLAY_SERVICES = 1002;
    static final int REQUEST_AUTHORIZATION = 1001;
    private Exception mLastError;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.fragment_receta);

        Bundle extras = getIntent().getExtras();
        final String imagen = extras.getString(getString(R.string.bundle_extra_imagen));
        String receta = extras.getString(getString(R.string.bundle_extra_receta));
        String ingredientes = extras.getString(getString(R.string.bundle_extra_ingredientes));
        float calorias = extras.getFloat(getString(R.string.bundle_extra_calorias));
        url = extras.getString(getString(R.string.bundle_extra_url));
        final ImageView imgReceta = (ImageView) findViewById(R.id.imgReceta);
        TextView txtvNombreReceta = (TextView) findViewById(R.id.txtvNombreReceta);
        TextView txtvIngredientes = (TextView) findViewById(R.id.txtvIngredientes);
        TextView txtvCalorias = (TextView) findViewById(R.id.txtvCalorias);
        //mostrar
        new Thread(new Runnable() {
            @Override
            public void run() {
                try{
                    final Drawable drawable = Util.cargarImagen(imagen);
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            imgReceta.setImageDrawable(drawable);
                        }
                    });
                }catch(Exception ex){
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            imgReceta.setImageResource(R.drawable.receta);
                        }
                    });
                }
            }
        }).start();

        txtvNombreReceta.setText(receta);
        txtvIngredientes.setText(getString(R.string.ingredientes, ingredientes));
        txtvCalorias.setText(getString(R.string.calorias, calorias));

        ImageButton btnFacebook = (ImageButton) findViewById(R.id.btnFacebook);
        ImageButton btnTwitter = (ImageButton) findViewById(R.id.btnTwitter);
        Button btnAgregarAlCalendario = (Button) findViewById(R.id.btnAgregarAlCalendario);

        this.receta = new Receta();
        this.receta.setNombre(receta);
        this.receta.setUrlImagen(imagen);
        this.receta.setCalorias(calorias);
        this.receta.setIngredientes(Util.stringLista(ingredientes));
        //listeners
        btnFacebook.setOnClickListener(this);
        btnTwitter.setOnClickListener(this);
        btnAgregarAlCalendario.setOnClickListener(this);

        mProgress = new ProgressDialog(this);
        mProgress.setMessage(getString(R.string.msg_cargando_google_calendar));
    }

    @Override
    public void onClick(View v) {
        int id = v.getId();
        switch (id){
            case R.id.btnTwitter:
                Intent intentTwitter = new Intent(Intent.ACTION_VIEW,Uri.parse("https://twitter.com/intent/tweet?text=Viendo+recetas+nutritivas!+" + url));
                startActivity(intentTwitter);
                break;
            case R.id.btnFacebook:
                Intent intentFacebook = new Intent(Intent.ACTION_VIEW,Uri.parse("https://www.facebook.com/sharer/sharer.php?u=" + url));
                startActivity(intentFacebook);
                break;
            case R.id.btnAgregarAlCalendario:
                final DatePicker calendario = new DatePicker(this);
                Date ahora = new Date(System.currentTimeMillis());
                GregorianCalendar maximo = (GregorianCalendar) GregorianCalendar.getInstance();
                maximo.setTime(ahora);
                maximo.add(Calendar.MONTH, 2);
                calendario.setMinDate(ahora.getTime());
                calendario.setMaxDate(maximo.getTime().getTime());
                AlertDialog show = new DatePickerDialog.Builder(this)
                        .setTitle("Información").setMessage("Fecha para preparar la receta: ")
                        .setView(calendario)
                        .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                /*int day = calendario.getDayOfMonth();
                                int month = calendario.getMonth() + 1;
                                int year = calendario.getYear();
                                GregorianCalendar date = new GregorianCalendar(year, month, day);
                                receta.setFecha(date.getTime());
                                */
                                Account account = Login.googleSignInAccount.getAccount();
                                final GoogleAccountCredential googleAccountCredential = GoogleAccountCredential.usingOAuth2(RecetaActivity.this
                                        , Arrays.asList(new String[]{CalendarScopes.CALENDAR}));
                                googleAccountCredential.setSelectedAccountName(account.name);

                                HttpTransport transport = AndroidHttp.newCompatibleTransport();
                                JsonFactory jsonFactory = JacksonFactory.getDefaultInstance();

                                final com.google.api.services.calendar.Calendar mService = new com.google.api.services.calendar.Calendar.Builder(
                                        transport, jsonFactory, googleAccountCredential)
                                        .setApplicationName("Google Calendar API")
                                        .build();

                                String json = "{\"nombre\":\""+receta.getNombre()+"\",\"url_imagen\":\""+
                                        receta.getUrlImagen()+"\",\"ingredientes\":\""+receta.getIngredientes()
                                        +"\",\"calorias\":"+receta.getCalorias()+"}";

                                final Event event = new Event().setSummary("Preparar "+receta.getNombre()).setDescription(json);
                                event.setStart(new EventDateTime().setDate(new DateTime(true, new Date().getTime(), 0)));
                                event.setEnd(new EventDateTime().setDate(new DateTime(true, new Date().getTime(), 0)));

                                    new Thread(new Runnable() {
                                        @Override
                                        public void run() {
                                            try {
                                                Event execute = mService.events().insert(getString(R.string.calendar_recetas_id), event).execute();
                                                Log.e("LOG", execute.getHtmlLink());
                                                finish();
                                            } catch (IOException e) {
                                                Log.e("LOG",e.toString());
                                            }
                                        }
                                    }).start();
                            }
                        })
                        .setNegativeButton("Cancelar", null)
                        .show();
                break;
        }
    }

}
