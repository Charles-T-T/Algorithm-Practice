package main

import (
	"fmt"
	"math"
)

var t_cnt map[rune]int
var window map[rune]int

func minWindow(s string, t string) string {
	t_cnt = make(map[rune]int)
	window = make(map[rune]int)
	for _, c := range t {
		t_cnt[c]++
	}

	uniqueCharCnt := len(t_cnt)

	l := 0
	start := -1
	minLen := math.MaxInt
	satisfiedCnt := 0
	for r, c := range s {
		window[c]++
		if cnt, ok := t_cnt[c]; ok && window[c] == cnt {
			satisfiedCnt++
		}
		for satisfiedCnt == uniqueCharCnt && l <= r {
			curLen := r - l + 1
			if curLen < minLen {
				start = l
				minLen = curLen
			}
			window[rune(s[l])]--
			if cnt, ok := t_cnt[rune(s[l])]; ok && window[rune(s[l])] < cnt {
				satisfiedCnt--
			}
			l++
		}
	}

	if start == -1 {
		return ""
	} else {
		return s[start : start+minLen]
	}
}

func main() {
	fmt.Println(minWindow("ADOBECODEBANC", "ABC"))
}
