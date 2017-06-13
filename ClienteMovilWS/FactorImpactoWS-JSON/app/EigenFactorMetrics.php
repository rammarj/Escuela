<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class EigenFactorMetrics extends Model
{
    //
    protected $table = "eigenfactor_metrics";
    protected $guarded = ['id'];
    protected $hidden = ['id'];
    
    public function factor_impact()
    {
        return $this->belongsTo('App\FactorImpact','id');
    }
}
