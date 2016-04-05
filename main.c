#include "stdio.h"

#define length 3


int main(int argc, char* argv[]){
    if (argc != 10){
        printf("Usage: %s numbers_1_through_9\n", argv[0]);
        return 1;
    }

    int grid[9];
    for (int i = 1; i < argc; i++){
        grid[i-1] = argv[i][0] - '0';
    }

    int expected = 0;
    for (int i = 0; i < length; i++){
        expected += grid[i];
    }

    // Rows
    for (int y = 1; y < length; y++){
        int start = y * length;
        int sum = 0;
        for (int x = 0; x < length; x++){
            sum += grid[start + x];
        }
        if (sum != expected){
            printf("Invalid. Found sum of %d on row %d. Expected %d.\n", sum, y, expected);
            return 1;
        }
    }

    // Cols
    for (int x = 0; x < length; x++){
        int sum = 0;
        for (int y = 0; y < length; y++){
            sum += grid[y * length + x];
        }
        if (sum != expected){
            printf("Invalid. Found sum of %d on col %d. Expected %d.\n", sum, x, expected);
            return 1;
        }
    }

    // Diags
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += grid[i * length + i];
    }
    if (sum != expected){
        printf("Invalid. Found sum of %d on upper left diag. Expected %d.\n", sum, expected);
        return 1;
    }

    sum = 0;
    for (int i = 0; i < length; i++){
        sum += grid[i * length + (length - i - 1)];
    }
    if (sum != expected){
        printf("Invalid. Found sum of %d on upper left diag. Expected %d.\n", sum, expected);
        return 1;
    }

    return 0;
}

