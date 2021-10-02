#include <bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int> &, int);

// your code will be pasted here

int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }

        vec = productExceptSelf(arr, n); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

//User function template for C++

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    //code here
    long long prod = 1;
    vector<long long> res;
    bool checkZero = false, checkMultipleZero = false;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i])
            prod *= nums[i];
        else
        {
            if (checkZero)
                checkMultipleZero = true;
            checkZero = true;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (checkZero)
        {
            if (checkMultipleZero)
            {
                res.push_back(0);
                continue;
            }
            if (nums[i])
                res.push_back(0);
            else
                res.push_back(prod);
        }
        else
        {
            res.push_back(prod / nums[i]);
        }
    }
    return res;
}