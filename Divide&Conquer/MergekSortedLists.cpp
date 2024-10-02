class Solution
{
public:
    // Iteratively merge two sorted linked lists (stack-allocated dummy node)
    ListNode *merge(ListNode *p, ListNode *q)
    {
        ListNode dummy(0);          // Create dummy node on the stack
        ListNode *current = &dummy; // Pointer to the dummy node

        while (p != nullptr && q != nullptr)
        {
            if (p->val < q->val)
            {
                current->next = p;
                p = p->next;
            }
            else
            {
                current->next = q;
                q = q->next;
            }
            current = current->next;
        }
        current->next = p ? p : q; // Attach remaining nodes

        return dummy.next; // Access 'next' using '.' since 'dummy' is an object
    }

    ListNode *solve(vector<ListNode *> &lists, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        if (start == end)
        {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        ListNode *left = solve(lists, start, mid);
        ListNode *right = solve(lists, mid + 1, end);
        return merge(left, right);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return solve(lists, 0, lists.size() - 1);
    }
};

/*class Solution {
public:
    // Iteratively merge two sorted linked lists (heap-allocated dummy node)
    ListNode* merge(ListNode* p, ListNode* q) {
        ListNode* dummy = new ListNode(0); // Create dummy node on the heap
        ListNode* current = dummy; // Pointer to the dummy node

        while (p != nullptr && q != nullptr) {
            if (p->val < q->val) {
                current->next = p;
                p = p->next;
            } else {
                current->next = q;
                q = q->next;
            }
            current = current->next;
        }
        current->next = p ? p : q; // Attach remaining nodes

        ListNode* result = dummy->next; // Access 'next' using '->' since 'dummy' is a pointer
        delete dummy; // Free the heap-allocated dummy node
        return result;
    }

    ListNode* solve(vector<ListNode*>& lists, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        if (start == end) {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        ListNode* left = solve(lists, start, mid);
        ListNode* right = solve(lists, mid + 1, end);
        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return solve(lists, 0, lists.size() - 1);
    }
};
*/