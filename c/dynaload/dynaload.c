/* Demonstrates the loading and reloading of dynamic modules */

#include <dlfcn.h>  /* dlopen(), dlerror(), dlclose() */
#include <stdio.h>  /* fprintf(), printf(), fgets(), puts() */
#include <stdlib.h> /* atoi(), exit() */

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
  printf("sum(5, 7) = %d\n", lf->sum(5, 7));
  printf("half(360) = %.2f\n", lf->half(360));
  printf("print_message(\"Hi!\") = ");
  lf->print_message("Hi!");
}

void menu(lib_funcs *lf, void **lib_handle, const char *lib_name)
{
  char input[64];
  int c = 0;

  while(atoi(input) != 3)
  {
    puts("\nDynaLoad Control Center");
    puts("-----------------------\n");
    printf("1. Reload %s\n", lib_name);
    printf("2. Test %s functions\n", lib_name);
    puts("3. Quit\n");
    printf("> ");
    fgets(input, sizeof(input) / sizeof(char), stdin);
    switch(atoi(input))
    {
      case 1:
        dlclose(&lib_handle);
        load_lib(lf, lib_handle, lib_name);
        break;
      case 2:
        puts("");
        test_lib(lf);
        break;
      case 3:
        dlclose(&lib_handle);
        puts("\nGoodbye!\n");
        exit(0);
        break;
      default:
        puts("\nPlease enter a valid number!");
        break;
    }
  }
  return;
}

int main()
{
  const char *lib_name = "libexample.so";
  void **lib_handle = NULL;
  lib_funcs lf; /* struct containing function pointers */
  lib_funcs *lfp = &lf;

  load_lib(lfp, lib_handle, lib_name);
  //test_lib(lfp);
  menu(lfp, lib_handle, lib_name);
  //dlclose(&lib_handle);

  return 0;
}
