//
//  trie.c
//  wordPuzzle
//
//  Created by Selin Ersev on 7.11.2017.
//  Copyright © 2017 Selin Ersev. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "trie.h"

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define INDEX_TO_CHAR(i) (i + (int)'a')




void insert(struct TrieNode *root,char *key)
{
    int level;
    int length = (int)strlen(key);
    int index;
    
    struct TrieNode *p = root;

    //printf(" string '%s'",key);
    
    for (level = 0; level < length; level++)
    {
        //printf("char %c",key[level]);

        index = CHAR_TO_INDEX(key[level]);
        //printf("index %d\n",index);
        if (!p->children[index]){
            p->children[index] = (struct TrieNode *)malloc(sizeof(struct TrieNode));
        }
        //printf("index %d\n",index);

        //if(p->children[index] == NULL){
        //    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
        //}

        p = p->children[index];
        //if(p == NULL){
        //    printf("bbbbbbbbbbbbbbbbbbbbbb");
        //}
    }
        p->aWord = true;
}

bool search(struct TrieNode *root,char *key)
{
    int level;
    int length = (int)strlen(key);
    int index;
    
    struct TrieNode *p = root;
    
    
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!p->children[index]){
            return false;
        }
        
        p = p->children[index];
    }
    if (p->aWord == true) {
        return p->aWord;
    }
    

    return true;
}
