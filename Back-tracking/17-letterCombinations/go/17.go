package main

import "fmt"

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

func main() {
	digits := "277"
	fmt.Println(letterCombinations(digits))
}
