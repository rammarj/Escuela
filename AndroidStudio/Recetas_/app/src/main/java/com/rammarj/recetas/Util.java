package com.rammarj.recetas;

import android.content.Context;
import android.graphics.drawable.Drawable;

import org.json.JSONException;
import org.json.JSONObject;

import java.net.URL;
import java.util.LinkedList;
import java.util.List;

/**
 * Created by RAMMARJ on 10/04/2017.
 */

public class Util {

    public static Drawable cargarImagen(String url) throws Exception {
        URL thumb_u = new URL(url);
        return Drawable.createFromStream(thumb_u.openStream(), "src");
    }

    public static List<Receta> getRecetasDesdeStrings(List<String> re, Context contexto) throws Exception {
        LinkedList<Receta> recetas = new LinkedList<>();
        for(String r : re){
            JSONObject jsonObject = new JSONObject(r);
            String url = jsonObject.getString(contexto.getString(R.string.bundle_extra_url));
            String url_imagen = jsonObject.getString(contexto.getString(R.string.bundle_extra_imagen));
            //String ingredientes = jsonObject.getString(contexto.getString(R.string.bundle_extra_ingredientes));
            float calorias = (float) jsonObject.getDouble(contexto.getString(R.string.bundle_extra_calorias));
            String nombreReceta = jsonObject.getString(contexto.getString(R.string.bundle_extra_receta));

            Receta receta = new Receta();
            receta.setNombre(nombreReceta);
            receta.setUrlImagen(url_imagen);
            //receta.setIngredientes();
            recetas.add(receta);
        }
        return recetas;
    }

    public static String recetasString(LinkedList<String> ingredientes){
        StringBuilder builder = new StringBuilder();
        for (String ingrediente: ingredientes)
            builder.append(ingrediente).append('\n');

        return builder.toString();
    }

    public static LinkedList<String> stringLista(String s){
        String[] split = s.split("\n");
        LinkedList<String> strings = new LinkedList<>();
        for (String receta: split)
            if (!receta.trim().equals(""))
                strings.add(receta.trim());
        return strings;
    }

}
