# Leandra-CPP-Projects

This repository is a compilation of all my coding assignments and projects completed from the beginning and end of my four-year undergraduate experience in C++.

### [LHallList.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects/blob/main/LHallList.cpp)

This program will create a list of 32 random numbers. It will then print the original list, the sum of the numbers in the list,
the average of the numbers in the list, the largest and smallest number in the list, and the list in sorted order.
The terms List and array will be used interchangeably.

### [LHallQuadraticFormula.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects/blob/main/LHallQuadraticFormula.cpp)

This program should solve quadratic equations using the quadratic formula and return the solution to the user based on their input.

### [circle.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects/blob/main/circle.cpp)

This program will calculate the area of a circle based on a user-inputted radius by utilizing a circle class with defined methods like getArea.

### [countingVowelsFunction.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects/blob/main/countingVowelsFunction.cpp)

Using a function, this program should determine the number of vowels in an inputted string.

### [fizzbuzzPractice.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects/blob/main/fizzbuzzPractice.cpp)

This program will print out "fizzbuzz", "fizz", or "buzz" based on whether a user-inputted integer is divisible by both 5 and 3 or divisible by 3 or 5.

### [hw2Code.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects/blob/main/hw2Code.cpp)

This program will create a dynamically-defined array based on inputted parameters from the user and store values defined by the user. Then it will find the smallest value of the array as well as print all of the array's values by using functions. 

### [leandraHallCh6EnumerationHW.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects/blob/main/leandraHallCh6EnumerationHW.cpp)

This program should create two enumeration types with five things in each type and perform operations on these types such as assignment and comparison.
Functions printColor and printDay allow the program to print out the day or color specified in the enumerated type.

### [leandraHallComfyShellPartA.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects/blob/main/leandraHallComfyShellPartA.cpp) 

This program will print out the number of arguments and the value of the arguments provided by the user through the CLI with argv and argc.

### [leandraHallComfyShellPartB.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects/blob/main/leandraHallComfyShellPartB.cpp)

This program will create a new shell titled "Comfy" for the user's CLI. It will then  tokenize the user’s input into a NULL-terminated array of char
strings. A child process, utilizing fork(), will be created and he child will invoke the execv() function to execute the user’s command (in argv[0]) 
and also pass the cmd_args[] array to execv(). The parent process will wait for the child to exit. If the child’s execv() call returns an error, the child should exit and return the error number to the parent.
The parent should print this to the screen.

### [leandraHallDonutShopCode2.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects/blob/main/leandraHallDonutShopCode2.cpp)

The program is a doughnut shop that utilizes 3 threads of execution, corresponding to the three co-
dependent segments of the business: the factory, the warehouse, and the sales counter. The factory will produce one doughnut every ½ second. 
These doughnuts are fed by a conveyor belt to the warehouse. The warehouse collects the doughnuts 12 at a time and puts them in boxes. 
The boxes then go on a shelf awaiting a sale. The warehouse keeps a running total of the number of boxes in inventory. Because the warehouse can only store 10 boxes, once the
shelves are full, the warehouse instructs the factory to halt production until the sales office has sold at least one box of doughnuts, making room for more inventory. 
Before the sales office can close a sale, it must verify that the warehouse has sufficient inventory to fill the order. If not, the sale must be declined. 
If the sale can be filled, the sales office must properly adjust the warehouse’s inventory levels so that the inventory count remains accurate. Sales are by the boxes only.

### [leandraHallExam2ProgrammingQuestion.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects/blob/main/leandraHallExam2ProgrammingQuestion.cpp)

This program will calculate the total cost of staying at a hotel by prompting the user to input the price of a hotel room, the number rooms to be booked, the duration of their stay in days, and the sales tax. Based on the number of rooms
to be booked, discounts may be applied.

### [leandraHallIteratorsHW.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects/blob/main/leandraHallIteratorsHW.cpp)
This program prompts the user to input 10 integers and stores those values into a vector. It then calculates the sum of the integers in the vector.

### [leandraHallPA3P2.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects/blob/main/leandraHallPA3P2.cpp)

This program should open, read, and print out contents from a file specified in the Command Line by utilizing the variables
argc and argv. Additionally, the program adds each character from the file into a linked list, prints out the list's contents,
and removes each character from the linked list using methods such as addFront, removeFront, and printList.

### [leandraHallPA3P3.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects)

This program should open, read, and print out contents from a file specified in the Command Line by utilizing the variables
argc and argv. Additionally, the program evaluates whether or not the characters in a sentence from each line are legal or not
through the method isBalanced.


### [leandraHallProgrammingAssignment3.cpp](https://github.com/LeandraHall/Leandra-CPP-Projects/blob/main/leandraHallProgrammingAssignment3.cpp)

This program should open, read, and print out contents from a file specified in the Command Line by utilizing the variables
argc and argv. 
