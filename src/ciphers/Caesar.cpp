#include "ciphers/Caesar.hpp"

using namespace sub_cipher;

Caesar::Caesar(const Alphabet& alphabet, size_t shift):
    SimpleSubstitution(alphabet),
    shift(shift)
{}
        
size_t Caesar::one_encrypt(size_t pos) const noexcept {
    size_t asize = get_alphabet().get_size();
    return (pos + shift % asize) % asize;
}

size_t Caesar::one_decrypt(size_t pos) const noexcept {
    size_t asize = get_alphabet().get_size();
    return (asize + pos - shift % asize) % asize;
}
