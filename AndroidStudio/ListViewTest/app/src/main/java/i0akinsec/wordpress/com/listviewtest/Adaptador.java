package i0akinsec.wordpress.com.listviewtest;

import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import java.util.LinkedList;

/**
 * Created by RAMMARJ on 18/03/2017.
 */

public class Adaptador extends BaseAdapter {

    private final Activity activity;
    private final LinkedList<String> lista;

    public Adaptador(Activity activity, LinkedList<String> lista){
        super();
        this.activity = activity;
        this.lista = lista;
    }

    @Override
    public int getCount() {
        return lista.size();
    }

    @Override
    public Object getItem(int position) {
        return lista.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        LayoutInflater inflater = activity.getLayoutInflater();
        View view = inflater.inflate(R.layout.elemento_lista, null, true);

        TextView textView = (TextView) view.findViewById(R.id.titulo);
        textView.setText(lista.get(position));
        ImageView imageView = (ImageView) view.findViewById(R.id.icono);
        switch ( Math.round((float)Math.random()*3)){
            case 0:
                imageView.setImageResource(android.R.drawable.alert_light_frame);
                break;
            case 1:
                imageView.setImageResource(android.R.drawable.alert_dark_frame);
                break;
            default:
                imageView.setImageResource(android.R.drawable.arrow_up_float);
                break;
        }
        return view;
    }
}
