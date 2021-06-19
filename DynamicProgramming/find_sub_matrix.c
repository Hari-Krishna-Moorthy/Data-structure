#include <stdio.h>

int min(int a, int b, int c) {
    return (a<b && b<c) ? a : (b<c) ? b : c;
}
int largest(int row,int col, int matrix[row][col]) {
    int memo[row][col];
    int res = 0;
    for(int x=0;x<row;x++){
        for(int y=0;y<col;y++)  memo[x][y] = (x==0 || y==0) ? 1 : 0;
    }

    for(int x=1;x<row;x++) {
        int maxNum=0;
        for(int y=1;y<col;y++) {
            if(x==row || y==col) memo[x][y] = 1;
            else {
                int temp = matrix[x][y];
                if(temp==matrix[x-1][y] && temp==matrix[x][y-1] && temp==matrix[x-1][y-1])
                    memo[x][y] = min(memo[x-1][y], memo[x][y-1], memo[x-1][y-1])+1;
                else
                    memo[x][y] = 1;
            }
            printf("%d ", memo[x][y]);
            maxNum = maxNum>memo[x][y] ? maxNum : memo[x][y];
        }printf("\n");
        res = res>maxNum ? res : maxNum;
    }
    return res;
}

int main() {
    int matrix[5][5] = {
        {1, 1, 1, 0, 2},
        {1 ,1, 1, 1, 1},
        {1, 1, 1, 2, 1},
        {1, 3, 2, 3, 5},
        {1, 2, 3, 4, 5}
    };
    printf("%d", largest(5, 5, matrix));
    return 0;
}
