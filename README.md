It is a sorting project. The aim is to sort the integers with the fewest moves possible.
Components of the Project
    Stacks:
        There are two stacks: Stack A (the input stack) and Stack B (the auxiliary stack). The integers will be pushed onto Stack A, and the program will need to sort these integers.
    Operations:
        You can perform specific operations to manipulate the stacks. The operations are:
            sa: Swap the first two elements of Stack A.
            sb: Swap the first two elements of Stack B.
            ss: Perform sa and sb simultaneously.
            pa: Push the top element of Stack B onto Stack A.
            pb: Push the top element of Stack A onto Stack B.
            ra: Rotate Stack A (move the first element to the end).
            rb: Rotate Stack B.
            rr: Rotate both stacks simultaneously.
            rra: Reverse rotate Stack A (move the last element to the front).
            rrb: Reverse rotate Stack B.
            rrr: Reverse rotate both stacks simultaneously.
    Sorting Algorithm:
        It is used LIS algorithm and the complexity is O(n log n). For more info:
          https://en.wikipedia.org/wiki/Longest_increasing_subsequence
