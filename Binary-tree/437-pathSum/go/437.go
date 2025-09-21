package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

var res int
var prefixCnt map[int64]int

func backtracking(node *TreeNode, targetSum int, curPrefix int64) {
	if node == nil {
		return
	}

	curPrefix += int64(node.Val)
	require := curPrefix - int64(targetSum)
	if prefixCnt[require] > 0 {
		res += prefixCnt[require]
	}

	prefixCnt[curPrefix]++
	backtracking(node.Left, targetSum, curPrefix)
	backtracking(node.Right, targetSum, curPrefix)
	prefixCnt[curPrefix]--
}

func pathSum(root *TreeNode, targetSum int) int {
	res = 0
	prefixCnt = make(map[int64]int)
	prefixCnt[0] = 1
	backtracking(root, targetSum, 0)
	return res
}

func main() {
	fmt.Print("input the tree, divided by ',' (without space): ")
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	fields := strings.Split(line, ",")

	rootVal, _ := strconv.Atoi(fields[0])
	root := &TreeNode{rootVal, nil, nil}
	queue := []*TreeNode{root}

	i := 1
	for i < len(fields){
		node := queue[0]
		queue = queue[1:]

		if fields[i] != "null" {
			v, _ := strconv.Atoi(fields[i])
			node.Left = &TreeNode{v, nil, nil}
			queue = append(queue, node.Left)
		}
		i++

		if i < len(fields) && fields[i] != "null" {
			v, _ := strconv.Atoi(fields[i])
			node.Right = &TreeNode{v, nil, nil}
			queue = append(queue, node.Right)
		}
		i++
	}

	fmt.Print("input the targetSum: ")
	var targetSum int
	fmt.Scan(&targetSum)

	fmt.Println("result: ", pathSum(root, targetSum))
}
