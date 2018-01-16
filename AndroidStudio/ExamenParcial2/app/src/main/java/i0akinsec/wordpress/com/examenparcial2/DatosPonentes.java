package i0akinsec.wordpress.com.examenparcial2;

import java.util.LinkedList;

/**
 * Created by RAMMARJ on 17/03/2017.
 */

public class DatosPonentes {

    private static LinkedList<Ponente> ponentes = new LinkedList<>();

    private DatosPonentes(){ }

    public static LinkedList<Ponente> getPonentesRegistrados(){
        return ponentes;
    }

    public static void registrarPonente(Ponente p){
        ponentes.add(p);
    }

}
