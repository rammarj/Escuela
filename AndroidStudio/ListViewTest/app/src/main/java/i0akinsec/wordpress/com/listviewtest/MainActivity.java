package i0akinsec.wordpress.com.listviewtest;

import android.app.ListActivity;
import android.os.Bundle;
import android.widget.ArrayAdapter;

import java.util.LinkedList;
import java.util.Vector;

public class MainActivity extends ListActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        LinkedList<String> objects = new LinkedList<>();
        objects.add("joaquin");
        objects.add("ramirez");
        objects.add("@rammarj");
        Adaptador adaptador = new Adaptador(this, objects);
        setListAdapter(new Adaptador(this, objects));
    }

}
