
package org.pitufos.pv;

import com.google.gson.Gson;
import java.util.LinkedList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.jws.WebService;
import javax.jws.WebMethod;
import javax.jws.WebParam;
import org.pitufos.pv.logica.Rol;
import org.pitufos.pv.logica.Util;

/**
 *
 * @author RAMMARJ
 */
@WebService(serviceName = "Roles")
public class Roles {


    /**
     * Web service operation
     */
    @WebMethod(operationName = "obtener")
    public String obtener(@WebParam(name = "id") final int id) {
        try {
            //TODO write your implementation code here:
            Rol rol = Rol.get(id);            
            return "{\"error\":false,\"mensaje\":\"Datos obtenidos exitosamente.\",\"datos\":"+new Gson().toJson(rol)+"}";
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
            int count = Rol.count();
            LinkedList<Rol> roles = Rol.get(0, count);
            return "{\"error\":false,\"mensaje\":\"Datos obtenidos exitosamente.\",\"datos\":"+new Gson().toJson(roles)+"}";            
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }
}
