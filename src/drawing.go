package main

import (
	"math"

	rl "github.com/gen2brain/raylib-go/raylib"
)

func drawCells() {
	for x := 0; x < numCellsH; x++ {
		for y := 0; y < numCellsV; y++ {
			rl.DrawRectangle(int32(float32(x)*rectSide), int32(float32(y)*rectSide),
				int32(rectSide), int32(rectSide), colors[cellStates[x][y]])
		}
	}
}

func drawAnt(ant Ant) {
	center := rl.NewVector2(
		float32(ant.X)*rectSide+rectSide/2,
		float32(ant.Y)*rectSide+rectSide/2,
	)
	points := [3]rl.Vector2{
		{center.X + rectSide/4, center.Y},
		{center.X - rectSide/4, center.Y + rectSide/4},
		{center.X - rectSide/4, center.Y - rectSide/4},
	}
	angle := float32(math.Atan2(float64(ant.Direction.Y), float64(ant.Direction.X)))
	for i := 0; i < 3; i++ {
		x := points[i].X - center.X
		y := points[i].Y - center.Y
		points[i].X = center.X + x*float32(math.Cos(float64(angle))) - y*float32(math.Sin(float64(angle)))
		points[i].Y = center.Y + x*float32(math.Sin(float64(angle))) + y*float32(math.Cos(float64(angle)))
	}
	rl.DrawTriangle(points[0], points[1], points[2], rl.Red)
}
