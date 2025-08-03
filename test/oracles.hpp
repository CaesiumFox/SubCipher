#pragma once

#include <exception>
#include <iostream>
#include <string>

#define START_ASSERT                      \
    try {
#define END_ASSERT                        \
    }                                     \
    catch (std::exception& e) {           \
        std::cerr                         \
            << "THROW: "                  \
            << e.what()                   \
            << std::endl;                 \
        return 1;                         \
    }                                     \
    catch (...) {                         \
        std::cerr                         \
            << "THROW: unknown exception" \
            << std::endl;                 \
        return 1;                         \
    }



int assert_true(bool value, std::string message) noexcept {
    START_ASSERT
    if (value) {
        return 0;
    }
    else {
        std::cerr
            << "FAIL: "
            << message
            << std::endl;
        return 1;
    }
    END_ASSERT
}

int assert_false(bool value, std::string message) noexcept {
    return assert_true(!value, message);
}

template <typename T>
int assert_equals(T actual, T expected, std::string message) noexcept {
    START_ASSERT
    return assert_true(actual == expected, message);
    END_ASSERT
}

template <typename T>
int assert_not_equals(T actual, T expected, std::string message) noexcept {
    START_ASSERT
    return assert_true(actual != expected, message);
    END_ASSERT
}

#undef START_ASSERT
#undef END_ASSERT
