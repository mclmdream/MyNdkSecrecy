#include "com_example_machao_myndksecrecy_Secrety.h"


JNIEXPORT jstring JNICALL  Java_com_example_machao_myndksecrecy_Secrety_getSecrety(JNIEnv *env, jobject thiz)  {
    return  (*env)->NewStringUTF(env, "www.baidu.com");;
}