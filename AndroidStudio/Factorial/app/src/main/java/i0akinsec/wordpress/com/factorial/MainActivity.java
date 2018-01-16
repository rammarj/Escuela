package i0akinsec.wordpress.com.factorial;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private EditText numero;
    private TextView resultado;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.numero = (EditText) findViewById(R.id.txtNumero);
        this.resultado = (TextView) findViewById(R.id.txtvRes);
    }

    public void calcular(View view) {
        int num = 0;
        try {
            num = Integer.parseInt(numero.getText().toString());
        }catch(NumberFormatException ex){
            //Toast.makeText(this, "Error de número.", Toast.LENGTH_LONG).show();
            return;
        }
        Hilo hilo = new Hilo(num);
        hilo.start();
    }

    /**
     * Clase que ejecuta el factorial
     */
    private class Hilo extends Thread {

        private int num;

        Hilo(int num){
            this.num = num;
        }
        @Override
        public void run() {
            double res = this.num;
            int cont = (int) res;
            final double fact = res;
            for (int i = cont-1; i > 0; i--)
                res = res * i;

            final double finalRes = res;
            runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    resultado.append("Resultado: factorial("+fact+")=" + finalRes+"\n");
                }
            });
        }

    }

}
