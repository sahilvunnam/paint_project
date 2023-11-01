#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "setup.h"

void print_board(board paint){
    /*
    this function prints the board with the proper values on the side
    @paint: the board to be printed 
    returns nothing but prints the board
    */
    if(paint.rows >= 10 && paint.cols){
        for(int i = paint.rows; i > 0; i--){
            printf(" %d  ", (i - 1));
        for(int j = 0; j < paint.rows; j++){
            printf("%c  ", paint.characters[i - 1][j]);
        }
        printf("\n");
        }
        printf("    ");
        for(int i = 0; i < paint.cols; i++){
        printf("%d  ", i);
        }
    printf("\n");
    }else{
    for(int i = paint.rows; i > 0; i--){
        printf("%d ", (i - 1));
        for(int j = 0; j < paint.cols; j++){
            printf("%c ", paint.characters[i - 1][j]);
        }
        printf("\n");
    }
    printf("  ");
    for(int i = 0; i < paint.cols; i++){
        printf("%d ", i);
    }
    printf("\n");
    }
}
    
void make_paint(board* paint){
    /*
    this function creates and allocates space for the board initally
    @paint: the paintboard that needs spaces to be allocated
    returns nothing, modicfies paint.characters to be all *
    */
    paint->characters = (char**)calloc(sizeof(char*), paint->rows);
    for(int i = 0; i < paint->rows; i++){
        paint->characters[i] = (char*)calloc(sizeof(char), paint->cols);
    }
    for(int i = 0; i < paint->rows; i++){
        for(int j = 0; j < paint->cols; j++){
            paint->characters[i][j] = '*';
        }
    }
}

/*
Prints help command
@return: void
*/
void print_help(){

  printf("Commands:\n");
  printf("Help: h\n");
  printf("Quit: q\n");
  printf("Draw line: w row_start col_start row_end col_end\n");
  printf("Resize: r num_rows num_cols\n");
  printf("Add row or column: a [r | c] pos\n");
  printf("Delete row or column: d [r | c] pos\n");
  printf("Erase: e row col\n");
  printf("Save: s file_name\n");
  printf("Load: l file_name\n");
}
