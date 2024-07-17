package LevelOrder

import (
	"strconv"
	"strings"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func GetTreeRoot(str string) *TreeNode {
	root := new(TreeNode)
	input := strings.Split(str, ",")
	val, err := strconv.Atoi(input[0])
	if err == nil {
		root.Val = val
	}
	if len(input) == 0 {
		return root
	}
	q := Queue[*TreeNode]{}
	q.Push(root)
	i := 1
	for !q.Empty() && i < len(input) {
		cur := q.Front()
		q.Pop()

		val, err := strconv.Atoi(input[i])
		if err == nil {
			cur.Left = &TreeNode{Val: val}
			q.Push(cur.Left)
		}
		i++

		if i >= len(input) {
			break
		}

		val, err = strconv.Atoi(input[i])
		if err == nil {
			cur.Right = &TreeNode{Val: val}
			q.Push(cur.Right)
		}
		i++
	}
	return root
}
