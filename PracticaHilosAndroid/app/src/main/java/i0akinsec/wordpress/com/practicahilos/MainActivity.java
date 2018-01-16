package i0akinsec.wordpress.com.practicahilos;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import java.util.LinkedList;
import java.util.Random;

public class MainActivity extends AppCompatActivity {

    private EditText txtCantidadNum;
    private TextView txtvRes;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txtCantidadNum = (EditText) findViewById(R.id.txtCantidadNum);
        txtvRes = (TextView) findViewById(R.id.txtvRes);
    }

    private LinkedList<Integer> sortInsercion(LinkedList<Integer> resolver)
    {
        int i, a;
        int aux;
        for (i = 1; i < resolver.size(); i++) //empezar desde 1
        {
            aux = resolver.get(i); //guardar el valor a comparar en un auxiliar
            for (a = (i - 1); a >= 0 && resolver.get(a) > aux; a--)
            {
                resolver.set(a + 1, resolver.get(a)); //recorrer los elementos
            }
            resolver.set(a + 1, aux); //poner al elemento en su pocicion real
        }
        return resolver;
    }

    public void ordenarClick(View view) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                LinkedList<Integer> resolver = new LinkedList<>();
                final int cantidad = Integer.parseInt(txtCantidadNum.getText().toString());
                //
                //ordenamiento en insercion
                //
                int  a;
                int aux;
                for (int i = 1; i < resolver.size(); i++) //empezar desde 1
                {
                    aux = resolver.get(i); //guardar el valor a comparar en un auxiliar
                    for (a = (i - 1); a >= 0 && resolver.get(a) > aux; a--)
                    {
                        resolver.set(a + 1, resolver.get(a)); //recorrer los elementos
                    }
                    resolver.set(a + 1, aux); //poner al elemento en su pocicion real
                }
                Random random = new Random();
                for(int i=0;i<cantidad;i++){
                    resolver.add(random.nextInt(10000));
                }
                //ordenar
                LinkedList<Integer> ordenados = sortInsercion(resolver);
                final StringBuilder builder = new StringBuilder();
                for (int num : ordenados){
                    builder.append(num).append(",");
                }
                builder.append("\n"); //agregar separacion entre resultados
                //mostrar el resultado
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        txtvRes.append(builder.toString());
                    }
                });
            }
        }).start();

    }
}
