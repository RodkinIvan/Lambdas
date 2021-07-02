#include <string>
#include <vector>
#include <unordered_map>


struct lambda_term{
    std::string term;
    std::vector<std::vector<size_t>> vars_places;
    std::vector<std::string> vars_names;


    explicit lambda_term(const std::string& term);
};