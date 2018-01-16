package org.pitufos.pv.logica;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Date;
import java.util.LinkedList;

/**
 *
 * @author RAMMARJ
 */
public class Ventas extends EntidadMySQL {

    private static String tabla = "ventas";

    private Date fecha;
    private String nota;

    public Date getFecha() {
        return fecha;
    }

    public void setFecha(Date fecha) {
        this.fecha = fecha;
    }

    public String getNota() {
        return nota;
    }

    public void setNota(String nota) {
        this.nota = nota;
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

    public static LinkedList<Ventas> find(String s, int limit) throws Exception {
        ResultSet find = EntidadMySQL.find(tabla, s, limit);
        return convertirLista(find);
    }

    public static LinkedList<Ventas> get(int start, int end) throws Exception {
        ResultSet get = EntidadMySQL.get(tabla, start, end);
        return convertirLista(get);
    }

    private static LinkedList<Ventas> convertirLista(ResultSet find) throws Exception{
        LinkedList<Ventas> ventas = new LinkedList<Ventas>();
        while (find.next()) {
            Ventas venta = new Ventas();
            venta.setId(find.getInt("id"));
            venta.setFecha(find.getDate("fecha"));
            venta.setNota(find.getString("nota"));
            ventas.add(venta);
        }
        return ventas;
    }
    
    public static Ventas get(int id) throws Exception {
        ResultSet get = EntidadMySQL.get(tabla, id);
        LinkedList<Ventas> convertirLista = convertirLista(get);
        if (convertirLista.size()==0) {
            throw new Exception("El elemento que está tratando de obtener no existe.");
        }
        return convertirLista.getFirst();
    }

    @Override
    public boolean save() throws Exception {
        if (id == 0) {
            PreparedStatement p = getConnection().prepareStatement("INSERT INTO "+tabla+" VALUES(NULL, ?,?)");
            p.setDate(1, (java.sql.Date) this.fecha);
            p.setString(2, this.nota);
            return !p.execute();
        }else{
//            PreparedStatement p = getConnection().prepareStatement("UPDATE "+tabla+" SET fecha=?, nota=? WHERE id="+this.id);
//            p.setDate(1,this.nombre);
//            return !p.execute();
            throw new Exception("Solo se pueden crear ventas, no actualizar.");
        }
    }

    @Override
    public boolean delete() throws Exception {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    public static void corte() throws Exception{
        
    }
    
}
