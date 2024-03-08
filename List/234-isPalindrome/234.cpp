#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*
����һ���������ͷ�ڵ� head �������жϸ������Ƿ�Ϊ
��������.����ǣ����� true �����򣬷��� false ��

ʾ�� 1��
���룺head = [1,2,2,1]
�����true

ʾ�� 2��
���룺head = [1,2]
�����false
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
        // ˼·��������洢�����ֵ������˫ָ���ڸ������ϼ���Ƿ����
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