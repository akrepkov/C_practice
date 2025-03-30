// Assignment name  : g_diam
// Expected files   : *.c, *.h
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a programe that takes a string. This string represents a graph and is
// composed of series of links between this graph's nodes. Links are separated by
// a single space. Nodes are represented by numbers, and links by two nodes
// separated by a '-'. For exemple, if there is a link between nodes 2
// and 3, it could be written as "2-3" or "3-2".

// The program will display the number of nodes comprised in the longest chain,
// followed by a '\n', given it's impossible to pass through a node more than once.

// If the number of parameters is different from 1, the program displays a '\n'.

// Examples:

// $>./g_diam "17-5 5-8 8-2 2-8 2-8 17-21 21-2 5-2 2-6 6-14 6-12 12-19 19-14 14-42" | cat -e
// 10$
// $>./g_diam "1-2 2-3 4-5 5-6 6-7 7-8 9-13 13-10 10-2 10-11 11-12 12-8 16-4 16-11 21-8 21-12 18-10 18-13 21-18" | cat -e
// 15$


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char** parse_str(char* s) {
    int rows = 0, i = 0, j = 0;
    while (s[i] != '\0') {
        if (s[i] == ' ') rows++;
        i++;
    }
    rows++;
    char** res = (char**)malloc(sizeof(char*) * (rows + 1));
    if (!res) return NULL;

    i = 0;
    int row_index = 0;
    while (s[i] != '\0') {
        int mem_count = 0;
        while (s[i] != ' ' && s[i] != '\0') {
            mem_count++;
            i++;
        }
        res[row_index] = (char*)malloc(sizeof(char) * (mem_count + 1));
        int k = 0;
        while (k < mem_count) {
            res[row_index][k] = s[i - mem_count + k];
            k++;
        }
        res[row_index][k] = '\0';
        row_index++;
        if (s[i] == ' ') i++;
    }
    res[rows] = NULL;
    i = 0;
    while(res[i] != NULL){
        printf("RES: %s\n", res[i]);
        i++;
    }
    return res;
}

int main(){
    char *str = "1-2 1-3 2-4 4-5 5-6 6-7 7-8";
    parse_str(str);
    return 0;
}