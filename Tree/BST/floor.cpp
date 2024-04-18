int Floor(BinaryTreeNode<int> *node, int input)
{
    int floor = -1;
    while (node != NULL)
    {
        if (node->data == input)
        {
            floor = input;
            return floor;
        }
        if (input > node->data)
        {
            floor = node->data;
            node = node->right;
        }
        else
        {
            node = node->left;
        }
    }
    return floor;
}
