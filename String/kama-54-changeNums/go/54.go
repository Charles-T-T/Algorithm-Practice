package main

import (
	"fmt"
	"strings"
	"unicode"
)

func changeNum(s string) string {
	var builder strings.Builder
	for _, c := range(s) {
		if unicode.IsDigit(c) {
			builder.WriteString("number")	
		} else {
			builder.WriteRune(c)
		}
	}
	return builder.String()
}

func main() {
	var s string
	fmt.Scanln(&s)
	fmt.Println(changeNum(s))
}