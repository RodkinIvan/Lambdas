#include <string>
#include <vector>
#include <unordered_map>


struct lambda_term {

    lambda_term* left;
    lambda_term* right;

    std::vector<std::vector<lambda_term*>> vars_places;
    std::vector<std::string> vars_names;


    explicit lambda_term(const std::string& term);

private:
    void construct_from_string_expr(const std::string& expr);
};

std::unordered_map<std::string, lambda_term> identifiers;

