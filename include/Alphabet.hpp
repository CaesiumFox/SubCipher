#pragma once

#include <cstdint>
#include <string>
#include <vector>

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
        };

        Alphabet(std::initializer_list<Letter> letters);
        Alphabet(std::vector<Letter> letters);
    private:
        /**
         * @brief Stores a list of letters in the language
         * and their variations, i.e. "\u00F1" ("ñ") and
         * "\u006E\u0303" ("ñ")
         */
        std::vector<Letter> letters;
    };
}
