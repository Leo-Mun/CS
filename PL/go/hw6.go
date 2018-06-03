package main


import (
	"fmt"
	"math/rand"
	"errors"
)

type Tree struct {
	Root * Node
}

// A Tree is a binary tree with integer values.
type Node struct {
	Left  *Node
	Value int
	Right *Node
}

// New make, random binary tree holding the values k, 2k, ..., 10k.
func (t * Tree) New(k int) {
	for _, v := range rand.Perm(10) {
		t.insert((1+v)*k)
	}
}

func (t * Tree) insert(value int) error {
	if t.Root == nil {
		t.Root = &Node{nil, value, nil}
		return nil
	}
	return t.Root.insert(value)
}

func (n * Node) insert(value int) error {
	if n == nil {
		return errors.New("Cannot insert a value into a nil tree")
	}

	switch {
		case value == n.Value :
			return nil
		case value < n.Value :
			if n.Left == nil {
				n.Left = &Node{nil,value, nil}
				return nil
			}
			return n.Left.insert(value)
		
		
		case value > n.Value :
			if n.Right == nil {
				n.Right = &Node{nil, value, nil}
				return nil
			}
			return n.Right.insert(value)
	}
	return nil
}

func (n *Node) String() string {
	if n == nil {
		return "()"
	}
	s := ""
	s += fmt.Sprint(n.Value)
	if n.Left != nil {
		s += n.Left.String() + ""
	}
	if n.Right != nil {
		s += "" + n.Right.String()
	}
	return "(" + s + ")"
}


func (t *Tree) inOrder(n *Node) {
	if n == nil {
		return
	}

	t.inOrder(n.Left)
	fmt.Printf("%d ", n.Value)
	t.inOrder(n.Right)
}



func main() {
	myTree := Tree{nil}
	myTree.New(5)

	fmt.Println("6-1_1 : Tree travel not using channel")
	myTree.inOrder(myTree.Root)
	fmt.Println()

	fmt.Println("=======================================")

	fmt.Println("6-1_2 : print tree using ()")
	fmt.Println(myTree.Root.String())

	fmt.Println()

}