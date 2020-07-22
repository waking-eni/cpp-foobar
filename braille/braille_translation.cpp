#include <iostream>
#include <map>
#include <iterator>
using std::string;
using std::map;
using std::cout;
using std::cin;
using std::endl;

string braille(string& s)
{
    map<char, string> braille_dict;
    braille_dict['a'] = "100000";
    braille_dict['b'] = "110000";
    braille_dict['c'] = "100100";
    braille_dict['d'] = "100110";
    braille_dict['e'] = "100010";
    braille_dict['f'] = "110100";
    braille_dict['g'] = "110110";
    braille_dict['h'] = "110010";
    braille_dict['i'] = "010100";
    braille_dict['j'] = "010110";
    braille_dict['k'] = "101000";
    braille_dict['l'] = "111000";
    braille_dict['m'] = "101100";
    braille_dict['n'] = "101110";
    braille_dict['o'] = "101010";
    braille_dict['p'] = "111100";
    braille_dict['q'] = "111110";
    braille_dict['r'] = "111010";
    braille_dict['s'] = "011100";
    braille_dict['t'] = "011110";
    braille_dict['u'] = "101001";
    braille_dict['v'] = "111001";
    braille_dict['w'] = "010111";
    braille_dict['x'] = "101101";
    braille_dict['y'] = "101111";
    braille_dict['z'] = "101011";
    braille_dict[' '] = "000000";

    string result("");
    map<char, string>::iterator i;
    for(std::string::iterator it = s.begin(); it != s.end(); ++it)
    {
        for(i = braille_dict.begin(); i!= braille_dict.end(); i++)
        {
            if(tolower(*it) == i->first && isupper(*it))
            {
                result.append("000001");
                result.append(i->second);
            } else if(*it == i->first)
            {
                result.append(i->second);
            }
        }
    }

    return result;

}

int main()
{
    string text;
    string result;
    cout << "Please enter your text: "<< endl;
    getline(cin, text);
    result = braille(text);
    cout << "The translation is: "<< result << endl;
    return 0;
}
