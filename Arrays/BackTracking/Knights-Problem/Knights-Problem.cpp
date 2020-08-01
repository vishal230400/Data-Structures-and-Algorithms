#include<iostream>
using namespace std;
int N;

bool safe(int next_x,int next_y,int board[8][8])
{
	if(next_x>=0 && next_x<N && next_y>=0 && next_y<N && board[next_x][next_y]==-1)
		return true;
	else return false;	
}

bool knightProblem(int curr_x,int curr_y,int x[8],int y[8],int board[8][8],int count)
{
	int next_x,next_y;
	if(count==N*N)
		return true;
	for(int k=0;k<8;k++)
	{
		next_x=curr_x+x[k];
		next_y=curr_y+y[k];
		
		if(safe(next_x,next_y,board))	
		{
			board[next_x][next_y]=count;
			
			if(knightProblem(next_x,next_y,x,y,board,count+1))
				return true;
			
			board[next_x][next_y]=-1;
		}
	}	
	
	return false;
}
 
int main()
{
	N=8;
	int board[8][8];
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			board[i][j]=-1;
	
	board[0][0]=0;
	
	int x[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
    int y[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
	
	bool check=knightProblem(0,0,x,y,board,1);
	
	if(check)
	{
		cout<<"Soution for Knights Problem:"<<endl<<endl;
		for(i=0;i<N;i++)
			{
				for(j=0;j<N;j++)
					{
					if(board[i][j]<10)
						cout<<" ";
					cout<<board[i][j]<<" ";
					}
				cout<<endl;
			}
	}
	else cout<<"No Solution";			
		
	return 0;				
 } 
