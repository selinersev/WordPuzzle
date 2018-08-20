//
//  Header.h
//  wordPuzzle
//
//  Created by Selin Ersev on 10.10.2017.
//  Copyright © 2017 Selin Ersev. All rights reserved.
//

#ifndef Header_h
#define Header_h


#endif /* Header_h */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>


struct puzzlewords {
    char word [6];
    int valid;
    struct puzzlewords *next;
};

void AddNewWord(char []);
void PrintAllWords();
char getRandomCharacter();
void createRandomPuzzle();
void printPuzzleMatris();
void traverse(int x,int y,int depth,char *carried_string,int been_there[6][6]);
