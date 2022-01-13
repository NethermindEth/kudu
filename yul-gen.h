#pragma once

#include <string>

std::string generateYul(std::string const& main_contract,
                        std::string const& filepath);

std::string generateYulJSON(std::string const& yul,
                            std::string const& filepath);
