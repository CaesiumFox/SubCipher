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
        count += assert_equals(result.size(), size_t(19), "test 1 size");
        auto restored = a1.unparse(result);
        auto changed = a2.unparse(result);

        count += assert_equals(restored, std::string("This is ABACABA 404"), "test 1 restore");
        count += assert_equals(changed, std::string("This is DEDFDED 404"), "test 1 change");
    }
    {
        sub_cipher::Alphabet a1({
            {"The", "the"},
            {"A", "a"},
            {"An", "an"},
        });
        sub_cipher::Alphabet a2({
            {"1"},
            {"2"},
            {"3"},
        });

        std::string text = "Then there apricot Ananas";
        auto result = a1.parse(text);
        count += assert_equals(result.size(), size_t(19), "test 1 size");
        auto restored = a1.unparse(result);
        auto changed = a2.unparse(result);

        count += assert_equals(restored, std::string("Then There Apricot AnAnAs"), "test 1 restore");
        count += assert_equals(changed, std::string("1n 1re 2pricot 332s"), "test 1 change");

    }
    return count;
}
