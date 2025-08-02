#pragma once

#include <cstdint>

namespace sub_cipher {
    class Character {
    public:
        Character(char byte);
        explicit Character(uint32_t position);

        bool is_encodable() const noexcept;
        char get_byte() const noexcept;
        uint32_t get_position() const noexcept;
    private:
        union {
            // a utf-8 byte
            char byte;
            uint32_t position;
        } inside;
        bool encodable;
    };
}
