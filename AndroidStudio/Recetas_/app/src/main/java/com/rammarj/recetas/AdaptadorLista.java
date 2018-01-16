package com.rammarj.recetas;

import android.app.Activity;
import android.content.res.Resources;
import android.graphics.drawable.Drawable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import java.net.URL;
import java.util.LinkedList;
import java.util.ResourceBundle;

/**
 * Created by RAMMARJ on 18/03/2017.
 */
public class AdaptadorLista extends BaseAdapter {

    private final Activity activity;
    private final byte tipoListAdapter;
    private LinkedList<Receta> lista;
    public static final byte LIST_ADAPTER_BUSQUEDA_RECETAS = 0;
    public static final byte LIST_ADAPTER_RECETAS_GUARDADAS = 1;

    public AdaptadorLista(Activity activity, LinkedList<Receta> lista, byte tipoListAdapter){
        super();
        this.activity = activity;
        this.tipoListAdapter = tipoListAdapter;
        if (lista!=null)
            this.lista = lista;
        else
            this.lista = new LinkedList<>();
        
    }

    public void setLista(LinkedList<Receta> lista) {
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
        Receta receta = lista.get(position);
        LayoutInflater inflater = activity.getLayoutInflater();
        View view = inflater.inflate(R.layout.elemento_lista, null, true);
        ImageView imageView = (ImageView) view.findViewById(R.id.icono);
        Drawable thumb_d = receta.getImagen();
        if(thumb_d!=null)
            imageView.setImageDrawable(thumb_d);
        else
            imageView.setImageResource(R.drawable.receta);
        TextView textView = (TextView) view.findViewById(R.id.titulo);
        TextView textViewSubtitulo = (TextView) view.findViewById(R.id.subtitulo);
        textViewSubtitulo.setText((int)receta.getCalorias()+" calorías");
        textView.setText(receta.getNombre());
        return view;
    }
}
