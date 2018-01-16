package i0akinsec.wordpress.com.navdrawer;

import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.design.widget.NavigationView;
import android.support.v7.app.AppCompatActivity;
import android.view.MenuItem;
import android.widget.Toast;

/**
 * Created by RAMMARJ on 20/02/2017.
 */

public class Navigation extends AppCompatActivity implements NavigationView.OnNavigationItemSelectedListener{

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.navigation);
        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);
    }

    @Override
    public boolean onNavigationItemSelected(@NonNull MenuItem item) {
        int itemId = item.getItemId();
        if(itemId == R.id.inicio){
            Toast.makeText(this,"Inicio", Toast.LENGTH_SHORT).show();
            return true;
        }
        if(itemId == R.id.configurar){
            Toast.makeText(this,"Configurar", Toast.LENGTH_SHORT).show();
            return true;
        }
        if(itemId == R.id.cerrar){
            Toast.makeText(this,"Cerrar", Toast.LENGTH_SHORT).show();
            return true;
        }
        if(itemId == R.id.galeria){
            finish();
        }
        if(itemId == R.id.contenido){
            Toast.makeText(this,"contenido", Toast.LENGTH_SHORT).show();
            return true;
        }
        return false;
    }
}
