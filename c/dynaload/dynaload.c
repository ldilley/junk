/* Demonstrates the loading of dynamic modules */

#include <dlfcn.h>  /* dlopen(), dlerror(), dlclose() */
#include <stdio.h>  /* fprintf(), printf() */
#include <stdlib.h> /* exit() */

/* Data types to determine function in assign_func() */
enum data_type{INT, FLOAT, VOID};

/* Functions contained in the library */
typedef struct
{
  int (*sum)(int x, int y);
  float (*half)(int num);
  void (*print_message)(const char *message);
} lib_funcs;

void assign_func(lib_funcs *lf, void *lib_handle, enum data_type dt, const char *func_name);

void load_lib(lib_funcs *lf, void **lib_handle, const char *lib_name)
{
  lib_handle = dlopen(lib_name, RTLD_NOW); /* attempt to open library */
  if(!lib_handle)
  {
    fprintf(stderr, "dlopen(): %s\n", dlerror());
    exit(EXIT_FAILURE);
  }

  dlerror(); /* resets error string */

  /* Associate functions with library symbols */
  assign_func(lf, lib_handle, INT, "sum");
  assign_func(lf, lib_handle, FLOAT, "half");
  assign_func(lf, lib_handle, VOID, "print_message");

  return;
}

/* Uses dlsym() to tie function pointer to symbol address */
void assign_func(lib_funcs *lf, void *lib_handle, enum data_type dt, const char *func_name)
{
  const char *error_message = NULL;
  switch(dt)
  {
    case 0:
      lf->sum = (int (*)(int x, int y))dlsym(lib_handle, func_name);
      break;
    case 1:
      lf->half = (float (*)(int num))dlsym(lib_handle, func_name);
      break;
    case 2:
      lf->print_message = (void (*)(const char *message))dlsym(lib_handle, func_name);
      break;
    default:
      fprintf(stderr, "Corresponding function not found in assign_func()!");
      exit(EXIT_FAILURE);
      break;
  }

  error_message = dlerror();
  if(error_message)
  {
    fprintf(stderr, "dlsym(): %s\n", error_message);
    dlclose(lib_handle);
    exit(EXIT_FAILURE);
  }

  return;
}

/* Test the library functions */
void test_lib(lib_funcs *lf)
{
  printf("sum: %d\n", lf->sum(5, 7));
  printf("half: %.2f\n", lf->half(360));
  lf->print_message("Hi!");
}

int main()
{
  const char *lib_name = "libexample.so";
  void **lib_handle = NULL;
  lib_funcs lf; /* struct containing function pointers */
  lib_funcs *lfp = &lf;

  load_lib(lfp, lib_handle, lib_name);
  test_lib(lfp);
  dlclose(&lib_handle);

  return 0;
}
