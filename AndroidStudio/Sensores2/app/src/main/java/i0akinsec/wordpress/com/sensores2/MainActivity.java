package i0akinsec.wordpress.com.sensores2;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void abrirListSensor(View view){
        Intent intent = new Intent(this, lista_sensores.class);
        startActivity(intent);
    }
    public void abrirSensorProximity(View view){
        Intent intent = new Intent(this, sensor_proximity.class);
        startActivity(intent);
    }
    public void abrirBrujula(View view){
        Intent intent = new Intent(this, brujula.class);
        startActivity(intent);
    }
    public void salir(View view) {
        System.exit(0);
    }

}
