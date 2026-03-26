class Solution {
public:

    unordered_map<char,string> keyboard = {
        {'2',"abc"},{'3',"def"},{'4',"ghi"},
        {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
        {'8',"tuv"},{'9',"wxyz"}
    };

    vector<string> result;

    void  traceback(int index,string &path ,string &digits)
    {
        if(index == digits.size()){
        result.push_back(path);
        return;}
        string letters = keyboard[digits[index]];
        for(char alpha : letters)
        {
            path.push_back(alpha);
            traceback(index+1,path,digits);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        
        if(digits.size()==0) return{};
        string path;
        traceback(0,path,digits);
        return result;
        
    }
};