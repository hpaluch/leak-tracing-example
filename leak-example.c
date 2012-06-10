/*
 * Simple leaky program to demonstrate mtrace capabilities
 * Copyright (C) Henryk Paluch, 2012
 * Licensed as Public Domain
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include <mcheck.h>


int main(int argc, char **argv)
{
  char * leak = NULL;
  
  /* trace starts */
  mtrace();

  leak = (char*)malloc(10);
  strcpy(leak,"Data1");
  printf("test: %s\n",leak);

  /* THIS IS LEAK - now we are unable to free first malloc() data ! */
  leak = (char*)malloc(10);
  strcpy(leak,"Data2");
  printf("test: %s\n",leak);

  /* this frees only second allocation */
  free(leak);

  /* trace ends */ 
  muntrace();
  return 0;
}
