#include "Alphabet.hpp"

#include "utility.hpp"

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

std::optional<Character> Alphabet::consume_character(std::string_view& text) const noexcept {
    if (text.empty()) {
        return std::nullopt;
    }
    
    size_t suitable = 0;
    size_t suitable_size = 0;
    for (size_t letter_index = 0; letter_index < letters.size(); letter_index++) {
        for (const auto& letter : letters[letter_index].variants) {
            size_t letter_size = letter.size();
            if (starts_with(text, letter) && letter_size > suitable_size) {
                suitable = letter_index;
                suitable_size = letter_size;
            }
        }
    }

    if (suitable_size > 0) {
        text.remove_prefix(suitable_size);
        return Character(suitable);
    }

    text.remove_prefix(1);
    return Character(text[0]);
}

std::vector<Character> Alphabet::parse(std::string_view text) const noexcept {
    std::optional<Character> current = std::nullopt;
    std::vector<Character> retval;
    while (current = consume_character(text)) {
        retval.push_back(current.value());
    }
    return retval;
}

std::string Alphabet::unparse(const std::vector<Character>& chars) const noexcept {
    std::string retval;
    for (const auto& c : chars) {
        if (c.is_encodable()) {
            size_t pos = c.get_position();
            if (pos < letters.size() && !letters[pos].variants.empty()) {
                retval += letters[pos].variants.front();
            }
        }
        else {
            retval += c.get_byte();
        }
    }
}
