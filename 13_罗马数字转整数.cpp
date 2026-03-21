class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char, int> table = {
            {'M', 1000}, {'D', 500}, {'C', 100},
            {'L', 50},   {'X', 10},  {'V', 5}, {'I', 1}
        }; 
        int result  =0;
        for(int i = 0;i<s.size();i++)
        {
            int cur = table[s[i]] ;
            int next = (i + 1 < s.size()) ? table[s[i+1]] : 0;
            if (cur < next)  result -= cur;  //罗马数字里，小的写在大的左边表示相减
            else             result += cur; //对于C I V  , I < V，说明I是减数，即IV = 5-1 = 4
        }
        return result;
    }
};