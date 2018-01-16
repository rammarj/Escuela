
package org.pitufos.pv;

import com.google.gson.Gson;
import com.google.gson.JsonObject;
import javax.jws.WebService;
import javax.jws.WebMethod;
import javax.jws.WebParam;
import org.pitufos.pv.logica.Rol;
import org.pitufos.pv.logica.Usuario;
import org.pitufos.pv.logica.Util;

/**
 *
 * @author RAMMARJ
 */
@WebService(serviceName = "Usuarios")
public class Usuarios {

    /**
     * Web service operation
     */
    @WebMethod(operationName = "eliminar")
    public String eliminar(@WebParam(name = "id") final int id) {
        try {
            //TODO write your implementation code here:
            boolean delete = Usuario.delete(id);
            if (!delete) throw new Exception("El usuario no se ha podido eliminar.");
            return "{\"error\":false,\"mensage\":\"Datos eliminados correctamente.\"}";
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "obtener")
    public String obtener(@WebParam(name = "id") final int id) {
        try {
            //TODO write your implementation code here:
            return "{\"error\":false,\"mensage\":\"Datos obtenidos exitosamente.\",\"datos\":"
                    +new Gson().toJson(Usuario.get(id))+"}";
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "obtenerIntervalo")
    public String obtenerIntervalo(@WebParam(name = "inicio") final int inicio, @WebParam(name = "fin") final int fin) {
        try {
            //TODO write your implementation code here:
            int count = Usuario.count();
            return "{\"error\":false,\"mensage\":\"Datos obtenidos exitosamente.\",\"datos\":"
                    +new Gson().toJson(Usuario.get(inicio, fin))+"}";
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "obtenerTodo")
    public String obtenerTodo() {
        try {
            //TODO write your implementation code here:
            int count = Usuario.count();
            return "{\"error\":false,\"mensage\":\"Datos obtenidos exitosamente.\",\"datos\":"
                    +new Gson().toJson(Usuario.get(0, count))+"}";
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "contar")
    public String contar() {
        try {
            //TODO write your implementation code here:
            int count = Usuario.count();
            return "{\"error\":false,\"mensaje\":\"Datos obtenidos correctamente.\",\"cantidad\":"+count+"}";
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "agregar")
    public String agrregar(@WebParam(name = "datos") String datos) {
        try {
            //TODO write your implementation code here:
            JsonObject objeto = Util.getObjeto(datos);
            String nombre = Util.getElemento(objeto,"nombre","string").getAsString();
            int rol = Util.getElemento(objeto,"id_rol","entero").getAsInt();
            String apPaterno = Util.getElemento(objeto,"ap_paterno","string").getAsString();
            String apMaterno = Util.getElemento(objeto,"ap_materno","string").getAsString();
            String sexo = Util.getElemento(objeto,"sexo","string").getAsString();
            String telefono = Util.getElemento(objeto,"telefono","string").getAsString();
            String correo = Util.getElemento(objeto,"ap_paterno","string").getAsString();
            String usuario = Util.getElemento(objeto,"usuario","string").getAsString();
            String password = Util.getElemento(objeto,"password","string").getAsString();
            Usuario usuario1 = new Usuario();
            usuario1.setRol(Rol.get(rol));
            usuario1.setNombre(nombre);
            usuario1.setApellidoPaterno(apPaterno);
            usuario1.setApellidoMaterno(apMaterno);
            usuario1.setSexo(sexo);
            usuario1.setTelefono(telefono);
            usuario1.setCorreo(correo);
            usuario1.setUsuario(usuario);
            if(usuario1.save())
                usuario1.cambiarPassword(password);
            return Util.mensajeJson(false, "El usuario fué creado exitosamente");
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }

}
