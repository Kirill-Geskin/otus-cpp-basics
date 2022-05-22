# Task 5 - Calculation of the statistical characteristics of the sequence

### Statement of the task

The input (standard input) to the application is a sequence (of unknown size) of numerical values. The application must, in the course of its work, read all
sequence from standard input and display a set of the following statistics:

* `min` is the minimum value from the sequence
* `max` - the maximum value from the sequence
* `mean` - arithmetic mean calculated based on all elements of the sequence
* `std` - standard deviation
* [optional] `pct90` - 90th percentile
- [optional] `pct95` - 95th percentile

Items marked as [optional] are "tasks with an asterisk" and may not be completed.

Stopping the sequence input is assumed by passing the `EOF` (End Of File) flag. On Windows, this is done with the following set of commands: **Ctrl+Z, Enter**. On Linux, this is done by pressing **Ctrl+D**.

Application example:
```
> statistics
0 1 2 3 4 5 6 7 8 9 10
min = 0
max=10
mean = 5
std = 3.162277
pct90 = 9
pct95 = 10
```
It is worth noting that the results may differ depending on the implementation. So, for example, some implementations might return the value `pct95` = 9.5. Or `std` values ​​that are different from what is indicated above, due to a different rounding of the result.

### Implementation clarifications
