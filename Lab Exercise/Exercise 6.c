/*  WARNING
    This code took me a while to debug and I apologize in advance for the hacky code I wrote...
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char player[4] = {'a','b','c','d'};
int row[10] = {29,26,23,20,17,14,11,8,5,2};
int col[10] = {49,44,39,34,29,24,19,14,9,4};
int revarr[10] = {26,25,20,19,14,13,8,7,2,1};
char board[31][51];
int SnakeHead_row[3];
int SnakeHead_col[3];
int SnakeTail_row[3];
int SnakeTail_col[3];
int LadderHead_row[3];
int LadderHead_col[3];
int LadderTail_row[3];
int LadderTail_col[3];
int lastColCoord[4];
int lastRowCoord[4];
int temp_lastColCoord[4];
int temp_lastRowCoord[4];
int gameOver=0;
//delegates the necessary characters for the game board
void board_val(){
    for(int i=30; i>=0; i--){
        for(int j=50; j>=0; j--){
            if(i%3==0){
                if(j%5==0)
                    *(*(board+i)+j) = '+';
                else 
                    *(*(board+i)+j) = '-';
            }
            else 
                if(j%5==0)
                    *(*(board+i)+j) = '|';
                else 
                    *(*(board+i)+j) = ' ';
        }
    }
}
// plots the initial position for the players
void initial_plot(){
    for(int i=0,j=1; i<=4, j<=4; i++,j++){
        *(*(board+1)+j) = *(player+i);
        *(*(board+29)+49) = '#';
        }
}
// Checks for redundant positioning of Snakes and Ladders
int randomSnl_check(){
    int counter=0;
    for(int i=30; i>=0; i--){
        for(int j=50; j>=0; j--){
            if(*(*(board+i)+j)=='S' || *(*(board+i)+j)=='s' || *(*(board+i)+j)=='L' || *(*(board+i)+j)=='l')
                counter++;
        }
    }
    if(counter==12)
        return 0;
    else 
        return 1;
}
//randomize the position of the Snakes and Ladders
void randomSnL(){
    // the coordinates for the Snake Head and Snake Tail
    int repeat=0;
    do{
        int SRow, srow, SCol, scol;
        int LRow, lrow, LCol, lcol;
    for(int k=0; k<3; k++){
        do{
            repeat=0;
            int y1=0, y2=0, a1=0, a2=0;
            int x1=0, x2=0, b1=0, b2=0;
            y1 = rand()%10; y2 = rand()%10;
            x1 = rand()%10; x2 = rand()%10;
            a1 = rand()%10; a2 = rand()%10;
            b1 = rand()%10; b2 = rand()%10;
            LRow = *(row+a1);
            LCol = *(col+b1);
            lrow = *(row+a2);
            lcol = *(col+b2);
            SRow = *(row+y1);
            SCol = *(col+x1);
            srow = *(row+y2);
            scol = *(col+x2);
        } while ((LRow >= lrow || SRow <= srow) || ((SRow==29 && SCol==49) && (srow==29 && scol==49)) || ((SRow==2) && (SCol==4)) || ((LRow==2) && (LCol==4)));
        repeat=0;
        /*printf("Bigsnake=%i\nsmallsnake=%i\n", SRow, srow); I use this to check the position of the snakes at the beginning
        printf("Bigladder=%i\nsmallladder=%i\n", LRow, lrow);*/

        *(*(board+SRow)+SCol) = 'S';
        *(*(board+srow)+scol) = 's';
        *(*(board+LRow)+LCol) = 'L';
        *(*(board+lrow)+lcol) = 'l';
        *(SnakeHead_col+k)=SCol;
        *(SnakeHead_row+k)=SRow;
        *(SnakeTail_col+k)=scol;
        *(SnakeTail_row+k)=srow;
        *(LadderHead_col+k)=LCol;
        *(LadderHead_row+k)=LRow;
        *(LadderTail_col+k)=lcol;
        *(LadderTail_row+k)=lrow;
    }
    repeat = randomSnl_check(); 
        if(repeat==1){
            for(int k=0; k<3; k++){
                *(*(board+*(SnakeHead_row+k))+*(SnakeHead_col+k)) = ' ';
                *(*(board+*(SnakeTail_row+k))+*(SnakeTail_col+k)) = ' ';
                *(*(board+*(LadderHead_row+k))+*(LadderHead_col+k)) = ' ';
                *(*(board+*(LadderTail_row+k))+*(LadderTail_col+k)) = ' ';
            }
            //printf("Oops something repeated\n"); I print this to check if there are positions that repeated when plotting the Snakes and Ladders
        }
            
}while(repeat==1);
}
//rolls the dice
int rollDice(){
    int dice = (rand()%6)+1;
    return dice;
}
//if something goes wrong try checking the parenthesis ;)
int check_playerPos(char* player, int* lastRowCoord, int* lastColCoord, int pcnt){
    int temp_row = *(lastRowCoord+pcnt)+1;
    //printf("temp row is %i\n", temp_row); I use this to check the row pointer
    int temp_col;
    int yes=0;
    int val;
    if(*(player+pcnt)=='a'){
        temp_col = *(lastColCoord+pcnt)+3;
        //printf("temp col is now %i\n", temp_col); I use this to check the column pointer
            /*printf("LadderHead_row+x = %i\n", *(LadderHead_row+x));
            printf("LadderHead_col+x = %i\n", *(LadderHead_col+x));*/
            if(*(*(board+temp_row)+temp_col)=='L'){
                printf("a lands on a ladder and goes up!\n");
                for(int x=0; x<3; x++){
                    if((temp_col==*(LadderHead_col+x)) && (temp_row==*(LadderHead_row+x))){
                        (*(*(board+(temp_row-1))+(temp_col-3)))=' ';
                        yes=1;
                        val=x;
                    }
                }
                if(yes){
                    temp_col = *(LadderTail_col+val)-3;
                    temp_row = *(LadderTail_row+val)-1;
                    *(*(board+temp_row)+temp_col) = 'a';
                    *(lastColCoord+pcnt) = temp_col;
                    *(lastRowCoord+pcnt) = temp_row;
                    return 1;
                }
                else    
                    return 0;
            
            }
            else if(*(*(board+temp_row)+temp_col)=='S'){
                 printf("Noo a Snake ahhh\n");
                for(int x=0; x<3; x++){
                    if((temp_col==*(SnakeHead_col+x)) && (temp_row==*(SnakeHead_row+x))){
                        (*(*(board+(temp_row-1))+(temp_col-3)))=' ';
                        yes=1;
                        val=x;
                    }
                }
                if(yes){
                    temp_col = *(SnakeTail_col+val)-3;
                    temp_row = *(SnakeTail_row+val)-1;
                    *(*(board+temp_row)+temp_col) = 'a';
                    *(lastColCoord+pcnt) = temp_col;
                    *(lastRowCoord+pcnt) = temp_row;
                    return 1;
                }
                else    
                    return 0;
            }
    }
   if(*(player+pcnt)=='b'){
        temp_col = *(lastColCoord+pcnt)+2;
        //printf("temp col is now %i\n", temp_col);
            if(*(*(board+temp_row)+temp_col)=='L'){
                printf("b lands on a ladder and goes up!\n");
                for(int x=0; x<3; x++){
                    if((temp_col==*(LadderHead_col+x)) && (temp_row==*(LadderHead_row+x))){
                        (*(*(board+(temp_row-1))+(temp_col-2)))=' ';
                        yes=1;
                        val=x;
                    }
                }
                if(yes){
                    temp_col = *(LadderTail_col+val)-2; // this was 3 before
                    temp_row = *(LadderTail_row+val)-1;
                    *(*(board+temp_row)+temp_col) = 'b';
                    *(lastColCoord+pcnt) = temp_col;
                    *(lastRowCoord+pcnt) = temp_row;
                    return 1;
                }
                else    
                    return 0;
            
            }
            else if(*(*(board+temp_row)+temp_col)=='S'){
                 printf("Noo a Snake ahhh\n");
                for(int x=0; x<3; x++){
                    if((temp_col==*(SnakeHead_col+x)) && (temp_row==*(SnakeHead_row+x))){
                        (*(*(board+(temp_row-1))+(temp_col-2)))=' ';
                        yes=1;
                        val=x;
                    }
                }
                if(yes){
                    temp_col = *(SnakeTail_col+val)-2;
                    temp_row = *(SnakeTail_row+val)-1;
                    *(*(board+temp_row)+temp_col) = 'b';
                    *(lastColCoord+pcnt) = temp_col;
                    *(lastRowCoord+pcnt) = temp_row;
                    return 1;
                }
                else    
                    return 0;
            }
    }
    if(*(player+pcnt)=='c'){
        temp_col = *(lastColCoord+pcnt)+1;
        //printf("temp col is now %i\n", temp_col);
            if(*(*(board+temp_row)+temp_col)=='L'){
                printf("c lands on a ladder and goes up!\n");
                for(int x=0; x<3; x++){
                    if((temp_col==*(LadderHead_col+x)) && (temp_row==*(LadderHead_row+x))){
                        (*(*(board+(temp_row-1))+(temp_col-1)))=' ';
                        yes=1;
                        val=x;
                    }
                }
                if(yes){
                    temp_col = *(LadderTail_col+val)-1;
                    temp_row = *(LadderTail_row+val)-1;
                    *(*(board+temp_row)+temp_col) = 'c';
                    *(lastColCoord+pcnt) = temp_col;
                    *(lastRowCoord+pcnt) = temp_row;
                    return 1;
                }
                else    
                    return 0;
            
            }
            else if(*(*(board+temp_row)+temp_col)=='S'){
                 printf("Noo a Snake ahhh\n");
                for(int x=0; x<3; x++){
                    if((temp_col==*(SnakeHead_col+x)) && (temp_row==*(SnakeHead_row+x))){
                        (*(*(board+(temp_row-1))+(temp_col-1)))=' ';
                        yes=1;
                        val=x;
                    }
                }
                if(yes){
                    temp_col = *(SnakeTail_col+val)-1;
                    temp_row = *(SnakeTail_row+val)-1;
                    *(*(board+temp_row)+temp_col) = 'c';
                    *(lastColCoord+pcnt) = temp_col;
                    *(lastRowCoord+pcnt) = temp_row;
                    return 1;
                }
                else    
                    return 0;
            }
    }
    if(*(player+pcnt)=='d'){
        temp_col = *(lastColCoord+pcnt);
        //printf("temp col is now %i\n", temp_col);
            if(*(*(board+temp_row)+temp_col)=='L'){
                printf("d lands on a ladder and goes up!\n");
                for(int x=0; x<3; x++){
                    if((temp_col==*(LadderHead_col+x)) && (temp_row==*(LadderHead_row+x))){
                        (*(*(board+(temp_row-1))+(temp_col)))=' ';
                        yes=1;
                        val=x;
                    }
                }
                if(yes){
                    temp_col = *(LadderTail_col+val);
                    temp_row = *(LadderTail_row+val)-1;
                    *(*(board+temp_row)+temp_col) = 'd';
                    *(lastColCoord+pcnt) = temp_col;
                    *(lastRowCoord+pcnt) = temp_row;
                    return 1;
                }
                else    
                    return 0;
            
            }
            else if(*(*(board+temp_row)+temp_col)=='S'){
                 printf("Noo a Snake ahhh\n");
                for(int x=0; x<3; x++){
                    if((temp_col==*(SnakeHead_col+x)) && (temp_row==*(SnakeHead_row+x))){
                        (*(*(board+(temp_row-1))+(temp_col)))=' ';
                        yes=1;
                        val=x;
                    }
                }
                if(yes){
                    temp_col = *(SnakeTail_col+val);
                    temp_row = *(SnakeTail_row+val)-1;
                    *(*(board+temp_row)+temp_col) = 'd';
                    *(lastColCoord+pcnt) = temp_col;
                    *(lastRowCoord+pcnt) = temp_row;
                    return 1;
                }
                else    
                    return 0;
            }
    }
}
//rolls the dice and moves the players position
int rollDicePLusMove(char* player,int* lastColCoord, int pcnt){
    int diceValue = rollDice();
    printf("%c rolled %i\n", *(player+pcnt), diceValue);
    int colAdd=0;
    for(int i=0; i<diceValue; i++){
        colAdd = colAdd + 5;
    }
    *(lastColCoord+pcnt) = *(lastColCoord+pcnt) + colAdd;
    return *(lastColCoord+pcnt);
}
int check_lastColCoord(int* lastColCoord, int pcnt){
    if(*(lastColCoord+pcnt)==51+pcnt)
        *(lastColCoord+pcnt)=1+pcnt;
    else if(*(lastColCoord+pcnt)==56+pcnt)
        *(lastColCoord+pcnt)=6+pcnt;
    else if(*(lastColCoord+pcnt)==61+pcnt)
        *(lastColCoord+pcnt)=11+pcnt;
    else if(*(lastColCoord+pcnt)==66+pcnt)
        *(lastColCoord+pcnt)=16+pcnt;
    else if(*(lastColCoord+pcnt)==71+pcnt)
        *(lastColCoord+pcnt)=21+pcnt;
    else if(*(lastColCoord+pcnt)==76+pcnt)
        *(lastColCoord+pcnt)=26+pcnt;
    return *(lastColCoord+pcnt);
}
// plots the position of the players' moves
void final_plot(int* lastColCoord, int* temp_lastColCoord, int* lastRowCoord, int* temp_lastRowCoord, char* player){
    int col,tempcol, row, temprow;
    for(int i=0; i<4; i++){
        col = *(lastColCoord+i);
        tempcol = *(temp_lastColCoord+i);
        row = *(lastRowCoord+i);
        temprow = *(temp_lastRowCoord+i);

        *(*(board+row)+col) = *(player+i);
        *(*(board+temprow)+tempcol) = ' ';
    }
}
int checkWin(){
    int counter=0;
    int win = 0;
    for(int i=30; i>=0; i--){
        for(int j=50; j>=0; j--){
            if(*(*(board+i)+j)=='a' || *(*(board+i)+j)=='b' || *(*(board+i)+j)=='c' || *(*(board+i)+j)=='d')
                counter++;
        }
    }
    if(*(*(board+28)+49) != ' ' || *(*(board+28)+48) != ' ' || *(*(board+28)+47) != ' ' || *(*(board+28)+46) != ' '){
        win = 1;
    }
    if(counter==4 && win == 0)
        return 0;
    else 
        return 1;
}
//prints out the game board
void print_board(){
    int x=0;
    for(int i=30; i>=0; i--){
        if(i==*(revarr+x)){
            for(int j=0; j<51; j++)
                printf("%c", *(*(board+i)+j));
            printf("\n");
            x++;
        }
        else{
            for(int j=50; j>=0; j--)
                printf("%c", *(*(board+i)+j));
            printf("\n");
        }
    }
}
/*int print_SnakeVal(){
    for(int i=0; i<3; i++){
        printf("%i ", *(SnakeTail_row+i));
    }
}*/
int main(){
    srand(time(NULL));
    board_val();
    randomSnL();
    initial_plot();
    print_board();
    int pcnt=0;
    int initial_value=4;
    for(int i=0; i<4; i++){
        *(lastColCoord+i) = i+1;
        *(lastRowCoord+i) = 1;
        *(temp_lastColCoord+i) = *(lastColCoord+i);
        *(temp_lastRowCoord+i) = *(lastRowCoord+i);
    }
    //print_SnakeVal(); This function I use to determine the postions of the Snaketail Row
    while(gameOver==0){
        printf("%c's turn\n", *(player+pcnt));
        printf("%c, press <Enter> to roll.\n", *(player+pcnt));
        getchar();
        *(temp_lastColCoord+pcnt) = *(lastColCoord+pcnt);
        *(temp_lastRowCoord+pcnt) = *(lastRowCoord+pcnt);
        *(lastColCoord+pcnt) = rollDicePLusMove(player, lastColCoord, pcnt);
        if(*(lastColCoord+pcnt)>50){
            *(lastRowCoord+pcnt) = *(lastRowCoord+pcnt) + 3;
            *(lastColCoord+pcnt) = check_lastColCoord(lastColCoord, pcnt);
        }
        /*printf("%c is now at col %i\n", *(player+pcnt), *(lastColCoord+pcnt));
        printf("%c is now at row %i\n", *(player+pcnt), *(lastRowCoord+pcnt)); This part I use to check the location coordinates of the players*/ 
        final_plot(lastColCoord, temp_lastColCoord, lastRowCoord, temp_lastRowCoord, player);
        initial_value--;
        if(initial_value==3){
            *(*(board+1)+2)='b';
            *(*(board+1)+3)='c';
            *(*(board+1)+4)='d';
        }
        else if(initial_value==2){
            *(*(board+1)+3)='c';
            *(*(board+1)+4)='d';
        }
        else if(initial_value==1){
            *(*(board+1)+4)='d';
        }
        int hi = check_playerPos(player, lastRowCoord, lastColCoord, pcnt);
        int gameOver_check = checkWin();
        if(gameOver_check){
            printf("Congratulations! Player %c won the game!\n", *(player+pcnt));
            gameOver=1;
        }
        else 
            print_board();
        pcnt++;
        if(pcnt==4)
            pcnt=0;
    }
}

