class Solution {
public:
    bool isValid(string s) {
        
        stack<char> barcket;
        
        for(int i =0;i<s.size();i++)
        {
            if(s[i] =='(') barcket.push(')');
            else if(s[i] =='[') barcket.push(']'); //与其存问题，不如直接存答案来匹配(以后要记住!)
            else if(s[i] =='{') barcket.push('}');
            else //只有当前元素为右括号时才进入
            {
                if(barcket.empty() || barcket.top()!= s[i]) return false;//顶部不匹配则一定完成不了
                barcket.pop();
            }
        }
        
        
        
        if(barcket.empty())
        {return true;}
        return false;
    }
};