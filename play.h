#ifndef PLAY_H
#define PLAY_H
    #include <stdbool.h>
    #include "input_validation.h"
    #include "setup.h"

    void free_board(board* paint);
    board add_row(board paint, int row_spot);
    board add_col(board paint, int col_spot);
    void erase(board paint, int row_input, int col_input);
    board delete_row(board paint, int input_row);
    board delete_col(board paint, int input_col);
    void write_board(board paint, int start_row, int start_col, int end_row, int end_col, char user_Input);
    char check_character(board paint, int start_row, int start_col, int end_row, int end_col);
    bool check_straight_line(board paint, int start_row, int start_col, int end_row, int end_col);
    board resize(board paint, int rows, int cols);
    board resize_smaller(board paint, int rows, int cols);

#endif