#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

int solution(int total_lambs)
{
    if(total_lambs >= std::pow(10, 9) )
        return 0;
    std::vector<int> generous_list;
    std::vector<int> stingy_list{1, 1};
    int x = 0, running_total = 0, fib_running_total = 2, y = 2;

    while(x <= total_lambs) {
        int current_value = std::pow(2, x);
        generous_list.push_back(current_value);
        running_total += current_value;

        if(running_total > total_lambs)
            break;

        x++;
    }

    while(y <= total_lambs) {
        int current_value = stingy_list.at(y - 1) + stingy_list.at(y - 2);
        stingy_list.push_back(current_value);
        fib_running_total += stingy_list.at(y);

        if(fib_running_total > total_lambs)
            break;
        y++;
    }

    return std::abs(stingy_list.size() - generous_list.size());
}

int main()
{
    std::cout << solution(143);
}
