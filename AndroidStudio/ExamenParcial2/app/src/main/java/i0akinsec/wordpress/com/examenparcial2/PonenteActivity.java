package i0akinsec.wordpress.com.examenparcial2;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class PonenteActivity extends AppCompatActivity {

    private EditText txtNombre;
    private EditText txtCorreo;
    private EditText txtTema;
    private EditText txtUniOrigen;
    private Intent intentPonenteRegistrado;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ponente);
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

        this.txtNombre = (EditText) findViewById(R.id.txtNombre);
        this.txtCorreo = (EditText) findViewById(R.id.txtCorreo);
        this.txtTema = (EditText) findViewById(R.id.txtTemaPonencia);
        this.txtUniOrigen = (EditText) findViewById(R.id.txtUniOrigen);

        intentPonenteRegistrado = new Intent(this, PonenteRegistrado.class);

    }

    public void btnRegistrarPonenteClick(View view) {
        String nombre = this.txtNombre.getText().toString();
        String correo = this.txtCorreo.getText().toString();
        String tema = this.txtTema.getText().toString();
        String uniOrigen = this.txtUniOrigen.getText().toString();

        intentPonenteRegistrado.putExtra("nombre", nombre);
        intentPonenteRegistrado.putExtra("correo", correo);
        intentPonenteRegistrado.putExtra("tema", tema);
        intentPonenteRegistrado.putExtra("uni_origen", uniOrigen);

        Ponente ponente = new Ponente();
        ponente.setNombre(nombre);
        ponente.setCorreo(correo);
        ponente.setTemaPonencia(tema);
        ponente.setUniversidadOrigen(uniOrigen);

        DatosPonentes.registrarPonente(ponente);

        startActivityForResult(intentPonenteRegistrado, 0);

    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (resultCode == 2){
            setResult(2);
            finish();
        }
    }

}
