package com.rammarj.websecurity;

import com.google.gson.Gson;
import com.google.gson.JsonObject;
import com.google.gson.reflect.TypeToken;
import java.lang.reflect.Type;
import java.util.LinkedList;
import javax.jws.WebService;
import javax.jws.WebMethod;
import javax.jws.WebParam;
import javax.xml.ws.RequestWrapper;
import javax.xml.ws.ResponseWrapper;

@WebService(serviceName = "FactorImpactWS")
public class FactorImpactWS {

    @WebMethod(operationName = "add")
    public String add(@WebParam(name = "parameter") FactorImpact parameter){
        try {
            parameter.save();
        } catch (Exception ex) {
            return ex.getMessage();
        }
        return "Registro guardado.";
    }

    @WebMethod(operationName = "find")
    public LinkedList<MySQLEntity> find(@WebParam(name = "search") final String search, @WebParam(name = "limit") final int limit) {
        try {
            return new FactorImpact().find(search, limit);
        } catch (Exception ex) { 
            System.out.println(ex);
        }
        return new LinkedList<>();
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "find_1")
    @RequestWrapper(className = "com.find_1")
    @ResponseWrapper(className = "com.find_1Response")
    public LinkedList<MySQLEntity> find(@WebParam(name = "inicio") final int inicio, @WebParam(name = "fin") final int fin) {
        try {
            //TODO write your implementation code here:
            return new FactorImpact().get(inicio, fin);
        } catch (Exception ex) {
            return new LinkedList();
        }
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "delete")
    public String delete(@WebParam(name = "id") final int id) {
        try {
            //TODO write your implementation code here:
            new FactorImpact().delete(id);
            return "Registro eliminado.";
        } catch (Exception ex) {
            return "Ocurrió un error al intentar eliminar el registro.";
        }
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "update")
    public String update(@WebParam(name = "data") final FactorImpact data) {
        try {
            data.update();
            return "Registro actualizado.";
        } catch (Exception ex) {
            return ex.getMessage();
        }
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "find_2")
    @RequestWrapper(className = "com.find_2")
    @ResponseWrapper(className = "com.find_2Response")
    public MySQLEntity find(@WebParam(name = "json") final String json) {
        try {
            Gson gson = new Gson();      
            Type tipo = new TypeToken<JsonObject>(){}.getType();
            return new FactorImpact().find(new Gson().fromJson(json, tipo));
        } catch (Exception ex) {
            return null;
        }
    }

    /**
     * Web service operation
     */
    @WebMethod(operationName = "getCount")
    public Integer getCount() {
        try {
            return new FactorImpact().count();
        } catch (Exception ex) {
            return 0;
        }
    }

}
