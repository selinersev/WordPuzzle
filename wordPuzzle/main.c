//
//  main.c
//  wordPuzzle
//
//  Created by Selin Ersev on 10.10.2017.
//  Copyright © 2017 Selin Ersev. All rights reserved.
//
#include "trie.h"
#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define strlength 60
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct puzzlewords *head=NULL;
int ROWS = 6;
int COLUMNS = 6;
char puzzle[6][6];

int is_seeded = 0;
char getRandomCharacter()
{
    if(is_seeded == 0){
        int seed = (int)time(NULL);
        srand(seed);
        is_seeded = 1;
    }
    int x = (rand() % 26) + 65;
    
    return (char)x;
}
void createRandomPuzzle()
{
    int i , j;
    
    for(i = 0;i < ROWS;i++)
    {
        for(j = 0;j < COLUMNS;j++)
        {
            puzzle[i][j] = getRandomCharacter();
        }
    }
    
}

void printPuzzleMatris()
{
    int i , j;
    for(i = 0;i < ROWS;i++)
    {
        for(j = 0;j < COLUMNS;j++)
        {
            printf("%c",puzzle[i][j]);
        }
        printf("\n");
    }
    
}


void AddNewWord(char input_word[6]){
    
    struct puzzlewords *newword;
    
    newword = malloc (sizeof (struct puzzlewords));
    strcpy(newword->word,input_word);
    newword->valid=0;
    newword->next=NULL;
    
    if(head==NULL) head=newword;
    else {
        newword->next=head;
        head=newword;
    }
}

void AddNewWordEnd(char input_word[6]){
    
    struct puzzlewords *newword,*cur;
    
    newword = malloc (sizeof (struct puzzlewords));
    strcpy(newword->word,input_word);
    newword->valid=0;
    newword->next=NULL;
    
    if(head==NULL) head=newword;
    else {
        cur=head;
        while(cur->next!=NULL) cur=cur->next;
        cur->next=newword;
    }
}
void PrintAllWords(){
    
    struct puzzlewords *cur;
    
    cur=head;
    
    while(cur!=NULL){
        
        printf("Word: %s\n",cur->word);
        cur=cur->next;
        
    }
}

void addToTrie(){
    
    char *str = malloc(sizeof(char)*(strlength));
    char c ;
    FILE *file;
    int index=0, wordcount=0;
    
    struct TrieNode *root = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    
    
    file = fopen("/Users/selinersev/Desktop/Dersler/SystemProgramming/WordPuzzleAssignment/wordPuzzle/TurkishWords.txt", "r");
    
    if (file)
    {
        while ((c = getc(file)) != EOF)
        {
            //print the char to the screen
            putchar(c);
            
            if(c != '\n')
                str[index++] = c; //insert the char to the string
            
            if(c == '\n')
            {
                str[index++] = '\0'; //insert the end of string
                wordcount++;
                printf("the word#%d is '%s'\n",wordcount,str);
                
                insert(root,str);
                bool is_added = false;
                is_added = search(root, str);
                printf("%d\n",is_added);
                is_added = search(root, "asdf");
                printf("%d\n",is_added);
                free(str);
                str = malloc(sizeof(char)*(strlength));
                index=0;
                
            }
        }
        
        fclose(file);
        
    }
}
void traverse(int x,int y,int depth,char *carried_string,int been_there[6][6]){
    
    int new_x;
    int new_y;
    int copy_been_there[6][6];
    char* temp;
    
    if(depth > 5)
    {
        return;
    }
    
    been_there[x][y] = 1;
    depth += 1;
    int len = (int) strlen(carried_string);
    temp = (char*) malloc(sizeof(char)*(len+1+1));
    stpcpy(temp, carried_string);
    temp[len] = puzzle[x][y];

    //free(carried_string);
    
    AddNewWordEnd(temp);
    
    printf("%s\n",temp);
    
    for(int i=-1;i<2;i++){
        for(int j = -1; j < 2; j++){
            new_x = x +i;
            new_y = y +j;
            if(new_x<0 || new_x>5 || new_y<0 || new_y>5){
                continue;
            }
            else if (been_there[new_x][new_y] == 0){
                for (int a=0; a<6; a++) {
                    for (int b=0; b<6; b++) {
                        copy_been_there[a][b] = been_there[a][b];
                    }
                }
                traverse(new_x, new_y, depth,temp,copy_been_there);
            }
        }
    }
    
}


int main() {
    
    createRandomPuzzle();
    printPuzzleMatris();
    addToTrie();
    /*
    int been_there[6][6];
    
    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
            
            for (int k=0; k<6; k++) {
                for (int l=0; l<6; l++) {
                    been_there[k][l] = 0;
                }
            }
            
            traverse(i, j, 0, "", been_there);
        }
    }*/
}
