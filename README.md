![Push_swap logo](.media/push_swap_logo.png)

![Grade badge](https://img.shields.io/badge/100_%2F_100-004d40?label=final%20grade&labelColor=151515&logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIGhlaWdodD0iMjRweCIgdmlld0JveD0iMCAwIDI0IDI0IiB3aWR0aD0iMjRweCIgZmlsbD0iI0ZGRkZGRiI+PHBhdGggZD0iTTAgMGgyNHYyNEgweiIgZmlsbD0ibm9uZSIvPjxwYXRoIGQ9Ik0xMiAxNy4yN0wxOC4xOCAyMWwtMS42NC03LjAzTDIyIDkuMjRsLTcuMTktLjYxTDEyIDIgOS4xOSA4LjYzIDIgOS4yNGw1LjQ2IDQuNzNMNS44MiAyMXoiLz48L3N2Zz4=) ![Language Badge](https://img.shields.io/badge/C-fe428e?logo=C&label=language&labelColor=151515) ![Norminette Badge](https://img.shields.io/badge/passing-brightgreen?logo=42&label=norminette&labelColor=151515) ![Library Badge](https://img.shields.io/badge/my_own_libft-004d40?logo=GitHub&label=library%20used&labelColor=151515)

# Push_swap

This project is about sorting a stack A by ascending order with two stacks with a limited number of operations available. The only possible operations are the following:
* **sa** (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
* **sb** (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
* **ss** : sa and sb at the same time.
* **pa** (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
* **pb** (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
* **ra** (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
* **rb** (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
* **rr** : ra and rb at the same time.
* **rra** (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
* **rrb** (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
* **rrr** : rra and rrb at the same time.

The full subject can be found [here](.media/en.subject.pdf).

# How the algorithm works

* The algorithm is looping through all the elements and calculate the cost to move it to the correct position in stack B (in descending order). It then moves the cheapest element.
* Once only three elements remain in stack A, they are sorted with a custom function.
* We then loop through stack B to again find the cheapest element to move.
* Once everything is done we rotate stack A until the smallest element is on top and the stack is sorted

# Downloading and compiling the project

Clone the repository and use `make` to compile
```
git clone https://github.com/theozanchi/42_Berlin_Push_swap/tree/main
cd 42_Berlin_Push_swap
make
```

# Visualizing how the algorithm works
The [Push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) developped by [o-reo](https://github.com/o-reo) can be used how the algorithm works.

![algorithm in action](.media/algorithm_in_action.gif)
