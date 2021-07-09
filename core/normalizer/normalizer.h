#pragma once

#include "../objects/lambda_term.h"
#include "iostream"

[[nodiscard]] lambda_term& beta_reduction(lambda_term&& term);