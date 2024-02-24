#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
����һ���ַ������飬���㽫 ��ĸ��λ�� �����һ�𡣿��԰�����˳�򷵻ؽ���б�

��ĸ��λ�� ������������Դ���ʵ�������ĸ�õ���һ���µ��ʡ�



ʾ�� 1:

����: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
���: [["bat"],["nat","tan"],["ate","eat","tea"]]
ʾ�� 2:

����: strs = [""]
���: [[""]]
ʾ�� 3:

����: strs = ["a"]
���: [["a"]]
*/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        for (string const str : strs){
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }

        vector<vector<string>> res;
        for (auto const pair : map){
            res.push_back(pair.second);
        }

        return res;
    }
};