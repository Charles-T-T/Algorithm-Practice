package main

import "fmt"

var res [][]string
var path []string

func palindrome(s string) bool {
	l := 0
	r := len(s) - 1
	for l <= r {
		if s[l] != s[r] {
			return false
		}
		l++
		r--
	}
	return true
}

func backTracking(s string, cutPos int) {
	if cutPos == len(s) {
		tmp := make([]string, len(path))
		copy(tmp, path)
		res = append(res, tmp)
		return
	}

	for i := cutPos; i < len(s); i++ {
		sub := s[cutPos : i+1]
		if palindrome(sub) {
			path = append(path, sub)
		} else {
			continue
		}
		backTracking(s, i+1)
		path = path[:len(path)-1]
	}
}

func partition(s string) [][]string {
	res = make([][]string, 0)
	path = make([]string, 0)
	backTracking(s, 0)
	return res
}

func main() {
	res := partition("aab")
	fmt.Println(res)	
}