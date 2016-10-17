# Calculating how many airport gates are needed

The arrival and departure times of planes at an airport can be defined by a pair of vectors:

- A vector `arrives` containing arrival times
- A vector `departs` containing departure times


We can represent the times as a whole number of minutes after midnight.  For instance, the time 7:17am would be recorded as `(7 * 60) + 17 = 437`.

Plane `i` then arrives at time `arrives[i]` and departs at time `departs[i]`.  The number of gates an airport needs so that no plane needs to wait for a gate is equal to the maximum number of gates needed that day.

In the file `MaximumGates.h` implement a function `maximumGates` that takes:

- The arrives vector
- The departs vector

...and returns the maximum number of gates needed at the airport.  For instance, given the inputs:

`arrives = {360, 400, 700}`  
`departs = {900, 515, 780}`  

...it should return 2.  Going through the day in chronological order:

* t=360: Plane 0 arrives: 1 gate now in use
* t=400: Plane 1 arrives: *2* gates now in use
* t=515: Plane 1 departs: 1 gate now in use
* t=700: Plane 2 arrives: *2* gates now in use
* t=780: Plane 2 departs: 1 gate now in use
* t=900: Plane 0 departs: 0 gates now in use


Conversely, if plane 2 had arrived *before* plane 1 had departed, e.g:

`arrives = {360, 400, 700}`  
`departs = {900, 720, 780}`  

...the maximum number of gates to return would be 3.

Notes:

- You can assume `arrives` is sorted into ascending order
- One plane will never arrive at the time another departs
