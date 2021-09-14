#include<stdio.h>
//Pseudocode
//1. Create a turn based function to determine who's move is it, x or o (finished)
//2. Replicate a board wit the use of lines  (finished)
//3. Create a 2d array that would represent the board (finished) 
//4. Ask x or o the position of their move using the row x column coordinatee system (finished)
//5. Create a checker that would tell x or o if their move is already occupied by their opponent (finished)
//6. Create a checker after x's first 3 moves if they won or not(in this game x always go first) (finished)
//7. Stop the game and declare victory to the victor or if all the slots in the board have been occupied (finished)
//8. Create a plotter for X and O in the grid (finished)

int Board[3][3]={{1,2,3}, {4,5,6}, {7,8,9}};
char displayGrid[5][11] = { {' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '}, {'-','-','-','+','-','-','-','+','-','-','-'}, {' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '}, {'-','-','-','+','-','-','-','+','-','-','-'}, {' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '} };
char printGrid();
int occupied[50];
int check(int val, int counter, int i, int detect);
void plot(int rowChoice, int colChoice, char temp);
int checkWin(char temp);
int moves=0, gameOver=0;

int main(){
    int rowChoice, colChoice, counter=0, i=0, stay=1, detect=0;
    char player1='X';
    char player2='O';
    char temp=player1;
    printGrid();
    while(moves<9 && gameOver==0){
        temp=player1;
        player1=player2;
        player2=temp;
        if(stay==0){
            temp=player1;
            player1=player2;
            player2=temp;
            counter++;
        }
        do
        {
        printf("%c's turn\n", temp);
        printf("Enter row and column: ");
        scanf("%i %i", &rowChoice, &colChoice);
        } while (rowChoice<0 || rowChoice>=3 || colChoice<0 || colChoice>=3);
        int val = Board[rowChoice][colChoice];
        printf("\n");
        counter++;
        stay = check(val, counter, i, detect);
        if(stay==1){
            moves++;
            i++;
            plot(rowChoice, colChoice, temp);
            gameOver=checkWin(temp);
        }
        printGrid();
    }
    
}

// Prints the Game Board
char printGrid(){
    for(int i=0; i<5; i++){
        for(int j=0; j<11; j++)
            printf("%c", displayGrid[i][j]);
    printf("\n");
    }
}

// Checks if there are moves duplicated and tells whether theh slot is occupied or not
int check(int val, int counter, int i, int detect){
    for(int x=0; x<=counter; x++){
        if(occupied[x] == val){
            printf("Sorry slot is occupied\n");
            detect=1;
        }    
    }
    if(detect)
        return 0;
    else{
        occupied[i]=val;
        return 1;
    }

}

// Plots the moves of the players
void plot(int rowChoice, int colChoice, char temp){
    if(rowChoice==0){
        if(colChoice==0){
            displayGrid[0][1] = temp;
        }
        else if(colChoice==1){
            displayGrid[0][5] = temp;
        }
        else if(colChoice==2){
            displayGrid[0][9] = temp;
        }
    }
    else if(rowChoice==1){
        if(colChoice==0){
            displayGrid[2][1] = temp;
        }
        else if(colChoice==1){
            displayGrid[2][5] = temp;
        }
        else if(colChoice==2){
            displayGrid[2][9] = temp;
        }
    }
    else if(rowChoice==2){
        if(colChoice==0){
            displayGrid[4][1] = temp;
        }
        else if(colChoice==1){
            displayGrid[4][5] = temp;
        }
        else if(colChoice==2){
            displayGrid[4][9] = temp;
        }
    }
}

// Checks if the player won or not
int checkWin(char temp){
    if(displayGrid[0][1]==temp && displayGrid[0][5]==temp && displayGrid[0][9]==temp){
        printf("\n%c won the game\n", temp);
        return 1;
    }
    if(temp==displayGrid[2][1] && temp==displayGrid[2][5] && temp==displayGrid[2][9]){
        printf("\n%c won the game\n", temp);
        return 1;
    }
    if(temp==displayGrid[4][1] && temp==displayGrid[4][5] && temp==displayGrid[4][9]){
        printf("\n%c won the game\n", temp);
        return 1;
    }
    if(temp==displayGrid[0][1] && temp==displayGrid[2][1] && temp==displayGrid[4][1]){
        printf("\n%c won the game\n", temp);
        return 1;
    }
    if(temp==displayGrid[0][5] && temp==displayGrid[2][5] && temp==displayGrid[4][5]){
        printf("\n%c won the game\n", temp);
        return 1;
    }
    if(temp==displayGrid[0][9] && temp==displayGrid[2][9] && temp==displayGrid[4][9]){
        printf("\n%c won the game\n", temp);
        return 1;
    }
    if(temp==displayGrid[0][1] && temp==displayGrid[2][5] && temp==displayGrid[4][9]){
        printf("\n%c won the game\n", temp);
        return 1;
    }
    if(temp==displayGrid[0][9] && temp==displayGrid[2][5] && temp==displayGrid[4][1]){
        printf("\n%c won the game\n", temp);
        return 1;
    }
    else 
        return 0;
    
}