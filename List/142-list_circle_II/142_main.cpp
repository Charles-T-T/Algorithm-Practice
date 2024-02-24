#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��

�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ������� pos �� -1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������

�������޸� ����

ʾ�� 1��
���룺head = [3,2,0,-4], pos = 1
�������������Ϊ 1 ������ڵ�
���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣

ʾ�� 2��
���룺head = [1,2], pos = 0
�������������Ϊ 0 ������ڵ�
���ͣ���������һ��������β�����ӵ���һ���ڵ㡣

ʾ�� 3��
���룺head = [1], pos = -1
��������� null
���ͣ�������û�л���
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // ˼·�����ù�ϣ���ϣ������ظ�����򷵻�
        ListNode *dummyNode = new ListNode(0);
        unordered_set<ListNode*> nodeSet;
        dummyNode->next = head;
        while (dummyNode->next)
        {
            dummyNode = dummyNode->next;
            if (nodeSet.find(dummyNode) != nodeSet.end())
                return dummyNode;
            nodeSet.insert(dummyNode);
        }
        return NULL;
    }
};