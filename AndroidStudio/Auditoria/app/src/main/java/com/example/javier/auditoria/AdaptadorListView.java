package com.example.javier.auditoria;

import android.app.Activity;
import android.app.ListFragment;
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

public class AdaptadorListView extends BaseAdapter {

    private final LayoutInflater inflater;
    private final LinkedList<ElementoLista> lista;
    private int icono;

    public AdaptadorListView(LayoutInflater inflater, LinkedList<ElementoLista> lista, int icono){
        super();
        this.inflater = inflater;
        this.lista = lista;
        this.icono = icono;
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
        //LayoutInflater inflater = getLayoutInflater();
        View view = inflater.inflate(R.layout.elemento_lista, null, true);

        TextView textTitulo = (TextView) view.findViewById(R.id.titulo);
        textTitulo.setText(lista.get(position).getTitulo());

        TextView textSubTitulo = (TextView) view.findViewById(R.id.subtitulo);
        textSubTitulo.setText(lista.get(position).getSubTitulo());

        ImageView imageView = (ImageView) view.findViewById(R.id.icono);
        /*switch ( Math.round((float)Math.random()*3)){
            case 0:
                imageView.setImageResource(android.R.drawable.alert_light_frame);
                break;
            case 1:
                imageView.setImageResource(android.R.drawable.alert_dark_frame);
                break;
            default:
                imageView.setImageResource(android.R.drawable.arrow_up_float);
                break;
        }*/
        imageView.setImageResource(icono);
        return view;
    }
}
