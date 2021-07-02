#include <iostream>
#include "core/objects/lambda_expression.h"

int main() {
    auto l = lambda_term("lambda f x. f f x");
    return 0;
}
