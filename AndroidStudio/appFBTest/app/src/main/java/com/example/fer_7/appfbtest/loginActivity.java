package com.example.fer_7.appfbtest;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.facebook.CallbackManager;
import com.facebook.FacebookCallback;
import com.facebook.FacebookException;
import com.facebook.login.LoginResult;
import com.facebook.login.widget.LoginButton;

public class loginActivity extends AppCompatActivity {

    private LoginButton loginBtn;
    private CallbackManager callbackManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        //Se inicializan loginBtn y CallBack
        callbackManager = CallbackManager.Factory.create();
        loginBtn = (LoginButton) findViewById(R.id.loginBtn);
        loginBtn.registerCallback(callbackManager, new FacebookCallback<LoginResult>() {
            @Override
            public void onSuccess(LoginResult loginResult) {
                //Nuevo metodo de la pantalla a donde vamosx
                goMainScreen();
            }

            @Override
            public void onCancel() {
                //Mandar mnsj de cancelación
                Toast.makeText(getApplicationContext(),R.string.login,Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onError(FacebookException error) {
                //Error
                Toast.makeText(getApplicationContext(),R.string.loginError,Toast.LENGTH_SHORT).show();
            }
        });
    }


    public void goMainScreen() {
        Intent intent = new Intent(this, MainActivity.class);
        intent.addFlags((intent.FLAG_ACTIVITY_CLEAR_TOP | intent.FLAG_ACTIVITY_CLEAR_TASK | intent.FLAG_ACTIVITY_NEW_TASK));
        startActivity(intent);
    }


    public void goMain(View view) {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data){
        super.onActivityResult(requestCode,resultCode,data);
        callbackManager.onActivityResult(requestCode,resultCode,data);
    }
}
