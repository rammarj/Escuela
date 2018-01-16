package i0akinsec.wordpress.com.examenparcial2;

/**
 * Created by RAMMARJ on 17/03/2017.
 */

public class Ponente {
    String nombre;
    String correo;
    String temaPonencia;
    String universidadOrigen;

    public Ponente(){
        this.nombre = "";
        this.correo = "";
        this.temaPonencia = "";
        this.universidadOrigen = "";
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }

    public String getTemaPonencia() {
        return temaPonencia;
    }

    public void setTemaPonencia(String temaPonencia) {
        this.temaPonencia = temaPonencia;
    }

    public String getUniversidadOrigen() {
        return universidadOrigen;
    }

    public void setUniversidadOrigen(String universidadOrigen) {
        this.universidadOrigen = universidadOrigen;
    }

    @Override
    public String toString() {
        return "Nombre: " + this.getNombre() + "\nCorreo: " + this.getCorreo() + "\nTema: " + this.getTemaPonencia()
                + "\nUniversidad origen: " + this.getUniversidadOrigen();
    }
}
