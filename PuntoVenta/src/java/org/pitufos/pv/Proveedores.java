/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package org.pitufos.pv;

import com.google.gson.Gson;
import com.google.gson.JsonObject;
import javax.jws.WebService;
import javax.jws.WebMethod;
import javax.jws.WebParam;
import org.pitufos.pv.logica.Proveedor;
import org.pitufos.pv.logica.Usuario;
import org.pitufos.pv.logica.Util;

/**
 *
 * @author RAMMARJ
 */
@WebService(serviceName = "Proovedores")
public class Proveedores {

    /**
     * Web service operation
     */
    @WebMethod(operationName = "eliminar")
    public String eliminar(@WebParam(name = "id") final int id) {        
        try {
            /*Usuario usuarioPorToken = Usuario.getUsuarioPorToken(token);
            if (usuarioPorToken.getRol().getId() != 1)
                throw new Exception("Usted no tiene permisos para realizar esta acción.");
            */
            //TODO write your implementation code here:
            boolean delete = Proveedor.delete(id);
            if (!delete) throw new Exception("El proveedor no se ha podido eliminar.");
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
            /*
            Usuario usuarioPorToken = Usuario.getUsuarioPorToken(token);
            if (usuarioPorToken.getRol().getId() != 1)
                throw new Exception("Usted no tiene permisos para realizar esta acción.");
            */
            //TODO write your implementation code here:
            return "{\"error\":false,\"mensage\":\"Datos obtenidos exitosamente.\",\"datos\":"
                    +new Gson().toJson(Proveedor.get(id))+"}";
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
            return "{\"error\":false,\"mensage\":\"Datos obtenidos exitosamente.\",\"datos\":"
                    +new Gson().toJson(Proveedor.get(inicio, fin))+"}";
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
            int count = Proveedor.count();
            return "{\"error\":false,\"mensage\":\"Datos obtenidos exitosamente.\",\"datos\":"
                    +new Gson().toJson(Proveedor.get(0, count))+"}";
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "contar")
    public String contar(@WebParam(name = "token") final String token) {
        try {
            Usuario usuarioPorToken = Usuario.getUsuarioPorToken(token);
            if (usuarioPorToken.getRol().getId() != 1)
                throw new Exception("Usted no tiene permisos para realizar esta acción.");
            
            //TODO write your implementation code here:
            int count = Proveedor.count();
            return "{\"error\":false,\"mensaje\":\"Datos obtenidos correctamente.\",\"cantidad\":"+count+"}";
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "agregar")
    public String agrregar(@WebParam(name = "datos") String datos,@WebParam(name = "token") final String token) {
        try {
            Usuario usuarioPorToken = Usuario.getUsuarioPorToken(token);
            if (usuarioPorToken.getRol().getId() != 1)
                throw new Exception("Usted no tiene permisos para realizar esta acción.");
            //TODO write your implementation code here:
            JsonObject objeto = Util.getObjeto(datos);
            String nombre = Util.getElemento(objeto,"nombre","string").getAsString();
            String telefono = Util.getElemento(objeto,"telefono","string").getAsString();
            String correo = Util.getElemento(objeto,"correo","string").getAsString();
            String direccion = Util.getElemento(objeto,"direccion","string").getAsString();
            //String password = Util.getElemento(objeto,"password","string").getAsString();
            Proveedor proveedor = new Proveedor();
            proveedor.setNombre(nombre);
            proveedor.setTelefono(telefono);
            proveedor.setCorreo(correo);
            proveedor.setDireccion(direccion);
            if(proveedor.save())
                return Util.mensajeJson(false, "El proveedor fué creado exitosamente");
            return Util.mensajeJson(true, "Ocurrió un error al guardar los datos.");
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }

}
