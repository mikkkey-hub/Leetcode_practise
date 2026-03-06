class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> hashmap; //unordered_map比map更快
        for(int i =0;i<nums.size();i++)
        {
            int complemet = target- nums[i];

            //hashmap.find(complemet)返回complemet所在的位置(即差值存在了)

            if(hashmap.find(complemet) != hashmap.end())
            {
                //如果这里找到了
               return{hashmap[complemet],i};//取出 complement 对应的下标

            }
            //没找到则将当前位置,存入map中(即nums位置i中存放的值a存到hashmap的第a个位置中,)
            hashmap[nums[i]] =i;
        }
        return {};
    }
};