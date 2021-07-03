cmake_minimum_required(VERSION 3.19)
project(Lambdas)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "\
        -O0\
        -Wall\
        -Wextra\
        -Werror\
        -fsanitize=address\
        -fsanitize=alignment\
        -fsanitize=bool\
        -fsanitize=bounds\
        -fsanitize=enum\
        -fsanitize=float-cast-overflow\
        -fsanitize=float-divide-by-zero\
        -fsanitize=integer-divide-by-zero\
        -fsanitize=leak\
        -fsanitize=nonnull-attribute\
        -fsanitize=null\
        -fsanitize=object-size\
        -fsanitize=return\
        -fsanitize=returns-nonnull-attribute\
        -fsanitize=shift\
        -fsanitize=signed-integer-overflow\
        -fsanitize=undefined\
        -fsanitize=unreachable\
        -fsanitize=vla-bound\
        -fsanitize=vptr\
        ")

add_executable(Lambdas
        main.cpp
        core/objects/lambda_term.h
        core/objects/lambda_term.cpp
        core/normalizer/normalizer.h
        )