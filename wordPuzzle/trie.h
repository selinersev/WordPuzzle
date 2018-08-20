//
//  trie.h
//  wordPuzzle
//
//  Created by Selin Ersev on 9.11.2017.
//  Copyright © 2017 Selin Ersev. All rights reserved.
//

#ifndef trie_h
#define trie_h
#define ALPHABET_SIZE (26)
#include <stdbool.h>

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    char c; // unnecessary ?
    bool aWord;
};

void insert(struct TrieNode *root,char *key);
bool search(struct TrieNode *root,char *key);

#endif /* trie_h */
