package com.rammarj.recetas;

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

    private static String appId = "970385af";
    private static String appKey = "509ffa3ddb9e74bd9ef6d518853b84b6"; //propositos test
    private static String baseUrl = "http://test-es.edamam.com/";
    private static String busquedaAPI = "search";

    private static JSONObject hacerPeticion(String api, String params) throws Exception {
        URL url = new URL(baseUrl+api+"?app_id="+appId+"&app_key="+appKey+"&"+params);
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

    public static LinkedList<Receta> buscar(String buscar) throws Exception{
        JSONObject jsonObject = hacerPeticion(busquedaAPI, "q="+buscar);
        final LinkedList<Receta> recetas = new LinkedList<>();
        JSONArray hits = jsonObject.getJSONArray("hits");
        for (int i=0;i<hits.length();i++){
            final JSONObject objReceta = hits.getJSONObject(i).getJSONObject("recipe");
            Drawable thumb_d = null;
            String image = objReceta.getString("image");
            try { thumb_d = Util.cargarImagen(image); }catch (Exception ex){ }
            JSONArray ingredientLines = objReceta.getJSONArray("ingredientLines");
            LinkedList<String> ingredientes = new LinkedList<>();
            for (int j=0; j<ingredientLines.length();j++)
                ingredientes.add(ingredientLines.getString(j));

            Receta receta = new Receta();
            receta.setUrlImagen(image);
            receta.setIngredientes(ingredientes);
            receta.setNombre(objReceta.getString("label"));
            receta.setImagen(thumb_d);
            receta.setUrl(objReceta.getString("url"));
            receta.setCalorias((float) objReceta.getDouble("calories"));
            recetas.add(receta);
        }
        return recetas;
    }

}
