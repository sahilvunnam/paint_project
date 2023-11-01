#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "setup.h"
#include "input_validation.h"
#include "in_outfile.h"
#include "play.h"
/*
This program creates a canvas that allows the user to resize and draw on it
*/


/*
Allows the user to create whatever they want on the canvas
*/
int main(int argc, char const* argv[]){
    if((argc < 3 || argc > 3) && (argc != 1)){
        printf("Wrong number of command line arguments entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
    }
    board paint;
    if((argv[2] != NULL && argv[1] != NULL) && check_arguements((char*)argv[1], (char*)argv[2], argc)){
        paint.rows = atoi(argv[1]);
        paint.cols = atoi(argv[2]);
    }else{
        if(argc != 1){
        printf("Making default board of 10 X 10.\n");
        }
        paint.rows = 10;
        paint.cols = 10;
    }

    make_paint(&paint);
    print_board(paint);

    char letter;
    bool flag = true;
    
    do{
        
        printf("Enter your command: ");
        char input_string[1000];
        fgets(input_string, sizeof(input_string), stdin);
        
        sscanf(input_string, " %c", &letter);
        if(!check_first_command(letter) && !input_validation_q(input_string, letter)){
            print_board(paint);
            continue;
        }
        
        //Done
        else if(letter == 'e'){
            int first_num_row;
            int second_num_col;
            if(input_validation_e(paint, input_string, letter, &first_num_row, &second_num_col)){
                erase(paint, first_num_row, second_num_col);
                print_board(paint);  
                continue;
            }
            else{
                print_board(paint);
                continue;
            }   
        }

        //Done
        else if(letter == 'h'){
            if(input_validation_h(input_string, letter)){
                print_help();
                print_board(paint);
                continue;
            }
            else{
                print_board(paint);
                continue;
            }
        }

        else if(letter == 'r'){
                int row;
                int cols;
                if(input_validation_r(paint, input_string, letter, &row, &cols)){
                    if(row < paint.rows && cols < paint.cols){
                        paint = resize_smaller(paint, row, cols);
                    }else if(row > paint.rows && cols < paint.cols){
                        paint = resize(paint, row, paint.cols);
                        paint = resize_smaller(paint, paint.rows, cols);
                    }else if(row < paint.rows && cols > paint.cols){
                        paint = resize(paint, paint.rows, cols);
                        paint = resize_smaller(paint, row, paint.cols);
                    }else if(row > paint.rows && cols > paint.cols){
                        paint = resize(paint, row, cols);
                    }
                    print_board(paint);
                    continue;
                }else{
                    print_board(paint);
                    continue;
                }
        }
        
        //Done
        else if(letter == 's'){
            //check for user input ////////////////////////////////////
            char file_name[1000];
            if(input_validation_s(input_string, letter, file_name)){
            save_file(paint, file_name);
            print_board(paint);
            // free(file_name);
            continue;
            }else{
                print_board(paint);
                continue;
            }
        }
        
        //Done
        else if(letter == 'l'){
            // check for valid user input ////////////////////////////////idk yet
            char file_name[1000];
            if(input_validation_L(input_string, letter, file_name)){
            free_board(&paint);
            paint = load_file(file_name);
            print_board(paint);
            // free(file_name);
            continue;
            }else{
                print_board(paint);
                continue;
            }
        }
        
        else if (letter == 'd'){
            
            int index_of_row_or_column;
            char row_or_col;
            if(input_validation_D(paint, input_string, letter, &row_or_col, &index_of_row_or_column)){
                if(row_or_col == 'r'){
                    paint = delete_row(paint, index_of_row_or_column);
                    print_board(paint);
                    continue;
                }else if(row_or_col == 'c'){
                    paint = delete_col(paint, index_of_row_or_column);
                    print_board(paint);
                    continue;
                }
            }else{
                print_board(paint);
                continue;
            }
        }
        
        else if(letter == 'a'){
            int index_of_row_or_column;
            char row_or_col;
            if(input_validation_a(paint, input_string, letter, &row_or_col, &index_of_row_or_column)){
                if(row_or_col == 'r'){
                    paint = add_row(paint, index_of_row_or_column);
                    print_board(paint);
                    continue;
                }else if(row_or_col == 'c'){
                    paint = add_col(paint, index_of_row_or_column);
                    print_board(paint);
                    continue;
                }
            }else{
                print_board(paint);
                continue;
            }
        }
        
        //Done
        else if(letter == 'w'){
            int start_row = '\0';
            int start_col;
            int end_row;
            int end_col;
            if(input_validation_w(paint, input_string, letter, &start_row, &start_col, &end_row, &end_col)){
                char s = check_character(paint, start_row, start_col, end_row, end_col);
                write_board(paint, start_row, start_col, end_row, end_col, s);
                print_board(paint);
                continue;
            }
            else{
                print_board(paint);
                continue;
            }
        }


        else if(!input_validation_q(input_string, letter)){
            print_board(paint);
            continue;
        }
        flag = false;
    }while(flag);
    

    free_board(&paint);
    return 0;
}