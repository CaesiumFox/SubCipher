#include "Character.hpp"

using namespace sub_cipher;

Character::Character(char byte) {
    inside.byte = byte;
    encodable = false;
}

Character::Character(uint32_t position) {
    inside.position = position;
    encodable = true;
}

bool Character::is_encodable() const noexcept {
    return encodable;
}

char Character::get_byte() const noexcept {
    return encodable ? '\0' : inside.byte;
}

size_t Character::get_position() const noexcept {
    return encodable ? inside.position : 0u;
}
