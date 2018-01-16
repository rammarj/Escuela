
package logicadifusa;

/**
 *
 * @author RAMMARJ
 */
class Clasificador {

    private int max;
    private int min;

    public Clasificador(int min, int max) {
        this.min = min;
        this.max = max;
    }      
    
    boolean evaluar(int v){
        return (v >= this.min && v<= this.max);
    }

    public void setMax(int max) {
        this.max = max;
    }

    public void setMin(int min) {
        this.min = min;
    }

    @Override
    public String toString() {
        return this.min+" - " + this.max;
    }
 
    
}
