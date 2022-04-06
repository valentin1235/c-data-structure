#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"
#include "hashmap.h"

#define DEFAULT_ARRAY_LENGTH (20)

static size_t hash_function(const char* key);


static void linkedlist_test(void)
{
    list_node_t* head = NULL;

    add_ordered(&head, 100);
    add_ordered(&head, 200);
    add_ordered(&head, 150);
    add_ordered(&head, 50);
    print_node(&head);

    assert(add_at(&head, 5, 124) == FALSE);
    assert(add_at(&head, 4, 124) == TRUE);

    print_node(&head);

    remove_at(&head, 1);
    print_node(&head);

    remove_last(&head);
    remove_last(&head);
    remove_last(&head);
    remove_last(&head);
    
    print_node(&head);

    assert(remove_last(&head) == FALSE);
    assert(head == NULL);
}

static void test_hashcollision(void)
{
    hashmap_t* hashmap = init_hashmap_malloc(2, hash_function);

    assert(add_key(hashmap, "key2", 99) == TRUE);
    assert(add_key(hashmap, "key4", 100) == TRUE);
    assert(add_key(hashmap, "key6", 100) == TRUE);
}

static void test_init_hashmap_malloc(void)
{
    hashmap_t* hashmap = init_hashmap_malloc(100, hash_function);

    assert(hashmap->length == 100);
    assert(hashmap->hash_func == &hash_function);
    assert(hashmap->plist != NULL);

    destroy(hashmap);
}

static void test_add_key(void)
{
    hashmap_t* hashmap = init_hashmap_malloc(100, hash_function);

    assert(add_key(hashmap, "key1", 10) == TRUE); /* TRUE */
    assert(add_key(hashmap, "key1", 13) == FALSE); /* FALSE */
    assert(add_key(hashmap, "key1", 10) == FALSE); /* FALSE */

    assert(add_key(hashmap, "key2", 99) == TRUE);
    assert(add_key(hashmap, "key3", 100) == TRUE);
    assert(add_key(hashmap, "key4", 101) == TRUE);
    assert(add_key(hashmap, "key5", 102) == TRUE);

    assert(get_value(hashmap, "key1") == 10);
    assert(get_value(hashmap, "key2") == 99);
    assert(get_value(hashmap, "key3") == 100);
    assert(get_value(hashmap, "key4") == 101);
    assert(get_value(hashmap, "key5") == 102);

    destroy(hashmap);
}

static void test_get_value(void)
{
    hashmap_t* hashmap = init_hashmap_malloc(100, hash_function);

    assert(add_key(hashmap, "key1", 21) == TRUE);

    assert(get_value(hashmap, "key1") == 21); /* 21 */

    destroy(hashmap);
}

static void test_update_value(void)
{
    hashmap_t* hashmap = init_hashmap_malloc(100, hash_function);

    assert(update_value(hashmap, "key1", 12) == FALSE); /* FALSE */

    assert(get_value(hashmap, "key1") == -1); /* -1 */

    assert(add_key(hashmap, "key1", 10) == TRUE);

    assert(update_value(hashmap, "key1", 12) == TRUE); /* TRUE */

    assert(get_value(hashmap, "key1") == 12); /* 12 */

    destroy(hashmap);
}

static void test_remove_key(void)
{
    hashmap_t* hashmap = init_hashmap_malloc(2, hash_function);

    assert(remove_key(hashmap, "key1") == FALSE);

    assert(add_key(hashmap, "key1", 98) == TRUE);
    assert(remove_key(hashmap, "key1") == TRUE);
    assert(get_value(hashmap, "key1") == -1);

    assert(add_key(hashmap, "key2", 98) == TRUE);
    assert(add_key(hashmap, "key4", 100) == TRUE);
    assert(add_key(hashmap, "key6", 102) == TRUE);

    assert(get_value(hashmap, "key2") == 98);
    assert(get_value(hashmap, "key4") == 100);
    assert(get_value(hashmap, "key6") == 102);

    assert(remove_key(hashmap, "key4") == TRUE);
    assert(remove_key(hashmap, "key6") == TRUE);
    assert(remove_key(hashmap, "key2") == TRUE);

    destroy(hashmap);
}

static void test_destroy(void)
{
    hashmap_t* hashmap = init_hashmap_malloc(100, hash_function);

    assert(add_key(hashmap, "key1", 98) == TRUE);
    assert(add_key(hashmap, "key2", 99) == TRUE);
    assert(add_key(hashmap, "key3", 100) == TRUE);
    assert(add_key(hashmap, "key4", 101) == TRUE);
    assert(add_key(hashmap, "key5", 102) == TRUE);

    destroy(hashmap);
}

static void wiki_test(void)
{
    size_t i = 0;
    hashmap_t* hashmap = NULL;

    hashmap = init_hashmap_malloc(DEFAULT_ARRAY_LENGTH, hash_function);

    for (i = 0; i < 100; i++) {
        char key[100];
        int value = (int)i;
        int c;
        int dummy = 512;

        sprintf(key, "key%lu", i);

        assert(add_key(hashmap, key, value) == TRUE);

        c = get_value(hashmap, key);
        assert(c == value);

        assert(add_key(hashmap, key, dummy) == FALSE);

        c = get_value(hashmap, key);
        assert(c == value);
    }

    for (i = 0; i < 100; i++) {
        char key[100];
        int value = (int)(i * i * i);
        int c;

        sprintf(key, "key%lu", i);

        assert(update_value(hashmap, key, value) == TRUE);
        c = get_value(hashmap, key);

        assert(c == value);
    }

    for (i = 0; i < 100; i++) {
        char key[100];
        int c;

        sprintf(key, "key%lu", i);

        assert(remove_key(hashmap, key) == TRUE);
        c = get_value(hashmap, key);

        assert(c == -1);

        assert(remove_key(hashmap, key) == FALSE);
    }

    for (i = 0; i < DEFAULT_ARRAY_LENGTH; i++) {
        assert((hashmap->plist)[i] == NULL);
    }

    destroy(hashmap);
}

int main(void)
{
    linkedlist_test();

    test_init_hashmap_malloc();
    test_add_key();
    test_get_value();
    test_update_value();
    test_remove_key();
    test_destroy();
    wiki_test();
    test_hashcollision();

    return 0;
}

/*
static size_t hash_function(const char* key)
{
    size_t code = 0;
    const char* c = key;

    while (*c != '\0') {
        code += *c++;
    }

    return code;
}
*/



static size_t hash_function(const char* key)
{
	size_t hash;
    const char* p  = key;
	
	hash = 0;
    while (*p != '\0') {
        hash = 65599 * hash + *p;
        ++p;
    }

	return hash ^ (hash >> 16);
}

