package LevelOrder

func RightSideView(root *TreeNode) []int {
	// 思路：层序遍历，只把每层最右节点元素加入结果集即可
	res := []int{}
	if root == nil {
		return res
	}
	q := Queue[*TreeNode]{}
	q.Push(root)
	for !q.Empty() {
		size := q.Size()
		for i := 0; i < size-1; i++ {
			if q.Front().Left != nil {
				q.Push(q.Front().Left)
			}
			if q.Front().Right != nil {
				q.Push(q.Front().Right)
			}
			q.Pop()
		}
		// 每层的最后一个节点
		res = append(res, q.Front().Val)
		if q.Front().Left != nil {
			q.Push(q.Front().Left)
		}
		if q.Front().Right != nil {
			q.Push(q.Front().Right)
		}
		q.Pop()
	}
	return res
}
