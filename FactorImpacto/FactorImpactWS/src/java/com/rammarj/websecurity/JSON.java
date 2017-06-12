/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.rammarj.websecurity;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import java.lang.reflect.Type;
import java.util.Dictionary;

/**
 *
 * @author RAMMARJ
 */
public class JSON {
    
    public static Dictionary<String, String> decode(String s){
        Gson gson = new Gson();      
        Type tipo = new TypeToken<Dictionary<String, String>>(){}.getType();        
        Dictionary<String, String> decoded = gson.fromJson(s, tipo);        
        return decoded;
    }
}
