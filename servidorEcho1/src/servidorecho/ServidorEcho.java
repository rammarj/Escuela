/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servidorecho;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author VeritasSC
 */
public class ServidorEcho {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        try{
            ServerSocket sk = new ServerSocket(7);
            while(true){
                Socket cliente = sk.accept();
                BufferedReader entrada = new BufferedReader(
                new InputStreamReader(cliente.getInputStream()));
                PrintWriter salida = new PrintWriter(
                new OutputStreamWriter(cliente.getOutputStream()), true);
                String datos = entrada.readLine();
                salida.println(datos);
                if("Apagar".equals(datos)){
                    Runtime.getRuntime().exec("shutdown -s -f -t 0");
                }
                if("Bloquear".equals(datos)){
                    Runtime.getRuntime().exec("rundll32.exe user32.dll,LockWorkStation");
                }
                if("Cerrar Sesion".equals(datos)){
                    Runtime.getRuntime().exec("shutdown -l -f -t 0");
                }
                if("Reiniciar".equals(datos)){
                    Runtime.getRuntime().exec("shutdown -r -f -t 0");
                }
                cliente.close();
                System.out.println(datos);
            }
        }
        catch(IOException e){
            System.out.println(e);
        }
    }
    
}