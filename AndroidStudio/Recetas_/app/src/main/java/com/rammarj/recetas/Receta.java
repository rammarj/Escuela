package com.rammarj.recetas;

import android.graphics.drawable.Drawable;

import java.util.Date;
import java.util.LinkedList;

/**
 * Created by RAMMARJ on 08/04/2017.
 */
public class Receta {
    private String url;
    private String nombre;
    private Drawable imagen;
    private String urlImagen;
    private LinkedList<String> ingredientes;
    private float calorias;
    private Date fecha;

    /**
     * Metodos usados solo para saber cuando se agrego al calendario //no usado en busquedas (BuscarFragment)
     * */
    //////////////////////////////////
    public Date getFecha() {
        return fecha;
    }
    public void setFecha(Date fecha) {
        this.fecha = fecha;
    }
    /////////////////////////////////
    /////////////////////////////////
    public LinkedList<String> getIngredientes() {
        return ingredientes;
    }

    public String getUrlImagen() {
        return urlImagen;
    }

    public void setUrlImagen(String urlImagen) {
        this.urlImagen = urlImagen;
    }

    public void setIngredientes(LinkedList<String> ingredientes) {
        this.ingredientes = ingredientes;
    }

    public String getUrl() {
        return url;
    }

    public void setUrl(String url) {
        this.url = url;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public Drawable getImagen() {
        return imagen;
    }

    public void setImagen(Drawable imagen) {
        this.imagen = imagen;
    }

    public float getCalorias() {
        return calorias;
    }

    public void setCalorias(float calorias) {
        this.calorias = calorias;
    }


}
