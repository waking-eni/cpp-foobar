#include <iostream>
#include <string>
#include <cmath>

std::string answer(std::string x, std::string y) {
    int match = stoi(x);
    int facula = stoi(y);
    int num_gen = 0;
    std::string impossible = "impossible";

    while((match != 1) || (facula != 1)) {
        if((match == 0) || (facula == 0))
           return impossible;
        if((match == 1) || (facula == 1)) {
            if(match == 1)
                num_gen += (facula - 1);
            if(facula == 1)
                num_gen += (match - 1);
            break;
        }
        if(match < facula) {
            num_gen += std::floor(facula / match);
            facula %= match;
        } else {
            num_gen += std::floor(match / facula);
            match %= facula;
        }
    }

    return std::to_string(num_gen);
}

int main()
{
    std::cout << answer("4", "7");
    return 0;
}
