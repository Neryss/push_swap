# push_swap
Push_swap is a tier 3 algorithm project at 42.
The purpose is to sort a serie of values with the least amount of moves (listed further down).

### General usage

This project is divided in two programs, once named [checker](checker.c) and the other one [push_swap](push_swap.c). Both of them can be used independently, or they can be used together.
You can compile them separatly with a `make [checker/push_swap]`, or you can compile them both with a simple `make`.

### General rules

You can't give neither of the programs any duped number, `./checker 1 1 2` will result in an error.
If anyhting wrong happens during the sorting or if you give them the wrong arguments, the programs will return `"Error\n"`.
You can enter negative values such as follows `./checker -1 -3 4 5` but it will return an error if you try to enter anything else such as letters, signs followed by a space etc.

---

# Push_swap

[push_swap] will sort the X numbers you'll pass as arguments with the help of two stacks, a and b, it will use the following moves/rules set :

- `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- `sb` :  swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- `ss` : sa and sb at the same time.
- `pa` : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- `pb` : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
- `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : ra and rb at the same time.
- `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : rra and rrb at the same time.

### Usage

You can use [push_swap] like this :
```
./push_swap 2 4 1 3 5
```

If you want to get the number of moves in which it sorted the values you can use the same command followed by `| wc -l`
It will count the number of line that [push_swap] outputs, since the programs must write the moves it made to sort everything to later, pass them to [checker].

---

# Checker

[checker] uses the sames rules that [push_swap] follows, same parsing, moves and so on.
It will check if the sorting was done correctly by [push_swap] and will receive the moves written by the later in the standard input, execute them and check if everything is sorted correctly. Basically it's a kind of anti cheat used to check if we didn't cut any move or sorted using something else.

### Usage

You can use [checker] like this :
```
./checker 2 4 1 3 5
```

Then you'll need to enter the moves you want to sort with and press `CTRL+D` to stop the reading and instantiate the check.

---

# Using both of them

If you want to use them both at the same time, which is the way intended, you can use this command in a bash terminal :

```
ARG="2 4 1 3 5" ./push_swap $ARG | ./checker $ARG;
```

It will first sort everything, then check if everything could be sorted with the command given by [push_swap].

---

# Other utils

You can generate random number between X and Y, sort them and check if everything's ok with the following command in bash :
```
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
```

You can swap the after pipe part with ` wc -l` to check the number of moves used.