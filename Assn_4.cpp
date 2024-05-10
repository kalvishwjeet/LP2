//prims
#include<iostream>
#include<vector>
using namespace std;

class Graph
{
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
				int a , b,w;
				cin>>a>>b>>w;
				if(a == -1 || b == -1)
				{
					break;
				}
				if((a>=0 && a<total) && (b>=0 && b<total))
				{
					matrix[a][b] = w;
					matrix[b][a] = w;
				}
				else
				{
					cout<<"Invalid Input"<<endl;
				}
			}
			cout<<endl;
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
		
		void prims()
		{
			int n = total;
			int**cost;
			cost = new int*[n];
			for(int i=0;i<n;i++)
			{
				cost[i] = new int[n];
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(matrix[i][j] == 0)
					{
						cost[i][j] = INT_MAX;
					}
					else
					{
						cost[i][j] = matrix[i][j];
					}
				}
			}
			int*visited;
			int*distance;
			int*from;
			visited = new int[n];
			distance = new int[n];
			from = new int[n];
			cout<<"Enter the starting vertex :";
			int v;
			cin>>v;
			for(int i=0;i<n;i++)
			{
				visited[i] = 0;
				distance[i] = cost[v][i];
				from[i] = v;
			}
			visited[v] = 1;
			from[v] = -1;
			int ne = n-1;
			int u;
			int mincost = 0;
			int mindist = INT_MAX;
			while(ne>0)
			{
				mindist = INT_MAX;
				for(int i=0;i<n;i++)
				{
					if(visited[i] == 0 && distance[i] < mindist)
					{
						v = i;
						mindist = distance[i];
					}
				}
				cout<<"latest visited"<<v<<endl;
				visited[v] = 1;
				u = from[v];
				cout<<"Add Edge "<<u<<" "<<v<<endl;
				mincost = mincost + cost[u][v];
				for(int i=0;i<n;i++)
				{
					if(visited[i] == 0 && cost[v][i] < distance[i])
					{
						distance[i] = cost[v][i];
						from[i] = v;
					}
				}
				ne--;
			}
			cout<<"Minimum cost "<<mincost<<endl;
		}
};

int main()
{
	int n;
	cout<<"Enter the number of vertices :";
	cin>>n;
	Graph g(n);
	g.print_graph();
	g.input();
	g.print_graph();
	g.prims();
}
