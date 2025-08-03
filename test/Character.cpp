#include <iostream>

#include "oracles.hpp"

#include "Character.hpp"

int main() {
    int count = 0;
    {
        sub_cipher::Character c('4');
        count += assert_false(c.is_encodable(), "test 1 should not be encodable");
        count += assert_equals(c.get_byte(), '4', "test 1 should be '4'");
    }
    {
        sub_cipher::Character c('A');
        count += assert_false(c.is_encodable(), "test 2 should not be encodable");
        count += assert_equals(c.get_byte(), 'A', "test 2 should be 'A'");
    }
    {
        sub_cipher::Character c(size_t(5));
        count += assert_true(c.is_encodable(), "test 3 should be encodable");
        count += assert_equals(c.get_position(), size_t(5), "test 3 should be 5");
    }
    return count;
}
