<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class FactorImpact extends Model
{
    //
    protected $table = "factor_impact";
    protected $guarded = ['id'];
    protected $appends = ['jcrdata','eigen_factor_metrics'];
    
    public function jcrdata()
    {
        return $this->hasOne('App\JCRData','id','id');
    }
    
    public function eigenfactor_metrics()
    {
        return $this->hasOne('App\EigenFactorMetrics','id', 'id');
    }
    
    public function getJcrdataAttribute()
    {
        return JCRData::find($this->id);
    }
    
    public function getEigenfactorMetricsAttribute()
    {
        return EigenFactorMetrics::find($this->id);
    }
}
