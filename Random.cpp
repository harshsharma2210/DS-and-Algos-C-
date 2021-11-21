/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        bool flag = true;
        dequeue<TreeNode *> q;
        q.push_back(root);
        vector<vector<int>> ans;
        while (!q.empty())
        {
            vector<int> v;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {

                if (flag)
                {
                    auto a = q.back();
                    if (a->left)
                    {
                        a.push_front(a->)
                    }
                    if (a->right)
                    {
                    }
                }
                else
                {
                }
            }
            flag = !flag;
        }
    }
};