#include <iostream>
#include <vector>

using namespace std;

/*
����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������

�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γɡ�

���⣬����Լ��������������߾���ˮ��Χ��

ʾ�� 1��
���룺grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
�����1

ʾ�� 2��
���룺grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
�����3
*/

class Solution
{
public:
    bool inArea(const vector<vector<char>> &grid, int i, int j){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return false;
        else
            return true;
    }

    int visit(vector<vector<char>> &grid, int i, int j){
        // �����ʵ�һƬ½��ʱ�����ط�0ֵ�����򷵻�0
        if (!inArea(grid, i, j))
            return 0;
        
        if (grid[i][j] != '1') // Ϊˮ����ѷ��ʹ���½��
            return 0;
        else{
            grid[i][j] = '2';
            return 1 + visit(grid, i - 1, j) + visit(grid, i + 1, j) + visit(grid, i, j - 1) + visit(grid, i, j + 1);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        /**
         * ˼·�������е�DFS������ݹ�д����
         * ����grid[i][j]��ֵ��
         * 0��ˮ��
         * 1��½�أ�δ���ʣ�
         * 2��½�أ��ѷ��ʣ�
         * �߽��жϣ�Խ��ʱ��ʹ����
        */
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++){
                if (visit(grid, i, j))
                    res++;
            }
        }

        return res;
    }
};