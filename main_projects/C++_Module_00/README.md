# C++ Module 00 — ex02: Account

## Overview

This project is part of the **C++ Module 00** from the 42 curriculum.
It implements a simplified **bank account system simulation** using a C++ class.

The goal of this exercise is to practice:

* Basic **Object-Oriented Programming (OOP)**
* **Class design and encapsulation**
* **Static class members**
* **Member initialization lists**
* **Object lifecycle (constructor / destructor)**
* Formatting program output according to a strict specification

Each `Account` object represents a bank account.
The class also maintains **global statistics** about all accounts using `static` members.

---

# Class Architecture

The `Account` class maintains two types of state.

## 1. Object State (per account)

Each instance stores information about a single account.

Example:

* account index
* current balance
* number of deposits
* number of withdrawals

These variables belong **only to the specific object**.

---

## 2. Class State (shared across all accounts)

The class also tracks global statistics across **all accounts** using `static` members:

* total number of accounts
* total amount of money
* total deposits
* total withdrawals

These variables exist **only once in the entire program** and are shared by all instances.

---

# Key Concepts Demonstrated

## Static Members

Static variables store **global state for the class**.

Example:

```
static int _nbAccounts;
static int _totalAmount;
```

These variables are defined once in `Account.cpp` and shared by all objects.

---

## Member Initialization List

The constructor uses an initialization list:

```
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
```

This is the **correct and efficient way** to initialize member variables in C++.

Benefits:

* avoids unnecessary default construction
* required for `const` members and references
* considered best practice in C++

---

## Object Lifecycle

Each account follows a lifecycle:

1. Constructor is called when the object is created
2. Methods modify the account state
3. Destructor is called when the object goes out of scope

The destructor logs when an account is closed.

---

# Project Structure

```
.
├── Account.hpp
├── Account.cpp
├── tests.cpp
├── Makefile
├── 19920104_091532.log
└── README.md
```

---

# Compilation

Compile the project using the provided Makefile:

```
make
```

This will produce the executable:

```
./account
```

---

# Running the Program

Run the program and redirect the output to a file:

```
./account > my_output.log
```

The program prints the full account activity log including:

* account creation
* deposits
* withdrawals
* account closure
* global statistics

---

# Output Verification

The project includes a **reference log file** provided by 42:

```
19920104_091532.log
```

Because the program prints a **timestamp**, the first column of each line will always differ.

Example:

Reference output:

```
[19920104_091532] index:0;amount:42;created
```

Your output:

```
[????????_??????] index:0;amount:42;created
```

To properly compare outputs we must **ignore the timestamp column**.

---

# Correct Diff Command

Use the following command to compare outputs **while ignoring timestamps**:

```
diff \
<(cut -d']' -f2 19920104_091532.log) \
<(cut -d']' -f2 my_output.log)
```

Explanation:

* `cut -d']' -f2`
  removes the timestamp column

Example transformation:

```
[19920104_091532] index:0;amount:42;created
```

becomes

```
 index:0;amount:42;created
```

This allows `diff` to compare **only the meaningful data**.

If the command prints **no output**, the program matches the expected result.

---

# Example Workflow

```
make

./account > my_output.log

diff \
<(cut -d']' -f2 19920104_091532.log) \
<(cut -d']' -f2 my_output.log)
```

If there is **no diff output**, the implementation is correct.

---

# Learning Outcomes

After completing this project you should understand:

* how classes encapsulate state and behavior
* the role of `static` members
* proper constructor initialization
* object lifecycle management
* clean separation between class interface and implementation

---

# Notes

This project is designed to simulate a simplified **bank system** where the class itself tracks global statistics across all accounts.

It is a common educational pattern used to demonstrate how **object state and class state interact**.

---
