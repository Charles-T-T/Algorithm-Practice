#include "../TreeNode.h"

class Solution
{
public:
    unordered_map<int, int> freqMap; // 用一个哈希表记录每个数值出现的频率
    int maxShowTime = -1;
    // 中序遍历
    void traversal(TreeNode *cur)
    {
        if (cur->left)
            traversal(cur->left); // 左
        freqMap[cur->val]++;      // 中
        if (cur->right)
            traversal(cur->right); // 右
    }

    vector<int> findMode(TreeNode *root)
    {
        traversal(root);
        vector<int> res;
        for (const auto &pair : freqMap)
        {
            if (pair.second > maxShowTime)
            {
                maxShowTime = pair.second;
                res.clear(); // 出现更高频的元素，将原来的结果集清空
                res.push_back(pair.first);
            }
            else if (pair.second == maxShowTime)
                res.push_back(pair.first); // 众数可能不止一个
        }
        return res;
    }
};

// 不用额外空间的解法
class Solution2
{
public:
    int maxShowTime = -1;
    int curShowTime = 0;
    TreeNode *pre = nullptr; // 中序遍历序列中，当前节点的前一个节点
    vector<int> res;
    // 中序遍历
    void traversal(TreeNode *cur)
    {
        // 左
        if (cur->left)
            traversal(cur->left);

        // 中
        if (!pre)
            curShowTime = 1; // 第一个节点
        else if (cur->val == pre->val)
            curShowTime++; // 相同的节点值
        else
            curShowTime = 1; // 新的节点值

        pre = cur; // 更新前节点指针

        if (curShowTime == maxShowTime)
            res.push_back(cur->val);

        if (curShowTime > maxShowTime)
        {
            maxShowTime = curShowTime; // 更新最大出现频率
            res.clear();               // 清除之前的结果
            res.push_back(cur->val);
        }

        // 右
        if (cur->right)
            traversal(cur->right);
    }

    vector<int> findMode(TreeNode *root)
    {
        traversal(root);
        return res;
    }
};

int main()
{
    TreeNode *root = getRootFromStr("1,1");
    Solution2 obj;
    vector<int> res = obj.findMode(root);
    for (int num : res)
        cout << num << " ";
    cout << endl;

    return 0;
}