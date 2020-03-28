//Copyright 2020 Kidinova Daria daria.kidinova@gmail.com

#include <cstring>
#include <iostream>
#include "string.hpp"

String::~String() {
    delete[] Data;
}

String::String() : Data(nullptr), Len(-1) {}

String::String(const String &rhs) {
    Len = rhs.Len;
    if (rhs.Data != nullptr) {
        Data = new char[strlen(rhs.Data) + 1];
        std::copy(rhs.Data, rhs.Data + strlen(rhs.Data), Data);
    }
}

String::String(const char *data) {
    Len = strlen(data);
    if (data != nullptr) {
        Data = new char[strlen(data) + 1];
        std::copy(data, data + strlen(data), Data);
    }
}

String &String::operator=(const String &rhs) {
    if (&rhs != this) {
        Len = rhs.Len;
        if (rhs.Data != nullptr) {
            Data = new char[strlen(rhs.Data) + 1];
            std::copy(rhs.Data, rhs.Data + strlen(rhs.Data), Data);
        }
    }
    return *this;
}

String &String::operator+=(const String &rhs) {
    Len += rhs.Len;
    char *temp = new char[Len];
    std::copy(Data, Data + strlen(Data), temp);
    strcat(temp, rhs.Data);
    Data = new char[Len];
    std::copy(temp, temp + strlen(temp), Data);
    delete[] temp;
    return *this;
}

String &String::operator*=(unsigned int m) {
    Len *= m;
    char *temp = new char[Len];
    for (unsigned int i = 0; i < m; ++i) {
        strcat(temp, Data);
    }
    Data = new char[Len];
    std::copy(temp, temp + strlen(temp), Data);
    delete[] temp;
    return *this;
}

bool String::operator==(const String &rhs) const {
    if (Len != rhs.Len) {
        return false;
    } else {
        return strcmp(Data, rhs.Data) == 0;
    }
}

bool String::operator<(const String &rhs) const {
    if (Len != rhs.Len) {
        return Len < rhs.Len;
    } else {
        return strcmp(Data, rhs.Data) < 0;
    }
}

int String::Find(const String &substr) const {
    int i = 0, answ = -1;
    for (auto it = Data; it <= Data + Len; ++i, ++it) {
        answ = i;
        auto it_sub = substr.Data;
        for (; it_sub < substr.Data + substr.Len; ++i, ++it, ++it_sub) {
            if (*it == *it_sub) {
                continue;
            } else {
                if (it_sub != substr.Data) {
                    --i;
                    --it;
                }
                break;
            }
        }
        if (it_sub == substr.Data + substr.Len) {
            return answ;
        } else {
            answ = -1;
        }
    }
    return -1;
}

void String::Replace(char oldSymbol, char newSymbol) {
    for (auto it = Data; it != Data + Len; ++it) {
        if (*it == oldSymbol) {
            *it = newSymbol;
        }
    }
}

size_t String::Size() const {
    return Len;
}

bool String::Empty() const {
    return Len == 0 && strlen(Data) == 0;
}

char String::operator[](size_t index) const {
    int ind = static_cast<int>(index);
    if (ind <= Len) {
        auto iter = Data + ind;
        return *iter;
    } else {
        return 0;
    }
}

char &String::operator[](size_t index) {
    int ind = static_cast<int>(index);
    if (ind <= Len) {
        auto &iter = *(Data + ind);
        return iter;
    } else {
        return *(Data + Len);
    }
}

void String::RTrim(char symbol) {
    auto iter = Data + Len - 1;
    while (*iter == symbol) {
        *iter = '\0';
        --iter;
        --Len;
    }
}

void String::LTrim(char symbol) {
    auto iter = Data;
    while (*iter == symbol && iter < Data + Len) {
        for (auto prev = Data, next = Data + 1;
        next < Data + Len; ++prev, ++next) {
            *prev = *next;
        }
        auto last = Data + Len - 1;
        *last = '\0';
        --Len;
    }
}

void String::Swap(String &oth) {
    char *temp = new char[oth.Len];
    std::copy(oth.Data, oth.Data + oth.Len, temp);
    delete[] oth.Data;
    oth.Len = Len;
    oth.Data = new char[Len];
    std::copy(Data, Data + Len, oth.Data);
    delete[] Data;
    Len = strlen(temp);
    Data = new char[Len];
    std::copy(temp, temp + Len, Data);
    delete[] temp;
}

String operator+(const String &a, const String &b) {
    String c = a;
    c += b;
    return c;
}

String operator*(const String &a, unsigned int b) {
    String c = a;
    c *= b;
    return c;
}

bool operator!=(const String &a, const String &b) {
    return a == b ? false : true;
}

bool operator>(const String &a, const String &b) {
    return a < b ? false : true;
}

/// Оператор вывода
/// <param name="out">Поток куда выводим строку </param>
/// <param name="str">Строка, которую выводим </param>
/// <returns>Возвращаем ссылку на поток</returns>
std::ostream &operator<<(std::ostream &out, const String &str) {
    for (auto iter = str.Data; iter != str.Data + str.Len; ++iter) {
        out << *iter;
    }
    return out;
}
