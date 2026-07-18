# BSQ

## Assignment

**Assignment name:** `bsq`

**Expected files:**

```
*.c
*.h
```

---

## Allowed Functions and Globals

```c
malloc
calloc
realloc
free
fopen
fclose
getline
fscanf
fputs
fprintf
stderr
stdout
stdin
errno
```

---

## Description

The goal of this program is to find the **biggest square on a map while avoiding obstacles**.

A file containing the map will be provided and must be passed as an argument to the program.

The first line of the map contains information required to read it:

- The number of lines on the map.
- The **empty** character.
- The **obstacle** character.
- The **full** character.

The map consists of:

- Empty characters.
- Obstacle characters.
- Lines.

The program must replace the appropriate **empty characters** with the **full character** to represent the biggest possible square.

If multiple solutions exist:

1. Choose the square closest to the top of the map.
2. If still multiple solutions exist, choose the one closest to the left.

---

## Input Handling

- When the program receives multiple maps as arguments, every solution or `"map error"` must be followed by a newline.
- If no arguments are provided, the program must read the map from **standard input**.

Example:

```bash
cat example.txt | ./bsq
```

---

## Valid Map Definition

A valid map must satisfy the following rules:

- All lines must have the same length.
- There must be at least one line containing at least one box.
- Each line must end with a newline character.
- Map characters can only be the characters defined in the first line.
- The map is invalid if:
  - A required character is missing from the first line.
  - Two or more of the characters (`empty`, `full`, `obstacle`) are identical.
- Characters can be any printable character, including numbers.

---

## Error Handling

For an invalid map:

```
map error
```

must be displayed on the error output followed by a newline.

The program must then continue processing the next map.

---

## Example

### Input

```text
%>cat example_file

9 . o x
...........................
....o......................
............o..............
...........................
....o......................
...............o...........
...........................
......o..............o.....
..o.......o................
```

### Command

```bash
./bsq example_file
```

### Output

```text
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxxo..............
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxx...o...........
.....xxxxxxx...............
......o..............o.....
..o.......o................
```
