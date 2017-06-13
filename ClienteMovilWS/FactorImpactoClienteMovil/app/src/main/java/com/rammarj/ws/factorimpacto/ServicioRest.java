package com.rammarj.ws.factorimpacto;

import android.graphics.drawable.Drawable;

import org.json.JSONArray;
import org.json.JSONObject;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.LinkedList;

/**
 * Created by RAMMARJ on 27/01/2017.
 */

public class ServicioRest{

    private static final String apiHost = "http://localhost:8000/factor_impact";

    private static JSONObject hacerPeticion(String baseUrl) throws Exception {
        URL url = new URL(baseUrl);
        HttpURLConnection conexion = (HttpURLConnection) url.openConnection();
        final int responseCode = conexion.getResponseCode();
        final StringBuilder respuesta = new StringBuilder();
        if (responseCode == HttpURLConnection.HTTP_OK){
            BufferedInputStream buffer = new BufferedInputStream(conexion.getInputStream());
            BufferedReader reader = new BufferedReader(new InputStreamReader(buffer));
            String linea;
            while ((linea = reader.readLine()) != null){
                respuesta.append(linea);
            }
        }
        return new JSONObject(respuesta.toString());
    }

    public static LinkedList<ItemLista> getItems() throws Exception{
        JSONObject jsonObject = hacerPeticion(apiHost);
        LinkedList<ItemLista> items = new LinkedList<>();
        JSONArray data = jsonObject.getJSONArray("data");
        for (int i = 0; i < data.length(); i++){
            JSONObject obj = data.getJSONObject(i);
            String titulo = obj.getString("abbreviated");
            String subtitulo = obj.getString("issn");

            ItemLista itemLista = new ItemLista();
            itemLista.setTitulo(titulo);
            itemLista.setSubtitulo(subtitulo);
            items.add(itemLista);
        }
        return items;
    }

}
