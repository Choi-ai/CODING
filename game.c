#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int level = 0;
    int size = 0, bombCount;
    int bombRow, bombColumn;
    int row, column;
    int revealed[11][11] = {0};
    int bombs[11][11] = {0};
    int safeRevealed = 0;
    int gameOver = 0;

    // Choose level
    do {
        printf("Select Level Difficulty:\n");
        printf("1 - Easy \n");
        printf("2 - Medium \n");
        printf("3 - Hard \n");
        printf("4 - Very Hard \n");
        printf("5 - Extreme \n");
        printf("Enter level: ");
        scanf("%d", &level);
    } while (level < 1 || level > 5); 

    // Set matrix size and bombCount
    if (level == 1) {
        size = 3; bombCount = 2;
    } else if (level == 2) {
        size = 4; bombCount = 6 ;
    } else if (level == 3) {
        size = 5; bombCount = size = 9;
    } else if (level == 4) {
        size = 6; bombCount = size = 12;
    } else if (level == 5) {
        size = 7; bombCount = size = 15;
    }
    printf("\nYour goal: Avoid %d bomb/s!\n", bombCount);
    int totalSafe = size * size - bombCount; //(logic:level2, size = 4, 4x4 = 16 -3 safe = 13 box need to open)

    //int totalSafe = level * size - bombCount; //logic. ex. user choose easy; level = 1, size = 2 bombcount = 1, 1*2-1 = 1 safe box player win
    //printf("\nFind at least %d safe symbol (O)!", totalSafe);
    
    //srand(time(0)); // seed random para unique kada run. change bomb location time to time srand(123) need baguhin para maiba ng pwesto yung bomb
    srand (123);
    // Place bombs randomly
    int placed = 0; // magloop hanggat di pa equal sa bombcount
    while (placed < bombCount) {
        bombRow = rand() % size + 1; // ex. size = 2 remainder 0 + 1 = 1 para maging 1 to size
        bombColumn = rand() % size + 1;
        if (bombs[bombRow][bombColumn] == 0) {
            bombs[bombRow][bombColumn] = 1;
            placed++; // placed increment until placed == bombcount
        }
    }

    // Game loop
    do {
        // Display current board
        printf("\nScreen:\n");
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                if (revealed[i][j])
                    printf("O ");
                else
                    printf("* ");
            }
            printf("\n");
        }

        // Get input from user
        printf("Enter row (1 to %d): ", size);
        scanf("%d", &row);
         printf("Enter column (1 to %d): ", size);
        scanf("%d", &column);
        // check user input 
        if (row < 1 || row > size || column < 1 || column > size) {
            printf("Invalid input!\n");
            continue;
        }

        if (revealed[row][column]) {
            printf("Already revealed.\n");
            continue;
        }

        // Check for bomb
        if (bombs[row][column]) {
            printf("\nBOOM! Game Over!\n");
            gameOver = 1;
        } else {
            revealed[row][column] = 1;
            safeRevealed++;
            printf("You're Safe!\n");

            if (safeRevealed == totalSafe) {
               printf("\nYou avoided all the bombs. You win!\n");
                //printf("\nYou found %d safe symbols. You win!\n", totalSafe);
                gameOver = 1; // istrue
            }
        }

        // Show final screen if bomb is hit
        if (gameOver && bombs[row][column]) {
            printf("\n(X = Bomb, O = Safe):\n");
            for (int i = 1; i <= size; i++) {
                for (int j = 1; j <= size; j++) {
                    if (bombs[i][j])
                        printf("X ");
                    else 
                        printf("O ");
                
                }
                printf("\n");
            }
        }

    } while (!gameOver);

    return 0;
}