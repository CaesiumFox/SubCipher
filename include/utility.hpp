#pragma once

#include <string_view>

/**
 * @brief Checks if sample `starts` with `target`
 * 
 */
bool starts_with(std::string_view sample, std::string_view target);
