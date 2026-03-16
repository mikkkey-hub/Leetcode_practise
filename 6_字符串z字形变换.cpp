class Solution {
public:
    string convert(string s, int numRows) 
	{
		if(numRows ==1|| numRows ==s.size()) return s;
		
		vector<string>result(numRows);
		
		int row =0;
		bool change_direct =false;
		for(char x: s)
		{
			result[row] += x;
			if(row == 0||  row == numRows-1)
			{
				change_direct =!change_direct;
			}
			row = row + (change_direct ? 1:-1);
		}
		string result_;
		for(string & row :result)
		{
			result_ +=row;
			
		}
		return result_;
		
	}
	
};