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
�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�

���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����

����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

ʾ�� 1��
���룺l1 = [2,4,3], l2 = [5,6,4]
�����[7,0,8]
���ͣ�342 + 465 = 807.

ʾ�� 2��
���룺l1 = [0], l2 = [0]
�����[0]

ʾ�� 3��
���룺l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
�����[8,9,9,9,0,0,0,1]
*/

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode();
        ListNode *head = res;

        // ˼·��һ�����߾�����
        int addFlag = 0; // ����Ƿ��λ
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

        // ����ĳ�������Ѷ�ȡ��
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