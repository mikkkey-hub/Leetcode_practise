class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if (s.empty()) return 0;   // 空串直接返回0
        if (s.length() == 1) return 1;  // 单字符直接返回1
        
        const char* p2 = s.data();  // 获取字符串底层数组指针，方便下标访问
        int carry = 1;  // 记录最长无重复子串长度，最少为1

        // ── 第一层：枚举子串长度 i（从2开始，1已经是初始值）──
        for (int i = 2; i <= s.length(); i++)
        {
            bool found_valid = false;  // 标记：当前长度i下是否找到无重复子串
           
            // ── 第二层：枚举当前长度i下所有可能的起点j ──
            // 起点最大值为 s.length()-i，保证子串不越界
            for (int j = 0; j <= s.length() - i; j++)
            {
                bool has_repeat = false;  // 标记：当前子串[j, j+i)是否含重复字符

                // ── 第三层：枚举子串内每个字符k作为"基准" ──
                // k 从起点j 到 倒数第二个字符(j+i-2)
                for (int k = j; k < j + i - 1; k++)
                {
                    // ── 第四层：将k与其后每个字符p逐一比较 ──
                    // p 从k+1 到 子串末尾(i+j-1)
                    for (int p = k + 1; p < i + j; p++)
                    {
                        if (p2[k] == p2[p])   // 发现重复字符
                        {
                            has_repeat = true;
                            break;  // 退出第四层
                        }
                    }
                    if (has_repeat) break;  // 退出第三层
                }

                if (!has_repeat)  // 当前子串无重复
                {
                    carry = i;          // 更新最长长度
                    found_valid = true; // 标记当前长度i有效
                    break;  // 同一长度下找到一个就够了，退出第二层
                }
            }

            // 当前长度i下，所有起点的子串都含重复字符
            // 说明更长的子串也不可能无重复，直接终止
            if (!found_valid) break;  // 退出第一层
        }

        return carry;  // 返回最长无重复子串长度
    }
};
/*

---

## 核心原理

**枚举子串长度，逐级验证**
```
字符串: a b c a b c b b
索引:   0 1 2 3 4 5 6 7

i=2（检查所有长度为2的子串）:
  j=0: [a,b] → a≠b → 无重复 ✅ carry=2, found_valid=true, break

i=3（检查所有长度为3的子串）:
  j=0: [a,b,c] → 两两比较全不同 → 无重复 ✅ carry=3, found_valid=true, break

i=4（检查所有长度为4的子串）:
  j=0: [a,b,c,a] → a==a → 有重复 ❌
  j=1: [b,c,a,b] → b==b → 有重复 ❌
  j=2: [c,a,b,c] → c==c → 有重复 ❌
  j=3: [a,b,c,b] → b==b → 有重复 ❌
  j=4: [b,c,b,b] → b==b → 有重复 ❌
  found_valid=false → break，终止外层循环

返回 carry = 3 ✅
```

---

## 关键设计决策
```
found_valid 的作用
─────────────────────────────────────────────
长度i下找到无重复子串  →  found_valid=true
                          记录carry=i，break内层
                          继续尝试更长的i+1

长度i下全部有重复     →  found_valid=false
                          if(!found_valid) break
                          ↓
                     比i更长的子串必然也有重复
                     （长子串包含短子串，重复只会更多）
                     直接终止，避免无效搜索*/