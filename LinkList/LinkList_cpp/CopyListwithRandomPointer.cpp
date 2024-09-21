/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return head;
        }
        Node *cur = head;
        while (cur != nullptr)
        {
            Node *newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = cur->next->next;
        }
        cur = head;
        while (cur != nullptr)
        {
            if (cur->random != nullptr)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        cur = head;
        Node *newHead = head->next;
        Node *headNext = newHead;
        while (cur != nullptr)
        {
            cur->next = headNext->next;
            cur = cur->next;
            if (cur != nullptr)
            {
                headNext->next = cur->next;
                headNext = headNext->next;
            }
        }

        return newHead;
    }
};