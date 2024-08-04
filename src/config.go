package main

import (
	"flag"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Config struct {
	Speed  float64
	Width  int
	Height int
}

func parseArguments() Config {
	speed := flag.Float64("s", 1.0, "Speed of the simulation")
	resolution := flag.String("r", "800x800", "Resolution of the window in WIDTHxHEIGHT format")

	flag.Parse()

	dimensions := strings.Split(*resolution, "x")
	if len(dimensions) != 2 {
		fmt.Fprintln(os.Stderr, "Invalid resolution format. Use WIDTHxHEIGHT.")
		os.Exit(1)
	}

	width, err := strconv.Atoi(dimensions[0])
	if err != nil {
		fmt.Fprintln(os.Stderr, "Invalid width in resolution.")
		os.Exit(1)
	}

	height, err := strconv.Atoi(dimensions[1])
	if err != nil {
		fmt.Fprintln(os.Stderr, "Invalid height in resolution.")
		os.Exit(1)
	}

	return Config{
		Speed:  *speed,
		Width:  width,
		Height: height,
	}
}
