#include "txtformat.h"
#include <iostream>
#include <vector>
#include <string>
#include <numeric>

namespace {
    // Given a vector of strings, return a single string that is space seperated
    auto combine_strings(std::vector<std::string> const& input_strings) -> std::string {
        auto space_fold = [](std::string a, std::string b) {
                            return std::move(a) + ' ' + b;
                        };
        auto new_string = std::accumulate(std::next(input_strings.begin())
                                          , input_strings.end()
                                          , input_strings.at(0)
                                          , space_fold);
        std::cout << new_string.size() << "\n";
        return new_string;
    }
}

namespace txtformat {
    auto format(std::vector<std::string> const& input_strings, int size) -> std::vector<std::string> {
        auto temp_vec = std::vector<std::vector<std::string>>{};
        auto curr_line_size = 0;
        auto curr_line = std::vector<std::string>{};

        for (auto const& word : input_strings) {
            if (curr_line_size + word.size() + curr_line.size() - 1 >= size) {
                // If adding new word and all space required for current line results in exceeding, go to new line
                // curr_line.size() - 1 refers to the spaces between each word
                temp_vec.push_back(curr_line);
                curr_line = std::vector<std::string>{};
                curr_line.push_back(word);
                curr_line_size = word.size();
            } else {
                curr_line_size += word.size();
                curr_line.push_back(word);
            }
        }
        
        if (curr_line.size() != 0) {
            temp_vec.push_back(curr_line);
        }

        auto res =  std::vector<std::string>{};
        for (auto const& line : temp_vec) {
            auto line_str = combine_strings(line);
            res.push_back(line_str);
        }

        return res;
    }
}

