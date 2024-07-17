package LevelOrder

import "sync"

func AverageOfLevels(root *TreeNode) []float64 {
	// 思路：层序遍历，返回每层的平均值
	// 偷个懒，调一下之前写好的层序遍历函数
	levels := LevelOrder(root)
	res := make([]float64, len(levels))

	var wg sync.WaitGroup
	for i := range levels {
		// 求每层的平均值
		wg.Add(1)
		go func(id int) { // 每层开一个goroutine并发计算
			defer wg.Done()
			var sum float64
			for _, num := range levels[id] {
				sum += float64(num)
			}
			res[id] = sum / float64(len(levels[id]))
		}(i)
	}
	wg.Wait() // 等待所有goroutine结束

	return res
}
