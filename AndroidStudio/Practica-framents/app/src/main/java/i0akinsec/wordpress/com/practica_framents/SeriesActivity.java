package i0akinsec.wordpress.com.practica_framents;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class SeriesActivity extends AppCompatActivity {

    private EditText txtCantidadPrimos;
    private EditText txtCantidadFibos;
    private TextView txtvSerieFibo;
    private TextView txtvPrimos;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_series);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
            }
        });

        this.txtCantidadPrimos = (EditText) findViewById(R.id.txtNumPrimos);
        this.txtCantidadFibos = (EditText) findViewById(R.id.txtNumSerie);

        this.txtvPrimos = (TextView) findViewById(R.id.txtvNumPrimos);
        this.txtvSerieFibo = (TextView) findViewById(R.id.txtvSerie);
    }

    private boolean verificarPrimo(int num){
        int limiteTest = num/2; //para no hacer tests de todos los numeros posibles.
        int aux;
        for (int i=2; i<=limiteTest; i++){
            aux = num%i; //obtener el resto para saber si es divisible
            if (aux == 0)
                return false; //no es primo portque es divisible entre otros numeros que no sea el mismo y la unidad (1)
        }
        return true;
    }

    public void btnPrimosClick(View view) {

        new Thread(new Runnable() {
            @Override
            public void run() {
                int numPrimos = Integer.parseInt(this.txtCantidadPrimos.getText().toString());
                int cont = 0;
                int num = 1; //numeros primos empieza en 1 (creo)
                StringBuilder builder = new StringBuilder();

                while (cont < numPrimos){
                    if (verificarPrimo(num)){
                        builder.append(num).append(", ");
                        cont ++;
                    }
                    num ++;
                }
            }
        }).start();
        this.txtvPrimos.setText(builder.toString());
    }

    public void btnFibonacciClick(View view) {
        int actual = 1;
        int anterior = 0;
        int siguiente;
        int cantidadFibos = Integer.parseInt(this.txtCantidadFibos.getText().toString());
        StringBuilder builder = new StringBuilder();
        for (int i=0;i<cantidadFibos;i++){
            builder.append(actual).append(", ");
            siguiente = anterior + actual;
            anterior = actual;
            actual = siguiente;
        }
        this.txtvSerieFibo.setText(builder.toString());
    }
}
