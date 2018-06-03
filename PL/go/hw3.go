package main

import "fmt"

func swap (x, y * int) {
	*x, *y = *y, *x
}

func main() {
	x, y := 5, 3
	fmt.Printf("before x : %d y : %d\n", x, y)
	swap(&x, &y)
	fmt.Printf("After x : %d y : %d\n", x, y)
}