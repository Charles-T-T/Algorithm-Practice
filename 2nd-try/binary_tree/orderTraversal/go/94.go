package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 递归法
func Traverse(cur *TreeNode, res *[]int) {
	if cur == nil { // 递归出口
		return
	}
	// 中序遍历，顺序：左 中 右
	Traverse(cur.Left, res)      // 左
	*res = append(*res, cur.Val) // 中
	Traverse(cur.Right, res)     // 右
}

func inorderTraversal(root *TreeNode) []int {
	res := make([]int, 0)
	Traverse(root, &res)
	return res
} 

// 统一迭代法
func inorderTraversal_II(root *TreeNode) []int {
	res := make([]int, 0)
	if root == nil {
		return res
	}
	st := []*TreeNode{root}
	for len(st) != 0 {
		cur := st[len(st) - 1]
		st = st[0:len(st) - 1]
		if cur != nil {
			if cur.Right != nil {
				st = append(st, cur.Right) // 右
			}
			st = append(st, cur) // 中
			st = append(st, nil) // 空节点标记
			if cur.Left != nil {
				st = append(st, cur.Left) // 左
			}
		} else {
			// 遇到空指针标记
			res = append(res, st[len(st) - 1].Val)
			st = st [0:len(st) - 1]
		}
	}
	return res
}

func main() {
	root := new(TreeNode)
	root.Val = 1
	root.Left = nil
	root.Right = &TreeNode{Val: 2, Left: &TreeNode{Val: 3}}

	res1 := inorderTraversal(root)
	fmt.Println("res1:", res1)
	res2 := inorderTraversal_II(root)
	fmt.Println("res2:", res2)
}