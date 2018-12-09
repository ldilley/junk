#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  account accounts[3];

  accounts[0].id = 100;
  accounts[0].balance = 500.00;
  strcpy(accounts[0].owner, "John Dough");

  accounts[1].id = 101;
  accounts[1].balance = 75.50;
  strcpy(accounts[1].owner, "Foo Bar");

  accounts[2].id = 102;
  accounts[2].balance = -1.00;
  strcpy(accounts[2].owner, "William Gates");

  file = fopen("accounts.dat", "w+b");

  if(file == NULL)
  {
    puts("Unable to open accounts.dat for writing!");
    exit(1);
  }

  for(i = 0; i < 3; i++)
  {
    fwrite(&accounts[i], sizeof(account), 1, file);
  }

  fclose(file);

  return 0;
}
