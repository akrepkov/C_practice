// Write a program that processes a string representing an undirected graph. 
// This string consists of links between nodes, with each link represented by two nodes separated by a hyphen (-), and multiple links separated by a space.
// The program should determine the longest path in the graph where each node is visited only once. The result should be the length (in terms of the number of nodes) of the longest path, which does not revisit any node.
// If the program receives no input or more than one argument, it should print a newline (\n).

// Output:
// The program will output the length of the longest chain of connected nodes (without revisiting any node), followed by a newline.

//  ./g_diam "10-5 5-8 8-3 3-5 1-9 9-2 2-5 3-2 8-4 4-7 7-10 2-1"
//  8$
//  Explanation: The longest path here is from node 1 to node 10, passing through nodes 2, 5, 3, 8, 4, and 7, with 8 nodes in total.

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NODES 8

struct Node {
    int vertex;
    struct Node* next;
};


struct Node* newNode(int vertex){
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}


int ft_split(char *s, int start, int finish){
    char* res = (char*)malloc(sizeof(char) * (finish - start + 1)+ 1);
    int i = 0;
    while(start <= finish){
        res[i++] = s[start++];
    }
    res[i] = '\0';
    int num = atoi(res);
    free(res);
    return num;
}

void addEdge(struct Node* adjacency_list[], int vertex1, int vertex2){
    struct Node* node1 = newNode(vertex1);
    node1->next = adjacency_list[vertex2];
    adjacency_list[vertex2] = node1; //changing head here

    struct Node* node2 = newNode(vertex2);
    node2->next = adjacency_list[vertex1];
    adjacency_list[vertex1] = node2;   //changing head here 

}

void print_adj_list(struct Node* adjacency_list[]){
    for (int i = 0; i < MAX_NODES; i++) {
        printf("List %d: ", i); // Print the vertex
        struct Node* temp = adjacency_list[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex); // Print its adjacent
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    char* s = "1-2 1-3 1-4 4-5 5-6 6-7 7-8";
    // Initialize adjacency list
    struct Node* adjacency_list[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        adjacency_list[i] = NULL;
    }
    int i = 0;
    while(s[i] != '\0'){
        int start = i;
        while (s[i] != '-' && s[i] != '\0') {
            i++;
        }
        int vertex1 = ft_split(s, start, i - 1);
        i++;
        start = i;
        while (s[i] != ' ' && s[i] != '\0') {
            i++;
        }
        int vertex2 = ft_split(s, start, i - 1);
        // printf("%d %d\n", vertex1, vertex2);
        addEdge(adjacency_list, vertex1, vertex2);
        i++;
    }
    print_adj_list(adjacency_list);
    for (int i = 0; i < MAX_NODES; i++) {
        struct Node* temp = adjacency_list[i];
        while (temp != NULL) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    return 0;
}