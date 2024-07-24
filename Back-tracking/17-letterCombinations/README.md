# 17. 电话号码的字母组合

[点此跳转题目链接](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/)

## 题目描述

给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。答案可以按 **任意顺序** 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

![img](./200px-telephone-keypad2svg.png)

 

**示例 1：**

```
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**示例 2：**

```
输入：digits = ""
输出：[]
```

**示例 3：**

```
输入：digits = "2"
输出：["a","b","c"]
```

 

**提示：**

- `0 <= digits.length <= 4`
- `digits[i]` 是范围 `['2', '9']` 的一个数字。



## 题解

> 参考：[代码随想录-17](https://programmercarl.com/0017.电话号码的字母组合.html#思路) 

回溯算法解决。首先想清楚回溯的树形结构图：

![img](./20201123200304469.png)

然后走**回溯三部曲** :sparkles: 

- **处理：** 从当前处理的数字对应的字母串中，取一个字母加入当前组合（字符串） `path` 

- **递归：** 递归地尝试将后面的数字对应的可能字母加入组合；递归出口： `path` 的长度与所给数字串 `digits` 相同，则将 `path` 加入结果集
- **回溯：** 弹出当前组合的最后一个字符，以便探索该位置放其他字母的可能

c++代码如下：

```cpp
class Solution
{
private:
    string path = "";
    vector<string> res;
    unordered_map<char, string> dict = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};

public:
    void backTracking(const string &digits, int start)
    {
        // 递归出口
        if (path.length() == digits.length())
        {
            res.push_back(path);
            return;
        }
        char digit = digits[start];   // 当前要处理的数字
        string letters = dict[digit]; // 当前处理数字对应的字母
        // 横向遍历
        for (int i = 0; i < letters.length(); i++)
        {
            path.push_back(letters[i]);      // 处理
            backTracking(digits, start + 1); // 递归
            path.pop_back();                 // 回溯
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
            return res;
        backTracking(digits, 0);
        return res;
    }
};
```

顺便再熟悉下golang：

```go
type Helper struct {
	path string
	res  []string
	dict map[byte]string
}

func newHelper() *Helper {
	return &Helper{
		dict: map[byte]string{
			'2': "abc",
			'3': "def",
			'4': "ghi",
			'5': "jkl",
			'6': "mno",
			'7': "pqrs",
			'8': "tuv",
			'9': "wxyz",
		},
	}
}

func (helper *Helper) backTracking(digits string, start int) {
	// 递归出口
	if len(helper.path) == len(digits) {
		helper.res = append(helper.res, helper.path)
		return
	}
	letters := helper.dict[digits[start]]
	for _, letter := range letters {
		helper.path = helper.path + string(letter)     // 处理
		helper.backTracking(digits, start+1)           // 递归
		helper.path = helper.path[:len(helper.path)-1] // 回溯
	}
}

func letterCombinations(digits string) []string {
	helper := newHelper()
	if len(digits) == 0 {
		return helper.res
	}
	helper.backTracking(digits, 0)
	return helper.res
}
```

