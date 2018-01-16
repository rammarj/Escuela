package mondragon.com.caracteresepeciales;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import org.ksoap2.SoapEnvelope;
import org.ksoap2.serialization.SoapObject;
import org.ksoap2.serialization.SoapSerializationEnvelope;
import org.ksoap2.transport.HttpTransportSE;

public class MainActivity extends AppCompatActivity {

    private static final String SOAP_ACTION = "http://mondragon.com/caracteres/verificarRequest";
    private static final String OPERATION_NAME = "verificar";
    private static final String WSDL_TARGET_NAMESPACE = "http://mondragon.com/";
    private static final String SOAP_ADDRESS = "http://localhost:8080/CaracteresEspeciales/carateres?wsdl";
    private EditText txtValidar;
    private TextView txtvRes;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txtValidar = (EditText) findViewById(R.id.txtValidar);
        txtvRes = (TextView) findViewById(R.id.txtvResultado);
    }

    public void validarClick(View view) {
        SoapObject request = new SoapObject(WSDL_TARGET_NAMESPACE,
                OPERATION_NAME);
        request.addProperty("cadena", txtValidar.getText().toString());
        SoapSerializationEnvelope envelope = new SoapSerializationEnvelope(
                SoapEnvelope.VER11);
        envelope.dotNet = true;
        envelope.setOutputSoapObject(request);
        HttpTransportSE httpTransport = new HttpTransportSE(SOAP_ADDRESS);
        try {
            httpTransport.call(SOAP_ACTION, envelope);
            Object response = envelope.getResponse();
            txtvRes.setText(response.toString()+"\n");
        }
        catch (Exception exception) {
            txtvRes.setText(exception.getMessage() +"\n");
        }
    }
}
