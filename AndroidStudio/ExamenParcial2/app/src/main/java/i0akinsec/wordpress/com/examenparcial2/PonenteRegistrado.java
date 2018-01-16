package i0akinsec.wordpress.com.examenparcial2;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.TextView;

public class PonenteRegistrado extends AppCompatActivity {

    private TextView txtNombre;
    private TextView txtCorreo;
    private TextView txtTema;
    private TextView txtUniOrigen;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ponente_registrado);
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

        this.txtNombre = (TextView) findViewById(R.id.txtvDatosRegistradoNombre);
        this.txtCorreo = (TextView) findViewById(R.id.txtvDatosRegistradoCorreo);
        this.txtTema = (TextView) findViewById(R.id.txtvDatosRegistradoTema);
        this.txtUniOrigen = (TextView) findViewById(R.id.txtvDatosRegistradoUni);

        Bundle extras = getIntent().getExtras();
        //mostrar los datos
        this.txtNombre.setText("Nombre: "+extras.getString("nombre"));
        this.txtCorreo.setText("Correo: "+extras.getString("correo"));
        this.txtTema.setText("Tema: "+extras.getString("tema"));
        this.txtUniOrigen.setText("Unversidad origen: "+extras.getString("uni_origen"));

    }

}
