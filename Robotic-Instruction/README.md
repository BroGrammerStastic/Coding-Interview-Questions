# Robotic Instruction
## Contents
- [Project Specification](#project-specification)
- [Aim Of This Project](#aim-of-this-project)

## Project Specification
#### Aim of this Project
Lets assume that we have a rectangular grid over the surface of Mars in which robots are able
to move according to instructions given:

A robot instruction is a string of the letters “L”, “R”, and “F” which represent, respectively,
the instructions:
- Left : the robot turns left 90 degrees and remains on the current grid point.
- Right : the robot turns right 90 degrees and remains on the current grid point.
- Forward : the robot moves forward one grid point in the direction of the current orientation and maintains the same orientation.

The direction North corresponds to the direction from grid point (x, y) to grid point (x, y+1).

A robot position consists of a grid coordinate (a pair of integers: x-coordinate followed by
y-coordinate) and an orientation (N, S, E, W for north, south, east, and west).

A robot can be lost (i.e the robot is out of bound either for x or y coordinates). However, when a robot is lost. Its last coordinates
are kept in a list so that a new robot is prevented from clashing with the same coordinates of the lost robots.

###### What must you "Input"
- The first line of input is the upper-right coordinates of the rectangular world, the lower-left
coordinates are assumed to be (0, 0).

- The remaining input consists of a sequence of robot positions and instructions.
- A position consists of two integers specifying the initial coordinates of the robot and an orientation (N, S, E, W), all separated by whitespace on one line.
- A robot instruction is a string of the letters “L”, “R”, and “F” on one line.
- Each robot is processed sequentially, i.e., finishes executing the robot instructions before the next robot begins execution.
- The maximum value for any coordinate is 50.
- All instruction strings will be less than 100 characters in length.

###### What must you "Output"
For each robot position/instruction in the input, the output should indicate the final grid
position and orientation of the robot. If a robot falls off the edge of the grid the word “LOST”
should be printed after the position and orientation.

> You are to write a program that determines each sequence of robot positions and reports the final position of the robot.
