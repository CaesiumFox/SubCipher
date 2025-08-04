#pragma once

#include "ciphers/SimpleSubstitution.hpp"

namespace sub_cipher {
    class Caesar: public SimpleSubstitution {
    public:
        Caesar(const Alphabet& alphabet, size_t shift);
        
        virtual size_t one_encrypt(size_t pos) const noexcept;
        virtual size_t one_decrypt(size_t pos) const noexcept;
    private:
        size_t shift;
    };
}
