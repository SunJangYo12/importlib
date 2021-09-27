#include <stdlib.h>
#include <dlfcn.h>
#define IMPORTGL_NO_FNPTR_DEFS
#define IMPORTGL_API
#define IMPORTGL_FNPTRINIT = NULL
#include "importlib.h"

static void *handler = NULL;


/* Imports function pointers to selected function calls in OpenGL ES Common
 * or Common Lite profile DLL or shared object. The function pointers are
 * stored as global symbols with equivalent function name but prefixed with
 * "funcPtr_". Standard gl/egl calls are redirected to the function pointers
 * with preprocessor macros (see importgl.h).
 */
int importLibInit()
{
    int result = 1;

    handler = dlopen("./libtes.so", RTLD_NOW);
    if (handler == NULL) {
        return 0;
    }

#define IMPORT_FUNC(funcName) do { \
        void *procAddress = (void *)dlsym(handler, #funcName); \
        if (procAddress == NULL) result = 0; \
        *((void **)&FNPTR(funcName)) = procAddress; } while (0)

    IMPORT_FUNC(jumlah);

    return result;
}


void importLibDeinit()
{

    dlclose(handler);
}
