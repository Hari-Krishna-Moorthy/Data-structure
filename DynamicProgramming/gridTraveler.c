#include <stdio.h> 

static int count = 0;

int gridTraveler( int row, int col, int x, int y) {	
	count++;
	// Time Complex is 2^n+m (left, right)

	if(x==row || y==col) return 0;
	else if (x==row-1 && y==col-1) return 1;
	else return gridTraveler(row, col, x+1, y) + gridTraveler(row, col, x, y+1); // Move right and Left
}


int gridTraveler_dp(int grid[][3] , int row, int col, int x, int y) {
	count ++;
	if(x==row || y==col) return 0;
	if(grid[x][y] != -1) return grid[x][y];
	if(x==row-1 && y==col-1) return 1;
	int temp = gridTraveler_dp(grid, row, col, x+1, y) + gridTraveler_dp(grid, row, col, x, y+1);
	grid[y][x] = grid[x][y] = temp;

	return grid[x][y];
}


int main() {
	printf("(1, 1) ways :%d \n" , gridTraveler( 1, 1, 0, 0));		//	1
	printf("(2, 3) ways :%d \n" , gridTraveler( 2, 3, 0, 0));		//	3
	printf("(3, 2) ways :%d \n" , gridTraveler( 3, 2, 0, 0));		//	3
	printf("(3, 3) ways :%d \n" , gridTraveler( 3, 3, 0, 0));		//	6
	// printf("%d" , count);
	printf("(8, 8) ways :%d \n" , gridTraveler( 8, 8, 0, 0));		//	3432
	// printf("(17, 18) ways :%d \n" , gridTraveler( 16, 18, 0, 0));   //	155117520
	printf("\n");		

	int grid[3][3] = {
		{-1, -1, -1},
		{-1, -1, -1}, 
		{-1, -1, -1}
	};
	count = 0;
	printf("(3, 3) ways :%d\n" , gridTraveler_dp(grid, 3, 3 , 0 ,0));
	for(int row=0; row<3;row++) {
		for(int col=0;col<3;col++) 
			printf("%d ", grid[row][col]);
		printf("\n");
	}	
	printf("%d" , count);


	return 0;
}