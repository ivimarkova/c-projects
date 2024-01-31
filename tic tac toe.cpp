#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
//global variables
char board [3][3];
const char PLAYER='X';
const char COMPUTER ='O';
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);
int main(){
    char winner='\0';//currently there is no winner
    printf("Player plays with X, and Computer plays with 0\n");

    resetBoard();
    while(winner =='\0'&& checkFreeSpaces()!=0){///if there is no winner and func
        printBoard();
        //for the player
        playerMove();
        winner=checkWinner();
        if(winner!='\0'||checkFreeSpaces()==0){
            break;
        }
        //for the computer
        computerMove();
        winner=checkWinner();
        if(winner!='\0'||checkFreeSpaces()==0){
            break;
        }
    }
    printBoard();
    printWinner(winner);
    return 0;

}
void resetBoard(){
    for(int i=0;i<3;i++){//row
        for(int j=0; j<3; j++){//columns
            board[i][j]='\0';
        }
    }
}
void printBoard(){
    printf(" %c | %c | %c", board[0][0], board[0][1], board[0][2]);//row 0,column 0
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
int checkFreeSpaces(){
    int freeSpaces=9;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!='\0'){
                freeSpaces--;
            }
        }
    }
    return freeSpaces;//if returns 0->game over
}
void playerMove(){
    int x;
    int y;
    do
    {
        printf("Enter row #(1-3):");
        scanf("%d",&x);
        x--;//in the code we begin at 0
        printf("Enter column #(1-3):");
        scanf("%d",&y);
        y--;
        if(board[x][y]!='\0'){
            printf("Invalid move!\n");}
        else{
            board[x][y]=PLAYER;
            break;
            }}
    while(board[x][y]!='\0');//if the spot, that the player wants is occupied
}
void computerMove(){
    //randomly generated: creates a seed based on current time
    srand(time(0));
    int x;
    int y;
    if(checkFreeSpaces()>0){
            do
            {
                x=rand()%3;
                y=rand()%3;
            }while(board[x][y]!='\0');
            board[x][y]=COMPUTER;
    }
    else {//if there are no more spaces available
        printWinner('\0');//there is no winner, it's a draw
        }

}
char checkWinner(){
    //check rows
    for(int i=0;i<3;i++){
            if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]){
                return board[i][0];
            }
    }
    //check collums
     for(int i=0;i<3;i++){
            if(board[0][i]==board[1][i]&&board[0][i]==board[2][i]){
                return board[0][i];
            }
    }
    //check diagonals
    if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]){
            return board[0][0];}
    if(board[0][2]==board[1][1]&&board[0][2]==board[2][0]){
            return board[0][2];}
    return '\0';//currently there is no winner

}
void printWinner(char winner){
    if(winner==PLAYER){
        printf("YOU WIN!");
    }
    else if(winner==COMPUTER){
        printf("YOU LOSE!");
    }
    else{
        printf("IT'S A DRAW!");
    }
}
