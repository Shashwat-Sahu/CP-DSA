#include<queue>
#include<vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int r,c;
	    cin>>r>>c;
	    int adj[r][c];
	    int count;
	    vector<pair<int,int>>v;
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            cin>>adj[i][j];
	            if(adj[i][j]==1)
	            {
	                v.push_back(make_pair(i,j));
	            }
	        }
	    }
	    int a,b;
	    count=v.size();
	    int ans=0;
	    vector<pair<int,int>>temp;
	    while(v.size()!=0)
	    {
	        count=v.size();
	        for(int i=0;i<v.size();i++)
	        {
	            a=v[i].first;
	            b=v[i].second;
	            if(a>0&&adj[a-1][b]==2)
	            {
	                v.erase(v.begin()+i,v.begin()+i+1);
	                temp.push_back(make_pair(a,b));
	                i--;
	            }
	            else if(b>0&&adj[a][b-1]==2)
	            {
	                v.erase(v.begin()+i,v.begin()+i+1);
	               temp.push_back(make_pair(a,b));
	                i--;
	            }
	            else if(a<r-1&&adj[a+1][b]==2)
	            {
	                v.erase(v.begin()+i,v.begin()+i+1);
	                temp.push_back(make_pair(a,b));
	                i--;
	            }
	            else if(b<c-1&&adj[a][b+1]==2)
	            {
	                v.erase(v.begin()+i,v.begin()+i+1);
	               temp.push_back(make_pair(a,b));
	                i--;
	            }

	        }
	        ans++;
	        if(count==v.size())
	        {
	            ans=-1;
	            break;
	        }
	        for(int i=0;i<temp.size();i++)
	        {
	            adj[temp[i].first][temp[i].second]=2;
	        }
	    }
	    cout<<ans<<endl;
	    
	}
}