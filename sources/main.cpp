//Copyright 2020 Kidinova Daria daria.kidinova@gmail.com

#include <string.hpp>

int main() {
    String a1("abc");
    String a2 = a1;
    String a3(a1);
    std::cout << "a1 = " << a1 << std::endl;
    std::cout << "a2 = " << a2 << std::endl;
    std::cout << "a3 = " << a3 << std::endl;
    String b("def");
    std::cout << "b = " << b << std::endl;
    a1 += b;
    std::cout << "a1 += b\na1 = " << a1 << std::endl;
    a1 *= 2;
    std::cout << "a1 *= 2\na1 = " << a1 << std::endl;
    if (a2 == a3) {
        std::cout << "a2 == a3" << std::endl;
    }
    if (a1 != b) {
        std::cout << "a1 != b" << std::endl;
    }
    if (b < a1) {
        std::cout << "b < a1" << std::endl;
    }
    if (a1 > b) {
        std::cout << "a1 > b" << std::endl;
    }
    String f("de");
    std::cout << "a1.Find('de') = " << a1.Find(f) << std::endl;
    a1.Replace('a', 'A');
    std::cout << "a1.Replace('a', 'A'); a1 = " << a1 << std::endl;
    std::cout << "a1.Size() = " << a1.Size() << std::endl;
    if (a1.Empty() == false) {
        std::cout << "a1 is not empty\n";
    }
    std::cout << "a1[2] = " << a1[2] << std::endl;
    String c("!!ABC!!!");
    std::cout << "c = " << c << std::endl;
    c.RTrim('!');
    std::cout << "c.RTrim('!'); c = " << c << std::endl;
    c.LTrim('!');
    std::cout << "c.LTrim('!'); c = " << c << std::endl;
    a2.swap(c);
    std::cout << "a2.swap(c); a2 = " << a2 << " ; c = " << c << std::endl;
    String d = a2 * 2;
    std::cout << "d = a2 * 2 = " << d << std::endl;
    String e = a3 + d;
    std::cout << "e = a3 + d = " << e << std::endl;
    return 0;
}
