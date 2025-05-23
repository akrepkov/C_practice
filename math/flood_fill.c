#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
// #include "test_functions.h"
// #include "flood_fill.h"

typedef struct s_point {
	int x;
	int y;
} t_point;


char** make_area(char** zone){
	int rows = 0;
	int len = 0;
	while(zone[rows]) rows++;
	char** area = (char **)malloc(sizeof(char *) * (rows + 1));
	for(int i = 0; i < rows; i++){
		int len = strlen(zone[i]);
		area[i] = (char *)malloc(sizeof(char) * (len + 1));
		for (int j = 0; j < len; j++) {
            area[i][j] = zone[i][j];
        }
        area[i][len] = '\0';
    }
	area[rows] = NULL;
	return area;
}

void print_tab(char** area){
	printf("Print:\n");
	for(int i = 0; area[i] != NULL; i++){
		for (int j = 0; area[i][j] != '\0'; j++){
			printf("%c ", area[i][j]);
		}
		printf("\n");
	}
}

int flood_fill(char** area, t_point size, t_point begin){
	t_point p;
	char c = area[begin.y][begin.x];
	area[begin.y][begin.x] = 'F';
	if (begin.y > 0 && area[begin.y - 1][begin.x] == c){
		p.x = begin.x;
		p.y = begin.y - 1;
		flood_fill(area, size, p);
	}
	if (begin.y < size.y - 1 && area[begin.y + 1][begin.x] == c){
		p.x = begin.x;
		p.y = begin.y + 1;
		flood_fill(area, size, p);
	}
	if (begin.x > 0 && area[begin.y][begin.x - 1] == c){
		p.x = begin.x - 1;
		p.y = begin.y;
		flood_fill(area, size, p);
	}
	if (begin.x < size.x - 1 && area[begin.y][begin.x + 1] == c){
		p.x = begin.x + 1;
		p.y = begin.y;
		flood_fill(area, size, p);
	}
	return 0;
}



int main(void)
{
    char **area;
    t_point size = { 8, 5 };
    t_point begin = { 2, 2 };
    char *zone[] = {
        "11111111",
        "10001001",
        "10010001",
        "10110001",
        "11100001",
		NULL
    };
    area = make_area(zone);
    print_tab(area);
    flood_fill(area, size, begin);
    print_tab(area);
    return (0);
}