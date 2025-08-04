#include "ciphers/SimpleSubstitution.hpp"

using namespace sub_cipher;

void SimpleSubstitution::transform_encrypt(std::vector<Character>& text) const noexcept {
    for (Character& c : text) {
        if (c.is_encodable()) {
            c.set_position(one_encrypt(c.get_position()));
        }
    }
}

std::vector<Character> SimpleSubstitution::map_encrypt(const std::vector<Character>& text) const noexcept {
    std::vector<Character> retval(text);
    transform_encrypt(retval);
    return std::move(retval);
}

void SimpleSubstitution::transform_decrypt(std::vector<Character>& text) const noexcept {
    for (Character& c : text) {
        if (c.is_encodable()) {
            c.set_position(one_decrypt(c.get_position()));
        }
    }
}

std::vector<Character> SimpleSubstitution::map_decrypt(const std::vector<Character>& text) const noexcept {
    std::vector<Character> retval(text);
    transform_decrypt(retval);
    return std::move(retval);
}
