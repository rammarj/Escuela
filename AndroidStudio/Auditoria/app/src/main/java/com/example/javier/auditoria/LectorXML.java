package com.example.javier.auditoria;

import android.content.Context;

import org.w3c.dom.Document;
import java.io.InputStream;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

/**
 * Created by RAMMARJ on 17/03/2017.
 */
public class LectorXML {

    private Document documento;

    protected LectorXML(InputStream archivo) throws Exception {
        DocumentBuilderFactory fabrica = DocumentBuilderFactory.newInstance();
        DocumentBuilder builder = fabrica.newDocumentBuilder();
        documento = builder.parse(archivo);
    }

    protected Document getDocumento() {
        return documento;
    }

}
