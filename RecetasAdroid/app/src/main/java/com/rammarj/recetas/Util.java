package com.rammarj.recetas;

import android.graphics.drawable.Drawable;

import java.net.URL;
import java.util.LinkedList;

/**
 * Created by RAMMARJ on 10/04/2017.
 */

public class Util {

    public static Drawable cargarImagen(String url) throws Exception {
        URL thumb_u = new URL(url);
        return Drawable.createFromStream(thumb_u.openStream(), "src");
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
