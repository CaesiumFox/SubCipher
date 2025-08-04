#include "Character.hpp"

using namespace sub_cipher;

Character::Character():
    Character('\0')
{}

Character::Character(char byte) {
    inside.byte = byte;
    encodable = false;
}

Character::Character(size_t position) {
    inside.position = position;
    encodable = true;
}

bool Character::is_encodable() const noexcept {
    return encodable;
}

char Character::get_byte() const noexcept {
    return encodable ? '\0' : inside.byte;
}

void Character::set_byte(char new_byte) noexcept {
    encodable = false;
    inside.byte = new_byte;
}

size_t Character::get_position() const noexcept {
    return encodable ? inside.position : 0u;
}

void Character::set_position(size_t new_pos) noexcept {
    encodable = true;
    inside.position = new_pos;
}
