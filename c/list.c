/* Linked list example */

#include <stdio.h>
#include <stdlib.h> /* for malloc() */

typedef struct
{
  int id;
  struct data *prev;
  struct data *next;
} data;

data *new_node(int *count)
{
  data *node = (data *)malloc(sizeof(data));
  char error_message[64];

  if(node == NULL)
  {
    sprintf(error_message, "Failed to allocate memory for node #%d!\n", *count);
    perror(error_message);
    exit(1);
  }

  node->id = *count;
  node->prev = NULL;
  node->next = NULL;

  *count += 1;

  return node;
}

void append_node(data *head, data *node)
{
  while(head->next != NULL)
    head = head->next;

  head->next = node;

  return;
}

void print_list(data *head)
{
  while(head->next != NULL)
  {
    printf("%d\n", head->id);
    head = head->next;
  }
  printf("%d\n", head->id);

  return;
}

int main()
{
  data *head = NULL; /* front of the list */
  data *new = NULL;
  int count = 0;
  int i = 0;

  head = new_node(&count);

  for(i = 0; i < 10; i++)
  {
    new = new_node(&count);
    append_node(head, new);
  }

  print_list(head);

  return 0;
}
