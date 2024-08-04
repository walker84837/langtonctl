package main

import (
	rl "github.com/gen2brain/raylib-go/raylib"
)

type CellState int

const (
	CELL_WHITE CellState = iota
	CELL_BLACK
)

var colors = [2]rl.Color{
	rl.White,
	rl.Black,
}

type Ant struct {
	X, Y      int
	Direction rl.Vector2
}

func initialize() {
	numCellsH = 80
	numCellsV = numCellsH
	rectSide = float32(rl.GetScreenWidth()) / float32(numCellsH)

	cellStates = make([][]CellState, numCellsH)
	for i := range cellStates {
		cellStates[i] = make([]CellState, numCellsV)
		for j := range cellStates[i] {
			cellStates[i][j] = CELL_WHITE
		}
	}

	ant.X = numCellsH / 2
	ant.Y = numCellsV / 2
	ant.Direction = rl.NewVector2(0, -1)
}

func updateAnt(ant *Ant) {
	antX := ant.X
	antY := ant.Y
	state := cellStates[antX][antY]

	if state == CELL_WHITE {
		temp := ant.Direction.X
		ant.Direction.X = ant.Direction.Y
		ant.Direction.Y = -temp
	} else {
		temp := ant.Direction.X
		ant.Direction.X = -ant.Direction.Y
		ant.Direction.Y = temp
	}

	cellStates[antX][antY] = 1 - cellStates[antX][antY]

	ant.X = (ant.X + int(ant.Direction.X) + numCellsH) % numCellsH
	ant.Y = (ant.Y + int(ant.Direction.Y) + numCellsV) % numCellsV
}
