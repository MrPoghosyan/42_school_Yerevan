# Life

## Assignment

**Assignment name:** `life`

**Expected files:**

```
*.c
*.h
```

---

## Allowed Functions

```c
atoi
read
putchar
malloc
calloc
realloc
free
```

---

## Description

Write a program that simulates the **Game of Life**.

The prototype of the program is:

```bash
./life width height iterations
```

Where:

- `width` and `height` are the dimensions of the board.
- `iterations` is the number of Game of Life iterations to simulate.

---

## Initial Board Configuration

The initial configuration of the board is drawn by a sequence of commands received from **standard input**.

Imagine a pen starting at the **top-left corner** of the board.

Each command is represented by one of these characters:

| Command | Action |
|---------|--------|
| `w` | Move the pen up |
| `a` | Move the pen left |
| `s` | Move the pen down |
| `d` | Move the pen right |
| `x` | Lift or lower the pen to start/stop drawing |

Additional rules:

- The pen cannot move outside the board.
- If a movement command would leave the board, the pen stays in place.
- Invalid commands are ignored.

---

## Game of Life Simulation

Once the end of file is reached:

1. The program must simulate the Game of Life for the given number of iterations.
2. The final board must be printed to `stdout`.

Cell representation:

- Alive cell:

```text
O
```

- Dead cell:

```text
(space)
```

Cells outside the board are considered dead.

---

## Examples

### Example 1

Command:

```bash
echo 'sdxddssaaww' | ./life 5 5 0 | cat -e
```

Output:

```text
    $
OOO $
O O $
OOO $
    $
```

---

### Example 2

Command:

```bash
echo 'sdxssdswdxdddxsaddawxwdxwaa' | ./life 10 6 0 | cat -e
```

Output:

```text
          $
 O   OOO  $
 O     O  $
 OOO  O   $
  O  OOO  $
          $
```

---

### Example 3

Command:

```bash
echo 'dxss' | ./life 3 3 0 | cat -e
```

Output:

```text
O $
O $
O $
```

---

### Example 4

Command:

```bash
echo 'dxss' | ./life 3 3 1 | cat -e
```

Output:

```text
   $
OOO$
   $
```

---

### Example 5

Command:

```bash
echo 'dxss' | ./life 3 3 2 | cat -e
```

Output:

```text
O $
O $
O $
```

---

### Example 6

Command:

```bash
echo 'sdxddssaaww' | ./life 5 5 1 | cat -e
```

Output:

```text
  O  $
 O O $
O   O$
 O O $
  O  $
```

---
