package main

import "fmt"

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

func main() {
	bills := []int{5, 5, 5, 10, 20}
	fmt.Println(lemonadeChange(bills))
}