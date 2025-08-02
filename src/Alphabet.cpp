#include "Alphabet.hpp"

using namespace sub_cipher;

Alphabet::Letter::Letter(std::string one_variant):
    variants({one_variant})
{}

Alphabet::Letter::Letter(std::initializer_list<std::string> many_variants):
    variants(many_variants)
{}

Alphabet::Letter::Letter(std::vector<std::string> many_variants):
    variants(many_variants)
{}

Alphabet::Alphabet(std::initializer_list<Letter> letters):
    letters(letters)
{}

Alphabet::Alphabet(std::vector<Letter> letters):
    letters(letters)
{}
