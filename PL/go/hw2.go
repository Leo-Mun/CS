package main

import "fmt"

func max(args ...int) int {
	max := -0xFFFFFFFF
	for _, value := range args {
		if max <= value {
			max = value
		}
	}
	return max
}

func min(args ...int) int {
	min := 0xFFFFFFFF
	for _, value := range args {
		if min >= value {
			min = value
		}
	}
	return min
}


func main() {
	fmt.Printf("Max : %d Min : %d\n", max(1, 5, 4, 2, 10, -4, 7), min(4, 3, 6, 2, 1, -8))
}