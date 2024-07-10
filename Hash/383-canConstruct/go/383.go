package main

import "fmt"

func canConstruct(ransomNote string, magazine string) bool {
	charMap := make(map[rune]int)
	for _, c := range magazine {
		charMap[c]++
	}
	for _, c := range ransomNote {
		if charMap[c] == 0 {
			return false
		}
		charMap[c]--
	}
	return true
}

func main() {
	ransomNote := "aa"
	magazine := "aab"
	if canConstruct(ransomNote, magazine) {
		fmt.Println("Ture")	
	} else {
		fmt.Println("False")
	}
}