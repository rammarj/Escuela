
package org.pitufos.pv.logica;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.LinkedList;

/**
 *
 * @author RAMMARJ
 */
public class Rol extends EntidadMySQL {

    private String nombre;
    private static String tabla = "roles";

    public Rol() throws Exception{
        this.id = 0;
    }    
    
    public String getNombre() {
        return nombre;
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
//
//    public static LinkedList<Rol> find(String s, int limit) throws Exception {
//        ResultSet find = MySQLEntity.find("roles", s, limit);
//        return convertirLista(find);
//    }
//
    public static LinkedList<Rol> get(int start, int end) throws Exception {
        ResultSet get = EntidadMySQL.get(tabla, start, end);
        return convertirLista(get);
    }

    private static LinkedList<Rol> convertirLista(ResultSet find) throws Exception{
        LinkedList<Rol> roles = new LinkedList<Rol>();
        while (find.next()) {
            Rol rol = new Rol();
            rol.id = find.getInt("id");
            rol.nombre = find.getString("rol");
            roles.add(rol);
        }
        return roles;
    }
    
    public static Rol get(int id) throws Exception {
        ResultSet get = EntidadMySQL.get(tabla, id);
        LinkedList<Rol> convertirLista = convertirLista(get);
        if (convertirLista.size()==0) {
            throw new Exception("El elemento que está tratando de obtener no existe.");
        }
        return convertirLista.getFirst();
    }
    
    public static Rol get(String nombre) throws Exception {
        PreparedStatement prepareStatement = connection.prepareStatement("SELECT * FROM "+tabla+" WHERE rol=?");
        prepareStatement.setString(1, nombre);
        LinkedList<Rol> convertirLista = convertirLista(prepareStatement.executeQuery());
        if (convertirLista.size()==0) {
            throw new Exception("El elemento que está tratando de obtener no existe.");
        }
        return convertirLista.getFirst();
    }

    @Override
    public boolean save() throws Exception {
        return false;
    }

    public static boolean delete(int id) throws Exception {
        return false;
    }    

    @Override
    public boolean delete() throws Exception {
        return Rol.delete(id);
    }    
    
}
