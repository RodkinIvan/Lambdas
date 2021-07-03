cmake_minimum_required(VERSION 3.19)
project(Lambdas)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS -O0)

add_executable(Lambdas
        main.cpp
        core/objects/lambda_expression.h
        core/objects/lambda_term.h
        core/objects/lambda_term.cpp
        core/normalizer/normalizer.h
        )