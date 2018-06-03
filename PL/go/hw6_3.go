// Go's concurrency primitives make it easy to
// express concurrent concepts, such as
// this binary tree comparison.
//
// Trees may be of different shapes,
// but have the same contents. For example:
//
//        4               6
//      2   6          4     7
//     1 3 5 7       2   5
//                  1 3
//
// This program compares a pair of trees by
// walking each in its own goroutine,
// sending their contents through a channel
// to a third goroutine that compares them.

package main

import (
	"fmt"
	"math/rand"
)

// A Tree is a binary tree with integer values.
type Tree struct {
	Left  *Tree
	Value int
	Right *Tree
}

// Walk traverses a tree depth-first,
// sending each Value on a channel.
func Walk(t *Tree, ch chan int) {
	if t == nil {
		return
	}
	Walk(t.Left, ch)
	ch <- t.Value
	
	Walk(t.Right, ch)
}

// Walker launches Walk in a new goroutine,
// and returns a read-only channel of values.
func Walker(t *Tree) <-chan int {
	ch := make(chan int)
	go func() {
		Walk(t, ch)
		close(ch)
	}()
	for v := range ch {
		fmt.Printf("%d ", v)
	}
	fmt.Println()
	
	return ch
}

// New returns a new, random binary tree
// holding the values 1k, 2k, ..., nk.
func New(n, k int) *Tree {
	var t *Tree
	for _, v := range rand.Perm(n) {
		t = insert(t, (1+v)*k)
	}
	return t
}

func insert(t *Tree, v int) *Tree {
	if t == nil {
		return &Tree{nil, v, nil}
	}
	if v < t.Value {
		t.Left = insert(t.Left, v)
		return t
	}
	t.Right = insert(t.Right, v)
	return t
}

func main() {
	t1 := New(10, 1)
	fmt.Println("6-2 : Tree traverse using channel")
	Walker(t1)
}