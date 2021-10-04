// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    struct node
    {
        char data;
        int freq;
        node *left, *right;
        node(char d, int f)
        {
            data = d;
            freq = f;
            left = NULL;
            right = NULL;
        }
    };
    struct cmp
    {
        bool operator()(node *a, node *b)
        {
            return a->freq > b->freq;
        }
    };
    void print(node *root, vector<string> &result, string str)
    {
        if (root == NULL)
            return;
        if (root->data != '$')
            result.push_back(str);
        print(root->left, result, str + "0");
        print(root->right, result, str + "1");
    }
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        // Code here
        priority_queue<node *, vector<node *>, cmp> pq;
        for (int i = 0; i < N; i++)
        {
            pq.push(new node(S[i], f[i]));
        }
        node *left, *right, *top;
        while (pq.size() != 1)
        {
            left = pq.top();
            pq.pop();
            right = pq.top();
            pq.pop();
            top = new node('$', left->freq + right->freq);
            top->left = left;
            top->right = right;
            pq.push(top);
        }
        vector<string> result;
        print(pq.top(), result, "");
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0; i < N; i++)
        {
            cin >> f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f, N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends