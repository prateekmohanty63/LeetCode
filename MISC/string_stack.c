#include <stdlib.h>
#include <string.h>

/**
 * Type for individual stack entry
 */
struct stack_entry {
  char *data;
  struct stack_entry *next;
};

/**
 * Type for stack instance
 */
struct stack_t
{
  struct stack_entry *head;
  size_t stackSize;  // not strictly necessary, but
                     // useful for logging
};

/**
 * Create a new stack instance
 */
struct stack_t *newStack(void)
{
  struct stack_t *stack = malloc(sizeof *stack);
  if (stack)
  {
    stack->head = NULL;
    stack->stackSize = 0;
  }
  return stack;
};

/**
 * Make a copy of the string to be stored (assumes
 * strdup() or similar functionality is not
 * available
 */
char *copyString(char *str)
{
  char *tmp = malloc(strlen(str) + 1);
  if (tmp)
    strcpy(tmp, str);
  return tmp;
}

/**
 * Push a value onto the stack
 */
void push(struct stack_t *theStack, char *value)
{
  struct stack_entry *entry = malloc(sizeof *entry);
  if (entry)
  {
    entry->data = copyString(value);
    entry->next = theStack->head;
    theStack->head = entry;
    theStack->stackSize++;
  }
  else
  {
    // handle error here
  }
}

/**
 * Get the value at the top of the stack
 */
char *top(struct stack_t *theStack)
{
  if (theStack && theStack->head)
    return theStack->head->data;
  else
    return NULL;
}

/**
 * Pop the top element from the stack; this deletes both
 * the stack entry and the string it points to
 */
void pop(struct stack_t *theStack)
{
  if (theStack->head != NULL)
  {
    struct stack_entry *tmp = theStack->head;
    theStack->head = theStack->head->next;
    free(tmp->data);
    free(tmp);
    theStack->stackSize--;
  }
}

/**
 * Clear all elements from the stack
 */
void clear (struct stack_t *theStack)
{
  while (theStack->head != NULL)
    pop(theStack);
}

/**
 * Destroy a stack instance
 */
void destroyStack(struct stack_t **theStack)
{
  clear(*theStack);
  free(*theStack);
  *theStack = NULL;
}


int main(void)
{
  struct stack_t *theStack = newStack();
  char *data;

  int n;
  scanf("%d",&n);

   push(theStack,"-1");

  for(int i=0;i<n;i++)
  {
      char str[100];
      printf("Enter the name of the person: ");
      scanf("%s",&str);
      push(theStack,str);

  }

  char *da=top(theStack);

   while(da!="-1"){
    printf("%s",da);
    pop(theStack);
     char *da=top(theStack);
   }

  //push(theStack, "foo");
  //push(theStack, "bar");

  data = top(theStack);
  printf("%s",data);
  pop(theStack);

  clear(theStack);
  destroyStack(&theStack);

}
