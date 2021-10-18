int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> adj(A+1);
for(int i=0; i<B.size(); i++)
{
adj[B[i][0]].push_back(B[i][1]);
adj[B[i][1]].push_back(B[i][0]);
}
int visited[A+1];
memset(visited,0,sizeof(visited));
queue<pair<int,int>> q;
for(int i=1; i<=A; i++)
{
if(visited[i]==0)
{
q.push({i,-1});
visited[i]=1;
}

    while(!q.empty())
    {
        auto p=q.front();
        int u=p.first;
        int parent=p.second;
        q.pop();
        for(auto node: adj[u])
        {
            if(visited[node]==0)
            {
                q.push({node,u});
                visited[node]=1;
            }
            else if(node!=parent)
            return 1;
        }
    }
}
return 0;
}
