void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    while (root != NULL)
    {

        if (root->key == key)
        {

            // To find sucessor-> Sucessor is either root of rightsubtree or
            // leftmost child in rightsubtree
            if (root->right)
            {

                Node *temp = root->right;
                while (temp->left)
                {
                    temp = temp->left;
                }
                suc = temp;
            }

            // To find Predecessor-> Predecessor is an element just less than key
            // So either root of left subtree or rightmost child in leftsubtree
            if (root->left)
            {
                Node *temp = root->left;
                while (temp->right)
                {
                    temp = temp->right;
                }
                pre = temp;
            }
            // IMP break when you reach the target node ie(KEY)
            break;
        }
        // Move towards key

        // Inorder is sorted in BST
        // If key less than root->data it means root->data can be it's sucessor

        else if (key < root->key)
        {
            suc = root;
            root = root->left;
        }
        // If key>root->data root->data can it's predesssor
        else
        {
            pre = root;
            root = root->right;
        }
    }
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    if (!root)
        return;

    if (root->key == key)
    {
        if (root->left)
        {
            pre = root->left;
            while (pre->right)
                pre = pre->right;
        }
        if (root->right)
        {
            suc = root->right;
            while (suc->left)
                suc = suc->left;
        }
    }
    else if (key < root->key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}