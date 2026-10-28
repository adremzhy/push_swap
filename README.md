*This project has been created as part of the 42 curriculum by nhuskov, adremzhy.*

# push_swap

## Description

**push_swap** is a sorting project with a limited set of operations. The program
gets a list of integers. It must print the shortest sequence of instructions it
can find that sorts these numbers in ascending order, using two stacks, **a**
and **b**.

At the start all numbers are in stack **a** (the first argument is on top) and
stack **b** is empty. Only these operations are allowed:

| Operation | Effect |
|-----------|--------|
| `sa` / `sb` / `ss` | swap the first two elements of a / b / both |
| `pa` / `pb` | take the top element of b and push it on a / the other way round |
| `ra` / `rb` / `rr` | rotate a / b / both up (first element becomes last) |
| `rra` / `rrb` / `rrr` | rotate a / b / both down (last element becomes first) |

The goal is to sort the numbers with as few operations as possible. The project
also has several sorting strategies with different complexities, an adaptive
mode that picks a strategy based on how unsorted the input is, and a benchmark
mode.

## Instructions

### Compilation

```sh
make        # builds libft (with ft_printf) and the push_swap binary
make clean  # removes object files
make fclean # removes object files and the binary
make re     # rebuilds everything
```

The project is compiled with `cc -Wall -Wextra -Werror`.

### Usage

```sh
./push_swap [flags] <numbers...>
```

Numbers can be given as separate arguments or as one string:

```sh
./push_swap 3 2 5 1 4
./push_swap "3 2 5 1 4"
```

Flags (they must come before the numbers):

| Flag | Meaning |
|------|---------|
| `--simple` | force the simple strategy, O(n²) |
| `--medium` | force the medium strategy, O(n√n) |
| `--complex` | force the complex strategy, O(n log n) |
| `--adaptive` | choose the strategy from the disorder of the input (default) |
| `--bench` | print statistics to **stderr** after sorting |

Example with benchmark:

```sh
./push_swap --bench --complex 5 3 1 4 2
```

The `--bench` output (on stderr) shows the initial disorder in percent, the
strategy that was used, the total number of operations and the count of each
operation.

### Error handling

The program prints `Error` followed by a newline to stderr when:
- an argument is not a valid integer,
- a number does not fit into an `int`,
- there are duplicate numbers.

With no arguments the program prints nothing and exits.

### Checking the result

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG   # prints OK / KO
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l                  # number of operations
```

## Algorithm

### 1. Preparation: ranks

After parsing, every value is replaced by its **rank**: its position in the
sorted order, from `0` to `n - 1`. For example `[42, -7, 100]` becomes
`[1, 0, 2]`. The order stays the same, but now all values are small and
non-negative, which the chunk and radix strategies rely on.

### 2. Disorder

The disorder is the share of pairs `(i, j)` with `i < j` where
`a[i] > a[j]`, i.e. the number of inversions divided by `n(n-1)/2`.

- `0.0` means the stack is already sorted,
- `1.0` means it is sorted in reverse.

### 3. Strategies

**Simple: O(n²), selection sort**
Find the minimum in a, rotate it to the top with whichever direction (`ra` or
`rra`) is shorter, then `pb`. Repeat until a is empty, then `pa` everything
back. The code is very short and works well when only a few elements are out
of place.

**Medium: O(n√n), chunk sort**
The ranks are split into chunks of size about √n. All elements of the first
chunk (ranks `< √n`) are pushed to b, then the next chunk, and so on. After
that the maximum of b is brought to the top and pushed back to a, again and
again. Each element only moves within its own chunk, so we need far fewer
rotations than in the simple sort.

**Complex: O(n log n), LSD radix sort (base 2)**
Ranks are sorted bit by bit, starting from the least significant bit. For each
bit, we look at every element of a: if the bit is `0` we use `pb`, otherwise
`ra`. Then everything is pushed back with `pa`. After `log2(n)` passes the
stack is sorted. The number of operations is predictable and grows slowly for
big inputs.

**Adaptive (default)**

| Disorder | Strategy | Reason |
|----------|----------|--------|
| `< 20%` | simple | almost sorted: few elements to move |
| `20% – 50%` | medium | partly sorted: chunks work well |
| `≥ 50%` | complex | very unsorted: radix scales best |

### Why these choices

- Using ranks instead of raw values makes radix and chunking work the same way
  for negative numbers and for big values.
- Each strategy fits a different kind of input. The disorder value gives a
  cheap way (O(n²) comparisons, done only once) to pick the most suitable one.

## Contributions

- **nhuskov**: parsing, ranks, disorder, adaptive strategy, bench
- **adremzhy**: stack operations, sorting strategies, Makefile

## Resources

- [Push_Swap: The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Radix sort (Wikipedia)](https://en.wikipedia.org/wiki/Radix_sort)
- [Selection sort (Wikipedia)](https://en.wikipedia.org/wiki/Selection_sort)
- The 42 push_swap subject and the provided checker

### Use of AI

AI was used as a learning assistant: to explain concepts such as radix sort, algorithm complexity and the inversion count, to explain norminette errors, and to help write this README. All code was written by the team members.