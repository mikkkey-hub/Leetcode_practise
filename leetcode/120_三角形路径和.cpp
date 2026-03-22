class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();  // 获取三角形的行数

        vector<vector<int>>s  =triangle;
        for(int i= n-2 ;i>=0 ;i--)
        {
            for(int j=0 ;j<=i ;j++)//因为是三角形 j<=i
            {
               s[i][j]=  min(s[i+1][j],s[i+1][j+1]) +triangle[i][j];
            }
        }
        return s[0][0];
    }
};