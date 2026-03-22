class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        for(int x: nums1) merged.push_back(x);
        for(int x: nums2) merged.push_back(x);

        sort(merged.begin(),merged.end());
        int total = merged.size();

        if(total%2==1)
        {
            return merged[total/2];
        }
        else
        {
            return (merged[total/2] +  merged[(total/2)-1])/2.0;
            }
    }
};