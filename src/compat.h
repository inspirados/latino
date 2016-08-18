/** Determina si el sistema es GNU */
#ifdef _WIN32
#define PATH_SEP "\\"
/* Visual Leak Detector for Visual C++ */
//#include <vld.h>
#define LAT_FUNC extern
#include <windows.h>
#include <limits.h>
#define snprintf(s, l, f, i) _snprintf(s, l, f, i)
#define getcwd(ruta, tamanio) GetCurrentDirectory (MAX_PATH, ruta);
#include "stdbool.h"
#else
#define PATH_SEP "/"
#define LAT_FUNC __attribute__((visibility("hidden"))) extern
#include <dlfcn.h>
#include <unistd.h>
#include <stdbool.h>
#endif

/** Determina el compilador*/
#if defined(__GNUC__)
#define lat_noret		void __attribute__((noreturn))
#elif defined(_MSC_VER) 
#define lat_noret		void __declspec(noreturn)
#else
#define lat_noret		void
#endif