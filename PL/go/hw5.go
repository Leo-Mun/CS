package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
	"sort"
)

func readNSort(path string) {

	count := 10
	index := 0
	data := make([]int, count)

	inFile, err := os.Open(path)
	if err != nil {
		panic(err)
	}
	defer inFile.Close()

	scanner := bufio.NewScanner(inFile)
	
	scanner.Split(bufio.ScanLines)

	for scanner.Scan() {
		value, _ := strconv.ParseInt(scanner.Text(), 10, 32)
		data[index] = int(value)
		index += 1
	}


	fmt.Println("Before Sort : ", data)
	sort.Sort(sort.IntSlice(data))
	fmt.Println("After Sort : ", data)

}

func main() {

	readNSort("/home/moon/Desktop/Source/input.txt")

}