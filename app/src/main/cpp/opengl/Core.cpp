#include <iostream>
#include <string>

#include <unistd.h>

char *NORMALIZE_PATH(const char *file)
{
#if defined(GLES)
    return BASE_ASSET_PATH + file;
    char *out = (char *)malloc(sizeof(BASE_ASSET_PATH) + sizeof(file) * 1);
    return out;
#else
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));

    char *out = (char *)malloc(sizeof(cwd) + sizeof(file) * 1);
    sprintf(out, "%s\\assets\\%s", cwd, file);
    return out;
#endif
}