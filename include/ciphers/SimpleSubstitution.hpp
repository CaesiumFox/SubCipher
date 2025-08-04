#pragma once

#include "ciphers/CipherBase.hpp"

namespace sub_cipher {
    class SimpleSubstitution: public CipherBase {
    public:
        using CipherBase::CipherBase;

        virtual ~SimpleSubstitution() = default;

        virtual void transform_encrypt(std::vector<Character>& text) const noexcept;
        virtual std::vector<Character> map_encrypt(const std::vector<Character>& text) const noexcept;
        virtual void transform_decrypt(std::vector<Character>& text) const noexcept;
        virtual std::vector<Character> map_decrypt(const std::vector<Character>& text) const noexcept;

        virtual size_t one_encrypt(size_t pos) const noexcept = 0;
        virtual size_t one_decrypt(size_t pos) const noexcept = 0;
    };
}
