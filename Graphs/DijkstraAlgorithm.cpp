#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define I INT_MAX

class node{
	public:
		int v;
		int weight;
		node(){
			
		}
		node(int x, int y){
			v = x;
			weight = y;
		}
};

class myCompare{
	public:
		bool operator() (node a, node b){
			return a.weight > b.weight;
		}
};

void Dijkstra(int n, int graph[][100], int *distance, int s){
	
	priority_queue<node, vector<node>, myCompare> minH;
	
	distance[s] = 0;
	int i, u, d;
	
	int visited[n+1];
	for(i=0;i<=n;i++){
		visited[i] = 0;
	}
	
	node t;
	
	minH.push(node(s, 0));
	while(!minH.empty()){
		t = minH.top(); minH.pop();
		u = t.v;
		for(i=1;i<=n;i++){
			if(graph[u][i] != 0){
				d = distance[u] + graph[u][i];
				if(d < distance[i]){
					minH.push(node(i, d));
					distance[i] = d;
				}
			}
		}
	}
	
	cout<<"Vertex \t Minimum distance\n";
	for(i=1;i<=n;i++){
		cout<<"  "<<i<<"\t\t"<<distance[i]<<"\n";
	}
}

int main()
{
	//	freopen("inputf.txt", "r", stdin);
	//	freopen("outputf.txt", "w", stdout);

	int t;
	cin>>t;
	while(t-- > 0){
		int n, e;
		cin>>n>>e;
		
		int graph[100][100];	
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				graph[i][j] = 0;
			}
		}
		
		int a, b, w;
		while(e-- > 0){
			cin>>a>>b>>w;
			graph[a][b] = w;
			graph[b][a] = w;
		}
		
		int *distance = new int[n+1];
		// Assigning all vertex distance as infinity 
		for(int i=0;i<=n;i++){
			distance[i] = I;
		}
		
		Dijkstra(n, graph, distance, 1);
		
		cout<<endl;
	}
	return 0;
}
