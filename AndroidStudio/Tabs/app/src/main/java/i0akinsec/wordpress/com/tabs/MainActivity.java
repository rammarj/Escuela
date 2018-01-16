package i0akinsec.wordpress.com.tabs;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TabHost;

public class MainActivity extends AppCompatActivity {

    TabHost tabHost;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tabHost = (TabHost) findViewById(R.id.tabhost);
        tabHost.setup();

        TabHost.TabSpec spec = tabHost.newTabSpec("TAB 1");
        spec.setIndicator("TAB 1");
        spec.setContent(R.id.layout1);
        tabHost.addTab(spec);

        spec = tabHost.newTabSpec("TAB 2");
        spec.setIndicator("TAB 2");
        spec.setContent(R.id.layout2);
        tabHost.addTab(spec);


    }
}
