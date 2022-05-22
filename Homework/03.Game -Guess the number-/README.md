# Task 3 - Game "guess the number" with a high score table

Game "guess the number" - the computer thinks of a number, the user tries to guess. Wherein
the number of attempts is counted and a table of records is formed.

In the materials for this independent work, you can find several code blanks by combining
which (with minor modifications) you can get the basic implementation of the application.

The essence of the game. The application “guesses” some number and waits in a loop for input from the user. AT
If the user has entered a number less than the specified one, the “less than” hint is displayed. AT
if the user enters a number greater than the given one, the hint "greater than" is displayed. AT
when the user finally guesses the number, the message "you win!" is displayed, and the loop
input ends. For an example, see the `check_value.cpp` example from
independent work.

In order to make the game more interesting, you should use a generator in the application
random numbers instead of "guessing" a constant. It is therefore recommended to use the most
a simple random number generator from the standard library is `std::rand`. There are a number of nuances:

* by default, `std::rand` returns values ​​from `0` to the constant `RAND_MAX` (a specific value
specific to different platforms, however, the standard guarantees that this value is not
less than `32767`)
* guessing such a large number can be difficult (although through binary search - even
interesting), so we take as a hidden number not the result of execution
std::rand, and the remainder of dividing the result by some constant, which we limit
the maximum value for guessing (in the example below, the limit will be the number 100):
```cpp
const int max_value = 100;
const int random_value = std::rand() % 100;
```
* before using the random number generator, you need to initialize it with the initial
value (the so-called seed), otherwise every time the application is restarted
the random number generator will produce the same sequence of values. AT
as the initial value for initialization, a good option is the current
time to the nearest second. This is done as follows:
```cpp
std::srand(std::time(nullptr));
```
For an example of working with a random number generator, see the `random_value.cpp` example.

To implement the table of records, the user is prompted at the start of the application
introduce yourself. The entered value is stored in a string type variable. Further
the application counts the number of attempts it took the user to guess
numbers. This number is also remembered. Then the username and the number of attempts are appended to
file with the table of records and the full current contents of the table of records are displayed. See example
`high_scores.cpp`.

Application example:
```
> guess_the_number
Hi! Enter your name, please:
username
Enter your guess:
42
less than 42
one
greater than 1
33
you win! attempts = 3
High score table:
13
SomeOtherName 24
username 9
username 3
```

## Additional task 1

The task is optional and not mandatory for the formal delivery of the work.

Add handling of the `-max` command line option with one numeric argument, with
with which you can set the maximum value for the hidden number. See example
argument.cpp If the parameter is not passed, the default constraint
some constant is chosen at the discretion of the author (for example, 100). Launch example
applications with this argument:
```
> guess_the_number –max 42
```

## Additional task 2.

The task is optional and not mandatory for the formal delivery of the work.

Add processing of the `-table` command line option with no arguments, with which
you can display a table of records immediately, without the need for a game. The application then outputs
current values ​​from the high score table and terminates immediately. Run example with this argument:
```
> guess_the_number -table
```

## Additional task 3

The task is optional and not mandatory for the formal delivery of the work.

When reading the table of records for each user, determine the minimum value of the number
attempts and output only them.

For example, the contents of the high score table:
```
A 15
B12
ABA10
one
3
```
For users A and B, we have 3 and 2 entries, respectively. But at the end of the application
we display only the minimum values ​​​​(these are still records):
```
High score table:
A 3
B1
```

## Extra task 4 (with an asterisk)

The task is optional and not mandatory for the formal delivery of the work.

When forming a table of records, overwrite the previous result of the user, if
the current result is better. Example:
```
-
BAC13
12
5
-a
BCA13
5
5
```
current highscore table values:
further suppose that user A played again and completed the task in 5 attempts,
then the contents of the high score table should change as follows:

## Extra task 5. (in case you get bored)

A variation of optional task 1 is to add processing of the `-level` command line parameter with one numeric type argument,
through which you can set the level of difficulty. The maximum depends on the difficulty level.
the value of the given number. For example, let's add 3 difficulty levels:
* `1` - the maximum value is 10 (thus guessing will be in the range from 0 to 9)
* `2` - the maximum value is 50 (the range will become from 0 to 49)
* `3` - maximum value 100 (range 0 to 99)
An example of running an application with this argument:
```
> guess_the_number - level 3
```
In the case of additional task 1, we consider the input of the parameters `-level` and `-max`
simultaneously an erroneous situation. You can either specify the level of difficulty, or explicitly
set the maximum value.
