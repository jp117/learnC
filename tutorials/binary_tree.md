```
        7
      /   \
     2     9
    / \   / \
   1   5 8  11
      /
     4
```

```
Pre-Order  Node -> Left -> Right

Visit 7
    Go left -> visit 2
        Go left -> visit 1
        Go right -> visit 5
        go left -> visit 4
    go right -> visit 9
        go left -> visit 8
        go right -> visit 11
```

```
In-order Left -> Node -> Right
Visit 7
    Go left to 2
        Go left to 1 -> Print 1
        Go up to 2 -> Print 2
        Go down to 5
            Go Down to 4 -> Print 4
            Print 5
    Go to 7 -> Print 7
    Go down to 9
        Go down to 8 -> Print 8
        Go up to 9 -> Print 9
        Go down to 11 -> Print 11



```

```
Post-Order Left -> Right -> Node
Visit 7
    Go left to 2
        Go left to 1 -> Print 1
        Go right to 5 
            Go down to 4 -> Print 4
        Print 5
        Print 2
    Go to 9
        Go to 8 -> Print 8
        Go to 11 -> Print 11
        Print 9
    Print 7

```