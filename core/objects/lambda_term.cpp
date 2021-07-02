#include "lambda_term.h"
#include <utility>
#include <iostream>

std::vector<std::string> split(const std::string& s, char c = ' ') {
    std::vector<std::string> res;
    size_t sz = s.size();
    size_t prev_c = -1;
    for (size_t i = 0; i < sz; ++i) {
        if (s[i] == c) {
            res.push_back(
                    s.substr(prev_c + 1, i - prev_c - 1)
            );
            prev_c = i;
        }
    }
    res.push_back(
            s.substr(prev_c + 1, sz - prev_c - 1)
    );
    return std::move(res);
}

std::vector<size_t> find_all(const std::string& s, const std::string& substr) { /// make KMP ///
    std::vector<size_t> res;
    size_t sz = s.size();
    size_t sub_sz = substr.size();
    if (s[0] != ' ') {
        std::cerr << "find_all should start with \' \' (space)";
    }
    for (size_t i = 0; i < sz - sub_sz + 1; ++i) {
        if (s[i] == substr[0]
            && (s[i - 1] == ' '
                    && (i + sub_sz == sz
                        || s[i + sub_sz] == ' '))
            && s.substr(i, sub_sz) == substr) {
            res.push_back(i);
        }
    }
    return res;
}


lambda_term::lambda_term(const std::string& s) : term(s) {
    if (s.substr(0, 7) != "lambda ") {
        std::cout << "Term should start with \"lambda \" word";
        return;
    }
    std::string variables = s.substr(7, s.find('.') - 7);

    vars_names = split(variables);
    size_t vars_num = vars_names.size();
    size_t term_sz = term.size();
    term.erase(term.begin(), term.begin() + s.find('.') + 1);
    vars_places.resize(vars_num);
    size_t iter = 0;
    for (auto& var : vars_names) {
        vars_places[iter++] = find_all(term, var);
    }
}
