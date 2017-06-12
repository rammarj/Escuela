package com.rammarj.websecurity;

import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import java.sql.Connection;
import java.sql.ResultSet;
import java.util.LinkedList;
import netscape.javascript.JSObject;

/**
 *
 * @author RAMMARJ
 */
public abstract class MySQLEntity {

    private static final MySqlConnection connection = new MySqlConnection();
    
    public Connection getConnection() {
        return connection.getConnection();
    }       
    
    public abstract int count();
    
    protected boolean runQuery(String sql) throws Exception {
        return connection.runQuery(sql);
    }

    protected ResultSet getQueryResults(String string) throws Exception {
        return connection.getQueryResults(string);
    }
    
    public abstract LinkedList<MySQLEntity> find(String s, int limit) throws Exception;

    public abstract LinkedList<MySQLEntity> get(int start, int end) throws Exception;

    public abstract void save() throws Exception;

    public abstract void delete(int id) throws Exception;

    public abstract void update() throws Exception;

    public abstract MySQLEntity find(JsonObject jso) throws Exception;
}
