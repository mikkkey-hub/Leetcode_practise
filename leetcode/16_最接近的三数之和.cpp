class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());

        int closetnum =nums[0]+nums[1]+nums[2];
        int n = nums.size();

        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1] ) continue;
        
            int left = i+1;
            int right = n-1;
            while(left<right)
            {
                int sum = nums[i] +nums[left]+nums[right];
                if(abs(sum-target)<abs(closetnum -target))
                {
                    closetnum = sum;
                    
                }

                if(sum == target)return target;
                else if(sum >target) right--;
                else {left++;}
            }

        
        }
        return closetnum;
    }
};