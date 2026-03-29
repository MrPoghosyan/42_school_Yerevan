#include "Point.hpp"

void test(std::string name, Point a, Point b, Point c, Point p)
{
    std::cout << name << ": " << bsp(a, b, c, p) << std::endl;
}

int main(void)
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    std::cout << "=== BASIC TESTS ===" << std::endl;

    test("Inside (simple)", a, b, c, Point(3, 3));     // ✅ 1
    test("Outside (far)", a, b, c, Point(10, 10));     // ❌ 0

    std::cout << "\n=== EDGE CASES ===" << std::endl;

    test("On edge AB", a, b, c, Point(5, 0));          // ❌ 0
    test("On edge BC", a, b, c, Point(5, 5));          // ❌ 0
    test("On edge CA", a, b, c, Point(0, 5));          // ❌ 0

    std::cout << "\n=== VERTEX CASES ===" << std::endl;

    test("On vertex A", a, b, c, Point(0, 0));         // ❌ 0
    test("On vertex B", a, b, c, Point(10, 0));        // ❌ 0
    test("On vertex C", a, b, c, Point(0, 10));        // ❌ 0

    std::cout << "\n=== BORDERLINE INSIDE ===" << std::endl;

    test("Very close inside", a, b, c, Point(0.1f, 0.1f)); // ✅ 1

    std::cout << "\n=== BORDERLINE OUTSIDE ===" << std::endl;

    test("Very close outside", a, b, c, Point(-0.1f, 0));  // ❌ 0

    std::cout << "\n=== DIFFERENT TRIANGLE ===" << std::endl;

    Point d(-5, -5);
    Point e(5, -5);
    Point f(0, 5);

    test("Inside (different triangle)", d, e, f, Point(0, 0));   // ✅ 1
    test("Outside (different triangle)", d, e, f, Point(6, 0));  // ❌ 0

    std::cout << "\n=== CLOCKWISE / COUNTER-CLOCKWISE ===" << std::endl;

    // reversed triangle (order changed)
    test("Inside (reversed order)", c, b, a, Point(3, 3)); // ✅ 1

    std::cout << "\n=== DEGENERATE TRIANGLE ===" << std::endl;

    Point g(0, 0);
    Point h(5, 5);
    Point i(10, 10); // collinear

    test("Degenerate triangle", g, h, i, Point(3, 3)); // ❌ 0 (undefined → treat as false)

    return 0;
}
