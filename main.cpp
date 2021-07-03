#include <iostream>
#include "core/objects/lambda_term.h"

void creating_test() {
    auto three = lambda_term("lambda f x. f(f (f x))");
    auto exp = lambda_term("lambda a b. b a");
    auto inc = lambda_term("lambda n f x. f (n f x)");
    auto inc_cp = std::move(inc);
    std::cout << "////////////////////////////////////\n"
                 "/////// Creating test passed ///////\n"
                 "////////////////////////////////////\n";
};

int main() {
    creating_test();
    return 0;
}
