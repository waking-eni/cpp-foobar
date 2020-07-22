#include <iostream>
#include <cmath>
using std::string;
using std::cout;
using std::cin;

string backToOriginBase(int number, int base)
{
    string convNum = "";
    while(number > 0)
    {
        convNum = convNum.append(std::to_string(number % base));
        number /= base;
    }
    return convNum;
}

int convertToBaseTen(int number, int base)
{
    int power = 0;
    int convNum = 0;
    string string_number = std::to_string(number);
    for(std::string::iterator it = string_number.end(); it != string_number.begin(); it--)
    {
        convNum += pow(base, power) + *it;
        power += 1;
    }
    return convNum;
}

string getSubZ(int x, int y, int b)
{
    if(b == 10)
    {
        return std::to_string(x - y);
    }

    int baseTenX = convertToBaseTen(x, b);
    int baseTenY = convertToBaseTen(y, b);
    int baseTenZ = baseTenX - baseTenY;
    return backToOriginBase(baseTenZ, b);
}

int main()
{
    int x;
    int y;
    int base;

    cout << "Please enter the first number: " << std::endl;
    cin >> x;
    cout << "Please enter the second number: " << std::endl;
    cin >> y;
    cout << "Please enter the base: " << std::endl;
    cin >> base;
    string result = getSubZ(x, y, base);
    cout << "The result is: " << result << std::endl;
}
