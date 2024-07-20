package LevelOrder

func LevelOrder(root *TreeNode) [][]int {
	res := [][]int{}
	if root == nil {
		return res
	}
	q := Queue[*TreeNode]{}
	q.Push(root)
	for !q.Empty() {
		size := q.Size()
		level := []int{}
		for i := 0; i < size; i++ {
			if q.Front().Left != nil {
				q.Push(q.Front().Left)
			}
			if q.Front().Right != nil { 
				q.Push(q.Front().Right)
			}
			level = append(level, q.Front().Val)
			q.Pop()
		}
		res = append(res, level)
	}
	return res
}