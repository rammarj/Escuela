package org.pitufos.pv.logica;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.LinkedList;

/**
 *
 * @author RAMMARJ
 */
abstract class EntidadMySQL {

    protected static Connection connection = ConexionBD.getConexion();
    protected int id;

    public EntidadMySQL() {
        this.id = 0;
    }
    
    public int getUltimoInsertID() throws Exception{
        ResultSet queryResults = getQueryResults("SELECT LAST_INSERT_ID()");
        queryResults.next();
        return queryResults.getInt(1);
    }

    //protected String nombreTabla;
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Connection getConnection() {
        return connection;
    }

    protected boolean runQuery(String sql) throws Exception {
        return connection.createStatement().executeUpdate(sql) > 0;
    }

    protected ResultSet getQueryResults(String string) throws Exception {
        return connection.createStatement().executeQuery(string);
    }

    public abstract boolean save() throws Exception;

    public abstract boolean delete() throws Exception;

    protected static boolean delete(String tabla, int id) throws Exception {
        return connection.createStatement().executeUpdate("DELETE FROM " + tabla + " WHERE id=" + id) > 0;
    }

    protected static int getCount(String tabla) throws SQLException {
        ResultSet queryResults = connection.createStatement().executeQuery("SELECT COUNT(*) FROM " + tabla);
        queryResults.next();
        return queryResults.getInt(1);
    }

    protected static ResultSet get(String tabla, int id) throws Exception {
        return connection.createStatement().executeQuery("SELECT * FROM " + tabla + " WHERE ID=" + id);
    }

    protected static ResultSet find(String tabla, String s, int limit) throws Exception {
        LinkedList<String> columnas = getColumnas(tabla);
        StringBuffer cols = new StringBuffer();
        for (int i = 0; i < columnas.size(); i++) {
            String columna = columnas.get(i);
            cols.append(columna);
            if ((i + 1) != columnas.size()) {
                cols.append(",' ',");
            }
        }
        String sql = "SELECT * FROM " + tabla + " WHERE CONCAT(" + cols.toString()
                + ") LIKE '%" + escapeLike(s) + "%' AND id<>1 limit " + limit + ""/*no seleccionar el admin 1*/;
        return connection.createStatement().executeQuery(sql);
    }

    protected static String escapeLike(String s) {
        return s;
    }

    protected static ResultSet get(String tabla, int start, int end) throws Exception {
        return connection.createStatement().executeQuery("SELECT * FROM " + tabla + " LIMIT " + start + "," + end);
    }

    protected static LinkedList<String> getColumnas(String tabla) throws Exception {
        ResultSet queryColumnas = connection.createStatement().executeQuery("SHOW COLUMNS FROM " + tabla);
        LinkedList<String> columnas = new LinkedList<String>();
        while (queryColumnas.next()) {
            String columna = queryColumnas.getString("Field");
            columnas.add(tabla + "." + columna);
        }
        return columnas;
    }

}
