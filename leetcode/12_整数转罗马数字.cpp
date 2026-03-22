class Solution {
public:
    string intToRoman(int num) {
       vector<pair<int,string>>table = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100,  "C"}, {90,  "XC"}, {50,  "L"}, {40,  "XL"},
        {10,   "X"}, {9,   "IX"}, {5,   "V"}, {4,   "IV"},
        {1,    "I"}
       };

       string s;
       for(auto& [val ,sym] :table)//当前的值不够了就走下一个面值
       {
            while(num>=val) // 只要还能用当前的这个值,就一直用,比如3000,一直用最大的1000
            {
                s += sym;
                num -= val; 
            }
       }
     return s;
    }
};