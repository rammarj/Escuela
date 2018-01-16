package i0akinsec.wordpress.com.appbar;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
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
        int id = item.getItemId();
        if (id == R.id.configuracion){
            Toast.makeText(this, "Configuración pulsado!", Toast.LENGTH_LONG).show();
            return true;
        }
        else if (id == R.id.acercaDe){
            Toast.makeText(this, "Acerca de pulsado!", Toast.LENGTH_LONG).show();
            return true;
        }
        return false;
    }
}
