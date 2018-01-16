package org.pitufos.pv.logica;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Date;
import java.util.LinkedList;

/**
 *
 * @author RAMMARJ
 */
public class Venta extends EntidadMySQL {

    private static String tabla = "venta";

    private int idVentas;
    private Producto producto;
    private int cantidad;
    private float precioUnitario;

    public int getIdVentas() {
        return idVentas;
    }

    public void setIdVentas(int idVentas) {
        this.idVentas = idVentas;
    }

    public Producto getProducto() {
        return producto;
    }

    public void setProducto(Producto producto) {
        this.producto = producto;
    }

    public int getCantidad() {
        return cantidad;
    }

    public void setCantidad(int cantidad) {
        this.cantidad = cantidad;
    }

    public float getPrecioUnitario() {
        return precioUnitario;
    }

    public void setPrecioUnitario(float precioUnitario) {
        this.precioUnitario = precioUnitario;
    }
    
    /**
     * Obtiene el identificador del registro
     */
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    /**
     * Obtiene el numero de registros que existen en la tabla
     *
     * @return numero de registros en la tabla
     */
    public static int count() throws Exception {
        ResultSet queryResults = connection.createStatement().executeQuery("SELECT COUNT(*) FROM "+tabla);
        queryResults.next();
        return queryResults.getInt(1);
    }

    public static LinkedList<Venta> find(String s, int limit) throws Exception {
        ResultSet find = EntidadMySQL.find(tabla, s, limit);
        return convertirLista(find);
    }

    public static LinkedList<Venta> get(int start, int end) throws Exception {
        ResultSet get = EntidadMySQL.get(tabla, start, end);
        return convertirLista(get);
    }

    private static LinkedList<Venta> convertirLista(ResultSet find) throws Exception{
        LinkedList<Venta> ventas = new LinkedList<Venta>();
        while (find.next()) {
            Venta venta = new Venta();
            venta.setId(find.getInt("id"));
            venta.setIdVentas(find.getInt("id_ventas"));
            venta.setProducto(Producto.get(find.getInt("id_producto")));
            venta.setCantidad(find.getInt("cantidad_producto"));
            venta.setPrecioUnitario(find.getFloat("precio_unitario"));
            ventas.add(venta);
        }
        return ventas;
    }
    
    public static Venta get(int id) throws Exception {
        ResultSet get = EntidadMySQL.get(tabla, id);
        LinkedList<Venta> convertirLista = convertirLista(get);
        if (convertirLista.size()==0) {
            throw new Exception("El elemento que está tratando de obtener no existe.");
        }
        return convertirLista.getFirst();
    }

    @Override
    public boolean save() throws Exception {
        if (id == 0) {
            PreparedStatement p = getConnection().prepareStatement("INSERT INTO "+tabla+" VALUES(NULL, ?,?,?,?)");
            p.setInt(1, this.idVentas);
            p.setInt(2, this.producto.getId());
            p.setInt(3, this.cantidad);
            p.setFloat(4, this.precioUnitario);
            return p.executeUpdate()>0;
        }else{
//            PreparedStatement p = getConnection().prepareStatement("UPDATE "+tabla+" SET fecha=?, nota=? WHERE id="+this.id);
//            p.setDate(1,this.nombre);
//            return !p.execute();
            throw new Exception("Solo se pueden crear ventas, no actualizar.");
        }
    }

//    public static int delete(int id) throws Exception {
//        return EntidadMySQL.delete(tabla, id);
//    }    

    @Override
    public boolean delete() throws Exception {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

}
