/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servidorecho;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

/**
 *
 * @author VeritasSC
 */
public class Prueba {
     public static void main(String[] args) throws IOException {
        // TODO code application logic here
        Runtime.getRuntime().exec("rundll32.exe user32.dll,LockWorkStation");
     }
}
