#include <iostream>
#include <string>

#if defined(GLES)
    #include <GLES2/gl2.h>
    #include <GLES2/gl2ext.h>
    #include <android/log.h>
    #include <jni.h>

    #define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
    #define BASE_ASSET_PATH "/data/user/0/org.raydelto.md2loader/files/"
#else
    #include <epoxy/gl.h>
    #include <GLFW/glfw3.h>
    // #include <windows.h>
    #include <unistd.h>

    #define LOGE(...)
#endif

char *NORMALIZE_PATH(const char *file);