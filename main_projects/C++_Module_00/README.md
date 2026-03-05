# C++ Module 00

<p align="center">

Introduction to **C++ programming** and **Object-Oriented Programming (OOP)** concepts through practical exercises.

</p>

---

# Table of Contents

* [About the Project](#about-the-project)
* [Learning Objectives](#learning-objectives)
* [Project Structure](#project-structure)
* [Exercises](#exercises)
* [Compilation](#compilation)
* [Usage](#usage)
* [Testing](#testing)
* [Key C++ Concepts](#key-c-concepts)
* [Architecture](#architecture)
* [Implementation Details](#implementation-details)
* [Author](#author)

---

# About the Project

**C++ Module 00** is the first module in the 42 C++ curriculum.

The goal of this module is to introduce the fundamentals of **C++** and transition from **procedural programming in C** to **object-oriented programming**.

This module focuses on:

* classes
* encapsulation
* constructors and destructors
* static members
* program architecture
* clean code practices

Each exercise gradually introduces new C++ concepts while maintaining a strong focus on **code structure and clarity**.

---

# Learning Objectives

By completing this module, the following skills are developed:

• Understanding the difference between **C and C++**

• Writing programs using **classes and objects**

• Managing **object lifecycle**

• Implementing **encapsulation**

• Using **static class members**

• Designing **clean program architecture**

• Separating **interface (.hpp)** from **implementation (.cpp)**

---

# Project Structure

```text
.
├── README.md
├── en.subject.pdf
├── ex00
│   ├── Makefile
│   └── megaphone.cpp
├── ex01
│   ├── Contact.cpp
│   ├── Contact.hpp
│   ├── Makefile
│   ├── PhoneBook.cpp
│   ├── PhoneBook.hpp
│   ├── main.cpp
│   └── utils.cpp
└── ex02
    ├── 19920104_091532.log
    ├── Account.cpp
    ├── Account.hpp
    ├── Makefile
    ├── README.md
    └── tests.cpp
```

---

# Exercises

## ex00 — Megaphone

A simple program that prints command-line arguments in **uppercase**.

Example:

```
./megaphone hello world
```

Output:

```
HELLO WORLD
```

Concepts introduced:

* command-line arguments
* `std::cout`
* string manipulation
* basic C++ program structure

---

## ex01 — PhoneBook

Implementation of a simple **phonebook application**.

Supported commands:

```
ADD
SEARCH
EXIT
```

The phonebook stores up to **8 contacts** using a **circular buffer**.

Concepts demonstrated:

* class design
* encapsulation
* getters and setters
* input validation
* formatted output
* modular code organization

Main classes:

```
Contact
PhoneBook
```

---

## ex02 — Account

Simulation of a **bank account system** where each object represents an account.

The class also maintains **global statistics** across all accounts.

Operations include:

* account creation
* deposits
* withdrawals
* global statistics
* account destruction

Example log entry:

```
[19920104_091532] index:0;amount:42;created
```

Concepts demonstrated:

* static class members
* constructor/destructor behavior
* object lifecycle
* class-level state management

---

# Compilation

Each exercise contains its own **Makefile**.

Compile an exercise:

```
cd ex00
make
```

Clean build files:

```
make fclean
```

Rebuild:

```
make re
```

---

# Usage

Example execution:

```
./megaphone "hello 42"
```

```
./phonebook
```

```
./account
```

---

# Testing

For **ex02**, the program output can be compared with the reference log.

Since timestamps differ, only the log content after the timestamp should be compared.

Example:

```
diff \
<(cut -d']' -f2 19920104_091532.log) \
<(cut -d']' -f2 dif_account)
```

This ignores the timestamp and compares only the actual log output.

---

# Key C++ Concepts

### Classes

A class defines a type that encapsulates both **data** and **behavior**.

### Encapsulation

Data is hidden inside the class and accessed through **public methods**.

### Constructors / Destructors

Constructors initialize objects.
Destructors clean up resources when objects go out of scope.

### Static Members

Static members belong to the **class itself** rather than individual objects.

This allows tracking global statistics such as:

```
total accounts
total deposits
total withdrawals
```

---

# Architecture

Typical file organization:

```
Header (.hpp)
    ↓
Class declaration

Source (.cpp)
    ↓
Function implementation
```

Example:

```
Account.hpp → class interface
Account.cpp → implementation
```

This separation improves maintainability and compilation efficiency.

---

# Implementation Details

Important design decisions used in this project:

• **Member initialization lists** for efficient object construction

• **Static variables** to maintain global state

• **Encapsulation** to protect internal class data

• **Modular code organization**

• **Clear separation of responsibilities between classes**

---

# Author

**Vahagn Poghosyan**

Self-taught developer interested in:

* systems programming
* cybersecurity
* low-level programming
* Linux systems

