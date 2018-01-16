
package logicadifusa;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import javax.swing.JOptionPane;

/**
 *
 * @author RAMMARJ
 */
public class MySqlConnection {

    private static final String HOST = "localhost";
    private static final String DATABASE = "bd_personas_info";
    private static final String USER = "root";
    private static final String PASSWORD = "";
    private static final int PORT = 3306;
    private Connection connection;
    
    public MySqlConnection() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            this.connection = DriverManager.getConnection("jdbc:mysql://"+HOST+":"+PORT+"/"+DATABASE, USER, PASSWORD);
        } catch (ClassNotFoundException | SQLException ex) {
            JOptionPane.showMessageDialog(null, ex);
        }
    }

    public Connection getConnection() {
        return connection;
    }
    
}
