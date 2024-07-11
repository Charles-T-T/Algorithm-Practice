# 151. 反转字符串中的单词

[点此跳转题目链接](https://leetcode.cn/problems/reverse-words-in-a-string/description/)

## 题目描述

给你一个字符串 `s` ，请你反转字符串中 **单词** 的顺序。

**单词** 是由非空格字符组成的字符串。`s` 中使用至少一个空格将字符串中的 **单词** 分隔开。

返回 **单词** 顺序颠倒且 **单词** 之间用单个空格连接的结果字符串。

**注意：**输入字符串 `s`中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

 

**示例 1：**

```
输入：s = "the sky is blue"
输出："blue is sky the"
```

**示例 2：**

```
输入：s = "  hello world  "
输出："world hello"
解释：反转后的字符串中不能存在前导空格和尾随空格。
```

**示例 3：**

```
输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
```

 

**提示：**

- `1 <= s.length <= 104`
- `s` 包含英文大小写字母、数字和空格 `' '`
- `s` 中 **至少存在一个** 单词

 

**进阶：**如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 `O(1)` 额外空间复杂度的 **原地** 解法。



## 题解

题目中主要问题有二：

- 将句子中的单词排列顺序反转，但是单词内容本身不反转
- 去除冗余的空格

所以想到用**栈**来实现，将句中单词依次入栈，这样出栈时就自然解决了排列顺序反转的问题；出栈时，每个单词加入新字符串并添加一个空格，最后删除最后一个多余的空格，这样就解决了去除重复空格的问题。

细节方面，从原句读取单词可以通过遍历原句，每次遇到空格就将前面的字符“打包”成新单词入栈，但是这样要注意先在原句末尾加一个空格，以保证最后一个单词也能入栈。

**代码（C++）**

```cpp
string reverseWords(string s)
{
    // 思路：用栈存储各单词，既能自然反转，又便于去除重复的空格
    string word = "";
    stack<string> wordStack;
    s += " "; // 先在结尾添加空格，确保最后一个单词也入栈
    for (char c : s) {
        if (c != ' ')
            word += c;
        else {
            if (word != "") {
                wordStack.push(word);
                word = "";
            }
        }
    }
    string res = "";
    while (!empty(wordStack)) {
        res += wordStack.top();
        res += " ";
        wordStack.pop();
    }
    res.pop_back(); // 去掉结尾的空格
    return res;
}
```

此外，如果考虑原地修改字符串，将空间复杂度降为 $O(1)$ ，可以综合运用**双指针**等方法实现，总体思路为

- 去除字符串中多余的空格
- 反转整个字符串
- 反转字符串的每一个单词（就把单词本身又倒回来了）

代码实现（C++）参考代码随想录：

```cpp
class Solution {
public:
    void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int slow = 0;   //整体思想参考https://programmercarl.com/0027.移除元素.html
        for (int i = 0; i < s.size(); ++i) { //
            if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
                if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); //slow的大小即为去除多余空格后的大小。
    }

    string reverseWords(string s) {
        removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
        reverse(s, 0, s.size() - 1);
        int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
                start = i + 1; //更新下一个单词的开始下标start
            }
        }
        return s;
    }
};

```

