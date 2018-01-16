package org.pitufos.pv;

import com.google.gson.Gson;
import javax.jws.WebService;
import javax.jws.WebMethod;
import javax.jws.WebParam;
import org.pitufos.pv.logica.Categoria;
import org.pitufos.pv.logica.Util;

/**
 *
 * @author RAMMARJ
 */
@WebService(serviceName = "Categorias")
public class Categorias {

    /**
     * Web service operation
     */
    @WebMethod(operationName = "agregar")
    public String agregar(@WebParam(name = "nombre") final String nombre) {
        try {
            Categoria categoria = new Categoria();
            categoria.setNombre(nombre);
            boolean save = categoria.save();
            return Util.mensajeJson(!save, (save ? "Los datos han sido guardados correctamente"
                    : "El registro no se ha podido guardar."));
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "eliminar")
    public String eliminar(@WebParam(name = "id") final int id) {
        try {
            //TODO write your implementation code here:
            boolean delete = Categoria.delete(id);
            return Util.mensajeJson(!delete, (delete ? "Datos eliminados" : "El elemento no se ha podido eliminar."));
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "actualizar")
    public String actualizar(@WebParam(name = "nombre") final String nombre, @WebParam(name = "id") final int id) {
        try {
            //TODO write your implementation code here:
            Categoria categoria = Categoria.get(id);
            categoria.setNombre(nombre);
            boolean save = categoria.save();
            return Util.mensajeJson(!save, (save ? "Los datos han sido guardados correctamente"
                    : "El registro no se ha podido guardar."));
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
            Gson gson = new Gson();
            return "{\"error\":false,\"mensage\":\"Datos obtenidos exitosamente.\",\"datos\":"
                    + gson.toJson(Categoria.get(inicio, fin)) + "}";
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "obtenerTodo")
    public String obtenerTodo() {
        //TODO write your implementation code here:
        try {
            //TODO write your implementation code here:
            int count = Categoria.count();
            Gson gson = new Gson();
            return "{\"error\":false,\"mensage\":\"Datos obtenidos exitosamente.\",\"datos\":"
                    + gson.toJson(Categoria.get(0, count)) + "}";
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
            Categoria get = Categoria.get(id);
            return "{\"error\":false,\"mensaje\":\"Datos obtenidos correctamente.\",\"datos\":" + new Gson().toJson(get) + "}";
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
            int count = Categoria.count();
            return "{\"error\":false,\"mensaje\":\"Datos obtenidos correctamente.\",\"cantidad\":" + count + "}";
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }
}
