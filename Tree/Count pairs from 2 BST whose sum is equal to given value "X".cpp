void insert(Node *root, unordered_map<int, int> &mp)
{
    if (!root)
    {
        return;
    }
    insert(root->left, mp);
    mp[root->data]++;
    insert(root->right, mp);
}
void cal(Node *root, int x, unordered_map<int, int> mp, int &count)
{
    if (!root)
    {
        return;
    }
    cal(root->left, x, mp, count);
    if (mp[x - root->data] > 0)
    {
        count++;
    }
    cal(root->right, x, mp, count);
}

int countPairs(Node *root1, Node *root2, int x)
{
    // Code here
    unordered_map<int, int> mp;
    insert(root1, mp);
    int count = 0;
    cal(root2, x, mp, count);
    return count;
}