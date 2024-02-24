#include <iostream>
#include <vector>
using namespace std;

/*
����һ������ nums ��һ��ֵ val������Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�

��Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ䲢 ԭ�� �޸��������顣

Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�

ʾ�� 1��

���룺nums = [3,2,2,3], val = 3
�����2, nums = [2,2]
���ͣ�����Ӧ�÷����µĳ��� 2, ���� nums �е�ǰ����Ԫ�ؾ�Ϊ 2���㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء����磬�������ص��³���Ϊ 2 ���� nums = [2,2,3,3] �� nums = [2,2,0,0]��Ҳ�ᱻ������ȷ�𰸡�
ʾ�� 2��

���룺nums = [0,1,2,2,3,0,4,2], val = 2
�����5, nums = [0,1,3,0,4]
���ͣ�����Ӧ�÷����µĳ��� 5, ���� nums �е�ǰ���Ԫ��Ϊ 0, 1, 3, 0, 4��ע�������Ԫ�ؿ�Ϊ����˳���㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
*/

class Solution
{
public:
    int removeElement1(vector<int> &nums, int val)
    {
        // ˼·������Ҫɾ���ģ��ͺ���������ǰ���루����˳����ɾ������ĩβԪ��pop_back()��
        int initSize = nums.size(), i = 0;
        while (i < nums.size())
        {
            if (nums[i] == val)
            {
                for (int j = i; j < nums.size() - 1; j++)
                {
                    nums[j] = nums[j + 1];
                }
                nums.pop_back();
                continue;
            }
            i++;
        }
        return nums.size();
    }

    int removeElement2(vector<int> &nums, int val)
    {
        // ˼·��˫ָ�룬���ָ�������ָ��֮ǰ�ƶ�
        int test = 0, fill = 0;
        while (test < nums.size())
        {
            if (nums[test] != val)
            {
                nums[fill] = nums[test];
                fill++;
            }
            test++;
        }
        return fill;
    }
};

int main(){
    vector<int> nums;
    int val, size, num;
    cout << "please input the val: ";
    cin >> val;
    cout << "please input the size of nums: ";
    cin >> size;
    cout << "please input the nums, divided by space: ";
    int i = 0;
    while (i < size)
    {
        cin >> num;
        nums.push_back(num);
        i++;
    }

    Solution solution;
    cout << "new size of nums: " << solution.removeElement2(nums, val) << endl;
    cout << "new nums: [ ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}