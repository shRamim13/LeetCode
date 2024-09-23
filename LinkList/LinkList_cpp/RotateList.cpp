class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || k == 0)
        {
            return head;
        }
        ListNode *cur = head;
        int sz = 1;
        while (cur->next != nullptr)
        {
            cur = cur->next;
            sz++;
        }

        k = k % sz;
        if (k == 0)
        {
            return head;
        }

        cur->next = head;

        cur = head;
        for (int i = 0; i < sz - k - 1; i++)
        {
            cur = cur->next;
        }

        ListNode *newHead = cur->next;
        cur->next = nullptr;

        return newHead;
    }
};
