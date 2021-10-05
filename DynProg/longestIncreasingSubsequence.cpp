//Program to find the longest increasing subsequence in an array

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> seq;
    seq.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > seq.back())
            seq.push_back(nums[i]);
        else
        {
            int ind = lower_bound(seq.begin(), seq.end(), nums[i]) - seq.begin();
            seq[ind] = nums[i];
        }
    }
    return seq.size();
}