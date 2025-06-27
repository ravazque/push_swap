
<p align="center">
  <img src="https://github.com/ayogun/42-project-badges/raw/main/badges/push_swape.png" alt="libftm badge">
</p>

## 📖 About

Push Swap is a sorting algorithm project at 42 Madrid that challenges students to sort a stack of integers using a limited set of operations and the minimum number of moves possible. The project emphasizes algorithm efficiency, optimization techniques, and understanding of data structures.

The goal is to sort integers in stack A using stack B as auxiliary storage, with specific operations and movement constraints.

## 🎯 Objectives

- Implement efficient sorting algorithms with limited operations
- Understand and optimize algorithm complexity
- Master stack data structure manipulation
- Develop algorithmic thinking and optimization strategies
- Learn about different sorting approaches and their trade-offs
- Make a strict parse for the input numbers

## 📋 Project Overview

<details>
<summary><strong>push_swap</strong></summary>

### Concepts

**Description:** Main program that outputs the optimal sequence of operations to sort the given integers  
**Input:** List of integers as command line arguments  
**Output:** Sequence of operations (one per line) to sort stack A  
**Objective:** Minimize the number of operations required

<br>

```c
./push_swap [list of integers]
```

</details>

<details>
<summary><strong>Available Operations</strong></summary>

---

### 1. **Swap elements (Swap)**.
- `sa`: Swaps the first and second element of the **A** stack.  
  Note_: Does nothing if the stack **A** is empty or has only one element.

- `sb`: Swaps the first and second element of stack **B**.  
  Note_: Does nothing if stack **B** is empty or has only one element.

- `ss`: Performs `sa` and `sb` operations at the same time.  
  _Note_: Does nothing on stacks that do not meet the conditions of `sa` or `sb`.

---

### 2. **Movements between stacks (Push)**.
- `pa`: Moves the first element of stack **B** to stack **A**.  
  Note_: Does nothing if stack **B** is empty.

- `pb`: Moves the first element of stack **A** to stack **B**.  
  _Note_: Does nothing if stack **A** is empty.

---

### 3. **Rotate up (Rotate)**.
- `ra`: Moves the first element of stack **A** to the end of the stack.  
  Note_: Does nothing if the stack **A** is empty or has only one element.

- `rb`: Moves the first element of stack **B** to the end of the stack.  
  Note_: Does nothing if stack **B** is empty or has only one element.

- `rr`: Performs `ra` and `rb` operations at the same time.  
  _Note_: Does nothing on stacks that do not meet the conditions of `ra` or `rb`.

---

### 4. **Reverse Rotate**: Moves the last element of the stack **A** to the top of the stack.
- `rra`: Moves the last element of the **A** stack to the top of the stack.  
  Note_: Does nothing if the stack **A** is empty or has only one element.

- `rrb`: Moves the last element of stack **B** to the top of the stack.  
  Note_: Does nothing if stack **B** is empty or has only one element.

- `rrr`: Performs `rra` and `rrb` operations at the same time.  
  Note_: Does nothing on stacks that do not meet the conditions of `rra` or `rrb`.

---

</details>

## 🚀 Installation & Structure

<details>
<summary><strong>📥 Download & Compilation</strong></summary>
    
<br>

```bash
# Clone the repository
git clone https://github.com/ravazque/push_swap.git
cd push_swap

# Compile the program
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile everything
make re
```

<br>

</details>

<details>
<summary><strong>📁 Project Structure</strong></summary>

<br>

```
push_swap/
├──┬ include/
│  └── push_swap.h                 # Header file with prototypes and structures
├──┬ src/
│  ├─┬─ moves/
│  │ └── *.c                       # All element movement functions
│  ├─┬─ ps_utils/
│  │ ├── ft_assing_index.c         # -
│  │ ├── ft_atoi.c                 # -
│  │ ├── ft_check_ordered.c        # -
│  │ ├── lists.c                   # -
│  │ └── nodes.c                   # -
│  ├─┬─ sorters/
│  │ ├── ft_simple_sort.c          # -
│  │ ├── ksort.c                   # -
│  │ └── mini_ksort.c              # - 
│  └── push_swap.c                 # Main program entry point
├── Makefile                       # Compilation rules
└── README.md                      # Project documentation
```

<br>

</details>

## 💡 Key Learning Outcomes

The Push Swap project develops crucial algorithmic and optimization skills:

- **Algorithm Design**: Creating efficient sorting algorithms with constraints
- **Optimization Techniques**: Minimizing operations through smart strategy selection
- **Data Structure Mastery**: Deep understanding of stack operations and limitations
- **Complexity Analysis**: Understanding time and space complexity of different approaches
- **Problem Decomposition**: Breaking complex problems into manageable sub-problems
- **Performance Benchmarking**: Measuring and comparing algorithm efficiency
- **Edge Case Handling**: Managing duplicate values, sorted inputs, and invalid data

## ⚙️ Technical Specifications

- **Language**: C (C99 standard)
- **Compiler**: cc with flags `-Wall -Wextra -Werror`
- **Memory Management**: Dynamic allocation for stack structures
- **Error Handling**: Proper validation of input and error messages
- **Performance Target**: 
  - 100 numbers: ≤ 700 operations (5 points)
  - 500 numbers: ≤ 5500 operations (4 points)

## 🚀 Usage Examples

<details>
<summary><strong>Examples</strong></summary>

<br>

```bash
# Basic usage
./push_swap 4 67 3 87 23
# Output: series of operations to sort the numbers

# Test with checker
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
# Output: OK (if sorting is correct)

# Performance testing
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
# Output: number of operations used

# Generate random test
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

<br>

</details>

---

> [!NOTE]
> This project has a part focused on parsing that will be useful later on.


