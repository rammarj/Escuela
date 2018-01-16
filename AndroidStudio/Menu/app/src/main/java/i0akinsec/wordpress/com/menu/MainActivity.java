package i0akinsec.wordpress.com.menu;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int itemId = item.getItemId();
        if (itemId == R.id.configuracion){
            final EditText entrada = new EditText(this);
            new AlertDialog.Builder(this)
            .setTitle("Ejemplo de cuadro de diálogo").setMessage("Introduce tu nombre: ")
            .setView(entrada)
            .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    String nombre = entrada.getText().toString();
                    Intent i = new Intent(getApplicationContext(), Configuracion.class);
                    i.putExtra("nombre",nombre);
                    startActivity(i);
                }
            })
            .setNegativeButton("Cancelar", null)
            .show();
            return true;
        }
        else if (itemId == R.id.acercaDe){
            Context applicationContext = getApplicationContext();
            CharSequence text = "Versión 1.0";
            Toast.makeText(applicationContext, text, Toast.LENGTH_SHORT).show();
            return true;
        }
        return false;
    }
}
