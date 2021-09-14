#include<stdio.h>

// 2d arrays were initialized and they needed constant parameters
int out[1000][1000]={0};
int in[1000][1000]={0};

// 8-way pixel connectivity coordinates
int xMoves[8]= {-1,0,1,1,1,0,-1,-1};
int yMoves[8] = {1,1,1,0,-1,-1,-1,0};

// Labels the number of objects in the array
void labeling_out(int x, int y, int group){
    out[x][y]=group;
    for(int i=0; i<8; i++){
        int newX = x + xMoves[i];  
        int newY = y + yMoves[i];
        if(in[newX][newY]==1 && out[newX][newY]==0)
            labeling_out(newX, newY, group); 
    }
}
int main(){
    int row, col, group=1;
    printf("Enter number of rows and columns: ");
    scanf("%i %i", &row, &col);

    //scans the elements of the array
    for(int x=0; x<row; x++){
        for(int y=0; y<col; y++){
            scanf("%i", &in[x][y]);
        }
    }
    printf("\n\n");
    //iterates the elements in the input array
    for(int x=0; x<row; x++){
        for(int y=0; y<col; y++){
            if(in[x][y]==1 && out[x][y]==0){
                labeling_out(x,y,group++);
            }
        }
    }
    //Subtracts 1 because it was incremented in the labeling_out function and the value was not put into use
    printf("Output: %i", group-1);

}