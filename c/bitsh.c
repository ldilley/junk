/*
 * bitsh.c - "bitch" pseudo shell
 * Last update: 09/21/2006
 * Author: Lloyd Dilley <lloyd@dilley.me>
 * Description: This small program emulates a user's login shell, but with a twist.
 *              Replace the user's shell in /etc/passwd or add the program to the
 *              target user's shell initialization file. Next time the user logs
 *              in, they will be using this pseudo shell which will (hopefully)
 *              aggravate them with a high chance of fake errors leading them to
 *              believe that something is wrong with the system. Some commands
 *              will actually go through to be successfully processed. Have fun! :)
 * License: You may freely distribute this program source code, the compiled program,
 *          and do the same with derivative works with the condition that this license
 *          and the above information in the header (authors, description, and notice)
 *          of this source program, bitsh.c, must be kept intact. Furthermore, if you
 *          find this software useful in some way, you can thank the author by buying
 *          him a beer if you ever meet up.
 */

#include <signal.h>              /* needed to handle SIGINT -- we don't want users breaking out with ctrl+c. :P */
#include <stdio.h>               /* printf(), scanf() and system() */
#include <stdlib.h>              /* NULL and rand() */
#include <string.h>              /* strlen() and strncpy() */
#include <unistd.h>              /* gethostname() */

#define MAX_CHANCE 100           /* the maximum percent chance that PERCENT_CHANCE is calculated out of */
#define PERCENT_CHANCE 40        /* the percent chance that any given command will fail with a fake error */
#define ERROR_COUNT 9            /* the amount of error strings in the error_string array */
#define ERROR_LENGTH 64          /* maximum length of error strings in the error_string array */
#define COMMAND_LENGTH 128       /* maximum length of strings accepted in our pseudo shell as commands */
#define HOSTNAME_LENGTH 255      /* maximum length of system hostname */
#define BOGUS_USERNAME "user"    /* username to use for the shell prompt if it cannot be set */
#define BOGUS_HOSTNAME "host"    /* hostname to use for the shell prompt if it cannot be set */
#define BOGUS_HOSTNAME_LENGTH 4  /* number of characters in BOGUS_HOSTNAME */

int main(void)
{
  /* You can put your own custom error messages into the array below (don't forget to update ERROR_COUNT!) */
  char error_string[ERROR_COUNT][ERROR_LENGTH] = {
  "I/O error.",
  "Invalid command.",
  "No such process.",
  "Permission denied.",
  "Interrupted system call.",
  "Operation not permitted.",
  "Kernel module not loaded.",
  "No such file or directory.",
  "Stack overflow (core dumped)" };

  int i, x;                                /* holds rand() integers */  
  char command[COMMAND_LENGTH];            /* holds the command typed in the pseudo shell */
  char hostname[HOSTNAME_LENGTH];          /* holds the system hostname used to populate the shell prompt */
  char *username = NULL;                   /* holds the username of the user to populate the shell prompt */

  /* Set the system hostname or set a bogus one if not able. */
  if(gethostname(hostname, sizeof(hostname)) != 0)
    strncpy(hostname, BOGUS_HOSTNAME, BOGUS_HOSTNAME_LENGTH + 1); /* Add 1 to append the null terminator. */
  hostname[sizeof(hostname) - 1] = '\0';

  /* Set the user's username if able. */
  username = getenv("LOGNAME");

  /* If the username was not able to be set above, use a bogus one. */
  if(username == NULL || strlen(username) == 0)
    username = BOGUS_USERNAME;

  for(;;)                                  /* infinite loop to keep the user inside the pseudo shell forever */
  {
    signal(SIGINT, SIG_IGN);               /* ignore ctrl+c */
    printf("%s@%s$ ", username, hostname); /* set the pseudo shell prompt */
    fgets(command, COMMAND_LENGTH, stdin); /* grab whatever they typed in the psuedo shell */
    i = rand() % MAX_CHANCE;               /* set the generated numbers to be from 0-99 (100 possible values) */

    /* If the number generated is over 40 (default), the command will be successful 60% (default) of the time. */
    if(i > PERCENT_CHANCE)                 /* PERCENT_CHANCE out of MAX_CHANCE the command will fail */
    {
      system(command);                     /* let the operating system handle the user-provided command */
    }
    else
    {
      x = rand() % ERROR_COUNT;            /* pick a random error message from the error_string array */
      printf("%s\n", error_string[x]);     /* display the random error string */
    }
  }
  return 0;
}
