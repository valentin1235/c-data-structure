
#include <stdio.h>

typedef enum {
    FALSE = 0,
    TRUE = 1
} Bool;

/* node.h */
typedef struct list_node {
    int value;
    struct list_node* next;
} list_node_t;

typedef struct node {
    char* key;
    int value;
    struct node* next;
} node_t;

/* hashmap.h */
typedef struct hashmap {
    size_t (*hash_func)(const char* key);
    node_t** plist;
    size_t length;
} hashmap_t;

hashmap_t* init_hashmap_malloc(size_t length, size_t (*p_hash_func)(const char* key));
int add_key(hashmap_t* hashmap, const char* key, const int value);
int get_value(const hashmap_t* hashmap, const char* key);
int update_value(hashmap_t* hashmap, const char* key, const int value);
int remove_key(hashmap_t* hashmap, const char* key);
void destroy(hashmap_t* hashmap);

/* linkedlist.h */
Bool add_ordered(list_node_t** head, int value);
Bool add_at(list_node_t** head, size_t index, int value);
Bool remove_last(list_node_t** head);
Bool remove_at(list_node_t** head, size_t index);
void print_node(list_node_t** head);

/* queue.h */
#define QUEUE_SIZE (10)
typedef struct myqueue {
    int front;
    int back;
    size_t value_count;
    int values[QUEUE_SIZE];
} myqueue_t;

void enqueue(myqueue_t* queue, int value);
int dequeue(myqueue_t* queue);

/* stack.h */
#define STACK_SIZE (10)
typedef struct {
    size_t value_count;
    int values[STACK_SIZE];
} mystack_t;

void push(mystack_t* stack, int value);
int pop(mystack_t* stack);