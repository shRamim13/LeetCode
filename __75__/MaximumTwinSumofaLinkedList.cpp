class Solution
{
public:
    int pairSum(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return 0;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = nullptr;
        ListNode *cur = slow;
        while (cur != nullptr)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        int maxSum = 0;
        ListNode *left = head;
        ListNode *right = prev;

        while (right)
        {
            maxSum = max(maxSum, left->val + right->val);
            left = left->next;
            right = right->next;
        }
        return maxSum;
    }
};