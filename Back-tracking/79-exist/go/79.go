package main

import "fmt"

var moves [][]int

func leagalPos(board [][]byte, i int, j int) bool {
	return i >= 0 && i < len(board) && j >= 0 && j < len(board[0])
}

func backTracking(board [][]byte, word string, i int, j int, k int) bool {
	// k 表示当前要匹配的 word 的字符的下标
	if k == len(word) {
		return true
	}

	if !leagalPos(board, i, j) || board[i][j] != word[k] || board[i][j] == '#' {
		return false
	}

	saved := board[i][j]
	board[i][j] = '#'
	for _, move := range moves {
		newi, newj := i+move[0], j+move[1]
		if backTracking(board, word, newi, newj, k+1) {
			return true
		}
	}
	board[i][j] = saved
	return false
}

func exist(board [][]byte, word string) bool {
	counter_word := make(map[byte]int)
	counter_board := make(map[byte]int)

	for i := range word {
		counter_word[word[i]] += 1
	}
	for i := range board {
		for j := range board[0] {
			counter_board[board[i][j]] += 1
		}
	}

	for char, count := range counter_word {
		if count > counter_board[char] {
			return false
		}
	}

	moves = [][]int{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}

	for i := range board {
		for j := range board[0] {
			if backTracking(board, word, i, j, 0) {
				return true
			}
		}
	}

	return false
}

func main() {
	board := [][]byte{
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'},
	}
	word := "ABCCED"
	fmt.Println(exist(board, word))
}
