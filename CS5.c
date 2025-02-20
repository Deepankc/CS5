#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<math.h>
#include<string.h>

struct user {
    char username[100];
    int ticTacToeWins;
    int ticTacToeLosses;
    int rockPaperScissorsWins;
    int rockPaperScissorsLosses;
    int guessTheNumberWins;
    int guessTheNumberLosses;
    int headsOrTailsWins;
    int headsOrTailsLosses;
    int rememberTheNumberWins;
    int rememberTheNumberLosses;
};

struct user currentUser;
int loggedIn = 0;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// File handling functions - updated to use text file
void saveUser() {
    FILE *fp = fopen("users.txt", "a");  // Append mode for text file
    if(fp != NULL) {
        fprintf(fp, "%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", 
            currentUser.username,
            currentUser.ticTacToeWins,
            currentUser.ticTacToeLosses,
            currentUser.rockPaperScissorsWins,
            currentUser.rockPaperScissorsLosses,
            currentUser.guessTheNumberWins,
            currentUser.guessTheNumberLosses,
            currentUser.headsOrTailsWins,
            currentUser.headsOrTailsLosses,
            currentUser.rememberTheNumberWins,
            currentUser.rememberTheNumberLosses);
        fclose(fp);
    }
}

void updateUserStats() {
    FILE *fpRead = fopen("users.txt", "r");
    FILE *fpTemp = fopen("temp.txt", "w");
    
    char line[256];
    int found = 0;
    
    if(fpRead != NULL && fpTemp != NULL) {
        while(fgets(line, sizeof(line), fpRead)) {
            // Remove newline character if present
            line[strcspn(line, "\n")] = 0;
            
            char username[100];
            char *token = strtok(line, ",");
            if(token != NULL) {
                strcpy(username, token);
                
                if(strcmp(username, currentUser.username) == 0) {
                    // Found the user, update with current stats
                    fprintf(fpTemp, "%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n", 
                        currentUser.username,
                        currentUser.ticTacToeWins,
                        currentUser.ticTacToeLosses,
                        currentUser.rockPaperScissorsWins,
                        currentUser.rockPaperScissorsLosses,
                        currentUser.guessTheNumberWins,
                        currentUser.guessTheNumberLosses,
                        currentUser.headsOrTailsWins,
                        currentUser.headsOrTailsLosses,
                        currentUser.rememberTheNumberWins,
                        currentUser.rememberTheNumberLosses);
                    found = 1;
                } else {
                    // Copy the line as is
                    fprintf(fpTemp, "%s\n", line);
                }
            }
        }
        
        fclose(fpRead);
        fclose(fpTemp);
        
        // Delete original file and rename temp file
        remove("users.txt");
        rename("temp.txt", "users.txt");
    }
    
    if(!found) {
        saveUser();
    }
}

int loginUser(char *username) {
    FILE *fp = fopen("users.txt", "r");  // Read mode for text file
    int found = 0;
    char line[256];
    
    if(fp != NULL) {
        while(fgets(line, sizeof(line), fp)) {
            // Remove newline character if present
            line[strcspn(line, "\n")] = 0;
            
            char *token = strtok(line, ",");
            if(token != NULL && strcmp(token, username) == 0) {
                strcpy(currentUser.username, token);
                
                // Parse remaining values
                token = strtok(NULL, ",");
                currentUser.ticTacToeWins = atoi(token);
                
                token = strtok(NULL, ",");
                currentUser.ticTacToeLosses = atoi(token);
                
                token = strtok(NULL, ",");
                currentUser.rockPaperScissorsWins = atoi(token);
                
                token = strtok(NULL, ",");
                currentUser.rockPaperScissorsLosses = atoi(token);
                
                token = strtok(NULL, ",");
                currentUser.guessTheNumberWins = atoi(token);
                
                token = strtok(NULL, ",");
                currentUser.guessTheNumberLosses = atoi(token);
                
                token = strtok(NULL, ",");
                currentUser.headsOrTailsWins = atoi(token);
                
                token = strtok(NULL, ",");
                currentUser.headsOrTailsLosses = atoi(token);
                
                token = strtok(NULL, ",");
                currentUser.rememberTheNumberWins = atoi(token);
                
                token = strtok(NULL, ",");
                currentUser.rememberTheNumberLosses = atoi(token);
                
                found = 1;
                break;
            }
        }
        fclose(fp);
    }
    
    return found;
}

void registerUser(char *username) {
    strcpy(currentUser.username, username);
    currentUser.ticTacToeWins = 0;
    currentUser.ticTacToeLosses = 0;
    currentUser.rockPaperScissorsWins = 0;
    currentUser.rockPaperScissorsLosses = 0;
    currentUser.guessTheNumberWins = 0;
    currentUser.guessTheNumberLosses = 0;
    currentUser.headsOrTailsWins = 0;
    currentUser.headsOrTailsLosses = 0;
    currentUser.rememberTheNumberWins = 0;
    currentUser.rememberTheNumberLosses = 0;
    
    saveUser();
}

void displayStats() {
    printf("\nUser Statistics for %s:\n", currentUser.username);
    printf("Tic Tac Toe: Wins: %d, Losses: %d\n", currentUser.ticTacToeWins, currentUser.ticTacToeLosses);
    printf("Rock Paper Scissors: Wins: %d, Losses: %d\n", currentUser.rockPaperScissorsWins, currentUser.rockPaperScissorsLosses);
    printf("Guess The Number: Wins: %d, Losses: %d\n", currentUser.guessTheNumberWins, currentUser.guessTheNumberLosses);
    printf("Heads or Tails: Wins: %d, Losses: %d\n", currentUser.headsOrTailsWins, currentUser.headsOrTailsLosses);
    printf("Remember The Number: Wins: %d, Losses: %d\n", currentUser.rememberTheNumberWins, currentUser.rememberTheNumberLosses);
}

// Game Helper Functions
int checkSpaces(char grid[][3]) {
    int spaces = 0;
    int i,j;
    for( i = 0; i < 3; i++) {
        for( j = 0; j < 3; j++) {
            if(grid[i][j] == 0) {
                spaces++;
            }
        }
    }
    return spaces > 0;
}

int checkWinner(char grid[][3]) {
	int i,j;
    // Check rows, columns and diagonals for X (player)
    for(i = 0; i < 3; i++) {
        if(grid[i][0] == 'x' && grid[i][1] == 'x' && grid[i][2] == 'x') return 0;
        if(grid[0][i] == 'x' && grid[1][i] == 'x' && grid[2][i] == 'x') return 0;
    }
    if(grid[0][0] == 'x' && grid[1][1] == 'x' && grid[2][2] == 'x') return 0;
    if(grid[0][2] == 'x' && grid[1][1] == 'x' && grid[2][0] == 'x') return 0;

    // Check rows, columns and diagonals for O (computer)
    for( i = 0; i < 3; i++) {
        if(grid[i][0] == 'o' && grid[i][1] == 'o' && grid[i][2] == 'o') return 1;
        if(grid[0][i] == 'o' && grid[1][i] == 'o' && grid[2][i] == 'o') return 1;
    }
    if(grid[0][0] == 'o' && grid[1][1] == 'o' && grid[2][2] == 'o') return 1;
    if(grid[0][2] == 'o' && grid[1][1] == 'o' && grid[2][0] == 'o') return 1;

    return -1; // No winner yet
}

int validateMove(char grid[][3], int row, int column) {
    if(row < 0 || row > 2 || column < 0 || column > 2) return 0;
    return grid[row][column] == 0;
}

// Game Implementations
void playTicTacToe() {
    printf("=============================================================================\n");
    printf("                                Tic Tac Toe\n");
    printf("=============================================================================\n");

    char grid[3][3] = {0};
    printf("You are 'x', computer is 'o'\n");
    printf("Enter row and column numbers (0-2) to make your move\n\n");

    while(checkSpaces(grid)) {
    	int i,j;
        // Display grid
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                printf("%c ", grid[i][j] == 0 ? '-' : grid[i][j]);
            }
            printf("\n");
        }

        // Player move
        int row, column;
        do {
            printf("\nYour move (row column): ");
            scanf("%d %d", &row, &column);
        } while(!validateMove(grid, row, column));

        grid[row][column] = 'x';

        // Check for player win
        if(checkWinner(grid) == 0) {
            currentUser.ticTacToeWins++;
            printf("\nYOU WIN!\n");
            updateUserStats();
            return;
        }

        // Computer move
        if(checkSpaces(grid)) {
            do {
                row = rand() % 3;
                column = rand() % 3;
            } while(!validateMove(grid, row, column));

            grid[row][column] = 'o';

            // Check for computer win
            if(checkWinner(grid) == 1) {
                currentUser.ticTacToeLosses++;
                printf("\nCOMPUTER WINS!\n");
                updateUserStats();
                return;
            }
        }
    }

    printf("\nDRAW!\n");
}

void playRockPaperScissors() {
    printf("=============================================================================\n");
    printf("                            Rock Paper Scissors\n");
    printf("=============================================================================\n");

    printf("1. Rock\n2. Paper\n3. Scissors\n");
    
    int playerMove;
    printf("Enter your move (1-3): ");
    scanf("%d", &playerMove);

    int computerMove = (rand() % 3) + 1;

    // Display moves
    const char* moves[] = {"Rock", "Paper", "Scissors"};
    printf("\nYou chose: %s\n", moves[playerMove-1]);
    printf("Computer chose: %s\n", moves[computerMove-1]);

    // Determine winner
    if(playerMove == computerMove) {
        printf("\nIt's a draw!\n");
    } else if((playerMove == 1 && computerMove == 3) || 
              (playerMove == 2 && computerMove == 1) || 
              (playerMove == 3 && computerMove == 2)) {
        currentUser.rockPaperScissorsWins++;
        printf("\nYou win!\n");
    } else {
        currentUser.rockPaperScissorsLosses++;
        printf("\nComputer wins!\n");
    }
    
    updateUserStats();
}

void playGuessTheNumber() {
    printf("=============================================================================\n");
    printf("                            Guess The Number\n");
    printf("=============================================================================\n");

    int number = rand() % 100 + 1;
    int guess, attempts = 0;
    const int MAX_ATTEMPTS = 10;

    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have %d attempts to guess it.\n\n", MAX_ATTEMPTS);

    while(attempts < MAX_ATTEMPTS) {
        printf("Attempt %d/%d. Enter your guess: ", attempts + 1, MAX_ATTEMPTS);
        scanf("%d", &guess);
        attempts++;

        if(guess == number) {
            currentUser.guessTheNumberWins++;
            printf("\nCongratulations! You guessed the number in %d attempts!\n", attempts);
            updateUserStats();
            return;
        } else if(guess < number) {
            printf("Too low!\n");
        } else {
            printf("Too high!\n");
        }
    }

    currentUser.guessTheNumberLosses++;
    printf("\nGame Over! The number was %d\n", number);
    updateUserStats();
}

void playHeadsOrTails() {
    printf("=============================================================================\n");
    printf("                            Heads or Tails\n");
    printf("=============================================================================\n");

    printf("1. Heads\n2. Tails\n");
    int choice;
    printf("Make your choice (1-2): ");
    scanf("%d", &choice);

    int result = (rand() % 2) + 1;

    printf("\nYou chose: %s\n", choice == 1 ? "Heads" : "Tails");
    printf("Coin shows: %s\n", result == 1 ? "Heads" : "Tails");

    if(choice == result) {
        currentUser.headsOrTailsWins++;
        printf("\nYou win!\n");
    } else {
        currentUser.headsOrTailsLosses++;
        printf("\nYou lose!\n");
    }

    updateUserStats();
}

void playRememberTheNumber() {
    printf("=============================================================================\n");
    printf("                          Remember The Number\n");
    printf("=============================================================================\n");

    printf("Enter number of digits (1-9): ");
    int digits;
    scanf("%d", &digits);

    // Generate random number
    int min = pow(10, digits-1);
    int max = pow(10, digits) - 1;
    int number = rand() % (max - min + 1) + min;

    printf("\nRemember this number: %d\n", number);
    printf("You have 5 seconds...\n");

    // Wait 5 seconds
    sleep(5);
    clearScreen();

    int guess;
    printf("What was the number? ");
    scanf("%d", &guess);

    if(guess == number) {
        currentUser.rememberTheNumberWins++;
        printf("\nCorrect! Well done!\n");
    } else {
        currentUser.rememberTheNumberLosses++;
        printf("\nSorry, the number was %d\n", number);
    }

    updateUserStats();
}

int home() {
    srand(time(NULL));  // Initialize random seed

    while(1) {
        printf("=============================================================================\n");
        printf("                                  CS5 Games\n");
        printf("=============================================================================\n");
        
        if(!loggedIn) {
            printf("1. Sign Up\n");
            printf("2. Login\n");
            printf("3. Exit\n");
            
            int option;
            printf("Choose your option: ");
            scanf("%d", &option);
            
            char username[100];
            switch(option) {
                case 1:
                    printf("Enter a username: ");
                    scanf("%s", username);
                    registerUser(username);
                    loggedIn = 1;
                    printf("Registration successful!\n");
                    break;
                    
                case 2:
                    printf("Enter your username: ");
                    scanf("%s", username);
                    if(loginUser(username)) {
                        loggedIn = 1;
                        printf("Login successful!\n");
                    } else {
                        printf("User not found!\n");
                    }
                    break;
                    
                case 3:
                    return 0;
            }
            continue;
        }
        
        printf("\n1. Tic Tac Toe\n");
        printf("2. Rock Paper Scissors\n");
        printf("3. Guess the number\n");
        printf("4. Heads or Tails\n");
        printf("5. Remember the number\n");
        printf("6. View Statistics\n");
        printf("7. Logout\n");
        printf("8. Exit\n");
        
        int option;
        printf("\nSelect an option: ");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                playTicTacToe();
                break;
            case 2:
                playRockPaperScissors();
                break;
            case 3:
                playGuessTheNumber();
                break;
            case 4:
                playHeadsOrTails();
                break;
            case 5:
                playRememberTheNumber();
                break;
            case 6:
                displayStats();
                break;
            case 7:
                loggedIn = 0;
                printf("\nLogged out successfully!\n");
                break;
            case 8:
                return 0;
        }
        
        printf("\nPress any key to continue...");
        getch();
        clearScreen();
    }
}

int main() {
    home();
    return 0;
}
