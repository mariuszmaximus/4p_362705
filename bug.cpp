#include "bug.h"
#include <iostream>  // std::cout

void Config::bug()
{
    nlohmann::json j2; 
    j2["name"] = "Niels"; // to powoduje ze projekt się nie kompiluje
    std::cout << j2.dump() << '\n';
}
