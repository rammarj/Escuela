package com.rammarj.websecurity;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 *
 * @author RAMMARJ
 */
public class MySqlConnection {

    private static final String HOST = "localhost";
    private static final String DATABASE = "factor_impacto";
    private static final String USER = "root";
    private static final String PASSWORD = "";
    private static final int PORT = 3306;
    private Connection connection;

    public MySqlConnection() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            connection = DriverManager.getConnection("jdbc:mysql://" + HOST
                    + ":" + PORT + "/" + DATABASE, USER, PASSWORD);
        } catch (Exception ex) { }
    }
    
    protected Connection getConnection() {
        return connection;
    }

    protected boolean runQuery(String query) throws SQLException {
        try {
            this.connection.createStatement().execute(query);
            return true;
        } catch (SQLException sQLException) {
            return false;
        }
    }

    protected ResultSet getQueryResults(String query) throws SQLException {
        return this.connection.createStatement().executeQuery(query);
    }

    protected boolean closeConnection(){
        try {
            this.connection.close();
            return true;
        } catch (SQLException ex) {
            return false;
        }
    }
    
}
