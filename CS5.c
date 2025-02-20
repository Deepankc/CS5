#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <unistd.h>  // For sleep function

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
//file handling:
void saveUser() {
    FILE *fp = fopen("users.txt", "a");  // Append mode for text file
    if (fp != NULL) {
        fprintf(fp, "Username: %s\n", currentUser.username);
        fprintf(fp, "Tic Tac Toe: Wins: %d, Losses: %d\n", currentUser.ticTacToeWins, currentUser.ticTacToeLosses);
        fprintf(fp, "Rock Paper Scissors: Wins: %d, Losses: %d\n", currentUser.rockPaperScissorsWins, currentUser.rockPaperScissorsLosses);
        fprintf(fp, "Guess The Number: Wins: %d, Losses: %d\n", currentUser.guessTheNumberWins, currentUser.guessTheNumberLosses);
        fprintf(fp, "Heads or Tails: Wins: %d, Losses: %d\n", currentUser.headsOrTailsWins, currentUser.headsOrTailsLosses);
        fprintf(fp, "Remember The Number: Wins: %d, Losses: %d\n", currentUser.rememberTheNumberWins, currentUser.rememberTheNumberLosses);
        fprintf(fp, "----------------------------------------\n");
        fclose(fp);
    }
}
//this is used to store the records of the users.
void updateUserStats() {
    FILE *fpRead = fopen("users.txt", "r");
    FILE *fpTemp = fopen("temp.txt", "w");
    
    char line[256];
    int found = 0;
    
    if (fpRead != NULL && fpTemp != NULL) {
        while (fgets(line, sizeof(line), fpRead)) {
            
            if (strstr(line, "Username:") != NULL) {
                char username[100];
                sscanf(line, "Username: %s", username);
                
                if (strcmp(username, currentUser.username) == 0) {
                	int i;
                    fprintf(fpTemp, "Username: %s\n", currentUser.username);
                    fprintf(fpTemp, "Tic Tac Toe: Wins: %d, Losses: %d\n", currentUser.ticTacToeWins, currentUser.ticTacToeLosses);
                    fprintf(fpTemp, "Rock Paper Scissors: Wins: %d, Losses: %d\n", currentUser.rockPaperScissorsWins, currentUser.rockPaperScissorsLosses);
                    fprintf(fpTemp, "Guess The Number: Wins: %d, Losses: %d\n", currentUser.guessTheNumberWins, currentUser.guessTheNumberLosses);
                    fprintf(fpTemp, "Heads or Tails: Wins: %d, Losses: %d\n", currentUser.headsOrTailsWins, currentUser.headsOrTailsLosses);
                    fprintf(fpTemp, "Remember The Number: Wins: %d, Losses: %d\n", currentUser.rememberTheNumberWins, currentUser.rememberTheNumberLosses);
                    fprintf(fpTemp, "----------------------------------------\n");
                    found = 1;
                    for (i = 0; i < 5; i++) {
                        fgets(line, sizeof(line), fpRead);
                    }
                } else {
                    
                    fprintf(fpTemp, "%s", line);
                }
            } else {
                
                fprintf(fpTemp, "%s", line);
            }
        }
        
        fclose(fpRead);
        fclose(fpTemp);
        
       
        remove("users.txt");
        rename("temp.txt", "users.txt");
    }
    
    if (!found) {
        saveUser();
    }
}

int loginUser(char *username) {
    FILE *fp = fopen("users.txt", "r");  
    int found = 0;
    char line[256];
    
    if (fp != NULL) {
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, "Username:") != NULL) {
                char fileUsername[100];
                sscanf(line, "Username: %s", fileUsername);
                
                if (strcmp(fileUsername, username) == 0) {
                    strcpy(currentUser.username, fileUsername);
                    int i;
                    for (i = 0; i < 5; i++) {
                        fgets(line, sizeof(line), fp);
                        if (strstr(line, "Tic Tac Toe:") != NULL) {
                            sscanf(line, "Tic Tac Toe: Wins: %d, Losses: %d", &currentUser.ticTacToeWins, &currentUser.ticTacToeLosses);
                        } else if (strstr(line, "Rock Paper Scissors:") != NULL) {
                            sscanf(line, "Rock Paper Scissors: Wins: %d, Losses: %d", &currentUser.rockPaperScissorsWins, &currentUser.rockPaperScissorsLosses);
                        } else if (strstr(line, "Guess The Number:") != NULL) {
                            sscanf(line, "Guess The Number: Wins: %d, Losses: %d", &currentUser.guessTheNumberWins, &currentUser.guessTheNumberLosses);
                        } else if (strstr(line, "Heads or Tails:") != NULL) {
                            sscanf(line, "Heads or Tails: Wins: %d, Losses: %d", &currentUser.headsOrTailsWins, &currentUser.headsOrTailsLosses);
                        } else if (strstr(line, "Remember The Number:") != NULL) {
                            sscanf(line, "Remember The Number: Wins: %d, Losses: %d", &currentUser.rememberTheNumberWins, &currentUser.rememberTheNumberLosses);
                        }
                    }
                    
                    found = 1;
                    break;
                }
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


int checkSpaces(char grid[][3]) {
    int spaces = 0,i,j;
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            if (grid[i][j] == 0) {
                spaces++;
            }
        }
    }
    return spaces > 0;
}

int checkWinner(char grid[][3]) {           //yeah we know this looks complex and we dont deny that we took (SOME) help from gpt.
	int i;
    for (i = 0; i < 3; i++) {
        if (grid[i][0] == 'x' && grid[i][1] == 'x' && grid[i][2] == 'x') return 0;
        if (grid[0][i] == 'x' && grid[1][i] == 'x' && grid[2][i] == 'x') return 0;
    }
    if (grid[0][0] == 'x' && grid[1][1] == 'x' && grid[2][2] == 'x') return 0;
    if (grid[0][2] == 'x' && grid[1][1] == 'x' && grid[2][0] == 'x') return 0;

    for ( i = 0; i < 3; i++) {
        if (grid[i][0] == 'o' && grid[i][1] == 'o' && grid[i][2] == 'o') return 1;
        if (grid[0][i] == 'o' && grid[1][i] == 'o' && grid[2][i] == 'o') return 1;
    }
    if (grid[0][0] == 'o' && grid[1][1] == 'o' && grid[2][2] == 'o') return 1;
    if (grid[0][2] == 'o' && grid[1][1] == 'o' && grid[2][0] == 'o') return 1;

    return -1; 
}

int validateMove(char grid[][3], int row, int column) {
    if (row < 0 || row > 2 || column < 0 || column > 2) return 0;
    return grid[row][column] == 0;
}


void playTicTacToe() {
    printf("=============================================================================\n");
    printf("                                Tic Tac Toe\n");
    printf("=============================================================================\n");

    char grid[3][3] = {0};
    printf("You are 'x', computer is 'o'\n");
    printf("Enter row and column numbers (0-2) to make your move\n\n");

    while (checkSpaces(grid)) {
    	int i,j;
     
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%c ", grid[i][j] == 0 ? '-' : grid[i][j]);
            }
            printf("\n");
        }
        int row, column;
        do {
            printf("\nYour move (row column): ");
            scanf("%d %d", &row, &column);
        } while (!validateMove(grid, row, column));

        grid[row][column] = 'x';
        if (checkWinner(grid) == 0) {
            currentUser.ticTacToeWins++;
            printf("\nYOU WIN!\n");
            updateUserStats();
            return;
        }
        if (checkSpaces(grid)) {
            do {
                row = rand() % 3;                             //yeah yeah we use the rand() function from internet. 
                column = rand() % 3;
            } while (!validateMove(grid, row, column));

            grid[row][column] = 'o';

            if (checkWinner(grid) == 1) {
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
    const char* moves[] = {"Rock", "Paper", "Scissors"};
    printf("\nYou chose: %s\n", moves[playerMove-1]);
    printf("Computer chose: %s\n", moves[computerMove-1]);

    if (playerMove == computerMove) {
        printf("\nIt's a draw!\n");
    } else if ((playerMove == 1 && computerMove == 3) || 
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

void playGuessTheNumber() {                                                                //this was the easiest to make among other games but difficult to win.
    printf("=============================================================================\n");
    printf("                            Guess The Number\n");
    printf("=============================================================================\n");

    int number = rand() % 100 + 1; 
    int guess, attempts = 0;
    const int MAX_ATTEMPTS = 10;

    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have %d attempts to guess it.\n\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt %d/%d. Enter your guess: ", attempts + 1, MAX_ATTEMPTS);
        scanf("%d", &guess);
        attempts++;

        if (guess == number) {
            currentUser.guessTheNumberWins++;
            printf("\nCongratulations! You guessed the number in %d attempts!\n", attempts);
            updateUserStats();
            return;
        } else {
            int difference = abs(guess - number); 

            if (difference >= 10) {
                if (guess < number) {
                    printf("Too low!\n");
                } else {
                    printf("Too high!\n");
                }
            } else {
                if (guess < number) {
                    printf("Low.\n");
                } else {
                    printf("High.\n");
                }
            }
        }
    }

    currentUser.guessTheNumberLosses++;
    printf("\nGame Over! The number was %d\n", number);
    updateUserStats();
}

void playHeadsOrTails() { //if you cant even win this game then your'e not a gamer your'e noob than a bot.
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

    if (choice == result) {
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
    int min = pow(10, digits-1);
    int max = pow(10, digits) - 1;
    int number = rand() % (max - min + 1) + min;             //this rand() function is very usefull not gonna lie.

    printf("\nRemember this number: %d\n", number);
    printf("You have 5 seconds...\n");
    sleep(5);
    clearScreen();

    int guess;
    printf("What was the number? ");
    scanf("%d", &guess);

    if (guess == number) {
        currentUser.rememberTheNumberWins++;
        printf("\nCorrect! Well done!\n");
    } else {
        currentUser.rememberTheNumberLosses++;
        printf("\nSorry, the number was %d\n", number);
    }

    updateUserStats();
}

int home() {
    srand(time(NULL));

    while (1) {
        printf("=============================================================================\n");
        printf("                                  CS5 Games\n");
        printf("=============================================================================\n");
        
        if (!loggedIn) {
            printf("1. Sign Up\n");
            printf("2. Login\n");
            printf("3. Exit\n");
            
            int option;
            printf("Choose your option: ");
            scanf("%d", &option);
            
            char username[100];
            switch (option) {
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
                    if (loginUser(username)) {
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
        
        switch (option) {
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
}                   //finally all the hardwork ends in this line. Thank you for enjoying the games.
