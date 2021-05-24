/*
 * @lc app=leetcode id=981 lang=c
 *
 * [981] Time Based Key-Value Store
 */

#include <stdio.h>
#include <stdlib.h>
#include <uthash.h>

// @lc code=start

// Linked list for value-timestamp pair
struct PairNode {
    char*            value;
    int              timestamp;
    struct PairNode* next;
};

// hash node
struct HashNode {
    char*            key;
    struct PairNode* head;
    UT_hash_handle   hh;
};

typedef struct {
    struct HashNode* hashHead;
} TimeMap;

/** Initialize your data structure here. */

TimeMap* timeMapCreate() {
    TimeMap* ret  = malloc(sizeof *ret);
    ret->hashHead = NULL;
    return ret;
}

void timeMapSet(TimeMap* obj, char* key, char* value, int timestamp) {
    struct HashNode* s;
    HASH_FIND_STR(obj->hashHead, key, s);
    if (s == NULL) {
        // new key, new linked list
        s                  = malloc(sizeof(*s));
        s->key             = key;
        s->head            = malloc(sizeof(struct PairNode));
        s->head->value     = value;
        s->head->timestamp = timestamp;
        s->head->next      = NULL;
        HASH_ADD_STR(obj->hashHead, key, s);
    } else {
        // existing key, insert in front of the list
        struct PairNode* ptr = malloc(sizeof *ptr);
        ptr->value           = value;
        ptr->timestamp       = timestamp;
        ptr->next            = s->head;
        s->head              = ptr;
    }
}

char* timeMapGet(TimeMap* obj, char* key, int timestamp) {
    struct HashNode* s;
    HASH_FIND_STR(obj->hashHead, key, s);
    if (s != NULL) {
        for (struct PairNode* ptr = s->head; ptr != NULL; ptr = ptr->next) {
            if (ptr->timestamp <= timestamp)
                return ptr->value;
        }
    }
    return "";
}

void timeMapFree(TimeMap* obj) {
    struct HashNode *curr, *tmp;
    HASH_ITER(hh, obj->hashHead, curr, tmp) {
        HASH_DEL(obj->hashHead, curr);
        while (curr->head != NULL) {
            struct PairNode* ptr = curr->head;
            curr->head           = curr->head->next;
            free(ptr);
        }
        free(curr);
    }
}

/**
 * Your TimeMap struct will be instantiated and called as such:
 * TimeMap* obj = timeMapCreate();
 * timeMapSet(obj, key, value, timestamp);

 * char * param_2 = timeMapGet(obj, key, timestamp);

 * timeMapFree(obj);
*/
// @lc code=end

int main(void) {
    TimeMap* obj = timeMapCreate();

    timeMapSet(obj, "foo", "bar", 1);
    puts(timeMapGet(obj, "foo", 1));
    puts(timeMapGet(obj, "foo", 3));
    timeMapSet(obj, "foo", "bar2", 4);
    puts(timeMapGet(obj, "foo", 4));
    puts(timeMapGet(obj, "foo", 5));

    return 0;
}
