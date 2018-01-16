package i0akinsec.wordpress.com.sensores2;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.animation.Animation;
import android.view.animation.RotateAnimation;
import android.widget.ImageView;
import android.widget.TextView;

public class brujula extends AppCompatActivity implements SensorEventListener{

    private TextView txtAngle;
    private ImageView imgCompas;
    private float currentDegree = 0f; //Guarda el angulo (grado) actual del compas
    private SensorManager mSensorManager; //El sensor manager del dispositivo

    //Los dos sensores necesarios
    private Sensor accelerometer;
    private Sensor magnetometer;

    float degree;//Los angulos de movimiento del compas que señala al norte
    float azimut;//Guarda el valor del azimut
    float[] mGravity;//Guarda los valores que cambián con las variaciones del sensor TYPE_ACCELEROMETER
    float[] mGeomagnetic;// Guarda los valores que cambián con las variaciones del sensor TYPE_MAGNETIC_FIELD

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_brujula);
        imgCompas = (ImageView) findViewById(R.id.imgViewCompas);
        txtAngle = (TextView) findViewById(R.id.txtAngle);
        //Se inicializan los sensores del dispositivo
        mSensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        accelerometer = mSensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        magnetometer = mSensorManager.getDefaultSensor(Sensor.TYPE_MAGNETIC_FIELD);
        mGravity = null;
        mGeomagnetic = null;
    }

    @Override
    protected void onResume(){
        super.onResume();
        mSensorManager.registerListener(this, accelerometer,SensorManager.SENSOR_DELAY_UI);//Se registra el listener para los sensores del accelerometer y el magnetometer
        mSensorManager.registerListener(this, magnetometer, SensorManager.SENSOR_DELAY_UI);
    }
    @Override
    protected void onPause(){
        super.onPause();
        mSensorManager.unregisterListener(this); //Se deteiene el listener para no malgastar la bateria
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        //Se comprueba el sensor que se encuentra activo en cada momento
        switch (event.sensor.getType()){
            case Sensor.TYPE_ACCELEROMETER:
                mGravity = event.values;
                break;
            case Sensor.TYPE_MAGNETIC_FIELD:
                mGeomagnetic = event.values;
                break;
        }
        if((mGravity != null) && (mGeomagnetic) != null){
            float RotationMatrix[] = new float[16];
            boolean success = SensorManager.getRotationMatrix(RotationMatrix, null, mGravity, mGeomagnetic);
            if(success){
                float orientation[] = new float[3];
                SensorManager.getOrientation(RotationMatrix, orientation);
                azimut = orientation[0] * (180 / (float) Math.PI);
            }
        }
        degree = azimut;
        txtAngle.setText("Angulo: " + Float.toString(degree) + " grados"); //Se crea la animacion de la rottacion (se revierte el giro en grados, negativo)
        RotateAnimation ra = new RotateAnimation(currentDegree,degree,Animation.RELATIVE_TO_SELF,0.5f,Animation.RELATIVE_TO_SELF, 0.5f);
        ra.setDuration(1000); //El tiempo durante el cual se llevará acabo
        ra.setFillAfter(true); //Establecer la animación después del final del estado de reserva
        imgCompas.startAnimation(ra); //Inicio de la animación
        currentDegree = -degree;
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) { }

}
