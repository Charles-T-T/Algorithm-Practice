#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*
给你一个单链表的头节点 head ，请你判断该链表是否为
回文链表.如果是，返回 true ；否则，返回 false 。

示例 1：
输入：head = [1,2,2,1]
输出：true

示例 2：
输入：head = [1,2]
输出：false
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        // 思路：用数组存储链表的值，再用双指针在该数组上检查是否回文
        vector<int> numsVec;
        while (head)
        {
            numsVec.push_back(head->val);
            head = head->next;
        }

        int left = 0, right = numsVec.size() - 1;
        while(left <= right){
            if (numsVec[left++] != numsVec[right--])
                return false;
        }

        return true;
    }
};

int main(){
    ListNode *dummyNode = new ListNode();
    ListNode *cur = dummyNode;
    string line, token;
    cout << "please input the list nums: ";
    getline(cin, line);
    stringstream ss(line);
    while (ss >> token)
    {
        cur->next = new ListNode(stoi(token));
        cur = cur->next;
    }

    Solution obj;
    if (obj.isPalindrome(dummyNode->next))
        cout << "True!" << endl;
    else
        cout << "False!" << endl;

    return 0;
}