package main

import (
	"fmt"
)

// 回溯法 + 记忆化搜索
// 记忆化搜索：memeory[i] = true 表示
// s 从下标 i 开始的子串可以由 wordDict 中的单词组成
var memeory map[int]bool

// wordDict 中单词的哈希表，方便查找
var words map[string]struct{}

// 回溯法：判断 s 从下标 start 开始的子串是否可以由 wordDict 中的单词组成
func canConsFromDict(s string, wordDict []string, start int) bool {
	// 回溯出口
	if start == len(s) {
		return true
	}

	// 利用记忆化搜索
	if memeory[start] {
		return true
	}

	// 回溯
	for end := start + 1; end <= len(s); end++ {
		if _, exist := words[s[start:end]]; exist && canConsFromDict(s, wordDict, end) {
			memeory[start] = true
			return true
		}
	}

	// 上述尝试都失败，说明当前子串不能由 wordDict 中的单词组成
	memeory[start] = false
	return false
}

func wordBreak_0(s string, wordDict []string) bool {
	for _, word := range wordDict {
		words[word] = struct{}{}
	}
	return canConsFromDict(s, wordDict, 0)
}

func init() {
	memeory = make(map[int]bool)
	words = make(map[string]struct{})
}
 

// 动态规划解决
func wordBreak(s string, wordDict []string) bool {
	// dp[i]: s 的前 i 个字符组成的子串，能否由 wordDict 中的单词构成
	dp := make([]bool, len(s) + 1)
	dp[0] = true // 初始化 
	
	// 将 wordDict 中的单词放到哈希表中，方便使用
	words := make(map[string]struct{})
	for _, word := range(wordDict) {
		words[word] = struct{}{}
	}

	for i := 0; i < len(s); i++ {
		for j := i + 1; j <= len(s); j++ {
			_, ijIsSubstr := words[s[i:j]]
			if dp[i] && ijIsSubstr {
				dp[j] = true
			}
		}
		if dp[len(s)] {
			return true
		}
	}
	return dp[len(s)]
}

func main() {
	s := "leetcode"
	wordDict := []string{"leet", "code"}
	fmt.Println(wordBreak(s, wordDict))
}
