package main

import "fmt"

func reverse(s string, begin int, end int) string {
	r := []rune(s)
	for i, j := begin, end-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	s = string(r)
	return s
}

func reverseStr(s string, k int) string {
	for i := 0; i < len(s); i += 2 * k {
		if len(s)-i >= k {
			s = reverse(s, i, i+k)
		} else {
			s = reverse(s, i, len(s))
		}
	}
	return s
}

func main() {
	s := "abcdefg"
	s = reverseStr(s, 2)
	fmt.Println("result:", s)
}