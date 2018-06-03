package main

import (
	"fmt"
	// "math/rand"
)



type Node struct {
	data int
	nChild int
	down  * Node
	right  * Node
}

func put_tree(node * Node, depth int) {
	
	var p * Node

	if node == nil {
		return
	}


	for j := 0; j < depth; j++ {
		fmt.Printf("	")
	}
	fmt.Printf("| %d (%d)\n", node.data, node.nChild)

	if node.nChild > 0 {
		p = node.down
		for i := node.nChild - 1; i >= 0; i-- {
			put_tree(p, depth + 1)
			if p == nil {
				return
			}
			p = p.right
		}
	}
}

func del_tree (node * Node) {
	if node == nil {
		return
	}

}

func build_tree(n int) * Node {
	node := new(Node)
	// node = Node{n * 1000, 4, nil, nil}

	node.nChild = 4
	node.down = nil
	node.right = nil
	node.data = n * 1000

	if n - 1 > 0 {
		node.down = build_tree(n-1)
		node.down.data += 1

		n2 := node.down
		for i := 0; i < node.nChild - 1; i++ {
			n2.right = build_tree(n - 1)
			n2.right.data += i + 2

			n2 = n2.right
		}
	} else {
		node.nChild = 0
	}

	return node
}

func main() {
	var depth int = 3
	var root * Node

	root = build_tree(depth)

	put_tree(root, 0)

}