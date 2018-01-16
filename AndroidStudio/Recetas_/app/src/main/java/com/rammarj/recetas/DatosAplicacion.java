package com.rammarj.recetas;

/**
 * Created by RAMMARJ on 24/04/2017.
 */

public class DatosAplicacion {
    private static String usuario;

    public static String getUsuario() {
        return usuario;
    }

    public static void setUsuario(String usuario) {
        DatosAplicacion.usuario = usuario;
    }
}
