#pragma once

#include <string>
#include <vector>
#include <unordered_map>


struct lambda_term {

    std::string expression;

    std::vector<std::vector<lambda_term*>> vars_places;
    std::vector<std::string> vars_names;

    lambda_term* left = nullptr;
    lambda_term* right = nullptr;

    lambda_term* parent = nullptr;


    explicit lambda_term(const std::string& term);

    lambda_term(const lambda_term& other);

    lambda_term(lambda_term&& other) noexcept ;

    lambda_term& operator=(lambda_term&& other) noexcept;

    ~lambda_term();

    lambda_term& operator=(const lambda_term& other);

private:
    void construct_from_string_expr(const std::string& expr);

    void set_vars_places(lambda_term* term, lambda_term* parent = nullptr);
};

// std::unordered_map<std::string, lambda_term> identifiers;
