package com.example.machao.myndksecrecy;

/**
 * Created by 0.0 on 2017/8/23.
 */

public class Secrety {
    static {
        System.loadLibrary("bsdiff");
    }

    public static native String getSecrety();
}
