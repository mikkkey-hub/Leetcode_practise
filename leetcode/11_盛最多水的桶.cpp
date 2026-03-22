class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        if(n<=1) return 0;
        int water = 0;

        vector<int>::iterator it = height.begin();
        vector<int>::iterator it2 = height.end() -1;//end() 指向最后一个元素的下一个位置，需要用 end() - 1 才能指向最后一个元素。
        while(it < it2)
        {
            int width = it2 -it;

            int volume = min((*it),(*it2))*width ;
            if(volume>water)
            {
                water = volume; 
            }
            if( *(it)< *(it2) )
            {
                it++;
            }
            else
            {
                it2--;
            }
            
        }

        return water;
    }
};

