
/*Necesssary condition: All nodes with no in-degree must in the final result,
because they can not be reached from
All other nodes can be reached from any other nodes.

Sufficient condition: All other nodes can be reached from some other nodes.  */
//its a leetcode ques so i won't able to provide full code 


    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res, seen(n);
        for (auto& e: edges)
            seen[e[1]] = 1;
        for (int i = 0; i < n; ++i)
            if (seen[i] == 0)
                res.push_back(i);
        return res;
    }
