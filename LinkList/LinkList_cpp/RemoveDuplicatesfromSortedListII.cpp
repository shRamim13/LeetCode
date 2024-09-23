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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *cur = head;
        ListNode *prev = nullptr;
        while (cur != nullptr)
        {
            if (cur->next != nullptr && cur->val == cur->next->val)
            {
                while (cur->next != nullptr && cur->val == cur->next->val)
                {
                    cur = cur->next;
                }
                if (prev != nullptr)
                {
                    prev->next = cur->next;
                }
                else
                {
                    head = cur->next;
                }
            }
            else
            {
                prev = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};