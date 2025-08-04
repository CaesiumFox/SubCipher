#pragma once

#include <vector>

#include "Alphabet.hpp"
#include "Character.hpp"

namespace sub_cipher {
    class CipherBase {
    public:
        CipherBase(const Alphabet& alphabet);
        virtual ~CipherBase() = default;
        virtual void transform_encrypt(std::vector<Character>& text) const noexcept = 0;
        virtual std::vector<Character> map_encrypt(const std::vector<Character>& text) const noexcept = 0;
        virtual void transform_decrypt(std::vector<Character>& text) const noexcept = 0;
        virtual std::vector<Character> map_decrypt(const std::vector<Character>& text) const noexcept = 0;
    protected:
        const Alphabet& get_alphabet() const;
    private:
        const Alphabet& alphabet;
    };
}
