/* Doubly linked list example */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int id;
  struct data *next;
  struct data *prev;
} data;

data *new_node(data *node)
{
  node = (data *)malloc(sizeof(data));
  return node;
}

void append_node(data *head, data *node)
{
  while(head->next != NULL)
    head = head->next;
  node->prev = head;
  head->next = node;
  return;
}

void display_list(data *list)
{
  while(list->next != NULL)
  {
    printf("%d\n", list->id);
    list = list->next;
  }
  printf("%d\n", list->id); /* print last node */

  /* Now do it in reverse... */
  while(list->prev != NULL)
  {
    printf("%d\n", list->id);
    list = list->prev;
  }
  printf("%d\n", list->id); /* print first/head node */
  return;
}

void free_list(data *list)
{
  data *next;
  while(list->next != NULL)
  {
    next = list->next;
    free(list);
    list = next;
  }
  free(list);
  return;
}

int main()
{
  int i = 0;
  data *new;
  data *head;

  for(i = 0; i < 10; i++)
  {
    new = new_node(new);
    if(i == 0)
    {
      head = new;
      head->prev = NULL;
    }
    new->id = i;
    if(i > 0)
      append_node(head, new);
  }

  display_list(head);
  free_list(head);

  return 0;
}
