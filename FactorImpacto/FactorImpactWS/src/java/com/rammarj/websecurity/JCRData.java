package com.rammarj.websecurity;

public class JCRData {
    
    private int totalCities, articles;
    private float factorImpact, immediacy, fiveImpactFactor;
    private String citedHalfLife;

    public JCRData() {
        this.totalCities = 0;
        this.articles = 0;
        this.immediacy = 0;
        this.factorImpact = 0;
        this.immediacy = 0;
        this.citedHalfLife = "";
    }   

    public float getFiveImpactFactor() {
        return fiveImpactFactor;
    }

    public void setFiveImpactFactor(float fiveImpactFactor) {
        this.fiveImpactFactor = fiveImpactFactor;
    }
    
    public int getTotalCities() {
        return totalCities;
    }

    public void setTotalCities(int totalCities) {
        this.totalCities = totalCities;
    }

    public int getArticles() {
        return articles;
    }
    public void setArticles(int articles) {
        this.articles = articles;
    }
    public float getFactorImpact() {
        return factorImpact;
    }
    public void setFactorImpact(float factorImpact) {
        this.factorImpact = factorImpact;
    }
    public float getImmediacy() {
        return immediacy;
    }
    public void setImmediacy(float immediacy) {
        this.immediacy = immediacy;
    }
    public String getCitedHalfLife() {
        return citedHalfLife;
    }
    public void setCitedHalfLife(String citedHalfLife) {
        this.citedHalfLife = citedHalfLife;
    }
    
}
