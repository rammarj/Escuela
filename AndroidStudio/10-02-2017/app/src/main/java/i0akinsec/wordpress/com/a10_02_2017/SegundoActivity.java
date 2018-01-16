package i0akinsec.wordpress.com.a10_02_2017;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class SegundoActivity extends AppCompatActivity {

    private TextView lblNombre;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_segundo);
        Bundle extras = getIntent().getExtras();
        lblNombre = (TextView) findViewById(R.id.lblNombre);
        lblNombre.setText("Hola " + extras.getString("nombre") + "!");
    }
}
