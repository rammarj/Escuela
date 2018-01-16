package com.example.veritassc.servidorecho;

import android.os.StrictMode;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

public class MainActivity extends AppCompatActivity {

    private TextView output;
    private EditText IP;
    private EditText message;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        output = (TextView)findViewById(R.id.output);
        IP = (EditText)findViewById(R.id.IP);
        message = (EditText)findViewById(R.id.Message);
        StrictMode.setThreadPolicy(new StrictMode.ThreadPolicy.Builder().permitNetwork().build());
    }

    public void ejecutarCliente(View view){
        String ip = IP.getText().toString();
        int puerto = 7;
        String Message = message.getText().toString();
        log("Socket " + ip + " " + puerto);
        try{
            Socket socket = new Socket(ip, puerto);
            BufferedReader entrada = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter salida = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()), true);
            log("Enviado acción: " + Message);
            salida.println(Message);
            log("Acción: " + entrada.readLine() + "Realizada");
            socket.close();
        }
        catch(Exception e){
            log("Error: " + e.toString());
        }
    }

    private void log(String string){
        output.append(string + "\n");
    }
}
