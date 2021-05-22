# CMSC-21

Fundamentals of Programming

-----------
## Exercise 1 `DayoftheWeek.c`

Given a year, a day, and a month, display 2 things:
  1. the day of the week that date falls on, and
  2. what day of the year it is
Note that not all years are the same, some years have a 29th of February (leap year) and most do not.

The Gregorian calendar has the following formula to calculate for whether a year is a leap year:
- the year is evenly divisible by 4;
- if the year can be evenly divided by 100, it is **NOT** a leap year, unless;
- the year is also evenly divisible by 400; then it is a leap year.
Knowing which year is a leap year, the calculation of what day of the year is trivial.

Calculating for the day of the week is trickier, but there exists some formulas to calculate for it. Here we describe Gauss' method:

Gauss' method calculates the week day of January 1 in Gregorian year number **A** with the following formula:
**R(1+5R(A−1,4)+4R(A−1,100)+6R(A−1,400),7)**

where **R(y,m)** is **y mod m**.

This gives us a number between 0 and 6, where 0 is Sunday, 1 is Monday, and etc.

Given the day of the week of the first day of the year, getting the day of the week for any day of the year becomes trivial.

I want to see many functions: a function to calculate the day of the year, a function to see whether it is a leap year, a function to calculate Gauss' method, and etc!

### Sample Input
```
1994 02 19
2021 03 15
2000 12 16
```

### Sample Output
```
Saturday, 50th day of the year
Monday, 74th day of the year
Saturday, 351st day of the year
```


----
## Exercise 2 `Recursion.c`

All solutions should be implemented via recursion.

Given a choice input (1 - 3), accept arguments and perform an operation based on the following choice inputs:
  - Choice input 1: 2 positive integers follow---A and B; print out the quotient (whole integer part only) when A is divided by B; NO DIVISION, MULTIPLICATION, OR MODULO ALLOWED
  - Choice input 2: 2 integers follow---A and B; determine whether they are relatively prime or not; print 1 if relatively prime, 0 if not
  - Choice input 3: an integer (2 - 20) follows---A; accept and store A more sorted (ascending) integers; accept final search integer N; print 1 if N is one of the A integers, 0 if not.
### Sample Input
```
1 10 3
1 922 21
2 34 90
2 18 35
3 5 10 20 24 37 89 25
3 6 5 12 48 62 73 91 62
```

### Sample Output
```
3
43
0
1
0
1
```


---
## Exercise 3 `TicTacToe.c`
Implement the game tic-tac-toe. Display the grid and ask the user for a row and column to play.

Use 2-d arrays!

---
## Exercise 4 `ObjectCounting.c`
Ask the user for 2 integers---N and M; this is followed by an **N × M** grid made of 1s and 0s to represent a grid of pixels; print out the number of objects found according to 8-connected connectivity.
### Sample Input
```
5 5 
0 0 0 0 0
0 1 1 1 0
1 1 1 0 0
0 0 0 0 1
1 1 1 1 1

8 10
0 0 0 0 0 0 0 0 0 0
0 1 1 1 0 0 0 0 1 1
0 1 1 1 0 0 1 0 1 1
0 0 0 0 0 1 0 0 1 0
0 1 0 0 1 1 1 0 0 0
0 0 1 0 0 0 0 1 1 1
0 1 1 1 0 0 1 0 1 1
1 0 0 0 0 1 1 1 1 0
```
### Sample Output
```
2
4
```
---
## Exercise 5 `Sorting.c`
Accept an integer, n; this is followed by n integers which you'll sort with a sorting algorithm of your choice. The use of any [ ] in the code is PROHIBITED, except to initialize an array. Use pointers and pointer arithmetic instead.
### Sample Input
```
10 5 7 -64 92 -50 18 40 -19 -71 -58
15 -97 41 76 -16 -90 -20 35 -30 37 74 -67 -50 33 0 12
```
### Sample Output
```
-71 -64 -58 -50 -19 5 7 18 40 92
-97 -90 -67 -50 -30 -20 -16 0 12 33 35 37 41 74 76
```
---
## Exercise 6 `SnakesandLadders1d.c`
Implement the famous snakes and ladders game. The grid shall be 10x10 and have 3 snakes and 3 ladders. Randomize the position of the snakes and ladders every start. The use of [ ] is PROHIBITED, except to initialize an array. Use pointers and pointer arithmetic instead.

Represent players as either 'a', 'b', 'c', or 'd'. Ladders are represented by an 'L' and take the player to 'l'. Snakes are represented by 'S' and take the player down to 's'.

---
## Exercise 7 `Fractions.c`
Ask for choice input (1 - 5), accept arguments and perform an operation based on the following choice inputs:
- Choice input 1: 2 strings representing fractions follow---A and B; print out result of A + B
- Choice input 2: 2 strings representing fractions follow---A and B; print out result of A - B
- Choice input 3: 2 strings representing fractions follow---A and B; print out result of A * B
- Choice input 4: 2 strings representing fractions follow---A and B; print out result of A / B
- Choice input 5: 1 string representing a fraction follows---A; print out simplified fraction of A

Create a fraction structure to store the fractions.

Answers must be simplified.
### Sample Input
```
1 2/3 10/2
2 4/3 1/3
3 1/5 5
4 1/3 1/3
5 24/16
```
### Sample Output
```
17/3
1
1
1
3/2
```
---
## Exercise 8 `Strings.c`
Implement a "string" using our vector implementation.

Implement a function, void initString(vector*, char*), that accepts a string and inserts all the character array's characters into the vector.

Implement a function, void concatenate(vector* combined, vector* a, vector* b), that concatenates 2 "strings", a and b, and puts the result into an empty vector, combined. (ex. concatenate(combined, a, b), where a contains "hello" and b contains "world", will put "helloworld" into combined)

Implement a function, void slice(vector* sliced, vector* source, int start, int end), that takes a portion of source starting from start and ends at end - 1. For example, slice(sliced, source, 5, 10), where source contains "Helloworld" slices "Helloworld" and takes the characters from index 5 to index 9: "world" and puts it into sliced.

Accept an integer choice (1 - 2), accept string arguments (at most 15 characters each) and perform an operation based on the following choice inputs:
-Choice input 1: 2 strings follow---A and B; print out the concatenation of A and B
-Choice input 2: 3 arguments follow, 1 string---A and 2 integers---B and C; print out the slice of A from B to C.

### Sample Input
```
1 jungle book
2 inbetweenin 2 9 
```
### Sample Output
```
junglebook
between
```
---
## Exercise 9

---
## Exercise 10

---
## Exercise 11

---
## Exercise 12 `Fractions.cpp`
Implement Exercise #7: Fractions, but this time using classes. Implement fraction operations as class member functions (ex. fractionA.add(fractionB), fractionA.divide(fractionB), fractionA.simplify()).
### Sample Input
```
1 2/3 10/2
2 4/3 1/3
3 1/5 5
4 1/3 1/3
5 24/16
```
### Sample Output
```
17/3
1
1
1
3/2
```
---
## Exercise 13



