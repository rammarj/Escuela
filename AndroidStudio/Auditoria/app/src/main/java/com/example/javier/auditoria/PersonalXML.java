package com.example.javier.auditoria;

import android.content.Context;
import android.content.res.Resources;

import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import java.util.LinkedList;

/**
 * Created by RAMMARJ on 17/03/2017.
 */

public class PersonalXML extends LectorXML {

    private static final String TAG_PERSONAL = "PersonalASEH";

    public PersonalXML(Context contexto) throws Exception {
        super(contexto.getResources().openRawResource(R.raw.ia_personal_aseh));
    }

    public LinkedList<Persona> getPersonal(){
        LinkedList<Persona> personal = new LinkedList<>();
        Element raiz = getDocumento().getDocumentElement();
        NodeList elementosPersonal = raiz.getElementsByTagName(TAG_PERSONAL);
        for (int i = 0; i < elementosPersonal.getLength(); i++){
            Element item = (Element) elementosPersonal.item(i);

            String cargoArea = item.getAttribute("CargoArea");
            String abreviaturaTitulo = item.getAttribute("AbreviaturaTitulo");
            String apellidos = item.getAttribute("Apellidos");
            String nombre = item.getAttribute("Nombre");
            String esCoordinador = item.getAttribute("EsCoordinador");
            String esSupervisor = item.getAttribute("EsSupervisor");
            String tipoPersonal = item.getAttribute("TipoPersonal");
            String idPersonalAuditoriasIniciadas = item.getAttribute("IDPersonalAuditoriasIniciadas");
            String idAuditoriasIniciadas = item.getAttribute("IDAuditoriasIniciadas");

            Persona persona = new Persona();
            persona.cargoArea = cargoArea;
            persona.abreviaturaTitulo = abreviaturaTitulo;
            persona.apellidos = apellidos;
            persona.nombre = nombre;
            persona.esCoordinador = esCoordinador.toLowerCase().equals("true");
            persona.esSupervisor = esSupervisor.toLowerCase().equals("true");
            persona.tipoPersonal = tipoPersonal;
            persona.idPersonalAuditoriasIniciadas = Integer.parseInt(idPersonalAuditoriasIniciadas);
            persona.idAuditoriasIniciadas = Integer.parseInt(idAuditoriasIniciadas);

            personal.add(persona);
        }
        return personal;
    }

    class Persona{

        private String cargoArea;
        private String abreviaturaTitulo;
        private String apellidos;
        private String nombre;
        private boolean esCoordinador;
        private boolean esSupervisor;
        private String tipoPersonal;
        private int idPersonalAuditoriasIniciadas;
        private int idAuditoriasIniciadas;

        private Persona(){ }

        public String getCargoArea() {
            return cargoArea;
        }

        public String getAbreviaturaTitulo() {
            return abreviaturaTitulo;
        }

        public String getApellidos() {
            return apellidos;
        }

        public String getNombre() {
            return nombre;
        }

        public boolean isEsCoordinador() {
            return esCoordinador;
        }

        public boolean isEsSupervisor() {
            return esSupervisor;
        }

        public String getTipoPersonal() {
            return tipoPersonal;
        }

        public int getIdPersonalAuditoriasIniciadas() {
            return idPersonalAuditoriasIniciadas;
        }

        public int getIdAuditoriasIniciadas() {
            return idAuditoriasIniciadas;
        }
    }

}
