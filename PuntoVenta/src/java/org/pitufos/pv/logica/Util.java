package org.pitufos.pv.logica;

import com.google.gson.Gson;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;

/**
 *
 * @author RAMMARJ
 */
public class Util {

    public static String randomStr(String salt) throws NoSuchAlgorithmException {
        SecureRandom secureRandom = SecureRandom.getInstanceStrong();
        secureRandom.nextBytes(new byte[1024]);
        return sha256(salt + Double.toString(secureRandom.nextDouble()));
    }
    
    public static JsonObject getObjeto(String json) throws Exception{
        try {
            JsonElement parse = new JsonParser().parse(json);
            return parse.getAsJsonObject();
        } catch (Exception jse) {
            throw new Exception("La cadena que ha proporcionado está malformado.");
        }        
    }
    
    public static JsonElement getElemento(JsonObject jo, String llave, String tipo) throws Exception{
        if (!jo.has(llave)) {            
            throw new Exception("El elemento "+llave+" no se encuentra en el objeto proporcionado.");
        }
        JsonElement elemento = jo.get(llave);
        switch(tipo){
            case "string":
                if(!(elemento.isJsonPrimitive() && elemento.getAsJsonPrimitive().isString()))
                    throw new Exception("El elemento "+llave+" debe ser de tipo string.");
                break;
            case "numero":
                if (!(elemento.isJsonPrimitive() && elemento.getAsJsonPrimitive().isNumber())) {
                    throw new Exception("El elemento " + llave + " debe ser numerico.");
                }
                break;
            case "objeto":
                if(!(elemento.isJsonObject()))
                    throw new Exception("El elemento "+llave+" debe ser de tipo string.");
                break;            
        }
        return jo.get(llave);
    }

    public static void validar(String validadores, String campo, String valor) throws Exception {
        String[] validaciones = validadores.split("\\|");
        for (int i = 0; i < validaciones.length; i++) {
            String validacion = validaciones[i];
            String[] validador = validacion.split("\\:");
            switch (validador[0]) {
                case "tam":
                    if (valor.length() != Integer.parseInt(validador[1])) {
                        throw new Exception("El tamaño del campo " + campo + " debe ser igual a " + validador[1] + " caracteres.");
                    }
                    break;
                case "mintam":
                    if (valor.length() < Integer.parseInt(validador[1])) {
                        throw new Exception("El tamaño del campo " + campo + " debe ser mayor o igual a " + validador[1] + " caracteres.");
                    }
                    break;
                case "maxtam":
                    if (valor.length() > Integer.parseInt(validador[1])) {
                        throw new Exception("El tamaño del campo " + campo + " debe ser menor o igual a " + validador[1] + " caracteres.");
                    }
                    break;
                case "float":
                    try {
                        Float.parseFloat(valor);
                    } catch (Exception e) {
                        throw new Exception("El valor del campo " + campo + " no es válido.");
                    }
                    break;
                case "minfloat":
                    if (Float.parseFloat(valor) < Float.parseFloat(validador[1])) {
                        throw new Exception("El valor del campo " + campo + " debe ser un número mayor que " + validador[1] + ".");
                    }
                    break;
                case "int":
                    try {
                        Integer.parseInt(valor);
                    } catch (Exception e) {
                        throw new Exception("El valor del campo " + campo + " no es válido.");
                    }
                    break;
                case "intmin":
                    if (Integer.parseInt(valor) < Integer.parseInt(validador[1])) {
                        throw new Exception("El valor del campo " + campo + " no puede tener valores menores a " + validador[1] + ".");
                    }

                    break;
                case "intmax":
                    if (Integer.parseInt(valor) > Integer.parseInt(validador[1])) {
                        throw new Exception("El valor del campo " + campo + " no puede tener valores mayores a " + validador[1] + ".");
                    }

                    break;
                default:
                    throw new Exception("La validacion " + validador[1] + " no existe.");
            }
        }
    }

    public static String sha256(String s) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        return byteArrayToHex(md.digest(s.getBytes(StandardCharsets.UTF_8)));
    }

    private static String byteArrayToHex(byte[] bytes) {
        StringBuilder builder = new StringBuilder(bytes.length * 2);
        for (byte b : bytes) {
            builder.append(String.format("%02x", new Object[]{Integer.valueOf(b & 0xFF)}));
        }
        return builder.toString();
    }

    public static void main(String[] args) throws NoSuchAlgorithmException {
        System.out.println(sha256(Config.LLAVE_SALT + "admin"));
    }

    public static String mensajeJson(boolean b, String message) {
        return "{\"error\":"+(b?"true":"false")+",\"mensaje\":\""+message+"\"}";
    }
}
