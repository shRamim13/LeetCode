class Solution
{
public:
    ListNode *findMid(ListNode *root)
    {
        ListNode *slow = root;
        ListNode *fast = root->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *lt, ListNode *rt)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (lt != nullptr && rt != nullptr)
        {
            if (lt->val < rt->val)
            {
                cur->next = lt;
                lt = lt->next;
            }
            else
            {
                cur->next = rt;
                rt = rt->next;
            }
            cur = cur->next;
        }
        cur->next = lt ? lt : rt;
        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *mid = findMid(head);
        ListNode *rightHead = mid->next;
        mid->next = nullptr;
        ListNode *leftNode = sortList(head);
        ListNode *rightNode = sortList(rightHead);
        return merge(leftNode, rightNode);
    }
};