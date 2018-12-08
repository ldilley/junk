/*
 * bytecrypt.c - single-byte key encryption/decryption example using XOR
 * Lloyd Dilley
 * 3/31/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if(argc == 1 || argc > 3)
  {
    puts("This program requires exactly 2 arguments: ./bytechar <plaintext/ciphertext> <1-byte key>");
    exit(1);
  }

  /*
   * argv[0] = program name
   * argv[1] = plaintext or ciphertext
   * argv[2] = 1-byte key
   */
  int i = 0;
  int text_length = strlen(argv[1]);
  char text[text_length];

  for(i = 0; i < text_length; i++)
  {
    /* This is where the magic happens. All characters in the plaintext string are XOR'd by the 1-byte key and stored in the text array. */
    text[i] = argv[2][0] ^ argv[1][i];
  }

  printf("%s\n", text);

  return 0;
}
