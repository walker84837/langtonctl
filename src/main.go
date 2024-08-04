package main

import (
	"math/rand"
	"time"

	rl "github.com/gen2brain/raylib-go/raylib"
)

var (
	numCellsH  int
	numCellsV  int
	cellStates [][]CellState
	ant        Ant
	speed      = 10000
	rectSide   float32
	isPaused   = false
)

func main() {
	rand.Seed(time.Now().UnixNano())

	config := parseArguments()

	rl.InitWindow(int32(config.Width), int32(config.Height), "LangtonCtl")
	defer rl.CloseWindow()

	rl.SetTargetFPS(int32(config.Speed * 3.6))

	initialize()

	for !rl.WindowShouldClose() {
		if rl.IsMouseButtonPressed(rl.MouseLeftButton) {
			isPaused = !isPaused
		}

		if !isPaused {
			for iter := 0; iter < speed; iter++ {
				updateAnt(&ant)
			}
		}

		rl.BeginDrawing()
		rl.ClearBackground(rl.Black)
		drawCells()
		drawAnt(ant)
		rl.EndDrawing()
	}
}
