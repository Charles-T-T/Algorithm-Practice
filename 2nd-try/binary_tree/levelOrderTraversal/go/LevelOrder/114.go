package LevelOrder

import "sync"

func Flatten(root *TreeNode) {
	// 思路：先序遍历，将结果连成单链表
	if root == nil {
		return
	}
	// 用一个channel，将先序遍历结果及时传给新的单链表
	c := make(chan int)
	quit := make(chan int)

	newRoot := new(TreeNode)
	cur := newRoot

	var wg sync.WaitGroup

	// 先序遍历
	wg.Add(1)
	go func() {
		defer wg.Done()
		st := []*TreeNode{root}
		for len(st) != 0 {
			cur := st[len(st)-1]
			c <- cur.Val // 当前访问节点值写入管道
			st = st[:len(st)-1]
			if cur.Right != nil {
				st = append(st, cur.Right)
			}
			if cur.Left != nil {
				st = append(st, cur.Left)
			}
		}
		quit <- 0
	}()

	// 连接新链表
	wg.Add(1)
	go func() {
		defer wg.Done()
		var num int
		for {
			select {
			case num = <-c:
				cur.Right = &TreeNode{Val: num}
				cur.Left = nil
				cur = cur.Right
			case <-quit:
				*root = *newRoot.Right
				return
			}
		}
	}()

	wg.Wait()
}
