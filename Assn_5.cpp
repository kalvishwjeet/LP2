//krushkals
#include<iostream>
#include<vector>
using namespace std;

class Edge
{
	public:
		int u,v,w;
		Edge(int a,int b,int c)
		{
			u=a;
			v=b;
			w=c;
		}
};

class Graph
{
	public:
		int n;
		vector<Edge> edge;
		
		Graph()
		{
			n=0;
		}
		void sort()
		{
			for(int i=0;i<edge.size();i++)
			{
				for(int j=0;j<edge.size();j++)
				{
					if(edge[i].w < edge[j].w)
					{
						swap(edge[i],edge[j]);
					}
				}
			}
		}
		void scan_matrix()
		{
			cout<<"Enter the total number of nodes :";
			cin>>n;
			vector<vector<int> >vct(n , vector<int>(n,0));
			cout<<"Enter starting ending and weight of edge :";
			while(1)
			{
				int u,v,w;
				cin>>u>>v>>w;
				if(u==-1 || v == -1)
				{
					break;
				} 
				if(u<0 || u>=n || v<0 || v>=n)
				{
					cout<<"Invalid input"<<endl;
				}
				else
				{
					vct[u][v] = w;
					vct[v][u] = w;
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					cout<<vct[i][j]<<" ";
				}
				cout<<endl;
			}
			for(int i=0;i<n;i++)
			{
				for(int j=i;j<n;j++)
				{
					if(vct[i][j] != 0)
					{
						Edge e(i,j,vct[i][j]);
						edge.push_back(e);
					}
				}
			}
			sort();
			for(int i=0;i<edge.size();i++)
			{
				cout<<edge[i].u<<"->"<<edge[i].v<<"->"<<edge[i].w<<endl;
			}
		}
		void krushkal()
		{
			int te = edge.size();
			int ne = n-1;
			int*comp = new int[n];
			for(int i=0;i<n;i++)
			{
				comp[i] = i;
			}
			int u,v,w,cu,cv;
			int mincost=0;
			for(int i=0;i<te;i++)
			{
				u = edge[i].u;
				v = edge[i].v;
				w = edge[i].w;
				cu = comp[u];
				cv = comp[v];
				if(cu!=cv)
				{
					cout<<"Add edge : "<<u<<"->"<<v<<endl;
					mincost += w;
					for(int j=0;j<n;j++)
					{
						if(comp[i] == cu)
						{
							comp[i] = cv;
						}
					}
					ne--;
				}
				if(ne==0)
				{
					break;
				}
			}
			cout<<"Mincost : "<<mincost<<endl;
		}
};

int main()
{
	Graph g;
	g.scan_matrix();
	g.krushkal();
}
