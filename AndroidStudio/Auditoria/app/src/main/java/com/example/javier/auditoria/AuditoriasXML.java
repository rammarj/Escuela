package com.example.javier.auditoria;

import android.content.Context;
import android.content.res.Resources;
import android.support.annotation.XmlRes;
import android.util.Xml;

import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Comparator;
import java.util.Date;
import java.util.LinkedList;

/**
 * Created by RAMMARJ on 17/03/2017.
 */

public final class AuditoriasXML extends LectorXML {

    private static final String TAG_AUDITORIA = "Auditoria";
    private final LinkedList<Integer> ejercicioAnios;

    public AuditoriasXML(Context contexto) throws Exception {
        super(contexto.getResources().openRawResource(R.raw.ia_auditorias));
        ejercicioAnios = new LinkedList<>();
    }

    public LinkedList<Integer> getEjercicioAnios() {
        return ejercicioAnios;
    }

    public enum AREA{
        ESTATAL, PARAESTATAL, MUNICIPAL, DESEMPENO
    }

    public static LinkedList<ElementoLista> getAuditorias(LinkedList<ElementoLista> lista, int anio){
        LinkedList<ElementoLista> ret = new LinkedList<>();
        for (ElementoLista l : lista){
            if (((Auditoria)l).getEjercicio() == anio)
                ret.add(l);
        }
        return  ret;
    }

    public LinkedList<ElementoLista> getAuditorias(AREA area) throws Exception {
        String areaAuditoria = "";
        switch (area){
            case ESTATAL:
                areaAuditoria = Auditoria.ESTATAL;
                break;
            case PARAESTATAL:
                areaAuditoria = Auditoria.PARAESTATAL;
                break;
            case MUNICIPAL:
                areaAuditoria = Auditoria.MUNICIPAL;
                break;
            case DESEMPENO:
                areaAuditoria = Auditoria.DESEMPENO;
                break;
        }
        LinkedList<ElementoLista> auditorias = getAuditorias();
        LinkedList<ElementoLista> resultado = new LinkedList<>();
        for (ElementoLista elemento : auditorias){
            Auditoria auditoria = (Auditoria)elemento;
            if (areaAuditoria.equals(auditoria.getArea()))
                resultado.add(auditoria);
        }
        return resultado;
    }

    public Auditoria getAuditoria(int idAuditoriasIniciadas) throws Exception {
        LinkedList<ElementoLista> auditorias = getAuditorias();
        for (ElementoLista auditoria : auditorias){
            int idAuditoria = ((Auditoria)auditoria).getIdAuditoriasIniciadas();
            if (idAuditoria == idAuditoriasIniciadas)
                return (Auditoria) auditoria;
        }
        return null;
    }

    private LinkedList<ElementoLista> getAuditorias() throws Exception {
        LinkedList<ElementoLista> auditorias = new LinkedList<>();
        Element raiz = getDocumento().getDocumentElement();
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("dd/MM/yyy");
        NodeList elementosAuditorias = raiz.getElementsByTagName(TAG_AUDITORIA);
        for (int i = 0; i < elementosAuditorias.getLength(); i++){
            Element item = (Element) elementosAuditorias.item(i);

            String area = item.getAttribute("Area");
            String modalidad = item.getAttribute("Modalidad");
            String tipo = item.getAttribute("Tipo");
            String fechaFinaliza = item.getAttribute("FechaFinaliza");
            String fechaInicio = item.getAttribute("FechaInicio");
            String ejercicio = item.getAttribute("Ejercicio");
            String nombreOrganismo = item.getAttribute("NombreOrganismo");
            String idAuditoriasIniciadas = item.getAttribute("IDAuditoriasIniciadas");

            Auditoria auditoria = new Auditoria();
            auditoria.area = area;
            auditoria.modalidad = modalidad;
            auditoria.tipo = tipo;
            auditoria.fechaFinaliza = simpleDateFormat.parse(fechaFinaliza);
            auditoria.fechaInicio = simpleDateFormat.parse(fechaInicio);
            auditoria.ejercicio = Integer.parseInt(ejercicio);
            auditoria.nombreOrganismo = nombreOrganismo;
            auditoria.idAuditoriasIniciadas = Integer.parseInt(idAuditoriasIniciadas);

            if(!ejercicioAnios.contains(auditoria.ejercicio))
                ejercicioAnios.add(auditoria.ejercicio); //agregar a la lista de años si es que todavia no está em la lista
            //para los titulos de los tabs.

            auditorias.add(auditoria);
        }
        return auditorias;
    }

    class Auditoria implements Comparator, ElementoLista{

        private static final String ESTATAL = "DIRECCIÓN GENERAL DE AUDITORÍA ESTATAL";
        private static final String PARAESTATAL = "DIRECCIÓN GENERAL DE AUDITORÍA DEL SECTOR PARAESTATAL";
        private static final String MUNICIPAL = "DIRECCIÓN GENERAL DE AUDITORÍA A MUNICIPIOS Y OBRA PÚBLICA";
        private static final String DESEMPENO = "DIRECCIÓN GENERAL DE AUDITORIA SOBRE EL DESEMPEÑO";

        private String area;
        private String modalidad;
        private String tipo;
        private Date fechaInicio;
        private Date fechaFinaliza;
        private int ejercicio;
        private String nombreOrganismo;
        private int idAuditoriasIniciadas;

        private Auditoria(){ }

        public String getArea() {
            return area;
        }

        public String getModalidad() {
            return modalidad;
        }

        public String getTipo() {
            return tipo;
        }

        public Date getFechaInicio() {
            return fechaInicio;
        }

        public Date getFechaFinaliza() {
            return fechaFinaliza;
        }

        public int getEjercicio() {
            return ejercicio;
        }

        public String getNombreOrganismo() {
            return nombreOrganismo;
        }

        public int getIdAuditoriasIniciadas() {
            return idAuditoriasIniciadas;
        }

        @Override
        public int compare(Object o1, Object o2) {
            Auditoria aud1 = (Auditoria) o1;
            Auditoria aud2 = (Auditoria) o2;

            if (aud1.getEjercicio() < aud2.getEjercicio())
                return -1;
            else if (aud1.getEjercicio() > aud2.getEjercicio())
                return 1;
            return 0;
        }

        @Override
        public String getTitulo() {
            return this.nombreOrganismo;
        }

        @Override
        public String getSubTitulo() {
            return this.getTipo();
        }

    }

}
