import javax.swing.*;
 
import org.math.plot.*;
 
import static org.math.array.StatisticSample.*;
 
public class CustomPlotExample {
        public static void main(String[] args) {
 
                // define your data
                //double[] x = randomLogNormal(1000, 0, 0.5); // 1000 random numbers from a log normal statistical law
 
                // create your PlotPanel (you can use it as a JPanel)
                Plot2DPanel plot = new Plot2DPanel();
 
                // add the histogram (50 slices) of x to the PlotPanel
                plot.addHistogramPlot("Log Normal population", new double[]{100,101,102}, 2);
                //plot.addBoxPlot("as", new double[][]{{1,2},{5,5}}, new double[][]{{1,2},{5,5}});
                // put the PlotPanel in a JFrame like a JPanel
                JFrame frame = new JFrame("a plot panel");
                frame.setSize(600, 600);
                frame.setContentPane(plot);
                frame.setVisible(true);
 
        }
}