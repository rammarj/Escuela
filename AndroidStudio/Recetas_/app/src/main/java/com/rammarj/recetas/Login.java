package com.rammarj.recetas;

import android.app.ProgressDialog;
import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;
import com.google.android.gms.auth.api.Auth;
import com.google.android.gms.auth.api.signin.GoogleSignInAccount;
import com.google.android.gms.auth.api.signin.GoogleSignInOptions;
import com.google.android.gms.auth.api.signin.GoogleSignInResult;
import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.SignInButton;
import com.google.android.gms.common.api.GoogleApiClient;
import com.google.android.gms.common.api.ResultCallback;
import com.google.android.gms.common.api.Scope;
import com.google.android.gms.common.api.Status;
import com.google.api.services.calendar.CalendarScopes;

public class Login extends AppCompatActivity  implements
        GoogleApiClient.OnConnectionFailedListener,
        View.OnClickListener{

    private static final int RC_SIGN_IN = 9001;
    private TextView txtvSubtitulo;
    private ProgressDialog mProgressDialog;
    private GoogleApiClient mGoogleApiClient;
    private boolean logueado = false;
    public static GoogleSignInAccount googleSignInAccount; //utilizare esto despues en el requrimiento de calendario

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (logueado){
                    Intent intent = new Intent(Login.this, Inicio.class);
                    //intent.putExtra(getString(R.string.bundle_extra_usuario), usuario); //cambiado por googleSignInAccount
                    startActivity(intent);
                }else{
                    new AlertDialog.Builder(Login.this)
                            .setTitle(getString(R.string.informacion)).setMessage(getString(R.string.err_inicio_logIn))
                            .setPositiveButton(getString(R.string.ok), null)
                            .show();
                }
            }
        });

        txtvSubtitulo = (TextView) findViewById(R.id.subtitulo);

        // Button listeners
        findViewById(R.id.sign_in_button).setOnClickListener(this);
        findViewById(R.id.btn_sign_out).setOnClickListener(this);
        //findViewById(R.id.sign_out_button).setOnClickListener(this);
        //findViewById(R.id.disconnect_button).setOnClickListener(this);

        // [START configure_signin]
        // Configure sign-in to request the user's ID, email address, and basic
        // profile. ID and basic profile are included in DEFAULT_SIGN_IN.
        GoogleSignInOptions gso = new GoogleSignInOptions.Builder(GoogleSignInOptions.DEFAULT_SIGN_IN)
                .requestEmail()
                .requestScopes(new Scope(CalendarScopes.CALENDAR))
                .build();

        // [END configure_signin]

        // [START build_client]
        // Build a GoogleApiClient with access to the Google Sign-In API and the
        // options specified by gso.
        mGoogleApiClient = new GoogleApiClient.Builder(this)
                .enableAutoManage(this /* FragmentActivity */, this /* OnConnectionFailedListener */)
                .addApi(Auth.GOOGLE_SIGN_IN_API, gso)
                //.addScope(new Scope(CalendarScopes.CALENDAR))
                .build();
        // [END build_client]
        // [START customize_button]
        // Set the dimensions of the sign-in button.
        SignInButton signInButton = (SignInButton) findViewById(R.id.sign_in_button);
        signInButton.setSize(SignInButton.SIZE_STANDARD);
        // [END customize_button]
        //findViewById(R.id.btn_sign_out).setVisibility(View.INVISIBLE); //ocultar primero el de desconectar
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_login, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            finish();
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
    // [START onActivityResult]
    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        // Result returned from launching the Intent from GoogleSignInApi.getSignInIntent(...);
        if (requestCode == RC_SIGN_IN) {
            GoogleSignInResult result = Auth.GoogleSignInApi.getSignInResultFromIntent(data);
            handleSignInResult(result);
        }
    }
    // [START handleSignInResult]
    private void handleSignInResult(GoogleSignInResult result) {
        Log.d(getString(R.string.log), getString(R.string.manejador_sign_res, String.valueOf(result.isSuccess())));
        if (result.isSuccess()) {
            // Signed in successfully, show authenticated UI.
            googleSignInAccount = result.getSignInAccount();
            //googleAccountCredential.setSelectedAccount(account);
            String usuario = googleSignInAccount.getDisplayName();
            txtvSubtitulo.setText(getString(R.string.logueado_como, usuario));
            updateUI(true);
        } else {
            // Signed out, show unauthenticated UI.
            updateUI(false);
        }
    }
    // [END handleSignInResult]
    private void updateUI(boolean signedIn) {
        logueado = signedIn;
        if (signedIn) {
            findViewById(R.id.sign_in_button).setVisibility(View.GONE);
            findViewById(R.id.btn_sign_out).setVisibility(View.VISIBLE);
        } else {
            txtvSubtitulo.setText(R.string.sign_out);
            findViewById(R.id.sign_in_button).setVisibility(View.VISIBLE);
            findViewById(R.id.btn_sign_out).setVisibility(View.GONE);
        }
    }
    // [START signIn]
    private void signIn() {
        Intent signInIntent = Auth.GoogleSignInApi.getSignInIntent(mGoogleApiClient);
        startActivityForResult(signInIntent, RC_SIGN_IN);
    }
    // [END signIn]

    // [START signOut]
    private void signOut() {
        Auth.GoogleSignInApi.signOut(mGoogleApiClient).setResultCallback(
                new ResultCallback<Status>() {
                    @Override
                    public void onResult(Status status) {
                        // [START_EXCLUDE]
                        updateUI(false);
                        // [END_EXCLUDE]
                    }
                });
    }
    // [END signOut]

    // [START revokeAccess]
    private void revokeAccess() {
        Auth.GoogleSignInApi.revokeAccess(mGoogleApiClient).setResultCallback(
                new ResultCallback<Status>() {
                    @Override
                    public void onResult(Status status) {
                        // [START_EXCLUDE]
                        updateUI(false);
                        // [END_EXCLUDE]
                    }
                });
    }
    // [END revokeAccess]

    @Override
    public void onConnectionFailed(ConnectionResult connectionResult) {
        // An unresolvable error has occurred and Google APIs (including Sign-In) will not
        // be available.
        Log.d(getString(R.string.log), getString(R.string.login_google_conexion_fallida, connectionResult.toString()));
    }

    private void showProgressDialog() {
        if (mProgressDialog == null) {
            mProgressDialog = new ProgressDialog(this);
            mProgressDialog.setMessage(getString(R.string.cargando));
            mProgressDialog.setIndeterminate(true);
        }

        mProgressDialog.show();
    }

    private void hideProgressDialog() {
        if (mProgressDialog != null && mProgressDialog.isShowing()) {
            mProgressDialog.hide();
        }
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.sign_in_button:
                signIn();
                break;
            case R.id.btn_sign_out:
                signOut();
                break;
        }
    }

}
