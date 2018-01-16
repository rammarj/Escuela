
package org.pitufos.pv.logica;

import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.LinkedList;

/**
 *
 * @author RAMMARJ
 */
public final class Usuario extends EntidadMySQL {

    private String nombre;
    private Rol rol;
    private String apellidoPaterno;
    private String apellidoMaterno;
    private String sexo;
    private String telefono;
    private String correo;
    private int entradas;
    private Date fechaUltimaEntrada;
    private Date fechaCreacion;
    private String usuario;
    private static String tabla = "usuarios";

    public Date getFechaCreacion() {
        return fechaCreacion;
    }

    public void setFechaCreacion(Date fechaCreacion) {
        this.fechaCreacion = fechaCreacion;
    }

    public String getUsuario() {
        return usuario;
    }

    public void setUsuario(String usuario) {
        this.usuario = usuario;
    }

    public Rol getRol() {
        return rol;
    }

    public void setRol(Rol rol) {
        this.rol = rol;
    }

    public String getApellidoPaterno() {
        return apellidoPaterno;
    }

    public void setApellidoPaterno(String apellidoPaterno) {
        this.apellidoPaterno = apellidoPaterno;
    }

    public String getApellidoMaterno() {
        return apellidoMaterno;
    }

    public void setApellidoMaterno(String apellidoMaterno) {
        this.apellidoMaterno = apellidoMaterno;
    }

    public String getSexo() {
        return sexo;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public String getTelefono() {
        return telefono;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }

    public int getEntradas() {
        return entradas;
    }

    public void setEntradas(int entradas) {
        this.entradas = entradas;
    }

    public Date getFechaUltimaEntrada() {
        return fechaUltimaEntrada;
    }

    public void setFechaUltimaEntrada(Date fechaUltimaEntrada) {
        this.fechaUltimaEntrada = fechaUltimaEntrada;
    }
    
    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    /**
     * Obtiene el numero de registros que existen en la tabla
     *
     * @return numero de registros en la tabla
     */
    public static int count() throws Exception {
        ResultSet queryResults = connection.createStatement().executeQuery("SELECT COUNT(*) FROM "+tabla);
        queryResults.next();
        return queryResults.getInt(1);
    }

    public static LinkedList<Usuario> find(String s, int limit) throws Exception {
        ResultSet find = EntidadMySQL.find(tabla, s, limit);
        return convertirLista(find);
    }

    public static LinkedList<Usuario> get(int start, int end) throws Exception {
        ResultSet get = EntidadMySQL.get(tabla, start, end);
        return convertirLista(get);
    }

    private static LinkedList<Usuario> convertirLista(ResultSet find) throws Exception{
        LinkedList<Usuario> usuarios = new LinkedList<Usuario>();
        while (find.next()) {
            Usuario usuario = new Usuario();
            usuario.setId(find.getInt("id"));
            usuario.setRol(Rol.get(find.getInt("id_rol")));
            usuario.setNombre(find.getString("nombre"));
            usuario.setApellidoPaterno(find.getString("ap_paterno"));
            usuario.setApellidoMaterno(find.getString("ap_materno"));
            usuario.setSexo(find.getString("sexo"));
            usuario.setTelefono(find.getString("telefono"));
            usuario.setCorreo(find.getString("correo"));
            usuario.setEntradas(find.getInt("entradas"));
            usuario.setFechaUltimaEntrada(find.getDate("fecha_ultima_entrada"));
            usuario.setFechaCreacion(find.getDate("fecha_creacion"));
            usuario.setUsuario(find.getString("usuario"));
            usuarios.add(usuario);
        }
        return usuarios;
    }
    
    public static Usuario get(int id) throws Exception {
        ResultSet resultados = EntidadMySQL.get(tabla, id);
        LinkedList<Usuario> usuarios = convertirLista(resultados);
        if (usuarios.size()==0) {
            throw new Exception("El elemento que está tratando de obtener no existe.");
        }
        return usuarios.getFirst();
    }

    @Override
    public boolean save() throws Exception {
        if (id <= 0) {
            if (Usuario.getUser(this.usuario)!=null) 
                throw new Exception("El usuario "+this.usuario+" ya existe.");
            
            PreparedStatement p = getConnection().prepareStatement("INSERT INTO "+tabla
                    + " VALUES(NULL, ?,?,?,?,?,?,?,?,?,?,?,?)");
            p.setInt(1,this.getRol().getId());
            p.setString(2,this.nombre);
            p.setString(3,this.apellidoPaterno);
            p.setString(4,this.apellidoMaterno);
            p.setString(5,this.sexo);
            p.setString(6,this.telefono);
            p.setString(7,this.correo);
            p.setInt(8,0);
            p.setDate(9,new Date(System.currentTimeMillis()));
            p.setString(10,this.usuario);
            p.setString(11, "");
            p.setDate(12,new Date(System.currentTimeMillis()));
            if (p.executeUpdate()>0) { //funcionó?
                this.id = getUser(this.usuario).getId();
                return true;
            }            
            return false;
        }else{
            PreparedStatement p = getConnection().prepareStatement(
                    "UPDATE "+tabla+" SET id_rol=?,nombre=?,ap_paterno=?,ap_materno=?,"
                            + "sexo=?,telefono=?,correo=?,usuario=? WHERE id="+this.id
            );
            p.setInt(1,this.rol.getId());
            p.setString(2,this.nombre);
            p.setString(3,this.apellidoPaterno);
            p.setString(4,this.apellidoPaterno);
            p.setString(5,this.sexo);
            p.setString(6,this.telefono);
            p.setString(7,this.correo);
            p.setString(8,this.usuario);
            return p.executeUpdate()>0;
        }
    }

    public static boolean delete(int id) throws Exception {
        return EntidadMySQL.delete(tabla, id);
    }    

    public static Usuario login(String usuario, String pass) throws Exception{
        PreparedStatement prepareStatement = connection.prepareStatement("SELECT * FROM "+tabla
                +" WHERE usuario=? and password=?");
        prepareStatement.setString(1, usuario);
        prepareStatement.setString(2, hashPassword(pass));        
        ResultSet resultado = prepareStatement.executeQuery();
        if(resultado.next()){
            return Usuario.get(resultado.getInt("id"));            
        }
        return null;
    }
    
    public static Usuario getUser(String user)throws Exception{
        PreparedStatement prepareStatement = connection.prepareStatement("SELECT * FROM "+tabla+" WHERE usuario=?");
        prepareStatement.setString(1, user);      
        ResultSet resultado = prepareStatement.executeQuery();
        if(resultado.next()){
            return Usuario.get(resultado.getInt("id"));            
        }
        return null;
    }
    
    public static Usuario getUsuarioPorToken(String token)throws Exception{
        PreparedStatement prepareStatement = connection.prepareStatement("SELECT * FROM "+tabla+" WHERE token=?");
        prepareStatement.setString(1, token);      
        ResultSet resultado = prepareStatement.executeQuery();
        if(resultado.next()){
            return Usuario.get(resultado.getInt("id"));            
        }
        return null;
    }
    
    private static String hashPassword(String pass) throws Exception{
        return Util.sha256(Config.LLAVE_SALT+pass);
    }
       
    public void cambiarPassword(String nuevoPass) throws Exception {
        if(this.id<=0) throw new Exception("No hay ningun usuario seleccionado");
        if(!runQuery("UPDATE "+tabla+" SET password='"+Usuario.hashPassword(nuevoPass)+"' WHERE id="+this.id))
            throw new Exception("Error al cambiar a contraseña del usuario.");
    }

    public String regenerarToken() throws Exception{
        try {            
            Usuario.get(this.id); //verificar existe
            String randomStr = Util.randomStr(Config.LLAVE_SALT);
            boolean runQuery = runQuery("UPDATE "+tabla+" SET token='"+randomStr+"' WHERE id="+this.id);
            if (!runQuery) {
                throw new Exception();
            }                    
            return randomStr;
        } catch (Exception e) {
            throw new Exception("El token no se ha podido guardar.");
        }  
    }

    @Override
    public boolean delete() throws Exception {
        return Usuario.delete(id);
    }
}
