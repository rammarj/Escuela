package com.example.javier.auditoria;

import android.os.Bundle;
import android.support.v4.app.ListFragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;
import android.widget.Toast;

import java.util.LinkedList;


public class FragmentTab extends ListFragment {

    private LinkedList<ElementoLista> ass;
    private int icono;

    public FragmentTab(){ /*No se ocupa*/ }

    public FragmentTab(LinkedList<ElementoLista> ass, int icono){
        this.ass = ass;
        this.icono = icono;
    }

    @Override
    public void onListItemClick(ListView l, View v, int position, long id) {
        super.onListItemClick(l, v, position, id);
        Toast.makeText(getActivity().getApplicationContext(), ass.get(position).getTitulo(), Toast.LENGTH_LONG).show();
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        AdaptadorListView adaptador = new AdaptadorListView(inflater, this.ass, this.icono);
        setListAdapter(adaptador);
        return inflater.inflate(R.layout.fragment_tab, container, false);
    }

}
