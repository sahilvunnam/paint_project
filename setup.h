#ifndef SETUP_H
#define  SETUP_H

typedef struct board{
    int rows;
    int cols;
    char** characters;
}board;

    void make_paint(board* paint);
    void print_board(board paint);
    void print_help();


#endif