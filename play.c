#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "play.h"
#include "input_validation.h"
#include "setup.h"


/*
Frees the board
@param paint: the board
*/
void free_board(board* paint){
    for(int i = 0; i < (paint -> rows); ++i){
        free((paint -> characters)[i]);
    }
    free(paint -> characters);
    (paint -> characters) = NULL;
}


/*
Adds row at the specific row spot the user choose
@param paint: the board
@param row_spot: the row spot that the user chose
*/
board add_row(board paint, int row_spot){
    // board new_paint;
    // new_paint.rows = paint.rows + 1;
    // new_paint.cols = paint.cols;

    // new_paint = (char**)malloc(new_paint.rows * sizeof(char*));


    if(!check_row(row_spot, paint.rows)){
        return paint;
    }
    else{
        board new_paint;
        new_paint.cols = paint.cols;
        new_paint.rows = paint.rows + 1;
        make_paint(&new_paint);
        // print_board(new_paint);
        for(int i = 0; i < paint.rows; i++){
            for(int j = 0; j < paint.cols; j++){
                if(i >= row_spot){
                    new_paint.characters[i + 1][j] = paint.characters[i][j];
                }else{
                    new_paint.characters[i][j] = paint.characters[i][j];
                }
            }
        }
        free_board(&paint);
        return new_paint;
    }  
}

/*
Adds a column at the spot the user chooses
@param paint: the board
@param col_spot: the column the user chooses to add a new column in the board
*/
board add_col(board paint, int col_spot){
    if(!check_col(col_spot, paint.cols)){
        return paint;
    }
    else{
    board new_paint;
    new_paint.cols = paint.cols + 1;
    new_paint.rows = paint.rows;
    make_paint(&new_paint);
    for(int i = 0; i < paint.rows; i++){
        for(int j = 0; j < paint.cols; j++){
            if(j >= col_spot){
                new_paint.characters[i][j + 1] = paint.characters[i][j];
            }else{
                new_paint.characters[i][j] = paint.characters[i][j];
            }
        }
    }
    free_board(&paint);
  return new_paint;
//  print_matrix(*new_matrix);
    }
}


/*
Erases something off the board at the specified row and column
@param paint: the board
@param row_input: the row the user chooses
@param col_input: the column the user chooses
*/
void erase(board paint, int row_input, int col_input){
    paint.characters[row_input][col_input] = '*';
}

/*
Deletes the row the user chooses, and creates a new board
@param paint: the board
@param input_row: the row the user chooses
@return: the new board
*/
board delete_row(board paint, int input_row){     
    board new_paint;
    new_paint.cols = paint.cols;
    new_paint.rows = paint.rows - 1;
    make_paint(&new_paint);
    for(int i = 0; i < new_paint.rows; i++){
        for(int j = 0; j < paint.cols; j++){
        if(i >= input_row){
            new_paint.characters[i][j] = paint.characters[i + 1][j];
        }else{
            new_paint.characters[i][j] = paint.characters[i][j];
      }
    }
  }
  free_board(&paint);
  return new_paint;
//  print_matrix(*new_matrix);
}

/*
Deletes the column where the user specified and creates a new board
@param paint: the board
@param input_col: the column the user wants to delete
@return: a new board with the specified column deleted
*/
board delete_col(board paint, int input_col){
    board new_paint;
    new_paint.cols = paint.cols - 1;
    new_paint.rows = paint.rows;
    make_paint(&new_paint);
    for(int i = 0; i < paint.rows; i++){
        for(int j = 0; j < new_paint.cols; j++){
        if(j >= input_col){
            new_paint.characters[i][j] = paint.characters[i][j + 1];
        }else{
            new_paint.characters[i][j] = paint.characters[i][j];
      }
    }
  }
  free_board(&paint);
  return new_paint;
//  print_matrix(*new_matrix);
}

/*
Writes a straight line on the board, if their is valid user input
@param paint: the board
@param start_row: the row where the line should start at
@param start_col: the column where the line should start at
@param end_row: the row where the line should end at
@param end_col: the column where the line should end at
*/
void write_board(board paint, int start_row, int start_col, int end_row, int end_col, char user_Input){
    if(!(check_row(start_row, paint.rows)) || !(check_row(end_row, paint.rows))){
        return;
    }
    else if(!(check_col(start_col, paint.cols)) || !(check_col(end_col, paint.cols))){
        return;
    }
    else if(!(check_straight_line(paint, start_row, start_col, end_row, end_col))){
        return;
    }
    //We can either put the above code in this function or in the main when we check what the user inputs

    else if(start_row == end_row){
        if(end_col > start_col){
            for(int i = start_col; i < end_col + 1; ++i){
                if(paint.characters[start_row][i] == '*'){
                    paint.characters[start_row][i] = user_Input;
                }
                else if(paint.characters[start_row][i] == user_Input){
                    paint.characters[start_row][i] = user_Input;
                }
                else{
                    paint.characters[start_row][i] = '+';
                }
            }
        }
        else{
            for(int i = end_col; i <= start_col; ++i){
                if(paint.characters[start_row][i] == '*'){
                    paint.characters[start_row][i] = user_Input;
                }
                else if(paint.characters[start_row][i] == user_Input){
                    paint.characters[start_row][i] = user_Input;
                }
                else{
                    paint.characters[start_row][i] = '+';
                }
            }
        }
    }

    else if(start_col == end_col){
        if(end_row > start_row){
            for(int i = start_row; i <= end_row; ++i){
                if(paint.characters[i][start_col] == '*'){
                    paint.characters[i][start_col] = user_Input;
                }
                else if(paint.characters[i][start_col] == user_Input){
                    paint.characters[i][start_col] = user_Input;
                }
                else{
                    paint.characters[i][start_col] = '+';
                }
            }
        }
        else{
            for(int i = end_row; i <= start_row; ++i){
                if(paint.characters[i][start_col] == '*'){
                    paint.characters[i][start_col] = user_Input;
                }
                else if(paint.characters[i][start_col] == user_Input){
                    paint.characters[i][start_col] = user_Input;
                }
                else{
                    paint.characters[i][start_col] = '+';
                }
            }
        }
    }


    //This '/'
    else if((end_row > start_row) && (end_col > start_col)){
        int second_count = 0;
        for(int i = start_row; i <= end_row; ++i){
            for(int j = start_col; j <= end_col; ++j){
                if(second_count == 0){
                    start_row++;
                    start_col++;
                    if(paint.characters[i][j] == '*'){
                        paint.characters[i][j] = user_Input;
                    }
                    else if(paint.characters[i][j] == user_Input){
                        paint.characters[i][j] = user_Input;
                    }
                    else{
                        paint.characters[i][j] = '+';
                    }
                    break;
                }
            }
        }
    }

    //w 1 5 0 4

    //w 4 5 6 7
    //w 2 3 1 2
    else if(start_row > end_row && start_col > end_col){
        int second_count = 0;
        for(int i = start_row; i >= end_row; --i){
            for(int j = start_col; j >= end_col; --j){
                if(second_count == 0){
                    start_row--;
                    start_col--;
                    if(paint.characters[i][j] == '*'){
                        paint.characters[i][j] = user_Input;
                    }
                    else if(paint.characters[i][j] == user_Input){
                        paint.characters[i][j] = user_Input;
                    }
                    else{
                        paint.characters[i][j] = '+';
                    }
                    break;
                }
            }
        }
    }

    //w 0 6 1 7


    // This '\'
    //w 2 1 0 3
    else if(start_row > end_row && start_col < end_col){
        int second_count = 0;
        for(int i = start_row; i >= end_row; --i){
            for(int j = start_col; j <= end_col; ++j){
                if(second_count == 0){
                    start_row--;
                    start_col++;
                    if(paint.characters[i][j] == '*'){
                        paint.characters[i][j] = user_Input;  //We don't know what user input is, we have to check to see what type of line makes it a straight line
                    }
                    else if(paint.characters[i][j] == user_Input){
                        paint.characters[i][j] = user_Input;
                    }
                    else{
                        paint.characters[i][j] = '+';
                    }
                    break;
                }
            }
        }
    }
    
    else if(start_row > end_row && start_col < end_col){
        int second_count = 0;
        for(int i = start_row; i >= end_row; --i){
            for(int j = start_col; j < end_col + 1; ++j){
                if(j == second_count){
                    second_count++;
                    if(paint.characters[i][j] == '*'){
                        paint.characters[i][j] = user_Input;  //We don't know what user input is, we have to check to see what type of line makes it a straight line
                    }
                    else if(paint.characters[i][j] == user_Input){
                        paint.characters[i][j] = user_Input;
                    }
                    else{
                        paint.characters[i][j] = '+';
                    }
                    break;
                }
            }
        }
    }

    //w 0 4 2 2

    //w 1 1 2 0
    else if(start_row < end_row && start_col > end_col){
        int second_count = 0;
        for(int i = end_row; i >= start_row; --i){
            for(int j = end_col; j <= start_col; ++j){
                if(second_count == 0){
                    end_row--;
                    end_col++;
                    if(paint.characters[i][j] == '*'){
                        paint.characters[i][j] = user_Input;  //We don't know what user input is, we have to check to see what type of line makes it a straight line
                    }
                    else if(paint.characters[i][j] == user_Input){
                        paint.characters[i][j] = user_Input;
                    }
                    else{
                        paint.characters[i][j] = '+';
                    }
                    break;
                }
            }
        }
    }
}

/*
Checks which character to input into the board
@param paint: the board
@param start_row: the row the user chose to start
@param start_col: the column the user chose to start
@param end_row: the row the user chose to end
@param end_col: the col the user chose to end
@return: the character that should be filled in on the board
*/
char check_character(board paint, int start_row, int start_col, int end_row, int end_col){
    char letter;
    if((end_row > start_row) && (end_col > start_col)){
        letter = '/';
    }
    else if(((end_row - start_row) == 1) && ((end_col - start_col) == 1)){
        letter = '-';
    }
    else if(start_row == end_row){
        letter = '-';
    }
    else if(start_col == end_col){
        letter = '|';
    }
    else if(start_row > end_row && start_col > end_col){
        letter = '/';
    }
    else{
        letter = '\\';
    }
    return letter;
}

/*
Checks if the user input creates a straight line
@param paint: the board
@param start_row: the row the user chose to start
@param start_col: the column the user chose to start
@param end_row: the row the user chose to end
@param end_col: the col the user chose to end
@return: true if the user input forms a straight line, false otherwise
*/
bool check_straight_line(board paint, int start_row, int start_col, int end_row, int end_col){
    bool flag;
    if(start_row == end_row){
        flag = true;;
    }
    else if(start_col == end_col){
        flag = true;
    }
    else if((abs(end_row - start_row) / abs(end_col - start_col)) == 1){
        flag = true;
    }
    else{
        flag = false;
    }
    return flag;
}

/*
Makes the board to a bigger size
@param paint: the original board
@param rows: the amount of rows in the new board
@param cols: the amount of cols in the new board
*/
board resize(board paint, int rows, int cols){
    board new_paint;

    new_paint.rows = rows;
    new_paint.cols = cols;

    new_paint.characters = (char**)malloc(new_paint.rows * sizeof(char*));
    for(int i = 0; i < new_paint.rows; ++i){
        new_paint.characters[i] = (char*)malloc(new_paint.cols * sizeof(char));
    }
    
    for(int i = 0; i < paint.rows; ++i){
        for(int j = 0; j < paint.cols; ++j){
            new_paint.characters[i][j] = paint.characters[i][j];
        }
    }
    
    for(int i = 0; i < new_paint.rows; ++i){
        for(int j = 0; j < new_paint.cols; ++j){
            if(!(i < paint.rows && j < paint.cols)){
                new_paint.characters[i][j] = '*';
            }
        }
    }

    free_board(&paint);
    return new_paint;
}

/*
Resizes the board to a smaller size
@param paint: the original board
@param rows: the amount of rows in the new board
@param cols: the amount of cols in the new board
@return new_paint: the new board
*/
board resize_smaller(board paint, int rows, int cols){
    board new_paint;
    new_paint.rows = rows;
    new_paint.cols = cols;
    make_paint(&new_paint);
    for(int i = 0; i < new_paint.rows; i++){
        for(int j = 0; j < new_paint.cols; j++){
            new_paint.characters[i][j] = paint.characters[i][j];
        }
    }
    free_board(&paint);
    return new_paint; 
}
