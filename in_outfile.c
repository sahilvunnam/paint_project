#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "setup.h"


/*
Saves the board into a file
@param paint: the board
@param file_name: the file name
@return: void
*/
void save_file(board paint, char* file_name){
    /*
    this function saves the file and outputs as file
    @paint: the current version of the paintboard
    @file_name: the name of the file that is going to be created
    returns nothing    
    */
    FILE* outfile = fopen(file_name, "w");
    for(int i = 0; i < paint.rows; i++){
        for(int j = 0; j < paint.cols; j++){
            fprintf(outfile, "%c", paint.characters[i][j]);
        }
        fprintf(outfile, "\n");
    }
    fclose(outfile);
}

/*
Loads the file
@param file_name: the file name
@return: the board from the file
*/
board load_file(char* file_name){
    /*
    this function loads a file
    */
    FILE* fp = fopen(file_name, "r");
    //getting dimensions of paint board
    char character_being_read;
    int num_cols = 0;
    while(!feof(fp)){
        fread(&character_being_read, sizeof(char), 1, fp);
        if(character_being_read == '\n'){
            break;
        }else{
            num_cols++;
        }
    }
    rewind(fp);
    //getting total number of characters in board to get numrows
    int total_characters = 0;
        while(!feof(fp)){
        fread(&character_being_read, sizeof(char), 1, fp);
        if(character_being_read == '\n'){
            total_characters = total_characters + 0;
        }else{
            total_characters++;
        }
    }
    int num_rows = total_characters / num_cols;
    board paint;
    paint.rows = num_rows;
    paint.cols = num_cols;
    make_paint(&paint);

    //filling in board
    rewind(fp);
    int row = 0;
    int col = 0; //iterators for the board
    while(!feof(fp)){
        fread(&character_being_read, sizeof(char), 1, fp);
        if(character_being_read == '\n'){
            row++;
            col = 0;
        }else{
            paint.characters[row][col] = character_being_read;
            col++;
        }
    }
    fclose(fp);
    return paint;
}