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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *smaller = new ListNode(0);
        ListNode *greater = new ListNode(0);
        ListNode *sml = smaller;
        ListNode *grt = greater;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            if (x > cur->val)
            {
                sml->next = cur;
                sml = sml->next;
            }
            else
            {
                grt->next = cur;
                grt = grt->next;
            }
            cur = cur->next;
        }
        grt->next = nullptr;
        sml->next = greater->next;
        ListNode *newHead = smaller->next;
        delete smaller;
        delete greater;
        return newHead;
    }
};