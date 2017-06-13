<?php

namespace App;

use Illuminate\Database\Eloquent\Model;

class JCRData extends Model
{
    //
    protected $table = "jcrdata";
    protected $guarded = ['id'];
    protected $hidden = ['id'];
    
    public function factor_impact()
    {
        return $this->belongsTo('App\FactorImpact','id');
    }
    
}
