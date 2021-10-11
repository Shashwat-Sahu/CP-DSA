//link : https://leetcode.com/problems/find-all-duplicates-in-an-array/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            //if the number is negative then it is repeated so insert it into the vector
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            else
                //if the number is not repeated change it to negative
                nums[abs(nums[i])-1]*=-1;
        }return ans;
    }
};