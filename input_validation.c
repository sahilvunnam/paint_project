#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "setup.h"
#include "play.h"

/*
Checks if the first letter is a right call
@param letter: the letter that is being checked
@return: true if one of the letters is valid, false otherwise
*/
bool check_first_command(char letter){
    if(letter == 'q' || letter == 'h'){
        return true;
    }
    else if(letter == 'w' || letter == 'e'){
        return true;
    }
    else if(letter == 'r' || letter == 'a'){
        return true;
    }
    else if(letter == 'd' || letter == 's'){
        return true;
    }
    else if(letter == 'l'){
        return true;
    }
    else{
        return false;
    }
}

/*
Checks if user input of rows is in the bounds of paint
@param row: the amount of rows in the board
@param input_row: the row that the user entered
@return: returns false if the user input is not in the bounds of the board, false otherwise
*/
bool check_row(int input_row, int row){
    if(input_row < 0 || input_row > row){
        return false;
    }
    return true;
}

/*
Checks if user input of rows is in the bounds of paint
@param col: the amount of rows in the board
@param input_col: the row that the user entered
@return: returns false if the user input is not in the bounds of the board, false otherwise
*/
bool check_col(int input_col, int col){
    if(input_col < 0 || input_col > col){
        return false;
    }
    return true;
}


/*
Checks the arguments that are passed in the command line
@param argument_one: the first argument
@param argunment_two: the second argument
@param argc: the number of arguments
@return: true if the right # of command line arguments are passed, false otherwise
*/
bool check_arguements(char* arguement_one, char* arguement_two, int argc){
    if(argc <= 2){
        printf("Too little arguements");
        return false;
    }else if(argc >= 4){
        printf("Too many arguements");
        return false;
    }else if(atoi(&arguement_one[0]) < 1){
        printf("The number of rows is less than 1.\n");
        return false;
    }else if(atoi(&arguement_two[0]) < 1){
        printf("The number of columns is less than 1.\n");
        return false;
    }
    else if(!isdigit(arguement_one[0])){
        return false;
    }else if(!isdigit(arguement_two[0])){
        return false;
    }else{
        return true;
    } 
}

/*
Input validation for the erase function
@param paint: the board
@param input_string: the user input
@param letter: the first thing that was passed (letter e)
@param first_num_row: int pointer, indicating the row
@param second_num_col: int pointer, indicating the column
@return: true if the right number of arguments are in input_string, false otherwise
*/
bool input_validation_e(board paint, char input_string[], char letter, int* first_num_row, int* second_num_col){
    char checker;
    sscanf(input_string," %c %d %d%c", &letter, first_num_row, second_num_col, &checker);

    // int first_num;
    // int second_num;

    // int row_check = sscanf(input_string, " %c %d", &letter, &first_num);
    // int col_check = sscanf(input_string, " %c %d %d", &letter, &first_num, &second_num);

    // char first;
    // char second;
    // int args_read = sscanf(input_string, " %c %c %c", &letter, &first, &second);
    sscanf(input_string," %c %d %d %c", &letter, first_num_row, second_num_col, &checker);
    
    // if(args_read < 3){
    //     printf("Improper erase command.\n"); // goes in if format is bad
    //     return false;
    // }
    // else if(row_check != 2){
    //     printf("The number of rows is not an integer.\n");
    //     return false;
    // }
    // else if(col_check != 3){
    //     printf("The number of columns is not an integer.\n");
    //     return false;
    // }
    if(!isspace(checker)){
        printf("Improper erase command.\n"); // goes in if format is bad
        return false;
    }
    else if(!check_row(*first_num_row, paint.rows)){
        printf("The number of rows is less than 1.\n");
        return false;
    } 
    else if(!check_col(*second_num_col, paint.rows)){
        printf("The number of columns is less than 1.\n");
        return false;
    }
    else{
        return true;
    }
}

/*
Input validation for the resize function
@param paint: the board
@param input_string: the user input
@param letter: the first thing that was passed (letter e)
@param first_num_row: int pointer, indicating the row
@param second_num_col: int pointer, indicating the column
@return: true if the right number of arguments are in input_string, false otherwise
*/
bool input_validation_r(board paint, char input_string[], char letter, int* first_num_row, int* second_num_col){
    char checker;
    sscanf(input_string," %c %d %d%c", &letter, first_num_row, second_num_col, &checker);

    // int first_num = sscanf(input_string, " %c %d", &letter, first_num_row);
    // int second_num = sscanf(input_string, " %c %d %d", &letter, first_num_row, second_num_col);

    // char first;
    // char second;
    // int args_valid = sscanf(input_string," %c %c %c", &letter, &first, &second);
    sscanf(input_string," %c %d %d %c", &letter, first_num_row, second_num_col, &checker);

    // if((args_valid < 3)){
    //     printf("Improper resize command.\n"); // goes in if format is bad
    //     return false;
    // }
    // else if(first_num != 2){
    //     printf("The number of rows is not an integer.\n");
    //     return false;
    // }
    // else if(second_num != 3){
    //     printf("The number of columns is not an integer.\n");
    //     return false;
    // }
    if(!isspace(checker)){
        printf("Improper resize command.\n"); // goes in if format is bad
        return false;
    }
    else{
        return true;
    }
}

/*
Input validation for the delete function
@param paint: the board
@param input_string: the user input
@param letter: the first thing that was passed (letter e)
@param row_or_col: int pointer, indicating the row
@param second_num_col: int pointer, indicating the column
@return: true if the right number of arguments are in input_string, false otherwise
*/
bool input_validation_D(board paint, char input_string[], char letter, char* row_or_col, int* second_num_col){
    char checker;
    sscanf(input_string," %c %c %d%c", &letter, row_or_col, second_num_col, &checker);
    
    // char first;
    // int args_valid = sscanf(input_string,"%c %c %c", &letter, row_or_col, &first);
    sscanf(input_string," %c %c %d %c", &letter, row_or_col, second_num_col, &checker);
    
    // if((args_valid < 3)){
    //     printf("Improper delete command.\n"); // goes in if format is bad
    //     return false;
    // }
    // else if(!((*row_or_col == 'r') || (*row_or_col == 'c'))){
    //     printf("Delete row or column: d [r | c] pos\n");
    //     return false;
    // }
    if(!isspace(checker)){
        printf("Improper delete command.\n"); // goes in if format is bad
        return false;
    }
    else if(*row_or_col == 'r' && *second_num_col < 0){
        printf("The number of rows is less than 1.\n");
        return false;
    }
    else if(*row_or_col == 'c' && *second_num_col < 0){
        printf("The number of columns is less than 1.\n");
        return false;
    }
    else{
        return true;
    }
}

/*
Input validation for the add function
@param paint: the board
@param input_string: the user input
@param letter: the first thing that was passed (letter e)
@param row_or_col: int pointer, indicating the row
@param second_num_col: int pointer, indicating the column
@return: true if the right number of arguments are in input_string, false otherwise
*/
bool input_validation_a(board paint, char input_string[], char letter, char* row_or_col, int* second_num_col){
    char checker;
    sscanf(input_string," %c %c %d%c", &letter, row_or_col, second_num_col, &checker);

    char first;
    int args_valid = sscanf(input_string,"%c %c %c", &letter, row_or_col, &first);
    sscanf(input_string," %c %c %d %c", &letter, row_or_col, second_num_col, &checker);
    
    if(args_valid < 3){
        printf("Improper add command.\n"); // goes in if format is bad
        return false;
    }
    else if(!((*row_or_col == 'r') || (*row_or_col == 'c'))){
        printf("Add row or column: d [r | c] pos\n");
        return false;
    }
    else if(!isspace(checker)){
        printf("Improper add command.\n"); // goes in if format is bad
        return false;
    }
    else if(*row_or_col == 'r' && *second_num_col < 0){
        printf("The number of rows is less than 1.\n");
        return false;
    }
    else if(*row_or_col == 'c' && *second_num_col < 0){
        printf("The number of columns is less than 1.\n");
        return false;
    }
    else{
        return true;
    }
}

/*
Input validation for the write function
@param paint: the board
@param input_string: the user input
@param letter: the first thing that was passed (letter e)
@param first_num_row: int pointer, indicating the start_row
@param second_num_col: int pointer, indicating the start_column
@param third_number: int pointer, indicating the end_row
@param fourth_number: int pointer, indicating the end_column
@return: true if the right number of arguments are in input_string, false otherwise
*/
bool input_validation_w(board paint, char input_string[], char letter, int* first_num_row, int* second_num_col,
                        int* third_number, int* fourth_number){
    char checker;
    sscanf(input_string," %c %d %d %d %d%c", &letter, first_num_row, second_num_col, third_number, fourth_number, &checker);

    // int first = sscanf(input_string, " %c %d", &letter, first_num_row);
    // int second = sscanf(input_string, " %c %d %d", &letter, first_num_row, second_num_col);
    // int third = sscanf(input_string, " %c %d %d %d", &letter, first_num_row, second_num_col, third_number);
    // int fourth = sscanf(input_string, " %c %d %d %d %d %c", &letter, first_num_row, second_num_col, third_number, fourth_number, &checker);

    // char first_letter;
    // char second_letter; 
    // char third_letter; 
    // char fourth_letter;
    
    // int args_read = sscanf(input_string, " %c %c %c %c %c%c", &letter, &first_letter, &second_letter, &third_letter, &fourth_letter, &checker);
    sscanf(input_string," %c %d %d %d %d %c", &letter, first_num_row, second_num_col, third_number, fourth_number, &checker);
    
    // if(args_read < 6){
    //     printf("Improper write command\n"); // goes in if format is bad
    //     return false;
    // }
    // else if(first != 2){
    //    printf("The number of rows is not an integer.\n"); 
    //    return false;
    // }
    // else if(second != 3){
    //     printf("The number of columns is not an integer.\n");
    //     return false;
    // }
    // else if(third != 4){
    //     printf("The number of rows is not an integer.\n"); 
    //     return false;
    // }
    // else if(fourth != 5){
    //     printf("The number of columns is not an integer.\n");
    //     return false;
    // }
    if(!isspace(checker)){
        printf("Improper draw command.\n"); // goes in if format is bad
        return false;
    }
    else if(!check_row(*first_num_row, paint.rows) || !check_row(*third_number, paint.rows)){
        printf("The number of rows is less than 1.\n");
        return false;
    }
    else if(!check_row(*second_num_col, paint.cols) || !check_col(*fourth_number, paint.cols)){
        printf("The number of columns is less than 1.\n");
        return false;
    }
    else{
        return true;
    }
}

/*
Input validation for the save function
@param input_string: the user input
@param letter: the first thing that was passed (letter e)
@param file_num = char pointer, indicating the file name
@return: true if the right number of arguments are in input_string, false otherwise
*/
bool input_validation_s(char input_string[], char letter, char* file_name){
    char checker;
    int args_valid = sscanf(input_string," %c %s%c", &letter, file_name, &checker);
    if(!isspace(checker) || (args_valid < 3)){
        printf("Improper save command or file could not be created.\n"); // goes in if format is bad
        return false;
    }else{
        return true;
    }
}

/*
Input validation for the help function
@param input_string: the user input
@param letter: the first thing that was passed (letter e)
@return: true if the right number of arguments are in input_string, false otherwise
*/
bool input_validation_h(char input_string[], char letter){
    char checker;
    int args_valid = sscanf(input_string," %c%c", &letter, &checker);
    if(!isspace(checker) || (args_valid < 2)){
        printf("Unrecognized command. Type h for help.\n"); // goes in if format is bad
        return false;
    }else{
        return true;
    }
}

/*
Input validation for the load function
@param input_string: the user input
@param letter: the first thing that was passed (letter e)
@return: true if the right number of arguments are in input_string, false otherwise
*/
bool input_validation_L(char input_string[], char letter, char* file_name){
    char checker;
    int args_valid = sscanf(input_string," %c %s%c", &letter, file_name, &checker);
    if(!isspace(checker) || (args_valid < 3)){
        printf("Improper load command or file could not be opened.\n"); // goes in if format is bad
        return false;
    }else{
        return true;
    }
}

/*
Input validation for the quit function
@param input_string: the user input
@param letter: the first thing that was passed (letter e)
@return: true if the right number of arguments are in input_string, false otherwise
*/
bool input_validation_q(char input_string[], char letter){
    char checker;
    int args_valid = sscanf(input_string," %c%c", &letter, &checker);
    if(!isspace(checker) || (args_valid < 2)){
        printf("Unrecognized command. Type h for help.\n");
        return false;
    }else{
        return true;
    }
}
