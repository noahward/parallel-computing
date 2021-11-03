# Parallel Computing
A collection of small parallel computing programs I have developed or helped develop in C.

<hr/>

### Quick n' Dirty BMP Processor
**Note:** I did not develop this library, I simply created a parallel implementation to allow faster processing times.
**Note:** Please read the readme.txt Terms and Conditions before running any code.
- Objective was to parallelize the code using the OpenMP library to allow multiple threads to iterate through the images pixels and write new RGB values
- Program takes an image, and either desaturates it or turns it negative depending on user specification

<hr/>

### Dart Throw
- This program aims to estimate Pi using a random number generator (Monte Carlo Method).
- User can change the numer of tosses and number of threads

*Background:*  
- Assumes square board with circle drawn in the middle and we always hit the board
- Circle has radius Pi and square board has side lengths of 2 feet

<hr/>

### Matrix Multiplication
- A simple parallel implementation of a matrix multiplication calculator
- User can edit the number of elements in each matrix to observe how drastic the time to process is reduced using multiple threads
- Each matrix is initialized with random integers, but can easily be programmed to take user input
