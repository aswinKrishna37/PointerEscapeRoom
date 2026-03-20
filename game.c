#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

int main(){
    char mat[3][3] = {{'S','0','0'},
                     {'0','0','0'},
                     {'0','0','0'}};
    char dmat[3][3]={{'S','0','0'}, 
                      {'0','0','0'},
                      {'0','0','0'}};           
    char mov;
    int row=0, col=0, i, j;
    char (*p)[3] = mat; 

    srand(time(NULL));

    int placed = 0;
    while(placed < 2) {
        int a = rand() % 3;
        int b = rand() % 3;
        if(mat[a][b] == '0') {
            if(placed == 0) mat[a][b] = 'X';
            else mat[a][b] = 'E';
            placed++;
        }
    }



// D Move Right 
// A Move Left 
// S Move Down 
// W Move Up
    while(1){
        printf("****Pointer Escape Room****\n");
        printf("\033[H\033[J");
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(row==i && col==j) printf("[%c]\t",dmat[i][j]);  
                else
                printf("%c\t",dmat[i][j]);
            }
            printf("\n");
        }

        // printf("\nYou are currently at (%d,%d)",row,col);
        printf("\n\t\t[W] Up\n[A] Left\t[S] Down\t[D] Right\n");
        printf("\nMake a move:");
        scanf("%c",&mov);

    // mat[i][j],when i=0 -> move up is not possible    ->  row > 0
                //    i=2 -> move down not possible     ->  row < 2
                //    j=0 -> move left not possible     ->  col > 0 
                //    j=2 -> move right not possible    ->  col < 2
            
        
        if(((mov == 'D')||(mov == 'd'))&&(col<2))col++;
        else if(((mov == 'A')||(mov == 'a'))&&(col > 0))col--;
        else if(((mov == 'S')||(mov == 's'))&&(row < 2))row++;
        else if(((mov == 'W')||(mov == 'w'))&&(row > 0))row--;
        else if(((mov == 'd')||(mov == 'D'))&&(mov == 'a')&&(mov == 'A')&&(mov == 's')&&(mov == 'S')&&(mov == 'w')&&(mov == 'W')){
            printf("\nMovement not possible\n\n");      // Matrix border
            continue;
        }
        else{
            printf("\nInvalid input\n\n");       // User enters value other than 1,2,3,4
            continue;
        }            



        char current = *(*(p + row) + col);

        if (current == 'X'){
                printf("\nYou hit a trap! Game Over");
                break;
            }
        else if (current == 'E'){
                printf("\nYou reached the exit! You win.");
                break;
            }
        else if(current=='0'){
            printf("\nSafe... continue \n\n");
        }
    }
                

    return 0;
}