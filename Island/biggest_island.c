#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

typedef struct s_point {
    int x;
    int y;
} t_point;

void ft_putnum(int n){
    if (n > 9) {
        ft_putnum(n / 10);
    }
    char c = (n % 10) + '0';
    write(1, &c, 1);  
}

int large_island(char** area, t_point size, t_point begin, char land_char) {
    int res = 1;
    t_point p;

    area[begin.y][begin.x] = 'F'; 

    if (begin.y > 0 && area[begin.y - 1][begin.x] == land_char) {
        p.x = begin.x;
        p.y = begin.y - 1;
        res += large_island(area, size, p, land_char);
    }
    if (begin.y < size.y - 1 && area[begin.y + 1][begin.x] == land_char) {
        p.x = begin.x;
        p.y = begin.y + 1;
        res += large_island(area, size, p, land_char);
    }
    if (begin.x > 0 && area[begin.y][begin.x - 1] == land_char) {
        p.x = begin.x - 1;
        p.y = begin.y;
        res += large_island(area, size, p, land_char);
    }
    if (begin.x < size.x - 1 && area[begin.y][begin.x + 1] == land_char) {
        p.x = begin.x + 1;
        p.y = begin.y;
        res += large_island(area, size, p, land_char);
    }

    return res;
}


//Here I solve both tasks: finding the largest island and counting the islands
void find_largest_island(char** area, t_point size) {
    int max_size = 0;
    int island_count = 0;

    for (int i = 0; i < size.y; i++) {
        for (int j = 0; j < size.x; j++) {
            if (area[i][j] == 'X') {
                t_point begin = { j, i };
                int current_island_size = large_island(area, size, begin, 'X');
                if (current_island_size > max_size) {
                    max_size = current_island_size;
                }
                island_count++;
            }
        }
    }
    ft_putnum(max_size);
    write(1, "\n", 1); 
    ft_putnum(island_count);
    write(1, "\n", 1); 
}

int validate_map(char* map, int size) {
    int row_len = 0, current_len = 0, rows = 0;
    int i = 0;
    while (i < size) {
        current_len = 0;
        while (i < size && map[i] != '\n') {
            if (map[i] != '.' && map[i] != 'X')
                return -1;
            current_len++;
            i++;
        }
        if (i < size && map[i] == '\n') {
            if (row_len == 0) {
                row_len = current_len; 
            } else if (current_len != row_len) {
                return -1;
            }
            rows++;
            i++;
        }
    }
    if (row_len == 0 || rows == 0)
        return -1;
    return 0;
}


char** parse_map(char* map, int size, t_point* map_size) {
    int rows = 0, cols = 0, i = 0, row_index = 0;

    while (i < size) {
        int row_len = 0;
        while (i < size && map[i] != '\n') {
            row_len++;
            i++;
        }
        if (cols == 0)
            cols = row_len;
        if (i < size && map[i] == '\n')
            i++;
        rows++;
    }

    char** area = (char**)malloc(sizeof(char*) * (rows + 1));
    if (!area)
    {
        write(1, "Map Error\n", 10);
        return 0;
    }

    i = 0;
    while (i < size) {
        area[row_index] = (char*)malloc(sizeof(char) * (cols + 1));
        if (!area[row_index])
        {
            write(1, "Map Error\n", 10);
            return 0;
        }
        int j = 0;
        while (i < size && map[i] != '\n') {
            area[row_index][j] = map[i];
            i++;
            j++;
        }
        area[row_index][j] = '\0';
        if (i < size && map[i] == '\n')
            i++;
        row_index++;
    }
    area[rows] = NULL;

    map_size->x = cols;
    map_size->y = rows;

    return area;
}

int main(int argc, char **argv) {
    struct stat sb;


    if (argc != 2)
    {
        write(1, "Map Error\n", 10);
        return 0;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        write(1, "Map Error\n", 10);
        return 0;
    }
    if (fstat(fd, &sb) == -1)
    {
        write(1, "Map Error\n", 10);
        return 0;
    }
    if (sb.st_size == 0)
    {
        write(1, "Map Error\n", 10);
        return 0;
    }
    char *map = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

    if (validate_map(map, sb.st_size) == -1)
    {
        write(1, "Map Error\n", 10);
        return 0;
    }

    t_point map_size;
    char** area = parse_map(map, sb.st_size, &map_size);

    find_largest_island(area, map_size);

    for (int i = 0; area[i] != NULL; i++) {
        free(area[i]);
    }
    free(area);

    munmap(map, sb.st_size);
    close(fd);
    return 0;
}
