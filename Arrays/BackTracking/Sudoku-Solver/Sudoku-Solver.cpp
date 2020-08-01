#include <bits/stdc++.h> 
using namespace std; 

#define N 9
;

bool Unassigned(int grid[N][N], int &r, int &c) 
{ 
	for (r = 0; r < N; r++) 
		for (c = 0; c < N; c++) 
			if (grid[r][c] ==0)
				return true; 
	return false; 
} 

bool inRow(int grid[N][N], int r, int i) 
{ 
	for (int c = 0; c < N; c++) 
		if (grid[r][c] == i) 
			return true; 
	return false; 
} 

bool inCol(int grid[N][N], int c, int i) 
{ 
	for (int r = 0; r < N; r++) 
		if (grid[r][c] == i) 
			return true; 
	return false; 
} 

bool inBox(int grid[N][N], int R,int C, int i) 
{ 
	for (int r = 0; r < 3; r++) 
		for (int c = 0; c < 3; c++) 
			if (grid[r + R] [c + C] == i) 
				return true; 
	return false; 
} 

bool safe(int grid[N][N], int r, int c, int i) 
{ 
	return !inRow(grid, r, i) && !inCol(grid, c, i) && !inBox(grid, r - r % 3 , c - c % 3, i) && grid[r][c] == 0; 
} 


bool SolveSudoku(int grid[N][N]) 
{ 
	int r, c; 

	if (!Unassigned(grid, r, c)) 
	return true;

	for (int i = 1; i <= 9; i++) 
	{ 
		if (safe(grid, r, c, i)) 
		{ 
			grid[r][c] = i; 

			if (SolveSudoku(grid)) 
				return true; 

			grid[r][c] = 0; 
		} 
	} 
	return false;  
} 


void printGrid(int grid[N][N]) 
{ 
	for (int row = 0; row < N; row++) 
	{ 
	for (int col = 0; col < N; col++) 
			cout << grid[row][col] << " "; 
		cout << endl; 
	} 
} 

int main() 
{ 
	int grid[N][N];
	
	cout<<"Enter the elements in the Sudoku Puzzle"<<endl<<"Enter 0 if the element is not known"<<endl;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			cin>>grid[i][j];
			}
	
	cout<<endl;
						
	if (SolveSudoku(grid) == true) 
		printGrid(grid); 
	else
		cout << "No solution exists"; 

	return 0; 
} 
