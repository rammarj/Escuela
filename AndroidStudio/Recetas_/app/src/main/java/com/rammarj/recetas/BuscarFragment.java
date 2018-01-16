package com.rammarj.recetas;

import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.ListFragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;

import java.util.LinkedList;

/**
 * Created by RAMMARJ on 08/04/2017.
 */

public class BuscarFragment extends ListFragment {

    private AdaptadorLista adaptador;
    private LinkedList<Receta> lista;

    public BuscarFragment(){ }

    public void setLista(final LinkedList<Receta> lista){
        this.lista = lista;
        adaptador.setLista(lista);
        adaptador.notifyDataSetChanged();
    }
    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        lista = new LinkedList<Receta>();
        adaptador = new AdaptadorLista(getActivity(), lista, AdaptadorLista.LIST_ADAPTER_BUSQUEDA_RECETAS);
        setListAdapter(adaptador );
    }
    @Override
    public void onListItemClick(ListView l, View v, int position, long id) {
        super.onListItemClick(l, v, position, id);
        Receta receta = lista.get(position);
        LinkedList<String> ingredientes = receta.getIngredientes();
        StringBuilder builder = new StringBuilder();

        Intent intent = new Intent(getActivity(), RecetaActivity.class);
        intent.putExtra(getString(R.string.bundle_extra_receta), receta.getNombre());
        intent.putExtra(getString(R.string.bundle_extra_ingredientes), Util.recetasString(ingredientes));
        intent.putExtra(getString(R.string.bundle_extra_calorias), receta.getCalorias());
        intent.putExtra(getString(R.string.bundle_extra_url), receta.getUrl());
        intent.putExtra(getString(R.string.bundle_extra_imagen), receta.getUrlImagen());
        startActivity(intent);
    }
    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        //listview
        return inflater.inflate(R.layout.content_inicio, container, false);
    }

}
