package com.example.javier.auditoria;

import android.content.Context;
import android.content.res.Resources;

import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

import java.util.LinkedList;

/**
 * Created by RAMMARJ on 17/03/2017.
 */

public class PersonalEntidadXML extends LectorXML {

    private static final String TAG_PERSONAL_ENTIDAD = "PersonalEntidad";

    public PersonalEntidadXML(Context contexto) throws Exception {
        super(contexto.getResources().openRawResource(R.raw.ia_personal_entidad));
    }

    public LinkedList<PersonaEntidad> getPersonalEntidad(){
        LinkedList<PersonaEntidad> personaEntidades = new LinkedList<>();
        Element raiz = getDocumento().getDocumentElement();

        NodeList elementosPersonalEntidad = raiz.getElementsByTagName(TAG_PERSONAL_ENTIDAD);
        for (int i = 0; i < elementosPersonalEntidad.getLength(); i++){
            Element item = (Element) elementosPersonalEntidad.item(i);

            String esTitular = item.getAttribute("EsTitular");
            String cargo = item.getAttribute("Cargo");
            String apellido = item.getAttribute("Apellido");
            String nombre = item.getAttribute("Nombre");
            String idPersonalOrganismoAuditoriasIniciadas = item.getAttribute("IDPersonalOrganismoAuditoriasIniciadas");
            String idAuditoriasIniciadas = item.getAttribute("IDAuditoriasIniciadas");

            PersonaEntidad personaEntidad = new PersonaEntidad();

            personaEntidad.esTitular = esTitular.toLowerCase().equals("true");
            personaEntidad.cargo = cargo;
            personaEntidad.apellido = apellido;
            personaEntidad.nombre = nombre;
            personaEntidad.idPersonalOrganismoAuditoriasIniciadas = Integer.parseInt(idPersonalOrganismoAuditoriasIniciadas);
            personaEntidad.idAuditoriasIniciadas = Integer.parseInt(idAuditoriasIniciadas);

            personaEntidades.add(personaEntidad);
        }
        return personaEntidades;
    }

    class PersonaEntidad{

        private boolean esTitular;
        private String cargo;
        private String apellido;
        private String nombre;
        private int idPersonalOrganismoAuditoriasIniciadas;
        private int idAuditoriasIniciadas;

        private PersonaEntidad(){}

        public boolean esTitular() {
            return esTitular;
        }

        public String getCargo() {
            return cargo;
        }

        public String getApellido() {
            return apellido;
        }

        public String getNombre() {
            return nombre;
        }

        public int getIdPersonalOrganismoAuditoriasIniciadas() {
            return idPersonalOrganismoAuditoriasIniciadas;
        }

        public int getIdAuditoriasIniciadas() {
            return idAuditoriasIniciadas;
        }
    }

}
