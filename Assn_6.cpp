#include<iostream>
#include<vector>
using namespace std;

class NQueens
{
	public:
		bool isSafe(int row,int col,vector<string> board , int n)
		{
			int r = row;
			int c = col;
			//diagonal left up;
			while(r>=0 && c>=0)
			{
				if(board[r][c] == 'Q')
				{
					return false;
				}
				r--;
				c--;
			}
			r = row;
			c = col;
			//diagonal left down
			while(r<n && c>=0)
			{
				if(board[r][c] == 'Q')
				{
					return false;
				}
				r++;
				c--;
			}
			r = row;
			c = col;
			//left row
			while(c>=0)
			{
				if(board[r][c] == 'Q')
				{
					return false;
				}
				c--;
			}
			return true;
		}
		void solve(int col , vector<string>&board , vector<vector<string> >&ans , int n)
		{
			if(col == n)
			{
				ans.push_back(board);
				return;
			}
			for(int row=0;row<n;row++)
			{
				if(isSafe(row,col,board,n))
				{
					board[row][col] = 'Q';
					solve(col+1,board,ans,n);
					board[row][col] = '.';
				}
			}
		}
		vector<vector<string> > solveNQueen(int n)
		{
			vector<string> board;
			vector<vector<string> > ans;
			
			string s(n,'.');
			
			for(int i=0;i<n;i++)
			{
				board.push_back(s);
			}
			
			solve(0,board,ans,n);
			return ans;
		}
};

int main()
{
	NQueens N;
	cout<<"Enter the size of matrix :";
	int n;
	cin>>n;
	vector<vector<string> > ans = N.solveNQueen(n);
	for(int i=0;i<ans.size();i++)
	{
		cout<<"Arrangement "<<i+1<<endl;
		for(int j=0;j<n;j++)
		{
			cout<<ans[i][j]<<endl;
		}
		cout<<" "<<endl;
	}
}
