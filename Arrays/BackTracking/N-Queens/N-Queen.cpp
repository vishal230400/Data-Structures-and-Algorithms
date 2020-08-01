#include<iostream>
using namespace std;

int N;

int main()
{
	cout<<"Enter N between 0 to 100"<<endl;
	cin>>N;
	int board[100][100];
	bool nqueen(int board[100][100],int Q);
	bool result;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			board[i][j]=0;
	result=nqueen(board,0);
	if(result)
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
				cout<<board[i][j]<<" ";
		cout<<endl;
		}
	return 0;
}

bool safe(int board[100][100],int row,int col)
{
	 int i, j; 
  
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
}

bool nqueen(int board[100][100],int Q)
{
	if(Q>=N)
		return true;	
	
	for(int i=0;i<N;i++)
	{
		if(safe(board,i,Q))
		{
			board[i][Q]=1;
			
			if(nqueen(board,Q+1))
				return true;
			
			board[i][Q]=0;		
		}	
	}	
	
	return false;
}
