#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "hashmap.h"

static node_t* get_node_or_null(node_t** phead, const char* str)
{
    node_t** pp = phead;
    while (*pp != NULL) {
        if (strcmp((*pp)->key, str) == 0) {
            break;
        }
        pp = &(*pp)->next;
    }

    return *pp;
}

hashmap_t* init_hashmap_malloc(size_t length, size_t (*p_hash_func)(const char* key))
{
    hashmap_t* hashmap = malloc(sizeof(hashmap_t));

    hashmap->hash_func = p_hash_func;
    hashmap->length = length;
    hashmap->plist = malloc(sizeof(node_t*) * length);

    memset(hashmap->plist, 0, sizeof(node_t*) * length);

    return hashmap;
}

int add_key(hashmap_t* hashmap, const char* key, const int value)
{
    unsigned int hashed = hashmap->hash_func(key) % hashmap->length;
    node_t* pa_node;
    node_t* cur_node;

    if (strcmp(key, "") == 0) {
        return FALSE;
    }

    pa_node = malloc(sizeof(node_t));
    pa_node->key = malloc(strlen(key) + 1);
    strcpy(pa_node->key, key);
    pa_node->value = value;
    pa_node->next = NULL;

    /* 1. 해시테이블에 매핑된 값이 없을 때 */
    if (hashmap->plist[hashed] == NULL) {
        hashmap->plist[hashed] = pa_node;
        return TRUE;
    }

    /* 2. 해시테이블에 매핑된 값이 있고, 지금 삽입하려는 키가 원래있는 키랑 같지않을때만 새로운 노드를 삽입 */
    cur_node = hashmap->plist[hashed];
    while (cur_node != NULL) {
        if (cur_node->next == NULL && strcmp(cur_node->key, key) != 0) {
            cur_node->next = pa_node;
            return TRUE;
        }
        cur_node = cur_node->next;
    }
    
    free(pa_node->key);
    free(pa_node);

    return FALSE;
}

int get_value(const hashmap_t* hashmap, const char* key)
{
    unsigned int hashed = hashmap->hash_func(key) % hashmap->length;
    node_t* head = hashmap->plist[hashed];
    node_t* node;

    if (head == NULL) {
        return -1;
    }

    node = get_node_or_null(&head, key);
    if (node == NULL) {
        return -1;
    }

    return node->value;
}

int update_value(hashmap_t* hashmap, const char* key, const int value)
{
    unsigned int hashed = hashmap->hash_func(key) % hashmap->length;
    node_t* head = hashmap->plist[hashed];
    node_t* node;

    if (head == NULL) {
        return FALSE;
    }

    node = get_node_or_null(&head, key);
    if (node == NULL) {
        return FALSE;
    }

    node->value = value;

    return TRUE;
}

int remove_key(hashmap_t* hashmap, const char* key)
{
    unsigned int hashed = hashmap->hash_func(key) % hashmap->length;
    node_t** pp = &hashmap->plist[hashed];
    node_t* trash;

    while (*pp != NULL) {        
        if (strcmp((*pp)->key, key) == 0) {
            break;
        }
        pp = &((*pp)->next);
    }

    if (*pp == NULL) {
        return FALSE;
    }

    trash = *pp;
    *pp = (*pp)->next;
    free(trash->key);
    free(trash);

    return TRUE;
}

void destroy(hashmap_t* hashmap)
{
    node_t** plist = hashmap->plist;
    size_t length = hashmap->length;
    size_t i;

    for (i = 0; i < length; ++i) {
        node_t* node = plist[i];
        while (node != NULL) {
            node_t* next = node->next;

            free(node->key);
            free(node);

            node = next;
        }
    }

    free(hashmap->plist);
    free(hashmap);
}
