package i0akinsec.wordpress.com.a10_02_2017;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    private EditText txtNombre;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        txtNombre = (EditText) findViewById(R.id.txtNombre);
    }

    public void enviarDatos(View v) {
        Intent intent = new Intent(this, SegundoActivity.class);
        intent.putExtra("nombre", txtNombre.getText().toString());
        startActivity(intent);
    }

}
