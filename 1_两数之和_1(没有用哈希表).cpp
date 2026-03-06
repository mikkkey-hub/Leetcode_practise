class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        for(int i =0;i<nums.size();i++)
        {
            for (int j= i +1 ;j<nums.size();j++)//必须从下一个位置开始 ,[3,2,4]否则直接3+3了
            {
               if (nums[i] + nums[j] == target) {
                    return {i, j}; //使用vector容器时可以这么写
               }
            }
        }
        return {};
    }
    
};