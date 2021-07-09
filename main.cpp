#include <iostream>
#include "core/normalizer/normalizer.h"


void creating_test() {
    auto three = lambda_term("lambda f x. f(f (f x))");
    auto exp = lambda_term("lambda a b. b a");
    auto inc = lambda_term("lambda n f x. f (n f x)");
    std::cout << "////////////////////////////////////\n"
                 "/////// Creating test passed ///////\n"
                 "////////////////////////////////////\n";
};

void copying_and_moving_test() {
    auto three = lambda_term("lambda f x. f (f (f x))");
    auto exp = lambda_term("lambda a b. b a");
    auto inc = lambda_term("lambda n f x. f (n f x)");
    auto exp_cp = exp;
    auto inc_mv = std::move(inc);
    auto equal = lambda_term("x");
    equal = three;
    std::cout << "////////////////////////////////////\n"
                 "// Copying and moving test passed //\n"
                 "////////////////////////////////////\n";
}

void beta_reduction_test() {
    auto four = lambda_term("(lambda f x. f (f x))(lambda f x. f (f x))");
    auto four_br = beta_reduction(std::move(four));
}

int main() {
    //creating_test();
    //copying_and_moving_test();
    beta_reduction_test();
    return 0;
}
