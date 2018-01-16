package com.example.fer_7.appfbtest;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

import com.facebook.AccessToken;
import com.facebook.FacebookSdk;
import com.facebook.login.LoginManager;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //if(AccessToken.getCurrentAccessToken() == null){
            //goLogInScreen();
        //}
    }

    private void goLogInScreen() {
        Intent intent = new Intent (this, loginActivity.class);
        intent.addFlags((intent.FLAG_ACTIVITY_CLEAR_TOP | intent.FLAG_ACTIVITY_CLEAR_TASK | intent.FLAG_ACTIVITY_NEW_TASK));
        startActivity(intent);
    }

    public void logout(View view) {
        LoginManager.getInstance().logOut();
        goLogInScreen();
    }
}
