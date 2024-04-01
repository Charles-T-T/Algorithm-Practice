#include <iostream>
#include <sstream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例 1：
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.

示例 2：
输入：l1 = [0], l2 = [0]
输出：[0]

示例 3：
输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
*/

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode();
        ListNode *head = res;

        // 思路：一步步走就行了
        int addFlag = 0; // 标记是否进位
        int sum;
        while (l1 && l2){
            sum = l1->val + l2->val;
            if (addFlag)
                sum++;
            if (sum >= 10){
                res->next = new ListNode(sum % 10);
                addFlag = 1;
            }
            else{
                res->next = new ListNode(sum);
                addFlag = 0;
            }

            l1 = l1->next;
            l2 = l2->next;
            res = res->next;
        }

        // 出现某个数字已读取完
        if (!l1 && !l2){
            if (addFlag)
                res->next = new ListNode(1);
            return head->next;
        }
            
        else if (!l1){
            while (l2)
            {
                sum = l2->val;
                if (addFlag){
                    sum++;
                    if (sum >= 10){
                        res->next = new ListNode(sum % 10);
                        l2 = l2->next;
                        res = res->next;
                        continue;
                    }
                }
                
                res->next = new ListNode(sum);
                l2 = l2->next;
                res = res->next;
                addFlag = 0;
            }
        }else {
            while (l1)
            {
                sum = l1->val;
                if (addFlag)
                {
                    sum++;
                    if (sum >= 10)
                    {
                        res->next = new ListNode(sum % 10);
                        l1 = l1->next;
                        res = res->next;
                        continue;
                    }
                }

                res->next = new ListNode(sum);
                l1 = l1->next;
                res = res->next;
                addFlag = 0;
            }
        }

        if (addFlag)
            res->next = new ListNode(1);

        return head->next;
    }
};

int main(){
    ListNode *dummyNode1 = new ListNode();
    ListNode *dummyNode2 = new ListNode();
    ListNode *l1 = dummyNode1;
    ListNode *l2 = dummyNode2;

    cout << "start inputting l1, ended by -1: ";
    string l1s;
    getline(cin, l1s);
    istringstream iss1(l1s);
    string token;
    while (iss1 >> token)
    {
        if (stoi(token) == -1)
            break;
        l1->next = new ListNode(stoi(token));
        l1 = l1->next;
    }

    cout << "start inputting l2, ended by -1: ";
    string l2s;
    getline(cin, l2s);
    istringstream iss2(l2s);
    while (iss2 >> token)
    {
        if (stoi(token) == -1)
            break;
        l2->next = new ListNode(stoi(token));
        l2 = l2->next;
    }



    cout << "------------------" << endl;
    Solution obj;
    ListNode *res = obj.addTwoNumbers(dummyNode1->next, dummyNode2->next);
    while (res)
    {
        cout << res->val << " ";
        res = res->next;
    }
    

    return 0;
}