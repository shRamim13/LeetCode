int findCeil(Node *root, int input)
{
    int ceil = -1;
    while (root)
    {
        if (root->data == input)
        {
            ceil = root->data;
            break;
        }
        else if (root->data > input)
        {
            ceil = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ceil;
}
/*

class Solution {

public:
    int floor(Node* root, int x) {
        int floor = -1; // Initialize floor to -1 (not found)

        while (root) {
            if (root->data == x) {
                // If exact match, root->data is the floor
                floor = root->data;
                break;
            } else if (root->data < x) {
                // Current node could be a floor, explore right subtree
                floor = root->data;
                root = root->right;
            } else {
                // Current node is greater, explore left subtree
                root = root->left;
            }
        }

        return floor;
    }
};



*/