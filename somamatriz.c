#include <stdio.h>

int main(){

    int a[2][2] = {
        {1,2},
        {5,6}
    };
    int b[2][2] = {
        {3, 4},
        {7,8}
    };

    int c[2][2];

    for (int i=0; i<2; i++){
        for(int j =0;j<2;j++){
            c[i][j] =  a[i][j] + b[i][j];
        }
    }

     for (int i=0; i<2; i++){
        for(int j =0;j<2;j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }


    int c_t[2][2];
    for (int i=0; i<2; i++){
        for(int j =0;j<2;j++){
            c_t[i][j] = c[j][i]; 
        }
        printf("\n");
    }

     for (int i=0; i<2; i++){
        for(int j =0;j<2;j++){
            printf("%d ", c_t[i][j]);
        }
        printf("\n");
    }



}