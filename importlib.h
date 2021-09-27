#ifndef IMPORTLIB_H_INCLUDED
#define IMPORTLIB_H_INCLUDED

extern int importLibInit();
extern void importLibDeinit();

#ifndef IMPORTGL_API
#define IMPORTGL_API extern
#endif
#ifndef IMPORTGL_FNPTRINIT
#define IMPORTGL_FNPTRINIT
#endif

#define FNDEF(retType, funcName, args) IMPORTGL_API retType (*funcPtr_##funcName) args IMPORTGL_FNPTRINIT

FNDEF(int, jumlah, (int a, int b));

#undef FN
#define FNPTR(name) funcPtr_##name

#ifndef IMPORTGL_NO_FNPTR_DEFS
// Redirect jumlah* function calls to jumlah*.
#define jumlah             FNPTR(jumlah)
#endif // !IMPORTGL_NO_FNPTR_DEFS


#endif // !IMPORTGL_H_INCLUDED
