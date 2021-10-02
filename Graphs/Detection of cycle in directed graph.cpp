#include<bits/stdc++.h> 
using namespace std; 

bool DFSRec(vector<int> adj[], int s,bool visited[], bool recSt[]) 
{ 	
    visited[s]=true;
    recSt[s]=true;
    
    for(int u:adj[s]){
        if(visited[u]==false && DFSRec(adj,u,visited,recSt)==true)
                {return true;}
        else if(recSt[u]==true)
            {return true;}
    }
    recSt[s]=false;
    return false;
}

bool DFS(vector<int> adj[], int V){
    bool visited[V]; 
	for(int i=0;i<V; i++) 
		visited[i] = false;
	bool recSt[V]; 
	for(int i=0;i<V; i++) 
		recSt[i] = false;
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            if(DFSRec(adj,i,visited,recSt)==true)
                return true;
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main() 
{ 
	int V=6;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,2,1); 
	addEdge(adj,2,3); 
	addEdge(adj,3,4); 
	addEdge(adj,4,5);
	addEdge(adj,5,3);

	if(DFS(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

	return 0; 
} 