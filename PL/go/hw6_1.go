package main

import (
	"fmt"
	"log"
	"errors"
)

type Node struct {
	Value string
	Data string
	Left * Node
	Right * Node
}

func (n * Node) Insert(value, data string) error {
	if n == nil {
		return errors.New("Cannot insert a value into a nil tree")
	}

	switch {
	case value == n.Value :
		return nil
	case value < n.Value :
		if n.Left == nil {
			n.Left = &Node{Value : value, Data: data}
			return nil
		}
		return n.Left.Insert(value, data)
	
	case value > n.Value:
		if n.Right == nil {
			n.Right = &Node{Value: value, Data: data}
			return nil
		}
		return n.Right.Insert(value, data)
	}
	return nil
}

type Tree struct {
	Root * Node
}

func (t * Tree) Insert(value, data string) error {
	if t.Root == nil {
		t.Root = &Node{Value: value, Data: data}
		return nil
	}
	return t.Root.Insert(value, data)
}

// func (t *Tree) Find(s string) (string, bool) {
// 	if t.Root == nil {
// 		return "", false
// 	}
// 	return t.Root.Find(s)
// }

func (t *Tree) Traverse(n * Node) {
	if n == nil {
		return
	}

	fmt.Println(n.Value + " ")
	t.Traverse(n.Left)
	t.Traverse(n.Right)
}

func main() {
	values := []string{"5", "3", "7", "19", "1", "13"}
	data := []string{"a", "b", "c", "d", "e", "f"}
	tree := &Tree{}
	for i := 0; i < len(values); i++ {
		err := tree.Insert(values[i], data[i])
		if err != nil {
			log.Fatal("Error inserting value '", values[i], "': ", err)
		}
	}
	// fmt.Print("Sorted values: | ")
	// tree.Traverse(tree.Root, func(n *Node) { fmt.Print(n.Value, ": ", n.Data, " | ") })
	// fmt.Println()

	tree.Traverse(tree.Root)
}