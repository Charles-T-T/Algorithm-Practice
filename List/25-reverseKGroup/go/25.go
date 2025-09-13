package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	dummyHead := &ListNode{
		Val:  0,
		Next: head,
	}
	kNodes := make([]*ListNode, 0, k)
	prev := dummyHead
	cur := head
	for cur != nil {
		kNodes = append(kNodes, cur)
		groupNext := cur.Next
		if len(kNodes) == k {
			groupNext = kNodes[k-1].Next
			for i := k - 1; i > 0; i-- {
				kNodes[i].Next = kNodes[i-1]
			}
			kNodes[0].Next = groupNext
			prev.Next = kNodes[k-1]
			prev = kNodes[0]
			kNodes = kNodes[:0]
		}
		cur = groupNext
	}
	return dummyHead.Next
}

func main() {
	dummyHead := &ListNode{
		Val:  0,
		Next: nil,
	}
	cur := dummyHead
	fmt.Print("input the values in the List: ")
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	for _, p := range parts {
		val, _ := strconv.Atoi(p)
		cur.Next = &ListNode{Val: val}
		cur = cur.Next
	}

	cur = reverseKGroup(dummyHead.Next, 2)
	fmt.Print("result: ")
	for cur != nil {
		fmt.Printf("%d ", cur.Val)
		cur = cur.Next
	}
	fmt.Println()
}
