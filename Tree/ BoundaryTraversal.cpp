class Solution
{
public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int mn = INT_MAX;
    Node *lca(Node *root, int n1, int n2)
    {
        //Your code here
        if (root == NULL)
            return NULL;

        if (n1 == root->data || n2 == root->data)
            return root;
        Node *left = lca(root->left, n1, n2);
        Node *right = lca(root->right, n1, n2);

        if (left && right)
            return root;
        if (left)
            return left;
        if (right)
            return right;
    }
    int dis(Node *root, int data, int d)
    {
        if (!root)
            return -1;
        if (root->data == data)
            return d;
        int l = dis(root->left, data, d + 1);
        int r = dis(root->right, data, d + 1);
        return max(l, r);
    }
    int findDist(Node *root, int a, int b)
    {
        // Your code here
        mn = INT_MAX;
        Node *lc = lca(root, a, b);
        int x = dis(lc, a, 0);
        int y = dis(lc, b, 0);
        return mn;
    }
};
