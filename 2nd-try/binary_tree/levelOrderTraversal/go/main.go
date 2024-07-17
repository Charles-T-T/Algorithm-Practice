package main

import (
	"fmt"

	"github.com/Charles-T-T/Algorithm-Practice/2nd-try/binary_tree/levelOrderTraversal/go/LevelOrder"
)

func main() {
	root1 := LevelOrder.GetTreeRoot("3,9,20,null,null,15,7")
	res1 := LevelOrder.LevelOrder(root1)
	fmt.Println("res1:", res1)

	root2 := LevelOrder.GetTreeRoot("1,2,3,null,5,null,4")
	res2 := LevelOrder.RightSideView(root2)
	fmt.Println("res2:", res2)

	root3 := LevelOrder.GetTreeRoot("3,9,20,null,null,15,7")
	res3 := LevelOrder.AverageOfLevels(root3)
	fmt.Println("res3:", res3)

	root4 := LevelOrder.GetTreeRoot("1,2,5,3,4,null,6")
	LevelOrder.Flatten(root4)
	fmt.Println("done")
}
