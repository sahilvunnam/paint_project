#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H
    #include <stdbool.h>
    #include <string.h>
    #include "setup.h"
    #include "play.h"

    bool is_valid_format(const int num_args_read, const int num_args_needed, char input_string[]);
    bool check_first_command(char letter);
    bool check_row(int input_row, int row);
    bool check_col(int input_col, int col);
    bool check_arguements(char*  arguement_one, char*  arguement_two, int argc);
    // bool input_validation_e(board paint, char input_string[], char letter, int* first_num_row, int* second_num_col);
    bool input_validation_e(board paint, char input_string[], char letter, int* first_num_row, int* second_num_col);
    bool input_validation_w(board paint, char input_string[], char letter, int* first_num_row, int* second_num_col, int* third_number, int* fourth_number);
    bool input_validation_s(char input_string[], char letter, char* file_name);
    bool input_validation_L(char input_string[], char letter, char* file_name);
    bool input_validation_r(board paint, char input_string[], char letter, int* first_num_row, int* second_num_col);
    bool input_validation_D(board paint, char input_string[], char letter, char* row_or_col, int* second_num_col);
    bool input_validation_h(char input_string[], char letter);
    bool input_validation_a(board paint, char input_string[], char letter, char* row_or_col, int* second_num_col);
    bool input_validation_q(char input_string[], char letter);

#endif