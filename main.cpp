#include <iostream>
#include "core/objects/lambda_term.h"

void creating_test() {
    auto three = lambda_term("lambda f x. f (f (f x))");
    auto exp = lambda_term("lambda a b. b a");
    std::cout << "////////////////////////////////////\n"
                 "/////// Creating test passed ///////\n"
                 "////////////////////////////////////\n";
};

int main() {
    creating_test();
    return 0;
}
