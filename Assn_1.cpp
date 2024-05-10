#include<iostream>
#include<vector>
using namespace std;

class Graph
{
	void dfs_rec(vector<int>&visited , int v , int lev)
	{
		cout<<v<<" level : "<<lev<<endl;
		visited[v] = 1;
		for(int i=0;i<total;i++)
		{
			if(matrix[v][i] == 1 && visited[i] == 0)
			{
				dfs_rec(visited , i , lev+1);
			}
		}
	}
	void bfs_rec(vector<int>&visited , int v , int lev)
	{
		lev++;
		vector<int> x;
		x.clear();
		for(int i=0;i<total ; i++)
		{
			if(matrix[v][i] == 1 && visited[i] == 0)
			{
				cout<<i<<" level = "<<lev<<endl;
				visited[i] = 1;
				x.push_back(i);
			}
		}
		for(int i=0;i<x.size();i++)
		{
			bfs_rec(visited , x[i] , lev);
		}
	}
	public:
		vector<vector<int> > matrix;
		int total;
		Graph(int x)
		{
			total = x;
			for(int i=0;i<total;i++)
			{
				vector<int> a(total , 0);
				matrix.push_back(a);
			}
		}
		void input()
		{
			cout<<"Enter the starting and ending point of edge or -1 to stop"<<endl;
			while(1)
			{
				int a , b;
				cin>>a>>b;
				if(a == -1 || b == -1)
				{
					break;
				}
				if((a>=0 && a<total) && (b>=0 && b<total))
				{
					matrix[a][b] = 1;
					matrix[b][a] = 1;
				}
				else
				{
					cout<<"Invalid Input"<<endl;
				}
			}
			cout<<endl;
		}
		void dfs()
		{
			int n;
			while(1)
			{
				cout<<"Enter the stating vertex : ";
				cin>>n;
				if(n >= 0 && n < total)
				{
					break;
				}
				else
				{
					cout<<"Invalid input"<<endl;
				}
			}
			vector<int> visited(total,0);
			cout<<"Depth first Search"<<endl;
			dfs_rec(visited , n , 0);
			cout<<""<<endl;
		}
		void bfs()
		{
			int n;
			while(1)
			{
				cout<<"Enter the starting vertex : ";
				cin>>n;
				if(n >= 0 && n < total)
				{
					break;
				}
				else
				{
					cout<<"Invalid input"<<endl;
				}
			}
			vector<int> visited(total,0);
			cout<<"Breadth first Search"<<endl;
			cout<<n<<" level : 0"<<endl;
			visited[n] = 1;
			bfs_rec(visited , n , 0);
			cout<<""<<endl;
		}
		void print_graph()
		{
			cout<<"Displaying the graph"<<endl;
			for(int i=0;i<total;i++)
			{
				for(int j=0;j<total;j++)
				{
					cout<<matrix[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<" "<<endl;
		}
};

int main()
{
	cout<<"Enter the number of nodes : ";
	int n;
	cin>>n;
	Graph g(n);
	g.print_graph();
	g.input();
	g.print_graph();
	g.dfs();
	g.bfs();
}
