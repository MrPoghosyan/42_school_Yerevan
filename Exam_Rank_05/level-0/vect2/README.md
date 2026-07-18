# vect2

## Assignment

**Assignment name:** `vect2`

**Expected files:**

```
vect2.cpp
vect2.hpp
```

---

## Description

Create a class **`vect2`** representing a mathematical vector of dimension 2 containing integers.

The class must support:

- Addition
- Subtraction
- Multiplication by a scalar

Example:

```cpp
vect2(2, 2) * 2 == vect2(4, 4)
```

The `[]` operator can be used to access the components of the vector:

```cpp
v[0]
v[1]
```

No bound checking is required.

---

## Output

Your class must be printable using the `<<` operator.

Example:

```cpp
std::cout << v << std::endl;
```

must produce the same output as:

```cpp
std::cout << "{" << v[0] << ", " << v[1] << "}" << std::endl;
```

---

## Subject Main

The following `main.cpp` must compile and work correctly with your implementation:

```cpp
#include "vect2.hpp"
#include <iostream>

int main()
{
    vect2 v1; // 0, 0
    vect2 v2(1, 2); // 1, 2
    const vect2 v3(v2); // 1, 2
    vect2 v4 = v2; // 1, 2

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v1: " << "{" << v1[0] << ", " << v1[1] << "}" << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;

    std::cout << v4++ << std::endl; // 2, 3
    std::cout << ++v4 << std::endl; // 3, 4
    std::cout << v4-- << std::endl; // 2, 3
    std::cout << --v4 << std::endl; // 1, 2

    v2 += v3; // 2, 4
    v1 -= v2; // -2, -4

    v2 = v3 + v3 * 2; // 3, 6
    v2 = 3 * v2; // 9, 18

    v2 += v2 += v3; // 20, 40

    v1 *= 42; // -84, -168

    v1 = v1 - v1 + v1;

    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "-v2: " << -v2 << std::endl;

    std::cout << "v1[1]: " << v1[1] << std::endl;

    v1[1] = 12;

    std::cout << "v1[1]: " << v1[1] << std::endl;
    std::cout << "v3[1]: " << v3[1] << std::endl;

    std::cout << "v1 == v3: " << (v1 == v3) << std::endl;
    std::cout << "v1 == v1: " << (v1 == v1) << std::endl;
    std::cout << "v1 != v3: " << (v1 != v3) << std::endl;
    std::cout << "v1 != v1: " << (v1 != v1) << std::endl;
}
```
