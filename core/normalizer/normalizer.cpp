#include "normalizer.h"

void copy_lambda_params(lambda_term* from, lambda_term* place) {
    place->expression = from->expression;
    place->vars_places = from->vars_places;
    place->vars_names = from->vars_names;
    place->left = new lambda_term(*from->left);
    place->right = new lambda_term(*from->right);
}

lambda_term& beta_reduction(lambda_term&& term) {
    if (term.left->vars_names.empty()) {
        std::cerr << "Impossible to do beta-reduction for " << term.expression << '\n';
        return term;
    }
    auto places = term.left->vars_places[0];
    for (auto& place : places) {
        copy_lambda_params(term.right, place);
    }
    auto tmp = term.left;
    tmp->parent = term.parent;
    if (term.parent) {
        if (term.parent->left == &term) {
            term.parent->left = tmp;
        } else {
            term.parent->right = tmp;
        }
    }
    term.left = nullptr;
    tmp->vars_names.pop_front();
    tmp->vars_places.pop_front();
    return *tmp;
}
