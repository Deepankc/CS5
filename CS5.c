#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

//okay okay i ain't that smart, i did chatgpt the clearScreen function
void clearScreen() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear");  // Linux/macOS
    #endif
}

//Functions
			int checkSpaces(char grid[][3]){
					int spaces=0,i,j;
					for(i=0;i<3;i++){
				    	for(j=0;j<3;j++){
					        if(grid[i][j]==0){
					        	spaces++;
							}
				    	}
				    }
				    if(spaces==0){
				    	return 0;
					}
					else{
						return 1;
					}
				}
				
				int checkGame(char grid[][3]){
					if(grid[0][0]=='x' && grid[0][1]=='x' && grid[0][2]=='x'){
						return 0;
					}
					else if(grid[1][0]=='x' && grid[1][1]=='x' && grid[1][2]=='x'){
						return 0;
					}
					else if(grid[2][0]=='x' && grid[2][1]=='x' && grid[2][2]=='x'){
						return 0;
					}
					else if(grid[0][0]=='x' && grid[1][0]=='x' && grid[2][0]=='x'){
						return 0;
					}
					else if(grid[0][1]=='x' && grid[1][1]=='x' && grid[2][1]=='x'){
						return 0;
					}
					else if(grid[0][2]=='x' && grid[1][2]=='x' && grid[2][2]=='x'){
						return 0;
					}
					else if(grid[0][0]=='x' && grid[1][1]=='x' && grid[2][2]=='x'){
						return 0;
					}
					else if(grid[0][2]=='x' && grid[1][1]=='x' && grid[2][0]=='x'){
						return 0;
					}
					//
				    else if(grid[0][0]=='o' && grid[0][1]=='o' && grid[0][2]=='o'){
						return 0;
					}
					else if(grid[1][0]=='o' && grid[1][1]=='o' && grid[1][2]=='o'){
						return 0;
					}
					else if(grid[2][0]=='o' && grid[2][1]=='o' && grid[2][2]=='o'){
						return 0;
					}
					else if(grid[0][0]=='o' && grid[1][0]=='o' && grid[2][0]=='o'){
						return 0;
					}
					else if(grid[0][1]=='o' && grid[1][1]=='o' && grid[2][1]=='o'){
						return 0;
					}
					else if(grid[0][2]=='o' && grid[1][2]=='o' && grid[2][2]=='o'){
						return 0;
					}
					else if(grid[0][0]=='o' && grid[1][1]=='o' && grid[2][2]=='o'){
						return 0;
					}
					else if(grid[0][2]=='o' && grid[1][1]=='o' && grid[2][0]=='o'){
						return 0;
					}
					else{
						return 1;	
					}
					}
					
					int checkWinner(char grid[][3]){
						if(grid[0][0]=='x' && grid[0][1]=='x' && grid[0][2]=='x'){
						return 0;
					}
					else if(grid[1][0]=='x' && grid[1][1]=='x' && grid[1][2]=='x'){
						return 0;
					}
					else if(grid[2][0]=='x' && grid[2][1]=='x' && grid[2][2]=='x'){
						return 0;
					}
					else if(grid[0][0]=='x' && grid[1][0]=='x' && grid[2][0]=='x'){
						return 0;
					}
					else if(grid[0][1]=='x' && grid[1][1]=='x' && grid[2][1]=='x'){
						return 0;
					}
					else if(grid[0][2]=='x' && grid[1][2]=='x' && grid[2][2]=='x'){
						return 0;
					}
					else if(grid[0][0]=='x' && grid[1][1]=='x' && grid[2][2]=='x'){
						return 0;
					}
					else if(grid[0][2]=='x' && grid[1][1]=='x' && grid[2][0]=='x'){
						return 0;
					}
					//
					else if(grid[0][0]=='o' && grid[0][1]=='o' && grid[0][2]=='o'){
						return 1;
					}
					else if(grid[1][0]=='o' && grid[1][1]=='o' && grid[1][2]=='o'){
						return 1;
					}
					else if(grid[2][0]=='o' && grid[2][1]=='o' && grid[2][2]=='o'){
						return 1;
					}
					else if(grid[0][0]=='o' && grid[1][0]=='o' && grid[2][0]=='o'){
						return 1;
					}
					else if(grid[0][1]=='o' && grid[1][1]=='o' && grid[2][1]=='o'){
						return 1;
					}
					else if(grid[0][2]=='o' && grid[1][2]=='o' && grid[2][2]=='o'){
						return 1;
					}
					else if(grid[0][0]=='o' && grid[1][1]=='o' && grid[2][2]=='o'){
						return 1;
					}
					else if(grid[0][2]=='o' && grid[1][1]=='o' && grid[2][0]=='o'){
						return 1;
					}
					}
					
					int validateMove(char grid[][3],int row,int column){
						if(grid[row][column]==0){
							return 0;
						}
						else if(grid[0][0]!=0 && grid[0][1]!=0 && grid[0][2]!=0 && grid[1][0]!=0 && grid[1][1]!=0 && grid[1][2]!=0 && grid[2][0]!=0 && grid[2][1]!=0 && grid[2][2]!=0){
							return 0;
						}
						else{
							return 1;
						}
					}
					
				//hol' up
					
					
int home(){
	printf("=============================================================================\n");
	printf("                                  CS5 Games\n");
	printf("=============================================================================\n");
	printf("1.Tic Tac Toe\n");
	printf("2.Rock Paper Scissors\n");
	printf("3.Guess the number\n");
	printf("4.Heads or Tails\n");
	printf("5.Remember the number\n");
	printf("6.Exit\n");
	int option;
	printf("Select an option:");
	scanf("%i",&option);
	switch(option){
		case 1:
			printf("=============================================================================\n");
	    	printf("                                Tic Tac Toe\n");
			printf("=============================================================================\n");
					
			option=1;
			while(option==1){
				printf("1.Play\n");
		    	printf("2.Home\n");
				printf("Select an option:");
		    	scanf("%i",&option);
		    	if(option==2){
		    		break;
				}
				char grid[3][3]={0};
				int i,j;
				printf("Assuming you are lonely, you will be playing against a computer making random moves.\n");
				printf("Each box in the grid has been encoded as the below layout.Type the assigned index to play your move(x) there.\n");
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						printf("%i,%i   ",i,j);
					}
					printf("\n");
				}
				printf("-----------------------------------------------------------------------------\n");
				int row,column;
				while(checkSpaces(grid) && checkGame(grid)){
					printf("Enter your row and column:");
					scanf("%i %i",&row,&column);
					grid[row][column]='x';
					srand(time(0));
					int row=(rand()%(2-0+1))+0;
				   	int column=(rand()%(2-0+1))+0;
					while(validateMove(grid,row,column)){
						row=(rand()%(2-0+1))+0;
				    	column=(rand()%(2-0+1))+0;
					}
					if(grid[row][column]==0){
						grid[row][column]='o';
					}
					for(i=0;i<3;i++){
					    for(j=0;j<3;j++){
						    printf("%c", grid[i][j] == 0 ? '-' : grid[i][j]);
				    	}
				    	printf("\n");
				    }
				    printf("\n");
				}
				if(checkWinner(grid)==0){
					printf("YOU WON!!!\n");
				}
				else if(checkWinner(grid)==1){
					printf("COMPUTER WON!!!\n");
				}
				else{
				    printf("DRAW!\n");	
				}
				getch();
              clearScreen();
			}
			home();
		break;
		
		case 2:
			printf("=============================================================================\n");
	    	printf("                               Rock Paper Scissors\n");
			printf("=============================================================================\n");
			option=1;
			while(option==1){
				printf("1.Play\n");
		    	printf("2.Home\n");
				printf("Select an option:");
		    	scanf("%i",&option);
		    	if(option==2){
		    		break;
				}
				printf("Assuming you are lonely like me, you will be playing against a computer making random moves.\n");
				printf("Type the corresponding number to play that move.\n");
				printf("1.Rock\n");
				printf("2.Paper\n");
				printf("3.Scissors\n");
				printf("-----------------------------------------------------------------------------\n");
				int playerMove;
				printf("Play your move:");
				scanf("%i",&playerMove);
				switch(playerMove){
					case 1:
						printf("You played Rock. ");
					break;
					case 2:
						printf("You played Paper. ");
					break;
					case 3:
						printf("You played Scissors. ");
					break;
				}
				srand(time(0));
				int computerMove=(rand()%(3-1+1))+1;
				switch(computerMove){
					case 1:
						printf("Computer played Rock.\n");
					break;
					case 2:
						printf("Computer played Paper.\n");
					break;
					case 3:
						printf("Computer played Scissors.\n");
					break;
				}
				if(playerMove==computerMove){
					printf("DRAW!");
				}
				else if(playerMove==1 && computerMove==2 ){
					printf("COMPUTER WINS!!!");
				}
				else if(playerMove==1 && computerMove==3 ){
					printf("YOU WIN!!!");
				}
				else if(playerMove==2 && computerMove==1 ){
					printf("YOU WIN!!!");
				}
				else if(playerMove==2 && computerMove==3 ){
					printf("COMPUTER WINS!!!");
				}
				else if(playerMove==3 && computerMove==1 ){
					printf("COMPUTER WINS!!!");
				}
				else if(playerMove==3 && computerMove==2 ){
					printf("YOU WIN!!!");
				}
				printf("\n");
				printf("-----------------------------------------------------------------------------\n");
				getch();
              clearScreen();
			}
			home();
		break;	
		
		case 3:
	    	printf("=============================================================================\n");
	    	printf("                               Guess The Number\n");
			printf("=============================================================================\n");
		    option=1;
			while(option==1){
				printf("1.Play\n");
		    	printf("2.Home\n");
				printf("Select an option:");
		    	scanf("%i",&option);
		    	if(option==2){
		    		break;
				}
				printf("\nThe computer will generate a random number from 1 to 100 without telling you and you have to guess the number within 10 tries. If your guess is higher than\
 the generated number ,the console will print \"Too High\" and if your guess is lower, the console will print \"Too Low\"\n");
				getch();
				srand(time(0));
				int randnum=(rand()%(100-1+1))+1,guess=10,num=-1;
				while(guess>=1 || randnum!=num){
					printf("No. of guesses left:%d\n",guess);
					printf("Guess:");
					scanf("%d",&num);
					if(randnum>num){
						printf("Too Low.\n");
					}
					else if(randnum<num){
						printf("Too High.\n");
					}
					else{
						printf("CORRECT!!!\n");
						break;
					}
					guess--;
				}
             printf("-----------------------------------------------------------------------------\n");
              clearScreen();
			}
			home();
		break;	
		
		case 4:
			printf("=============================================================================\n");
	    	printf("                               Heads or Tails\n");
			printf("=============================================================================\n");
		option=1;
			while(option==1){
				printf("1.Play\n");
		    	printf("2.Home\n");
				printf("Select an option:");
		    	scanf("%i",&option);
		    	if(option==2){
		    		break;
				}
				printf("Call dibs on either heads or tails.\n");
				printf("Type the corresponding number to call dibs on that side.\n");
				printf("1.Heads\n");
				printf("2.Tails\n");
				int side;
				printf("Call dibs on:");
				scanf("%i",&side);
				switch(side){
					case 1:
						printf("You called dibs on Heads.\n");
					break;
					case 2:
						printf("You called dibs on Tails.\n");
					break;
				}
				srand(time(0));
				int randSide=(rand()%2)+1;
				switch(randSide){
					case 1:
						printf("It landed Heads.\n");
					break;
					case 2:
						printf("It landed Tails.\n");
					break;
				}
				if(randSide==side){
					printf("You won.\n");
				}
				else{
					printf("BRUHHHHH you lost with 1 in 2 odds.\n");
				}
				printf("-----------------------------------------------------------------------------\n");
				getch();
				clearScreen();
			}
			home();
		break;	
		
		case 5:
			printf("=============================================================================\n");
	    	printf("                              Remember The Number\n");
			printf("=============================================================================\n");
			option=1;
			while(option==1){
				printf("1.Play\n");
		    	printf("2.Home\n");
				printf("Select an option:");
		    	scanf("%i",&option);
		    	if(option==2){
		    		break;
				}
				printf("The computer will generate a random n digit number then,it will clear the screen and you have to remember the number.\n");
				int n;
				printf("Enter the value of n:");
				scanf("%i",&n);
				srand(time(0));
				int randnum=(rand()%((int)(pow(10,n)-1)-(int)(pow(10,n-1))+1))+(int)pow(10,n-1);
				printf("Your number is %i.",randnum);
				getch();
				clearScreen();
				int num;
				printf("Enter the number:");
				scanf("%i",&num);
				if(num==randnum){
					printf("CORRECT!!!\n");
				}
				else{
					printf("INCORRECT!\n");
					printf("The number was %i.",randnum);
				}
				printf("-----------------------------------------------------------------------------\n");
              getch();
              clearScreen();
			}
			home();
		break;	
		
		case 6:
			return 0;
		break;
	}
    return 0;
}

//=============================================================================================================================================
//=============================================================================================================================================
//=============================================================================================================================================

int main(){
	home();
}
