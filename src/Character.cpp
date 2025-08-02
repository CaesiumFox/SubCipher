#include "Character.hpp"

using namespace sub_cipher;

Character::Character(char32_t codepoint) {
    inside.codepoint = codepoint;
    encodable = false;
}

Character::Character(uint32_t position) {
    inside.position = position;
    encodable = true;
}

bool Character::is_encodable() const noexcept {
    return encodable;
}

char32_t Character::get_codepoint() const noexcept {
    return encodable ? U'\0' : inside.codepoint;
}

uint32_t Character::get_position() const noexcept {
    return encodable ? inside.position : 0u;
}
