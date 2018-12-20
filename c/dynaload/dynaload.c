/* Demonstrates the loading and reloading of dynamic modules */

#include <dlfcn.h>   /* dlopen(), dlerror(), dlsym(), dlclose() */
#include <stdbool.h>
#include <stdint.h>  /* SIZE_MAX */
#include <stdio.h>   /* fprintf(), printf(), fgets(), puts() */
#include <stdlib.h>  /* atoi(), exit() */
#include <string.h>  /* strcspn(), strcpy(), strlen() */

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
  if(lf->sum)
  {
    printf("\nAlready loaded: %s\n", lib_name);
    return;
  }

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

  printf("\nLoaded: %s\n", lib_name);

  return;
}

void unload_lib(lib_funcs *lf, void **lib_handle, const char *lib_name)
{
  if(!lf->sum)
  {
    printf("\nAlready unloaded: %s\n", lib_name);
    return;
  }

  if(lib_handle)
    dlclose(&lib_handle);
  lib_handle = NULL;
  lf->sum = NULL;
  lf->half = NULL;
  lf->print_message = NULL;
  printf("\nUnloaded: %s\n", lib_name);
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

/* Automatically expands to accommodate user input. Caller must free() returned pointer. */
char *get_input()
{
  char input[64];
  char *new_input = NULL;
  char *tmp_input = NULL;
  size_t input_length = 0;
  size_t full_length = 0;

  while(fgets(input, sizeof(input), stdin))
  {
    input_length = strlen(input);
    if(SIZE_MAX - input_length - 1 < full_length)
      break;

    tmp_input = realloc(new_input, full_length + input_length + 1);
    if(tmp_input == NULL)
      break;
    new_input = tmp_input;

    strcpy(new_input + full_length, input);
    full_length += input_length;
    if(feof(stdin) || input[input_length-1] == '\n')
      return new_input;
  }
  free(new_input);
  return "";
}

/* Ensure input is numeric except for trailing character */
bool validate_input(char *input)
{
  int i = 0;
  for(i = 0; i < strlen(input) - 1; i++)
  {
    if(!isdigit(input[i]))
      return false;
  }
  return true;
}

/* Automatically test the library functions */
void auto_test_lib(lib_funcs *lf)
{
  if(lf->sum)
  {
    printf("sum(5, 7) = %d\n", lf->sum(5, 7));
    printf("half(360) = %.2f\n", lf->half(360));
    printf("print_message(\"Hi!\") = ");
    lf->print_message("Hi!");
  }
  else
    puts("Library not loaded!");
  return;
}

/* Manually test the library functions */
void man_test_lib(lib_funcs *lf)
{
  char *input = "";
  int x = 0, y = 0;

  if(lf->sum)
  {
    puts("Notice: Invalid input will be considered zero.");

    printf("Enter a number (x) to sum: ");
    input = get_input();
    x = atoi(input);
    free(input);
    printf("Enter another number (y) to sum: ");
    input = get_input();
    y = atoi(input);
    free(input);
    printf("sum(%d, %d) = %d\n\n", x, y, lf->sum(x, y));

    printf("Enter a number to half: ");
    input = get_input();
    x = atoi(input);
    free(input);
    printf("half(%d) = %.2f\n\n", lf->half(x));

    printf("Enter a string to print: ");
    input = get_input();
    input[strcspn(input, "\n")] = 0; /* remove trailing newline */
    printf("print_message(\"%s\") = ", input);
    lf->print_message(input);
    free(input);
  }
  else
    puts("Library not loaded!");
  return;
}

void menu(lib_funcs *lf, void **lib_handle, const char *lib_name)
{
  char *input = "";

  while(atoi(input) != 5)
  {
    puts("\nDynaLoad Control Center");
    puts("-----------------------\n");
    printf("1. Unload %s\n", lib_name);
    printf("2. Load %s\n", lib_name);
    printf("3. Automatically test %s functions\n", lib_name);
    printf("4. Manually test %s functions\n", lib_name);
    puts("5. Quit\n");
    printf("> ");
    input = get_input();
    if(!validate_input(input))
    {
      puts("\nPlease enter a valid number!");
      free(input);
      continue;
    }
    switch(atoi(input))
    {
      case 1:
        unload_lib(lf, lib_handle, lib_name);
        break;
      case 2:
        if(lib_handle)
          dlclose(&lib_handle);
        load_lib(lf, lib_handle, lib_name);
        break;
      case 3:
        puts("");
        auto_test_lib(lf);
        break;
      case 4:
        puts("");
        man_test_lib(lf);
        break;
      case 5:
        dlclose(&lib_handle);
        free(input);
        puts("\nGoodbye!\n");
        exit(0);
        break;
      default:
        puts("\nPlease enter a valid number!");
        break;
    }
    free(input);
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
