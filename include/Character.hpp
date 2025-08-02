#pragma once

#include <cstdint>

namespace sub_cipher {
    class Character {
    public:
        Character(char32_t codepoint);
        explicit Character(uint32_t position);

        bool is_encodable() const noexcept;
        char32_t get_codepoint() const noexcept;
        uint32_t get_position() const noexcept;
    private:
        union {
            char32_t codepoint;
            uint32_t position;
        } inside;
        bool encodable;
    };
}
