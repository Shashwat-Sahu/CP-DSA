#include<bits/stdc++.h>
using namespace std;
#define dd double
#define ll long long int
#define pb push_back
#define light ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define t_pair pair<ll,pair<ll,ll>>
#define I INT_MAX
#define N 200

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void dfs_visit(int n, int graph[N][N], int visited[], int u, stack<int> &st){
	if(visited[u] == 1)
		return;
	
	visited[u] = 1;	
	for(int i=0;i<n;i++){
		if(graph[u][i] == 1){
			dfs_visit(n, graph, visited, i, st);
		} 
	}
	st.push(u);
}

void dfs(int n, int graph[N][N], int visited[], stack<int> &st){
	for(int i=0;i<n;i++){
		if(visited[i] == 0){
			dfs_visit(n, graph, visited, i, st);
		}
	}
}

void transposed_dfs_visit(int n, int graph[N][N], int visited[], int u){
	if(visited[u] == 1)
		return;
	
	visited[u] = 1;	
	for(int i=0;i<n;i++){
		if(graph[u][i] == 1){
			transposed_dfs_visit(n, graph, visited, i);
		} 
	}
	cout<<u<<" ";
}

void transposed_dfs(int n, int graph[N][N], int visited[], int u, int *cnt){
	for(int i=0;i<n;i++){
		if(visited[i] == 0){
			*cnt += 1;
			transposed_dfs_visit(n, graph, visited, i);
			cout<<"\n";
		}
	}
}

int find_SCC(int n, int graph[N][N]){
	stack<int> st;
	int visited[n] = {0};
	
	dfs(n, graph, visited, st);
	
	// Taking transpose of the graph
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			swap(&graph[i][j], &graph[j][i]);
		}
	}
	
	for(int i=0;i<n;i++){
		visited[i] = 0;
	}
	
	int v, cnt = 0;
	while(!st.empty()){
		v = st.top(); st.pop();
		if(visited[v] == 0){
			transposed_dfs(n, graph, visited, v, &cnt);
		}
	}
	
	return cnt;
}

int main()
{
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);

	int t;
	cin>>t;
	while(t-- > 0){
		int n, e;
		cin>>n>>e;
		
		int graph[N][N];
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				graph[i][j] = 0;
			}
		}
			
		int a, b, i = 0;
		while(i<e){
			cin>>a>>b;
			graph[a][b] = 1;
			i++;
		}

		cout<<"Total numbers of SCC ---> "<<find_SCC(n, graph);
		
		cout<<endl<<endl;
	}
	
	return 0;
}

