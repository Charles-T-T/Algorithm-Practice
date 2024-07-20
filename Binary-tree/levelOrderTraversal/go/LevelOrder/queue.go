package LevelOrder

type Queue[T any] struct {
	slice []T
	size int
}

func (q *Queue[T]) Push(val T) {
	q.slice = append(q.slice, val)
	q.size++
}

func (q *Queue[T]) Pop() {
	q.slice = q.slice[1:]
	q.size--
}

func (q Queue[T]) Front() T {
	return q.slice[0]
}

func (q Queue[T]) Size() int {
	return q.size
}

func (q Queue[T]) Empty() bool {
	return q.size == 0
}