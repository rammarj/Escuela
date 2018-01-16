package i0akinsec.wordpress.com.navigationviewsgo;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

/**
 * Created by RAMMARJ on 04/03/2017.
 */

public class Fragment1 extends Fragment {

    public Fragment1(){
    }

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_fragment1, container, false);
    }
}
