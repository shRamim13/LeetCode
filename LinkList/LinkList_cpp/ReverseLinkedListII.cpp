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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == nullptr || left == right)
        {
            return head;
        }
        ListNode *cur = head;
        ListNode *prev = nullptr;
        for (int i = 1; i < left; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        ListNode *start = prev;
        ListNode *end = cur;
        ListNode *tmp = nullptr;
        for (int i = 0; i < right - left + 1; i++)
        {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        if (start != nullptr)
        {
            start->next = prev;
        }
        else
        {
            head = prev;
        }
        end->next = cur;
        return head;
    }
};