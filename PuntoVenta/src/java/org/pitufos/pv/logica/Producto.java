package org.pitufos.pv.logica;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.LinkedList;

/**
 *
 * @author RAMMARJ
 */
public class Producto extends EntidadMySQL {

    private Categoria categoria;
    private Proveedor proveedor;
    private String nombre;
    private float precio;
    private String descripcion;
    private int existencia;
    private static String tabla = "productos";

    public Categoria getCategoria() {
        return categoria;
    }

    public void setCategoria(Categoria categoria) {
        this.categoria = categoria;
    }

    public Proveedor getProveedor() {
        return proveedor;
    }

    public void setProveedor(Proveedor proveedor) {
        this.proveedor = proveedor;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public float getPrecio() {
        return precio;
    }

    public void setPrecio(float precio) {
        this.precio = precio;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    public int getExistencia() {
        return existencia;
    }

    public void setExistencia(int existencia) {
        this.existencia = existencia;
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

    public static LinkedList<Producto> find(String s, int limit) throws Exception {
        ResultSet find = EntidadMySQL.find(tabla, s, limit);
        return convertirLista(find);
    }

    public static LinkedList<Producto> get(int start, int end) throws Exception {
        ResultSet get = EntidadMySQL.get(tabla, start, end);
        return convertirLista(get);
    }

    private static LinkedList<Producto> convertirLista(ResultSet find) throws Exception {
        LinkedList<Producto> productos = new LinkedList<Producto>();
        while (find.next()) {
            Producto producto = new Producto();
            producto.setId(find.getInt("id"));
            producto.setCategoria(Categoria.get(find.getInt("id_categoria")));
            producto.setProveedor(Proveedor.get(find.getInt("id_provedor")));
            producto.setNombre(find.getString("nombre"));
            producto.setPrecio(find.getFloat("precio"));
            producto.setDescripcion(find.getString("descripcion"));
            producto.setExistencia(find.getInt("existencia"));
            productos.add(producto);
        }
        return productos;
    }

    public static Producto get(int id) throws Exception {
        ResultSet get = EntidadMySQL.get(tabla, id);
        LinkedList<Producto> convertirLista = convertirLista(get);
        if (convertirLista.size() == 0) {
            throw new Exception("El elemento que está tratando de obtener no existe.");
        }
        return convertirLista.getFirst();
    }

    @Override
    public boolean save() throws Exception {
        PreparedStatement p = null;
        if (id == 0) {
            p = getConnection().prepareStatement("INSERT INTO "+tabla+" VALUES(NULL, ?,?,?,?,?,?)");
        } else {
            p = getConnection().prepareStatement("UPDATE "+tabla+" SET id_categoria=?,"
                    + " id_provedor=?, nombre=?, precio=?, descripcion=?, existencia=? WHERE id=" + this.id);
        }
        p.setInt(1, this.getCategoria().getId());
        p.setInt(2, this.getProveedor().getId());
        p.setString(3, this.nombre);
        p.setFloat(4, this.precio);
        p.setString(5, this.descripcion);
        p.setInt(6, this.existencia);
        return p.executeUpdate() > 0;
    }

    public static boolean delete(int id) throws Exception {
        return EntidadMySQL.delete(tabla, id);
    }

    @Override
    public boolean delete() throws Exception {
        return Producto.delete(id);
    }

}
