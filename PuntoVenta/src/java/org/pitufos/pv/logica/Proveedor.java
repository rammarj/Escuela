package org.pitufos.pv.logica;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.LinkedList;

/**
 *
 * @author RAMMARJ
 */
public class Proveedor extends EntidadMySQL {

    private String nombre;
    private String telefono;
    private String correo;
    private String direccion;
    private static String tabla = "provedores";

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }

    public String getDireccion() {
        return direccion;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

    public Proveedor() throws Exception {
        this.id = 0;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
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

    public static LinkedList<Proveedor> find(String s, int limit) throws Exception {
        ResultSet find = EntidadMySQL.find(tabla, s, limit);
        return convertirLista(find);
    }

    public static LinkedList<Proveedor> get(int start, int end) throws Exception {
        ResultSet get = EntidadMySQL.get(tabla, start, end);
        return convertirLista(get);
    }

    private static LinkedList<Proveedor> convertirLista(ResultSet find) throws Exception {
        LinkedList<Proveedor> provedores = new LinkedList<Proveedor>();
        while (find.next()) {
            Proveedor proveedor = new Proveedor();
            proveedor.setId(find.getInt("id"));
            proveedor.setNombre(find.getString("nombre"));
            proveedor.setTelefono(find.getString("telefono"));
            proveedor.setCorreo(find.getString("correo"));
            proveedor.setDireccion(find.getString("direccion"));
            provedores.add(proveedor);
        }
        return provedores;
    }

    public static Proveedor get(int id) throws Exception {
        ResultSet get = EntidadMySQL.get(tabla, id);
        LinkedList<Proveedor> convertirLista = convertirLista(get);
        if (convertirLista.size() == 0) {
            throw new Exception("El elemento que está tratando de obtener no existe.");
        }
        return convertirLista.getFirst();
    }

    public static Proveedor get(String nombre) throws Exception {
        PreparedStatement p = connection.prepareStatement("SELECT * FROM "+tabla+" WHERE nombre=?");        
        p.setString(1, nombre);
        ResultSet get = p.executeQuery();
        LinkedList<Proveedor> convertirLista = convertirLista(get);
        if (convertirLista.size()==0) {
            throw new Exception("El elemento que está tratando de obtener no existe.");
        }
        return convertirLista.getFirst();
    }

    
    @Override
    public boolean save() throws Exception {
        PreparedStatement p = null;
        if (id == 0) {
            p = getConnection().prepareStatement("INSERT INTO "+tabla+" VALUES(NULL, ?,?,?,?)");
        } else {
            p = getConnection().prepareStatement("UPDATE "+tabla+" SET nombre=?,"
                    + " telefono=?, correo=?, direccion=? WHERE id=" + this.id);
        }
        p.setString(1, this.nombre);
        p.setString(2, this.telefono);
        p.setString(3, this.correo);
        p.setString(4, this.direccion);
        return p.executeUpdate() > 0;
    }

    public static boolean delete(int id) throws Exception {
        return EntidadMySQL.delete(tabla, id);
    }

    @Override
    public boolean delete() throws Exception {
        return Proveedor.delete(id);
    }

}
