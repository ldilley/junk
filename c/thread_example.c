/* Compile with: gcc thread_example.c -o thread_example -lpthread */

#include <pthread.h>
#include <stdio.h>

void *print_id(void *id)
{
  int i = 0;

  printf("ID: %s\n", (const char *)id);
  sleep(1);

  return;
}

int main()
{
  pthread_t thread1 = NULL;
  pthread_t thread2 = NULL;

  pthread_create(&thread1, NULL, print_id, "foo");
  pthread_create(&thread2, NULL, print_id, "bar");
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0;
}
