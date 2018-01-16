package i0akinsec.wordpress.com.examenparcial2;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;

public class Registro extends AppCompatActivity {

    private Intent intentPonente;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_registro);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                setResult(2);
                finish();
            }
        });

        intentPonente = new Intent(this, PonenteActivity.class);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (resultCode == 2){
            setResult(resultCode);
            finish();
        }
    }

    public void btnPonenteClick(View view) {
        startActivityForResult(intentPonente, 0);
    }

    public void btnAsistenteClick(View view) {
        //Intent intent = new Intent(this, Asis.class);
        //startActivity(intent);
    }

}
