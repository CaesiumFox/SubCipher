#include "utility.hpp"

bool sub_cipher::starts_with(std::string_view sample, std::string_view target) {
    if (target.size() > sample.size()) {
        return false;
    }

    for (size_t i = 0; i < target.size(); i++) {
        if (target[i] != sample[i]) {
            return false;
        }
    }

    return true;
}
