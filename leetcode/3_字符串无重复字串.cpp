class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // 边界处理：空字符串直接返回 0
        if (s.empty()) return 0;

        unordered_map<char, int> lastpos; // 记录每个字符最近一次出现的下标
        int MaxLength = 0;               // 当前找到的最长子串长度
        int left = 0;                    // 滑动窗口左边界

        for (int right = 0; right < s.length(); right++)
        {
            char CurrentChar = s[right];

            // 若当前字符已在窗口内出现过，则将左边界移到该字符上次出现位置的下一位
            // 条件 lastpos[CurrentChar] >= left 确保重复字符确实在当前窗口内
            if (lastpos.find(CurrentChar) != lastpos.end() && lastpos[CurrentChar] >= left)
            {
                left = lastpos[CurrentChar] + 1;
            }

            // 更新当前字符最近一次出现的下标
            lastpos[CurrentChar] = right;

            // 更新最大窗口长度（当前窗口大小 = right - left + 1）
            MaxLength = max(MaxLength, right - left + 1);
        }
        return MaxLength;
    }
};