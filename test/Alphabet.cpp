#include <iostream>

#include "oracles.hpp"

#include "Alphabet.hpp"

int main() {
    int count = 0;
    {
        sub_cipher::Alphabet a1({
            {"A", "a"},
            {"B", "b"},
            {"C", "c"},
        });
        sub_cipher::Alphabet a2({
            {"D", "d"},
            {"E", "e"},
            {"F", "f"},
        });

        std::string text = "This is abAcaBa 404";
        auto result = a1.parse(text);
        auto restored = a1.unparse(result);
        auto changed = a2.unparse(result);

        count += assert_equals(restored, std::string("This is ABACABA 404"), "test 1 restore");
        count += assert_equals(changed, std::string("This is DEDFDED 404"), "test 1 change");
    }
    return count;
}
