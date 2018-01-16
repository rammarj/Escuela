package com.rammarj.recetas;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.ListFragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;
import java.util.LinkedList;

/**
 * Created by RAMMARJ on 25/04/2017.
 */

public class RecetasAgregadasFragment extends ListFragment {

    private AdaptadorLista adaptador;
    private LinkedList<Receta> lista;

    public RecetasAgregadasFragment(){ }

    public void setLista(final LinkedList<Receta> lista){
        this.lista = lista;
        adaptador.setLista(lista);
        adaptador.notifyDataSetChanged();
    }
    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        lista = new LinkedList<Receta>();
        adaptador = new AdaptadorLista(getActivity(), lista, AdaptadorLista.LIST_ADAPTER_RECETAS_GUARDADAS);
        setListAdapter(adaptador );
    }
    @Override
    public void onListItemClick(ListView l, View v, int position, long id) {
        super.onListItemClick(l, v, position, id);

    }
    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        //listview
        return inflater.inflate(R.layout.content_recetas_agregadas, container, false);
    }
}
