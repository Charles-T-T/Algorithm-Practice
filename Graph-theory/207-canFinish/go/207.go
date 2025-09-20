package main

import "fmt"

// BFS
func canFinish(numCourses int, prerequisites [][]int) bool {
	graph := make([][]int, numCourses)
	for i := range numCourses {
		graph[i] = make([]int, 0)
	}
	indegree := make([]int, numCourses) // 某节点的入度
	queue := make([]int, 0)
	// 初始化图和入度
	for _, pair := range prerequisites {
		graph[pair[1]] = append(graph[pair[1]], pair[0])
		indegree[pair[0]]++
	}
	// 初始化后入度为 0 的节点就是不需要先修课的节点
	for i := range indegree {
		if indegree[i] == 0 {
			queue = append(queue, i)
		}
	}
	// 每次取出队头，将队头节点指向的其他节点入度减一
	// 相当于“把这门先修课修完了”
	studied := 0
	for len(queue) != 0 {
		u := queue[0]
		queue = queue[1:]
		studied++
		for _, v := range graph[u] {
			indegree[v]--
			if indegree[v] == 0 {
				queue = append(queue, v)
			}
		}
	}
	return studied == numCourses
}

func main() {
	prerequisites := [][]int{{1, 0}, {0, 1}}
	fmt.Println(canFinish(2, prerequisites))
}
