package org.pitufos.pv.logica;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.LinkedList;

/**
 *
 * @author RAMMARJ
 */
public class Categoria extends EntidadMySQL {

    private String nombre;
    private static String tabla = "categorias";

    public Categoria() throws Exception{
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

    public static LinkedList<Categoria> find(String s, int limit) throws Exception {
        ResultSet find = EntidadMySQL.find(tabla, s, limit);
        return convertirLista(find);
    }

    public static LinkedList<Categoria> get(int start, int end) throws Exception {
        ResultSet get = EntidadMySQL.get(tabla, start, end);
        return convertirLista(get);
    }

    private static LinkedList<Categoria> convertirLista(ResultSet find) throws Exception{
        LinkedList<Categoria> categorias = new LinkedList<Categoria>();
        while (find.next()) {
            Categoria categoria = new Categoria();
            categoria.setId(find.getInt("id"));
            categoria.setNombre(find.getString("categoria"));
            categorias.add(categoria);
        }
        return categorias;
    }
    
    public static Categoria get(int id) throws Exception {
        ResultSet get = EntidadMySQL.get(tabla, id);
        LinkedList<Categoria> convertirLista = convertirLista(get);
        if (convertirLista.size()==0) {
            throw new Exception("El elemento que está tratando de obtener no existe.");
        }
        return convertirLista.getFirst();
    }
    
    public static Categoria get(String nombre) throws Exception {
        PreparedStatement p = connection.prepareStatement("SELECT * FROM "+tabla+" WHERE categoria=?");        
        p.setString(1, nombre);
        ResultSet get = p.executeQuery();
        LinkedList<Categoria> convertirLista = convertirLista(get);
        if (convertirLista.size()==0) {
            throw new Exception("El elemento que está tratando de obtener no existe.");
        }
        return convertirLista.getFirst();
    }

    @Override
    public boolean save() throws Exception {
        if (id == 0) {
            PreparedStatement p = getConnection().prepareStatement("INSERT INTO "+tabla+" VALUES(NULL, ?)");
            p.setString(1,this.nombre);
            return !p.execute();
        }else{
            PreparedStatement p = getConnection().prepareStatement("UPDATE "+tabla+" SET categoria=? WHERE id="+this.id);
            p.setString(1,this.nombre);
            return !p.execute();
        }
    }

    public static boolean delete(int id) throws Exception {
        return EntidadMySQL.delete(tabla, id);
    }    

    @Override
    public boolean delete() throws Exception {
        return Categoria.delete(this.id);
    }

}
