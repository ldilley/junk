#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int id;
  float balance;
  char owner[32];
} account;

int main()
{
  int i;
  FILE *file;
  account acct;
  account accounts[3];

  file = fopen("accounts.dat", "r+b");

  if(file == NULL)
  {
    puts("Unable to open accounts.dat for reading!");
    exit(1);
  }

  for(i = 0; i < 3; i++)
  {
    fread(&acct, sizeof(account), 1, file);
    printf("%i %.2f %s\n", acct.id, acct.balance, acct.owner);
  }

  fclose(file);

  return 0;
}
