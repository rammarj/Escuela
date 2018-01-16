package com.rammarj.recetas;

import android.accounts.Account;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.util.Log;
import android.view.View;
import android.support.design.widget.NavigationView;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.TabHost;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.gms.common.GoogleApiAvailability;
import com.google.api.client.googleapis.extensions.android.gms.auth.GoogleAccountCredential;
import com.google.api.client.googleapis.extensions.android.gms.auth.GooglePlayServicesAvailabilityIOException;
import com.google.api.client.googleapis.extensions.android.gms.auth.UserRecoverableAuthIOException;
import com.google.api.services.calendar.CalendarScopes;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

import layout.AcercaDe;

public class Inicio extends AppCompatActivity
        implements NavigationView.OnNavigationItemSelectedListener, View.OnClickListener {

    private BuscarFragment buscarFragment;
    private AcercaDe acercaDeFragment;
    private RecetasAgregadasFragment recetasAgregadasFragment;
    private EditText txtBuscar;
    private DrawerLayout drawer;
    private ProgressDialog mProgress;
    private Exception mLastError;
    private static final int REQUEST_GOOGLE_PLAY_SERVICES = 1002;
    static final int REQUEST_AUTHORIZATION = 1001;
    private GoogleAccountCredential mCredential;
    private String cuentaUsuario;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_inicio);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        ///Identifiable data
        drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        NavigationView navView = (NavigationView) drawer.findViewById(R.id.nav_view);
        TextView usuarioTxtv = (TextView)navView.getHeaderView(0).findViewById(R.id.textViewUsuarioLogin);
        cuentaUsuario = Login.googleSignInAccount.getAccount().name;
        usuarioTxtv.setText(cuentaUsuario.trim());

        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.addDrawerListener(toggle);
        toggle.syncState();

        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);


        mProgress = new ProgressDialog(this);
        mProgress.setMessage("Buscando...");

        buscarFragment = new BuscarFragment();
        acercaDeFragment =  new AcercaDe();
        recetasAgregadasFragment = new RecetasAgregadasFragment();
        getSupportFragmentManager().beginTransaction()
                .add(R.id.contenedorFrag ,buscarFragment)
                .add(R.id.contenedorFrag, acercaDeFragment)
                .add(R.id.contenedorFrag, recetasAgregadasFragment)
                .commit();


    }
    @Override
    protected void onStart() {
        super.onStart();
        getSupportFragmentManager().beginTransaction()
                .hide(acercaDeFragment)
                .hide(recetasAgregadasFragment)
                .show(buscarFragment)
                .commit();

        txtBuscar = (EditText) findViewById(R.id.txtBuscar);
        ImageButton btnBuscar = (ImageButton) findViewById(R.id.btnBuscar);
        btnBuscar.setOnClickListener(this);

        //fragment acerca de
        TabHost tabHost = (TabHost) findViewById(R.id.tabhost);
        tabHost.setup();

        TabHost.TabSpec spec = tabHost.newTabSpec(getString(R.string.acerca_app));
        spec.setIndicator(getString(R.string.acerca_app));
        spec.setContent(R.id.layout1);
        tabHost.addTab(spec);

        spec = tabHost.newTabSpec(getString(R.string.acerca_autor));
        spec.setIndicator(getString(R.string.acerca_autor));
        spec.setContent(R.id.layout2);
        tabHost.addTab(spec);

        //fabButton de RecetasAgredas

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                GoogleAccountCredential googleAccountCredential
                        = GoogleAccountCredential.usingOAuth2(Inicio.this, Arrays.asList(new String[]{CalendarScopes.CALENDAR}));
                //googleAccountCredential.setSelectedAccount(account);
                googleAccountCredential.setSelectedAccountName(cuentaUsuario);
                new ListarRecetasCalendarTask(googleAccountCredential, Inicio.this).execute();
            }
        });
    }
    @Override
    public void onBackPressed() {
        drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        } else {
            super.onBackPressed();
        }
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        //noinspection SimplifiableIfStatement
        if (id == R.id.salir) {
            finish();
            return true;
        }
        if (id == R.id.acercaDe){
            /*new AlertDialog.Builder(this)
                    .setTitle(getString(R.string.acerca_de)).setMessage(getString(R.string.acerca_de_info))
                    .setPositiveButton(getString(R.string.ok), null)
                    .show();*/
            acercaDeItemClick();
        }
        return super.onOptionsItemSelected(item);
    }

    private void acercaDeItemClick(){
        getSupportFragmentManager().beginTransaction()
                .show(acercaDeFragment)
                .hide(buscarFragment)
                .hide(recetasAgregadasFragment)
                .commit();
    }

    @SuppressWarnings("StatementWithEmptyBody")
    @Override
    public boolean onNavigationItemSelected(MenuItem item) {
        // Handle navigation view item clicks here.
        int id = item.getItemId();
        if (id == R.id.nav_inicio) {
            getSupportFragmentManager().beginTransaction()
                    .hide(acercaDeFragment)
                    .hide(recetasAgregadasFragment)
                    .show(buscarFragment)
                    .commit();
        }else if (id == R.id.nav_recetas){
            getSupportFragmentManager().beginTransaction()
                    .hide(acercaDeFragment)
                    .hide(buscarFragment)
                    .show(recetasAgregadasFragment)
                    .commit();
        }else if (id == R.id.nav_acerca_de) {
            acercaDeItemClick();
        }else if (id == R.id.nav_share_fb) {
            Intent intentFacebook = new Intent(Intent.ACTION_VIEW, Uri.parse("https://www.facebook.com/sharer/sharer.php?u=https://i0akinsec.wordpress.com"));
            startActivity(intentFacebook);
        } else if (id == R.id.nav_share_twitter) {
            Intent intentTwitter = new Intent(Intent.ACTION_VIEW,Uri.parse("https://twitter.com/intent/tweet?text=Baja+la+app+que+mas+me+gusta+Recetas+Nutritivas!!+https://i0akinsec.wordpress.com"));
            startActivity(intentTwitter);
        }
        drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }

    @Override
    public void onClick(View v) {
        int id = v.getId();
        switch (id){
            case R.id.btnBuscar:
                mProgress.show();
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        String buscar = txtBuscar.getText().toString();
                        try {
                            final LinkedList<Receta> recetas = ServicioRest.buscar(buscar);
                            runOnUiThread(new Runnable() {
                                @Override
                                public void run() {
                                    buscarFragment.setLista(recetas);
                                    mProgress.hide();
                                }
                            });
                            //
                        } catch (final Exception e) {
                            runOnUiThread(new Runnable() {
                                @Override
                                public void run() {
                                    Toast.makeText(getApplicationContext(), e.toString(), Toast.LENGTH_LONG).show();
                                    mProgress.hide();
                                }
                            });
                        }
                    }
                }).start();

                break;

        }
    }


    public void onPreExecuteCargarCalendar() {
        //mOutputText.setText("");
        mProgress.show();
    }

    public void onPostExecuteCargarCalendar(List<String> output) {
        mProgress.hide();
        if (output == null || output.size() == 0) {
            //mOutputText.setText("No results returned.");
            Log.e(getString(R.string.log), "no hay");
            //Toast.makeText(this, "no hay", Toast.LENGTH_LONG).show();
        } else {
            /*output.add(0, "Data retrieved using the Google Calendar API:");*/
            List<Receta> recetasDesdeStrings = null;
            try {
                recetasDesdeStrings = Util.getRecetasDesdeStrings(output, this);
            } catch (Exception e) {
                e.printStackTrace();
            }
            //*/
            recetasAgregadasFragment.setLista((LinkedList<Receta>) recetasDesdeStrings);
            //mOutputText.setText(TextUtils.join("\n", output));
            Log.e(getString(R.string.log),output.get(0));
            Toast.makeText(getApplicationContext(), output.get(0), Toast.LENGTH_LONG).show();
        }
    }

    private void showGooglePlayServicesAvailabilityErrorDialog(
            final int connectionStatusCode) {
        GoogleApiAvailability apiAvailability = GoogleApiAvailability.getInstance();
        Dialog dialog = apiAvailability.getErrorDialog(
                Inicio.this,
                connectionStatusCode,
                REQUEST_GOOGLE_PLAY_SERVICES);
        dialog.show();
    }

    public void onCancelledCargarCalendar() {
        mProgress.hide();
        if (mLastError != null) {
            if (mLastError instanceof GooglePlayServicesAvailabilityIOException) {
                showGooglePlayServicesAvailabilityErrorDialog(
                        ((GooglePlayServicesAvailabilityIOException) mLastError)
                                .getConnectionStatusCode());
            } else if (mLastError instanceof UserRecoverableAuthIOException) {
                startActivityForResult(
                        ((UserRecoverableAuthIOException) mLastError).getIntent(),
                        Inicio.REQUEST_AUTHORIZATION);
            } else {
                //mOutputText.setText("The following error occurred:\n" + mLastError.getMessage());
                Log.e(getString(R.string.log), mLastError.getMessage());
            }
        } else {
            //mOutputText.setText("Request cancelled.");
            Log.e(getString(R.string.log), "Request cancelled.");
        }
    }

}
