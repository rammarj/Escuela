package org.pitufos.pv.logica;

import java.sql.Connection;
import java.sql.DriverManager;

/**
 *
 * @author RAMMARJ
 */
class ConexionBD {

    private static Connection conexion;

    private ConexionBD() { }

    public static Connection getConexion(){
        if (conexion == null) {
            try {
                Class.forName("com.mysql.jdbc.Driver");
                conexion = DriverManager.getConnection("jdbc:mysql://" + Config.BD_HOST
                        + ":" + Config.BD_PUERTO + "/" + Config.BD_NOMBRE, Config.BD_USUARIO, Config.BD_PASSWORD);
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
        return conexion;
    }

}
