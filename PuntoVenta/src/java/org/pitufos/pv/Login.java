/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package org.pitufos.pv;

import com.google.gson.Gson;
import javax.jws.WebService;
import javax.jws.WebMethod;
import javax.jws.WebParam;
import org.pitufos.pv.logica.Usuario;
import org.pitufos.pv.logica.Util;

/**
 *
 * @author RAMMARJ
 */
@WebService(serviceName = "Login")
public class Login {


    /**
     * Web service operation
     */
    @WebMethod(operationName = "login")
    public String login(@WebParam(name = "usuario") final String usuario, @WebParam(name = "password") final String password) {
        try {
            //TODO write your implementation code here:
            Usuario login = Usuario.login(usuario, password);
            String token = login.regenerarToken();
            return "{\"error\":false,\"mensaje\":\"Autenticación exitosa.\",\"token\":\""+token
                    +"\",\"usuario\":"+new Gson().toJson(login)+"}";
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }
}
