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


public class RecetaActivity extends AppCompatActivity {

    private String url;
    private Receta receta;
    private ProgressDialog mProgress;

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
        this.receta = new Receta();
        this.receta.setNombre(receta);
        this.receta.setUrlImagen(imagen);
        this.receta.setCalorias(calorias);
        this.receta.setIngredientes(Util.stringLista(ingredientes));

        mProgress = new ProgressDialog(this);
        mProgress.setMessage(getString(R.string.cargando));
    }
}
