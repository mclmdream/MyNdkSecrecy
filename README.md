# MyNdkSecrecy
ndk生成.so


# 编译ndk生成.so

### 目的：仅仅只是简单的实用ndk生成.so文件
### 效果：点击按钮button,调用.so文件的内容
### ndk版本：android-ndk-r13b
### 项目目录 如图：
![这里写图片描述](http://img.blog.csdn.net/20170823172325037?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvZmxvd2VybWFjaGFv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
1.首先看下代码
MainActivity:

```
public class MainActivity extends AppCompatActivity {
    private TextView textView;
    private Button button;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView=(TextView)findViewById(R.id.textview);
        button=(Button)findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textView.setText(Secrety.getSecrety()+"");
            }
        });

    }
}
```


activity_main:
```
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical"
    >

    <Button
        android:id="@+id/button"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:text="点击获取"
        />

    <TextView
        android:id="@+id/textview"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="dsds"
        />

</LinearLayout>
```
Secrety:
```
public class Secrety {
    static {
        System.loadLibrary("bsdiff");
    }

    public static native String getSecrety();
}
```

2.配置module的build.gradle:在defaultConfig中加,如图：
```
 ndk {
            moduleName = 'bsdiff'
            abiFilters "armeabi", "armeabi-v7a", "x86"
        }
```

![这里写图片描述](http://img.blog.csdn.net/20170823171647306?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvZmxvd2VybWFjaGFv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

3.打开studio中的terminal,生成Secrety这个类的头文件,网上很多资料,例如在Terminal中，切换到项目Java目录下执行“javah -jni 包名.类名”,如下图： 
![这里写图片描述](http://img.blog.csdn.net/20170823171743826?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvZmxvd2VybWFjaGFv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

4.在main下（注意必须是在main下，否则不能生成.so文件）新建jni目录，将Secrety这个类的头文件（就是生成的.h结尾的文件）移动到此文件夹下（移动或者不移动都可以）

5.写c文件,并且将c文件放入jni文件中，必须注意用红色的选中的部分,例如：

![这里写图片描述](http://img.blog.csdn.net/20170823171935877?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvZmxvd2VybWFjaGFv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
6.执行build-->Rebuild Project，可以在如图中找到.so文件

![这里写图片描述](http://img.blog.csdn.net/20170823172149990?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvZmxvd2VybWFjaGFv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

7.将.so文件复制到jniLibs中就可以使用了

8.可能会遇到的问题：


问题1：修改ndk版本，最好不要用studio自带的，我用的是android-ndk-r13b
![这里写图片描述](http://img.blog.csdn.net/20170823172701707?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvZmxvd2VybWFjaGFv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

问题2：在gradle.properties中加 android.useDeprecatedNdk=true
![这里写图片描述](http://img.blog.csdn.net/20170823172747124?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvZmxvd2VybWFjaGFv/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

