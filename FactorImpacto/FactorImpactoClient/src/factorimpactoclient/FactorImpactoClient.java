
package factorimpactoclient;

import javax.swing.SwingUtilities;
import javax.swing.UIManager;

/**
 *
 * @author RAMMARJ
 */
public class FactorImpactoClient {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        UI ui = new UI();
        UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        SwingUtilities.updateComponentTreeUI(ui);
        ui.setVisible(true);
    }
    
}
