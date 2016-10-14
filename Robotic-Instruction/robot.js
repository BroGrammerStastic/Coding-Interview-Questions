var x;
var y;
var orientation = ["N", "E", "S", "W"];
var instruction = ["L", "R", "F"];
var lost_Robot_Scent = [];

// function created for assigning coordinates and an orientation
function Robot_Coordinatation(x,y,orientation) {
	// coordinate (x,y) must be located at (0,0) at the initial state of the program
	this.x = 0;
	this.y = 0;
	// orientation assigned
	this.orientation = orientation;
	// this is printed for the purpose of tidiness
	console.log("============================" + "<br />");

	// We have a nested function here that will determine the movement/instruction of the robot
	this.Robot_Instruction = function(instruct_The_Robot) {
		//if x & y is bigger than or equal to 0 and smaller than or equal to 50 -> If its true then go inside the if statment.
		// Essentiallly, what this statement is actually doing is that its creating the rectangular grid.
		if ( ( x <= 50 && x >= 0 ) && ( y <= 50 && y >= 0 ) ) {
			// We are making sure here that the length of the instruction is less than 100
			if ( instruct_The_Robot.length <= 100 ) {
				// itterate the array of the instruct_The_Robot
				for (var i = 0; i < instruct_The_Robot.length; i++) {
					// if any value of instruct_The_Robot is strictly equal to "L", then go inside this if statement. refer to line: 10
					if ( instruct_The_Robot[i] === instruction[0] ) {
						// variable Left declaired and initialised with -90 degrees
						var Left = (-90 * Math.PI / 180);
						// cosine formula used and assigned to x and y;
						x += Math.cos(Left) * 1;
						y += Math.sin(Left) + 1;
						// here we are checking whether x and y are still in the scope between 0 to 50;
						if ( ( x >= 0 && x <= 50 ) && ( y >= 0 && y <= 50 ) ) {
							// if the above satisfies, then and only then will the result be printed;
							var result = " | ( " + x + ", " + y + " ) " + " | " + orientation + " " + -90 + "&#176" + "<br />";
						} else {
							//variale lost instantiated with "Lost!" message
							var result = "LOST!" + "<br />";
							// push the robot to the lost_Robot_Scent
							lost_Robot_Scent.push( [x,y]	 + "<br />");
						}
						// however, if at line: 32 is not true, then follow this : if the value of instruct_The_Robot is equal to "R"...
					} else if ( instruct_The_Robot[i] === instruction[1] ) {
						// formula to calculate 90 degrees
						var Right = (90 * Math.PI / 180);
						x += Math.cos(Right) * 1;
						y += Math.sin(Right) - 1;
						// again checking whether the x and y is still in the scope between 0 and 50
						if ( ( x >= 0 && x <= 50 ) && ( y >= 0 && y <= 50 ) ) {
							var result = " | ( " + x + ", " + y + " ) " + " | " + orientation + " " + 90 + "&#176" + "<br />";
						} else {
							// variale lost instantiated with "Lost!" message
							var result = "LOST!" + "<br />";
							// push the robot to the lost_Robot_Scent
							lost_Robot_Scent.push( [x,y] + "<br />");
						}
						// however, if the if...statment at line: 33 & elseif at line: 39 is not true, then if instruct_The_Robot is equal to "F"...
					} else if (instruct_The_Robot[i] === instruction[2]) {
						// variable y_Plus_One is instantiated with the current value of y and moves y one point forward
						var y_Plus_One = y += 1;
						// We are checking whether the [x,y] is still in the scope
						if ( ( x >= 0 && x <= 50 ) && ( y_Plus_One >= 0 && y_Plus_One <= 50 ) ) {
							var result = " | ( " + x + ", " + y_Plus_One + " ) " + " | " + orientation + " " + "<br />";
						} else {
							// boolean robotLostAtSameLocation as false;
							var robotLostAtSameLocation = false;
							// checking the values within lost_Robot_Scent using for loop;
							for (var i = 0; i < lost_Robot_Scent.length; i++) {
								// check if the current x value of the robot exists inside the lost_Robot_Scent
							  if ( x in lost_Robot_Scent ) {
									// if it does, then make the robotLostAtSameLocation true and exit the condition;
							    robotLostAtSameLocation = true;
							    break;
							  }
							}
							// if robotLostAtSameLocation is true then print this result;
							if (robotLostAtSameLocation) {
								result = "Previous Robot was lost at this location";
							}
							// if not then print this result and push the [x,y] into lost_Robot_Scent;
							else {
							  result = "LOST! <br />";
								lost_Robot_Scent.push([x,y] + "<br />");
							}
						}
					}
				}
				//print the result
				//console.log( result );
				//return result;
				// if none of the if...statement abov	e satisfy, then...
			} else {
				alert("There is alot of of instructions given. Please make sure that the instruction is less than 100 instructions");
			}
		} else {
			// variale lost instantiated with "Lost!" message
			var lost = "LOST!" + "<br />";
			console.log(lost);
			// push the robot to the lost_Robot_Scent
			lost_Robot_Scent.push( [x,y] + "<br />");
		}
	};
}

// new Robot object initialised
var one = new Robot_Coordinatation(49,49,orientation[2]);
one.Robot_Instruction("LLR");


// With this robot object I am suspecting that the program must reject this object and print "Lost" because the y value is 51, and the scape of [x,y] must be betweeen 0 to 50
var two = new Robot_Coordinatation(38,51,orientation[3]);
two.Robot_Instruction("LF");

/*
With this robot object. I am expecting the program to run the instruction. When the program reads the F instruction,
The robot must be lost because our y which is 50 will be 51 when F instruction is read. Also, the program must check wether the same coordinate
exists in the lost_Robot_Scent array. If it does, then the program must print that "Previous Robot was lost at this point!". If the coordinate
is not in the array, then it will be recorded. Note this functionality is my only problem within this program which I cant make it to work
*/
var three = new Robot_Coordinatation(38,50,orientation[3]);
three.Robot_Instruction("LF");
