// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool check(int n, int x, int y, vector<vector<int>> &visited, vector<vector<int>> &m)
    {
        // cout<<x<<" "<<y<<"\n";
        return x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && m[x][y];
    }
    void dfs(int n, int x, int y, vector<vector<int>> &visited, vector<vector<int>> &m, string res, vector<string> &result)
    {

        if (x == n - 1 && y == n - 1)
        {
            result.push_back(res);
            return;
        }
        visited[x][y] = 1;
        // cout<<res<<"\n";
        if (check(n, x - 1, y, visited, m))
            dfs(n, x - 1, y, visited, m, res + "U", result);
        if (check(n, x + 1, y, visited, m))
            dfs(n, x + 1, y, visited, m, res + "D", result);
        if (check(n, x, y - 1, visited, m))
            dfs(n, x, y - 1, visited, m, res + "L", result);
        if (check(n, x, y + 1, visited, m))
            dfs(n, x, y + 1, visited, m, res + "R", result);
        visited[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<vector<int>> visited(n, vector<int>(n));
        vector<string> result;
        if (m[0][0])
            dfs(n, 0, 0, visited, m, "", result);
        sort(result.begin(), result.end());
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends
