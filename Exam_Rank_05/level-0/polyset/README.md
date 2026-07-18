# Polyset

## Assignment

**Assignment name:** `Polyset`

**Expected files:**

```
searchable_array_bag.cpp
searchable_array_bag.hpp
searchable_tree_bag.cpp
searchable_tree_bag.hpp
set.cpp
set.hpp
```

---

## Description

You will find in this directory some classes:

- `bag`: an abstract class representing a bag.
- `searchable_bag`: an abstract class representing a bag with the ability to search in it.
- `array_bag`: an implementation of a bag using an array as the underlying data structure.
- `tree_bag`: an implementation of a bag using a binary search tree as the underlying data structure.

If you don't know what a **set** or a **bag** is, you can read the attached file:

```
shame.en.txt
```

---

## Part 1

Since a bag without a searching function isn't very useful, implement two classes:

- `searchable_array_bag`
- `searchable_tree_bag`

These classes must:

- Inherit from `array_bag` and `tree_bag` respectively.
- Implement the `searchable_bag` abstract class.

---

## Part 2

Implement the class `set`.

The `set` class must:

- Wrap a `searchable_bag`.
- Transform the behavior of a bag into a set.

You will find a `main` file in this directory that must compile and work correctly with your implementation.

---

## Requirements

- All classes must follow the **Orthodox Canonical Form**.
- Don't forget to use `const` correctly.
