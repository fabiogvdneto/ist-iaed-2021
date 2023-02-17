#define INITIAL_CAPACITY 4

typedef struct {
    int *v;     /* contents of the stack */
    int cap;    /* capacity of v, i.e. how many elements can fit in v */
    int sz;     /* number of elements currently stored in v */
} stack;

stack* build();                 /* builds a new empty stack with initial capacity 4 */
void push(stack * s, int e);    /* pushes integer e on top of the stack  (reallocate v if necessary) */
int top(stack * s);             /* returns top element in the stack */
int pop(stack * s);             /* removes top element from the stack and return it
                                    (not necessary to reallocate v) */
int is_empty(stack * s);        /* returns 1 iff s represents the empty stack, returns 0 otherwise */
void destroy(stack * s);		/* frees the memory associated with the stack */
