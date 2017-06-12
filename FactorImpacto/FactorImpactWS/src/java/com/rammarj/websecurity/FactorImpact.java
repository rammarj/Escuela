package com.rammarj.websecurity;

import com.google.gson.JsonObject;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.LinkedList;

/**
 *
 * @author RAMMARJ
 */
public class FactorImpact extends MySQLEntity {

    private int id;
    private String title, issn;
    private JCRData jCRData;
    private EigenFactorMetrics eigenFactorMetrics;

    public FactorImpact() throws Exception {
        this.title = "";
        this.issn = "";
        this.jCRData = null;
        this.eigenFactorMetrics = null;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getIssn() {
        return issn;
    }

    public void setIssn(String issn) {
        this.issn = issn;
    }

    public JCRData getjCRData() {
        return jCRData;
    }

    public void setjCRData(JCRData jCRData) {
        this.jCRData = jCRData;
    }

    public EigenFactorMetrics getEigenFactorMetrics() {
        return eigenFactorMetrics;
    }

    public void setEigenFactorMetrics(EigenFactorMetrics eigenFactorMetrics) {
        this.eigenFactorMetrics = eigenFactorMetrics;
    }

    @Override
    public void save() throws Exception {
        PreparedStatement prepareStatement = getConnection()
                .prepareStatement("INSERT INTO factor_impact(abbreviated, issn) values (?, ?);");
        prepareStatement.setString(1, getTitle());
        prepareStatement.setString(2, getIssn());
        String sql = prepareStatement.toString().substring(prepareStatement.toString().indexOf(':') + 1);
        //System.out.println(sql);
        boolean queryRes = runQuery(sql);
        if (!queryRes) {
            throw new Exception("Error mientras se guardaba el registro.");
        }
        prepareStatement = getConnection().prepareStatement("INSERT INTO jcrdata VALUES(last_insert_id(), ?, ?, ?, ?, ?, ?);");
        JCRData jcrData = getjCRData();
        prepareStatement.setInt(1, jcrData.getTotalCities());
        prepareStatement.setFloat(2, jcrData.getFactorImpact());
        prepareStatement.setFloat(3, jcrData.getFiveImpactFactor());
        prepareStatement.setFloat(4, jcrData.getImmediacy());
        prepareStatement.setInt(5, jcrData.getArticles());
        prepareStatement.setString(6, jcrData.getCitedHalfLife());
        ////
        sql = prepareStatement.toString().substring(prepareStatement.toString().indexOf(':') + 1);
        queryRes = runQuery(sql);
        if (!queryRes) {
            getConnection().rollback();
            throw new Exception("Error mientras se guardaba el registro.");
        }
        System.out.println(sql);
        EigenFactorMetrics eigenFactorMetrics = getEigenFactorMetrics();
        prepareStatement = getConnection().prepareStatement("INSERT INTO eigenfactor_metrics VALUES(last_insert_id(), ?, ?);");
        prepareStatement.setFloat(1, eigenFactorMetrics.getEigenFactorScore());
        prepareStatement.setFloat(2, eigenFactorMetrics.getArticleInfluenceScore());
        sql = prepareStatement.toString().substring(prepareStatement.toString().indexOf(':') + 1);
        System.out.println(sql);
        queryRes = runQuery(sql);
        if (!queryRes) {
            getConnection().rollback();
            getConnection().rollback();
            throw new Exception("Error mientras se guardaba el registro.");
        }
    }

    @Override
    public void delete(int id) throws Exception {
        String sql = "DELETE FROM jcrdata WHERE id=" + id;
        boolean runQuery = runQuery(sql);
        if (!runQuery) {
            getConnection().rollback();
            throw new Exception("Error mientras se guardaba el registro.");
        }
        sql = "DELETE FROM eigenfactor_metrics WHERE id=" + id;
        runQuery = runQuery(sql);
        if (!runQuery) {
            getConnection().rollback();
            throw new Exception("Error mientras se guardaba el registro.");
        }
        sql = "DELETE FROM factor_impact WHERE id=" + id;
        runQuery = runQuery(sql);
        if (!runQuery) {
            getConnection().rollback();
            getConnection().rollback();
            throw new Exception("Error mientras se guardaba el registro.");
        }
    }

    @Override
    public void update() throws Exception{
        int id = getId();
        PreparedStatement prepareStatement = getConnection()
                .prepareStatement("UPDATE factor_impact SET abbreviated=?,issn=? WHERE id="+id);
        prepareStatement.setString(1, getTitle());
        prepareStatement.setString(2, getIssn());
        String sql = prepareStatement.toString().substring(prepareStatement.toString().indexOf(':')+1);
        boolean runQuery = runQuery(sql);
        if (!runQuery)
            throw new Exception("Error al actualizar el registro.");
        prepareStatement = getConnection()
                .prepareStatement("UPDATE jcrdata SET total_cities=?,factor_impact=?"
                        + ",factor_impact_5=?,immediacy_index=?,articles=?,cited_half_life=? WHERE id="+id);
        prepareStatement.setInt(1, jCRData.getTotalCities());
        prepareStatement.setFloat(2, jCRData.getFactorImpact());
        prepareStatement.setFloat(3, jCRData.getFiveImpactFactor());
        prepareStatement.setFloat(4, jCRData.getImmediacy());
        prepareStatement.setFloat(5, jCRData.getArticles());
        prepareStatement.setString(6, jCRData.getCitedHalfLife());
        sql = prepareStatement.toString().substring(prepareStatement.toString().indexOf(':')+1);
        runQuery = runQuery(sql);
        if (!runQuery){
            getConnection().rollback();
            throw new Exception("Error al actualizar el registro.");
        }
        prepareStatement = getConnection()
                .prepareStatement("UPDATE eigenfactor_metrics SET score=?,article_influence=? WHERE id="+id);
        prepareStatement.setFloat(1, eigenFactorMetrics.getEigenFactorScore());
        prepareStatement.setFloat(2, eigenFactorMetrics.getArticleInfluenceScore());
        sql = prepareStatement.toString().substring(prepareStatement.toString().indexOf(':')+1);
        runQuery = runQuery(sql);
        if (!runQuery){
            getConnection().rollback();
            getConnection().rollback();
            throw new Exception("Error al actualizar el registro.");
        }
    }

    @Override
    public MySQLEntity find(JsonObject jso) {
        String col = jso.get("column").getAsString().replace("`", "");
        if (col.equals("id")) {
            col = "factor_impact`.`id";
        }
        String val = jso.get("value").getAsString().replace("'", "").replace("\\", "");
        System.out.println(col+"="+val);
        try {
            ResultSet res = getQueryResults("SELECT factor_impact.id as `id`,abbreviated,issn,score,"
                    + "article_influence,total_cities,factor_impact,factor_impact_5,immediacy_index,"
                    + "articles,cited_half_life FROM factor_impact,jcrdata,eigenfactor_metrics WHERE "
                    + "factor_impact.id=jcrdata.id AND factor_impact.id=eigenfactor_metrics.id AND `"
                    + col+"`='"+val+"';");
            LinkedList<MySQLEntity> list = toLinkedList(res);
            if (list.size()==0) 
                return null;
            return list.get(0);
        } catch (Exception ex) {
            System.out.println(ex);
            return null;
        }
    }

    @Override
    public LinkedList<MySQLEntity> get(int start, int end) throws Exception {
        String sql = "SELECT factor_impact.id as `id`,abbreviated,issn,score,"
                + "article_influence,total_cities,factor_impact,factor_impact_5,immediacy_index,"
                + "articles,cited_half_life FROM factor_impact,jcrdata,eigenfactor_metrics WHERE "
                + "factor_impact.id=jcrdata.id AND factor_impact.id=eigenfactor_metrics.id LIMIT "
                + start + "," + end + ";";
        ResultSet res = getQueryResults(sql);
        System.out.println(sql);
        return toLinkedList(res);
    }

    private LinkedList<MySQLEntity> toLinkedList(ResultSet res) throws Exception {
        LinkedList<MySQLEntity> list = new LinkedList<MySQLEntity>();
        while (res.next()) {
            FactorImpact factorImpact = new FactorImpact();
            factorImpact.setId(res.getInt("id"));
            factorImpact.setTitle(res.getString("abbreviated"));
            factorImpact.setIssn(res.getString("issn"));

            EigenFactorMetrics eigenFactorMetrics = new EigenFactorMetrics();
            eigenFactorMetrics.setArticleInfluenceScore(res.getFloat("article_influence"));
            eigenFactorMetrics.setEigenFactorScore(res.getFloat("score"));
            factorImpact.setEigenFactorMetrics(eigenFactorMetrics);

            JCRData jcrData = new JCRData();
            jcrData.setArticles(res.getInt("articles"));
            jcrData.setCitedHalfLife(res.getString("cited_half_life"));
            jcrData.setFactorImpact(res.getFloat("factor_impact"));
            jcrData.setFiveImpactFactor(res.getFloat("factor_impact_5"));
            jcrData.setImmediacy(res.getFloat("immediacy_index"));
            jcrData.setTotalCities(res.getInt("total_cities"));
            factorImpact.setjCRData(jcrData);

            list.add(factorImpact);
        }
        return list;
    }

    @Override
    public LinkedList<MySQLEntity> find(String s, int limit) throws Exception {
        if (limit<0) return new LinkedList<>(); //retornar vacio
        s.replace("%", "").replace("'", "").replace("\\", ""); //evitar inyeccion de metacaracter peligroso
        String sql = "SELECT factor_impact.id as `id`,abbreviated,issn,score,"
                + "article_influence,total_cities,factor_impact,factor_impact_5,immediacy_index,"
                + "articles,cited_half_life FROM factor_impact,jcrdata,eigenfactor_metrics "
                + "WHERE factor_impact.id=jcrdata.id AND factor_impact.id=eigenfactor_metrics.id "
                + "AND concat(factor_impact.id,' ',abbreviated,' ',issn,' ',score,' ',article_influence"
                + ",' ',total_cities,' ',factor_impact,' ',factor_impact_5,' ',immediacy_index,' '"
                + ",articles,' ',cited_half_life) LIKE '%"+s+"%' LIMIT " + limit + ";";
        ResultSet res = getQueryResults(sql);
        return toLinkedList(res);
    }

    @Override
    public int count() {
        String sql = "SELECT COUNT(*) FROM factor_impact;";
        try {
            ResultSet runQuery = getQueryResults(sql);
            runQuery.next();
            return runQuery.getInt(1);
        } catch (Exception ex) {
            return 0;
        }
    }

}
