# turing_machine
Simple C++ Turing Machine implementation

## Build
`mkdir build`
`cd build`
`cmake ..`  
`make`

## Run
1. executable is in the `/build` directory
2. `./turing_machine <configuration>`

## Configuration 
Import Configuration as a textfile
###Examples:
####2-state-busy-beaver
`
0 1 2
0
-
2
0 1
0
0 0 1 1 R
0 1 1 1 L
1 0 0 1 L
1 1 2 1 R
`


