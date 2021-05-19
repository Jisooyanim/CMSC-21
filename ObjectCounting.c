#include <stdio.h>

int grid[100][100];
int gridz[100][100];
void pixels(int row, int column, int counter);

int main(){
    int n,m,count = 0,i,j;

    printf("Row: ");
    scanf("%i", &n);
    printf("Column: ");
    scanf("%i", &m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%i ", &grid[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if(grid[i][j] == 1 && !gridz[i][j]){
                pixels(i,j,++count);
            }
        }
    }
    printf("%i", count); 
    return 0;
}

void pixels(int row, int column, int counter){
    gridz[row][column] = counter;
    int x[8] = {-1,0,1,1,1,0,-1,-1};
    int y[8] = {1,1,1,0,-1,-1,-1,0};

    for (int i = 0; i < 8; i++)
    {
        int fx = row + x[i];
        int fy = column + y[i];
        if(grid[fx][fy] && !gridz[fx][fy])
            pixels(fx,fy,counter);
    }
}