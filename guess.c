#include "stdio.h"


int main(int argc, char* argv[]){
    if (argc != 7){
        printf("Usage: %s numbers_1_through_6\n", argv[0]);
        return 1;
    }

    int grid[6];
    int remaining[3];
    for (int i = 1; i < argc; i++){
        grid[i-1] = argv[i][0] - '0';
    }

    for (int i = 0; i < 9; i++){
        int found = 0;
        for (int j = 0; j < 6; j++){
            if (i == j){
                found = 1;
                break;
            }
        }
        if (found){
        }
    }

    return 0;
}

