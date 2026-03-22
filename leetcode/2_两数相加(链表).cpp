/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 创建虚拟头节点：避免处理空链表的特殊情况
        ListNode* L3 = new ListNode();
        ListNode* p = L3;
        int carry = 0; 
        int temp1, temp2;

        // 循环条件：只要还有节点没处理完，或者还有进位，就要继续
        // 错误1：之前写成了 l1->next != NULL，这是错的！
        // 教训：要判断当前节点是否存在，而不是下一个节点
        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            // 获取l1当前节点的值
            // 错误2：之前用 l1->next 判断，导致最后一个节点无法取值
            // 教训：应该用 l1 != NULL 判断当前节点是否存在
            if(l1 != NULL)
            {
                temp1 = l1->val;  // 注意：l1是指针，要用->
            }
            else 
            {
                temp1 = 0;  // 链表长度不同时，短链表补0
            }
            
            // 获取l2当前节点的值，同理
            if(l2 != NULL)
            {
                temp2 = l2->val;
            }
            else 
            {
                temp2 = 0;
            }

            // 计算当前位的和（带上进位）
            int sum = temp1 + temp2 + carry;
            int mod = sum % 10;  // 当前位要存的值
            carry = sum / 10;    // 更新进位
            
            // 创建新节点存储当前位的结果
            ListNode* q = new ListNode(mod);
            p->next = q;  // 连接到结果链表
            p = q;        // 移动指针到新节点
            
            // 移动l1和l2的指针到下一个节点
            // 错误3：之前用 l1->next != NULL 判断，导致指针无法移动
            // 教训：应该用 l1 != NULL 判断，然后移动到next
            if(l1 != NULL)
            {
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                l2 = l2->next;
            }
        }
        // 返回虚拟头节点的下一个节点（真正的头节点）
        return L3->next;
    }
};