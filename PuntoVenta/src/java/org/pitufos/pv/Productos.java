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
import org.pitufos.pv.logica.Categoria;
import org.pitufos.pv.logica.Producto;
import org.pitufos.pv.logica.Proveedor;
import org.pitufos.pv.logica.Util;

/**
 *
 * @author RAMMARJ
 */
@WebService(serviceName = "Productos")
public class Productos {

    /**
     * Web service operation
     */
    @WebMethod(operationName = "eliminar")
    public String eliminar(@WebParam(name = "id") final int id) {
        try {
            //TODO write your implementation code here:
            boolean delete = Producto.delete(id);
            if (!delete) throw new Exception("El producto no se ha podido eliminar.");
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
                    +new Gson().toJson(Producto.get(id))+"}";
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
            return "{\"error\":false,\"mensage\":\"Datos obtenidos exitosamente.\",\"datos\":"
                    +new Gson().toJson(Producto.get(inicio, fin))+"}";
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
            int count = Producto.count();
            return "{\"error\":false,\"mensage\":\"Datos obtenidos exitosamente.\",\"datos\":"
                    +new Gson().toJson(Producto.get(0, count))+"}";
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
            int count = Producto.count();
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
            int idCategoria = Util.getElemento(objeto, "id_categoria", "entero").getAsInt();
            int idProveedor = Util.getElemento(objeto, "id_proveedor", "entero").getAsInt();
            String nombre = Util.getElemento(objeto, "nombre", "string").getAsString();
            float precio = Util.getElemento(objeto, "precio", "entero").getAsFloat();
            String descripcion = Util.getElemento(objeto, "descripcion", "string").getAsString();
            int existencia = Util.getElemento(objeto, "existencia", "entero").getAsInt();
            
            Producto producto = new Producto();
            producto.setCategoria(Categoria.get(idCategoria));
            producto.setProveedor(Proveedor.get(idProveedor));
            producto.setNombre(nombre);
            producto.setPrecio(precio);
            producto.setDescripcion(descripcion);
            producto.setExistencia(existencia);
            
            if(producto.save())
                return Util.mensajeJson(false, "El producto fué creado exitosamente");
            return Util.mensajeJson(true, "Ocurrió un error al guardar los datos.");
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }

}
