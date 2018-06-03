package main

import "fmt"

func main() {
        x := []int{ 38, 76, 65, 48, 52, 28, 36, 60, 33, 39, 9, 19, 28, 84, 19, 26}

        max, min := x[0], x[0]

        for index := range x {
                if max <= x[index] {
                        max = x[index]
                }
                if min >= x[index] {
                        min = x[index]
                }
        }

        fmt.Printf("Max : %d, Min : %d\n", max, min)
}
