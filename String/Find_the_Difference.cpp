#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        for ( int i = 0; i < t.length() ; i++ ) sum+=(t[i]-'a');
        for ( int i = 0; i < s.length() ; i++ ) sum-=(s[i]-'a');
        return ('a'+sum);
    }
};