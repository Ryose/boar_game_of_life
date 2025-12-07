/**
 * @author boarCoder
 * @date 07/12/2025 
 *
 * @brief Main file for the implementation of Conway's game of life
 */


#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 50
#define NUM_COLS 50

#define clear_screen() printf("\033[2J\033[H")

enum gol_cell{
    CELL_ALIVE,
    CELL_DEAD
};


void gol_init_grid(enum gol_cell* grid, int rows, int cols) {
    
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            grid[i*cols+j] = CELL_DEAD;
        }

    }
    grid[1*cols+1] = CELL_ALIVE;
}

enum gol_cell gol_update_cell(enum gol_cell* grid, int rows, int cols, int current_row, int current_col) {
    int count_alive = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int r = (current_row+i)%rows;
            int c = (current_col+j)%cols;
            if((r != current_row || c!=current_col) && grid[r*cols+c]==CELL_ALIVE) {
                count_alive++;
            }
        }
    }
    if(grid[current_row*cols+current_col] ==CELL_ALIVE && (count_alive<2 || count_alive>3) ) return CELL_DEAD;
    if(grid[current_row*cols+current_col] ==CELL_ALIVE && (count_alive==2 || count_alive==3)) return CELL_ALIVE;
    if(grid[current_row*cols+current_col] ==CELL_DEAD && count_alive==3) return CELL_ALIVE;
}

void gol_show_grid(enum gol_cell* grid, int rows, int cols) {
    int i, j;
    for(i=0;i<rows; i++) {
        for(j=0; j<cols; j++) {
            if(grid[i*cols+j] == CELL_ALIVE)
                printf("*");
            else 
                printf("_"); 
        }
        printf("\n");
    }

}

int main(int argc, char** argv) {
    enum gol_cell *grid = malloc(sizeof(*grid)*NUM_COLS*NUM_ROWS);
    printf("Conway's game of life will start after you press ENTER\n");
    getchar();
    gol_init_grid(grid, NUM_ROWS, NUM_COLS);
    clear_screen();
    gol_show_grid(grid, NUM_ROWS, NUM_COLS);
    getchar();
    printf("We are going outside\n");
    return 0;
}
