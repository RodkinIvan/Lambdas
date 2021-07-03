#include "lambda_term.h"
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
    return res;
}

size_t find_open_bracket(const std::string s) {
    if (*(s.end() - 1) != ')') {
        std::cerr << "end char is not a bracket" << '\n';
        return 0;
    }
    size_t end = s.size();
    --end;
    int count_closed = 0;
    while (count_closed != -1 && end != 0) {
        if (s[end - 1] == '(') {
            count_closed -= 1;
        } else if (s[end - 1] == ')') {
            count_closed += 1;
        }
        --end;
    }
    if (count_closed != -1) {
        std::cerr << "there is no open bracket" << '\n';
        return 0;
    }
    return end;
}

/*std::vector<size_t> find_all(const std::string& s, const std::string& substr) { /// make KMP ///
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
}*/


lambda_term::lambda_term(const std::string& s) {
    if (s.substr(0, 7) != "lambda ") {
        construct_from_string_expr(s);
        return;
    }

    vars_names = split(
            s.substr(7, s.find('.') - 7)
    );

    construct_from_string_expr(
            s.substr(s.find('.') + 1, s.size())
    );
}

void lambda_term::construct_from_string_expr(const std::string& expr) {
    size_t sz = expr.size();
    size_t begin = 0;
    size_t end = sz;
    while (expr[begin] == ' ') {
        ++begin;
    }
    while (expr[end - 1] == ' ') {
        --end;
    }
    if (expr[end - 1] == ')') {
        size_t open = find_open_bracket(
                expr.substr(begin, end - begin)
        );
        if(open == 0){
            construct_from_string_expr(expr.substr(begin + 1, end - begin - 2));
            return;
        }
        right = new lambda_term(
                expr.substr(
                        begin + open + 1, end - open - begin - 2
                )
        );
        left = new lambda_term(
                expr.substr(
                        begin, open
                )
        );
    } else {
        size_t subterm_name_start = end - 1;
        while (
                subterm_name_start != -1 &&
                expr[subterm_name_start] != ' ' &&
                expr[subterm_name_start] != ')'
                ) {
            --subterm_name_start;
        }
        ++subterm_name_start;
        if (subterm_name_start != begin) {
            right = new lambda_term(
                    expr.substr(
                            subterm_name_start, end - subterm_name_start
                    )
            );
            left = new lambda_term(
                    expr.substr(
                            0, subterm_name_start
                    )
            );
        }
    }
}
