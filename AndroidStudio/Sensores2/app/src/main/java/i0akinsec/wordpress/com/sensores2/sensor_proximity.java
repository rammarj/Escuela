package i0akinsec.wordpress.com.sensores2;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import java.util.List;

public class sensor_proximity extends AppCompatActivity implements SensorEventListener{

    private TextView message;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sensor_proximity);
        message = (TextView) findViewById(R.id.txtMessage);
        SensorManager sensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        List<Sensor> listaSensores = sensorManager.getSensorList(Sensor.TYPE_PROXIMITY);
        if(!listaSensores.isEmpty()){
            Sensor proximidadSensor = listaSensores.get(0);
            sensorManager.registerListener(this, proximidadSensor, SensorManager.SENSOR_DELAY_NORMAL);
        }
    }
    @Override
    public void onSensorChanged(SensorEvent evento) {
        float valor = Float.parseFloat(String.valueOf(evento.values[0]));
        valor = valor * 10;
        if (valor < 5) {
            message.setText("Objeto detectado");
        }
        else {
            message.setText("Objeto fuera de alcance");
        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) { }

}
