package com.rammarj.ws.factorimpacto;

import android.app.Activity;
import android.graphics.drawable.Drawable;
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
public class AdaptadorLista extends BaseAdapter {

    private final Activity activity;
    private final LinkedList<ItemLista> lista;

    public AdaptadorLista(Activity activity, LinkedList<ItemLista> lista){
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
        TextView textView2 = (TextView) view.findViewById(R.id.subtitulo);
        textView.setText(lista.get(position).getTitulo());
        textView2.setText(lista.get(position).getSubtitulo());
        return view;
    }
}
