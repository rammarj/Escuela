package i0akinsec.wordpress.com.sensores2;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;
import java.util.List;

public class lista_sensores extends AppCompatActivity implements SensorEventListener {

    private TextView salida;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_lista_sensores);
        salida = (TextView) findViewById(R.id.txtSalida);
        SensorManager sensorManager = (SensorManager)
                getSystemService(SENSOR_SERVICE);
        List<Sensor> listaSensores = sensorManager.getSensorList(Sensor.TYPE_ALL);
        for(Sensor sensor: listaSensores){
            log(sensor.getName());
        }
    }

    private void log(String string){
        salida.append(string + "\n");
    }

    @Override
    public void onSensorChanged(SensorEvent event) {}

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {}

}
