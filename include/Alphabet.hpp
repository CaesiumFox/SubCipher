#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

#include "Character.hpp"

namespace sub_cipher {
    class Alphabet {
    public:
        class Letter {
        public:
            Letter(std::string one_variant);
            Letter(std::initializer_list<std::string> many_variants);
            Letter(std::vector<std::string> many_variants);
        private:
            std::vector<std::string> variants;
            friend class Alphabet;
        };

        Alphabet(std::initializer_list<Letter> letters);
        Alphabet(std::vector<Letter> letters);

        std::optional<Character> consume_character(std::string_view& text) const noexcept;
        std::vector<Character> parse(std::string_view text) const noexcept;
        std::string unparse(const std::vector<Character>& chars) const noexcept;

    private:
        /**
         * @brief Stores a list of letters in the language
         * and their variations, i.e. "\u00F1" ("ñ") and
         * "\u006E\u0303" ("ñ")
         */
        std::vector<Letter> letters;
    };
}
