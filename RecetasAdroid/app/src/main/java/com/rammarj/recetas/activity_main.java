package com.rammarj.recetas;

import android.app.ListActivity;
import android.app.ProgressDialog;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;

import java.util.LinkedList;

/**
 * Created by RAMMARJ on 08/04/2017.
 */

public class activity_main extends ListActivity implements View.OnClickListener {

    private AdaptadorLista adaptador;
    private LinkedList<Receta> lista;
    private EditText txtBuscar;
    private ProgressDialog mProgress;
    private Button btnBuscar;

    public activity_main(){ }

    public void setLista(final LinkedList<Receta> lista){
        this.lista = lista;
        adaptador.setLista(lista);
        adaptador.notifyDataSetChanged();
    }
    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.content_main);
        lista = new LinkedList<Receta>();
        adaptador = new AdaptadorLista(this, lista, AdaptadorLista.LIST_ADAPTER_BUSQUEDA_RECETAS);
        setListAdapter(adaptador );
        mProgress = new ProgressDialog(this);
        txtBuscar = (EditText) findViewById(R.id.txtBuscar);
        btnBuscar = (Button) findViewById(R.id.btnBuscar);
        btnBuscar.setOnClickListener(this);
    }
    public void onListItemClick(ListView l, View v, int position, long id) {
        super.onListItemClick(l, v, position, id);
        Receta receta = lista.get(position);
        Intent intent = new Intent(this, RecetaActivity.class);
        intent.putExtra(getString(R.string.bundle_extra_receta), receta.getNombre());
        intent.putExtra(getString(R.string.bundle_extra_ingredientes), Util.recetasString(receta.getIngredientes()));
        intent.putExtra(getString(R.string.bundle_extra_calorias), receta.getCalorias());
        intent.putExtra(getString(R.string.bundle_extra_url), receta.getUrl());
        intent.putExtra(getString(R.string.bundle_extra_imagen), receta.getUrlImagen());
        startActivity(intent);
    }
    public void onClick(View v) {
        mProgress.show();
        new Thread(new Runnable() {
            public void run() {
                String buscar = txtBuscar.getText().toString();
                try { final LinkedList<Receta> recetas = ServicioRest.buscar(buscar);
                      runOnUiThread(new Runnable() {
                        public void run() {
                            setLista(recetas);
                            mProgress.hide();
                        }
                    });
                } catch (final Exception e) {
                    runOnUiThread(new Runnable() {
                        public void run() {
                            mProgress.hide();
                            Toast.makeText(getApplicationContext(), e.toString(), Toast.LENGTH_LONG).show();
                        }
                    });
                }
            }}).start();
    }
}
