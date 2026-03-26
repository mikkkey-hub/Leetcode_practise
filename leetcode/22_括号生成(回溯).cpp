class Solution {
public:

/*
            1.这道题是"枚举出所有可能"吗？
            2.枚举的过程能不能画成一棵树？
            3.树上有没有可以提前剪掉的分支？

    三个都满足大概率可以用回溯。
*/

    vector<string> result;

    void traceback(int left,int right,string&path,int n)//回溯提通用模板
    {
        if(left == n && right == n) 
        {
        result.push_back(path);
        return;
        }

        if(left<n)
        {
            path.push_back('(');
            traceback(left+1 ,right,path,n);
            path.pop_back();
        }

        if(right<left) //必须要这么写,而不能是right<n,否则可能出现 类似于")("的情况
            //话说反着写的两个括号配上引号有种莫名的可爱感呢..
        {
            path.push_back(')');
            traceback(left ,right+1,path,n);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string path;
        traceback(0,0,path,n);
        return result;
    }
};