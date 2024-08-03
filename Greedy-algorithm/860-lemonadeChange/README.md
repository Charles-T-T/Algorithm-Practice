# 860. 柠檬水找零

[点此跳转题目链接](https://leetcode.cn/problems/lemonade-change/description/)

## 题目描述

在柠檬水摊上，每一杯柠檬水的售价为 `5` 美元。顾客排队购买你的产品，（按账单 `bills` 支付的顺序）一次购买一杯。

每位顾客只买一杯柠檬水，然后向你付 `5` 美元、`10` 美元或 `20` 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 `5` 美元。

注意，一开始你手头没有任何零钱。

给你一个整数数组 `bills` ，其中 `bills[i]` 是第 `i` 位顾客付的账。如果你能给每位顾客正确找零，返回 `true` ，否则返回 `false` 。

 

**示例 1：**

```
输入：bills = [5,5,5,10,20]
输出：true
解释：
前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
由于所有客户都得到了正确的找零，所以我们输出 true。
```

**示例 2：**

```
输入：bills = [5,5,10,10,20]
输出：false
解释：
前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
由于不是每位顾客都得到了正确的找零，所以答案是 false。
```

 

**提示：**

- `1 <= bills.length <= 105`
- `bills[i]` 不是 `5` 就是 `10` 或是 `20` 



## 题解

非常简单的贪心算法，直接按生活常识的思路解决：每次尽量把大面值的钱找给顾客即可（小面值总是能找开的，贪心地尽量留着）。

**代码（C++）**

```cpp
bool lemonadeChange(vector<int> &bills)
{
    // 贪心：尽量先把大面值的找出去
    int cash5 = 0, cash10 = 0;
    for (int bill : bills)
    {
        switch (bill)
        {
        case 5:
            cash5++;
            break;
        case 10:
            if (!cash5)
                return false;
            cash5--;
            cash10++;
            break;
        case 20:
            if (cash10 && cash5)
                cash10--, cash5--;
            else if (cash5 >= 3)
                cash5 -= 3;
            else
                return false;
            break;
        default:
            break;
        }
    }
    return true;
}
```

**Go**

```go
func lemonadeChange(bills []int) bool {
	cash5, cash10 := 0, 0
	for _, bill := range bills {
		switch bill {
		case 5:
			cash5++
		case 10:
			if cash5 == 0 {
				return false
			}
			cash5--
			cash10++
		case 20:
			if cash10 > 0 && cash5 > 0 {
				cash10--
				cash5--
			} else if cash5 >= 3 {
				cash5 -= 3
			} else {
				return false
			}
		}
	}
	return true
}
```

