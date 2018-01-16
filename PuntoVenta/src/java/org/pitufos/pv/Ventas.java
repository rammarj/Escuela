/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package org.pitufos.pv;

import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import java.util.Date;
import javax.jws.WebService;
import javax.jws.WebMethod;
import javax.jws.WebParam;
import org.pitufos.pv.logica.Producto;
import org.pitufos.pv.logica.Util;
import org.pitufos.pv.logica.Venta;

/**
 *
 * @author RAMMARJ
 */
@WebService(serviceName = "Ventas")
public class Ventas {

    /**
     * Web service operation
     */
    @WebMethod(operationName = "realizarVenta")
    public String realizarVenta(@WebParam(name = "productos_json") final String productos_json) {
        try {
            //TODO write your implementation code here:
            JsonObject parse = new JsonParser().parse(productos_json).getAsJsonObject();
            String nota = parse.get("nota").getAsString();
            JsonArray asJsonArray = parse.get("productos").getAsJsonArray();

            org.pitufos.pv.logica.Ventas ventas = new org.pitufos.pv.logica.Ventas();
            ventas.setNota(productos_json);
            Date date = new Date(System.currentTimeMillis());
            ventas.setFecha(date);
            ventas.setNota(nota);
            boolean save = ventas.save();
            int ultimoInsertID = ventas.getUltimoInsertID();
            if (save) {
                for (int i = 0; i < asJsonArray.size(); i++) {
                    JsonObject objeto = asJsonArray.get(i).getAsJsonObject();

                    int idProducto = Util.getElemento(objeto, "id_producto", "entero").getAsInt();
                    int cantidad = Util.getElemento(objeto, "cantidad", "string").getAsInt();
                    float precio = Util.getElemento(objeto, "precio_unitario", "entero").getAsFloat();
                    //String password = Util.getElemento(objeto,"password","string").getAsString();
                    Venta venta = new Venta();
                    venta.setIdVentas(ultimoInsertID);
                    venta.setCantidad(cantidad);
                    venta.setProducto(Producto.get(idProducto));
                    venta.setPrecioUnitario(precio);
                    if (!venta.save()) {
                        return Util.mensajeJson(true, "Error al guardar un dato.");
                    }
                }
                return Util.mensajeJson(false, "Datos guardados.");
            }
            return Util.mensajeJson(true, "Ocurrió un error al crear la venta.");
        } catch (Exception ex) {
            return Util.mensajeJson(true, ex.getMessage());
        }
    }
}
