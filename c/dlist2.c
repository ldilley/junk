/* Doubly linked list example */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int id;
  struct data *prev;
  struct data *next;
} data;

data *new_node(data *head, int *count)
{
  data *new = (data *)malloc(sizeof(data));

  if(new == NULL)
  {
    perror("Could not allocate memory for new node!");
    exit(1);
  }

  new->id = *count;
  if(head == NULL)
    new->prev = NULL; /* unless not circular, point to rear of list */
  else
  {
    while(head->next != NULL)
      head = head->next;
    new->prev = head;
  }
  new->next = NULL;

  *count += 1;
  return new;
}

void print_nodes(data *head)
{
  while(head->next != NULL)
    printf("%d\n", head->id);
  printf("%d\n", head->id);   /* print last element */
  return;
}

int main()
{
  data *new = NULL;
  data *head = NULL;
  int count = 0;
  int i = 0;

  new = new_node(head, &count);
  head = new;
  for(i = 0; i < 10; i++)
    new = new_node(head, &count);

  print_nodes(head);

  return 0;
}
