class Solution {
public:
    string longestPalindrome(string s) {
        
        if (s.size()<=1) return s;
        
        string exp_s(s.size()*2+1,'#');
        int index =0;
        for(int i =1;i<exp_s.size();i+=2)
        {
            exp_s[i]=s[index];
            index++;
        }//得到一个在字符之间插入了 # 号的新字符串 exp_s,确保始终为奇数有中心

        //遍历扩展之后的字符串
        int max_radius =-1;
        int max_center =-1; //记录最大的回文半径和最大半径的对应的中心
        vector<int> radiuse(exp_s.size());//存储每个点的最大半径

        int right_radius = -1; //之前所有处理过的回文串中能够到达的最右边的索引
        int right_center = -1; //如果之前有回文串半径延伸到了当前遍历的点的右边,right_center 就是那个回文串的中心点

        for(int i =0;i<exp_s.size();i++)//exp_s[i]//为当前中心点
        {
            
            //int radius =1;//当前的半径
            int radius = i < right_radius ? min(radiuse[2*right_center-i],right_radius -i):1;
            //i < right_radius，说明当前位置 i 在某个已知回文串的内部，可以利用对称(?区域)
            //2*right_center - i,这是 i 以 right_center 点的对称点的索引,因为i在right_center右边,索引值更大
            //radiuse[2*right_center-i] 即对应的对称点的最大回文半径
            //right_radius - i 来防止i的半径超出边界

            while( i+radius<exp_s.size() && i-radius >-1)//如果没有碰到边界,向两边扩
            {
                if(exp_s[i+radius]==exp_s[i-radius])
                {
                    radius++;
                }
                else
                {
                    break;
                }

            }
            radiuse[i] = radius; //存储当前点的最大半径
            if(radius>max_radius)
            {
                max_center =i;//记录当前的中心点和半径
                max_radius = radius;
            }
            if(i+radius>right_radius)//如果当前点的半径更大则修改为新的最大半径
            {//即需要维护一个最大的半径,即对应的中心点
                right_radius = i+radius;
                right_center = i;
            }    
        }
        string res_s =exp_s.substr(max_center-max_radius+1,2*max_radius-1);
        // substr(起始位置, 长度)
        // 起始位置: max_center - max_radius + 1
        // 长度: 2*max_radius - 1  
        // 回文串长度为 (2*radius-1)，减去1是因为半径包括中心点本身


        string res;
        for(auto c : res_s)
        {
            if(c!= '#')
            {
                res.push_back(c);
            }
        }


        return res;

    }
};