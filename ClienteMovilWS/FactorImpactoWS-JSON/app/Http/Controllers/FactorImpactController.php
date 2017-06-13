<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class FactorImpactController extends Controller
{
    public function __construct() {
        header("Content-Type: application/json; charset=UTF-8");         
        header("Content-Type-Options: nosniff");
        header("X-Content-Type-Options: nosniff");
        header("X-XSS-Protection: 1; mode=block");
        //header("Server: Apache-Coyote/1.1");
        //header("X-Powered-By: Apache 2");
    }
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index(Request $request)
    {
        $count = $request->get('count', 20);
        if ($count>50 || $count<1) 
            return response ()->json (['error'=>'el parametro count debe valer enntre 0 y 50.']);
        return \App\FactorImpact::paginate($request->get('count', 20));
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
        $this->modify($request);
    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {       
        return \App\FactorImpact::find($id);
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function edit($id)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, $id)
    {
        return $this->modify($request, $id);
    }

    private function modify($request, $id=0) {
        if ($request->acceptsJson() && $request->isJson()){           
            $abbreviated = $request->input('abbreviated');
            $issn = $request->input('issn');
            //jcrdata
            $total_cities = $request->input('jcrdata.total_cities');
            $factor_impact = $request->input('jcrdata.factor_impact');
            $factor_impact_5 = $request->input('jcrdata.factor_impact_5');
            $immediacy_index = $request->input('jcrdata.immediacy_index');
            $articles = $request->input('jcrdata.articles');
            $cited_half_life = $request->input('jcrdata.cited_half_life');
            //eigen_factor_metrics
            $score = $request->input('eigen_factor_metrics.score');
            $article_influence = $request->input('eigen_factor_metrics.article_influence');
            
            if ($id>0)$data = \App\FactorImpact::find($id);
            else $data = new \App\FactorImpact();
            if($abbreviated)$data->abbreviated=$abbreviated;
            if($issn)$data->issn=$issn;
            
            if($total_cities)$data->jcrdata->total_cities=$abbreviated;
            if($factor_impact)$data->jcrdata->factor_impact=$factor_impact;
            if($factor_impact_5)$data->jcrdata->factor_impact_5=$factor_impact_5;
            if($immediacy_index)$data->jcrdata->immediacy_index=$immediacy_index;
            if($articles)$data->jcrdata->articles=$articles;
            if($cited_half_life)$data->jcrdata->cited_half_life=$cited_half_life;
            
            if($score)$data->jcrdata->score=$score;
            if($article_influence)$data->jcrdata->article_influence=$article_influence;
            
            $data->save();
            return response()->json(["exito"=>"Registro guardado."]);
        }
        return response()->json(["error"=>"La peticion debe aceptar json y enviar json"]);
    }
    
    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        \App\FactorImpact::destroy($id);
        return response()->json(['exito'=>'El registro fue eliminado.']);
    }
}
