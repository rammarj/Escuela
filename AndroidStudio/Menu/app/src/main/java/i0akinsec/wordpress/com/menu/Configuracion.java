package i0akinsec.wordpress.com.menu;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class Configuracion extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_configuracion);

        String nombre = getIntent().getExtras().getString("nombre");
        TextView txt = (TextView) findViewById(R.id.txtvNombre);
        txt.setText(nombre);
    }
}
