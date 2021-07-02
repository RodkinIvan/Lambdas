#include "lambda_term.h"


std::unordered_map<std::string, lambda_term> identificators;

struct lambda_expression{
private:
    lambda_expression* left;
    lambda_expression* right;
public:
    lambda_expression(const lambda_term& term);
};