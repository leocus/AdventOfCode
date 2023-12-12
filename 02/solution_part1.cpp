#include <iostream>
#include <string>
#include <vector>
#include <math.h>


using namespace std;


int get_number(string s, int index) {
    int number = 0;
    for (int i = index; i > 0; i--) {
        /* cout << i << endl; */
        if ((s[i] >= '0') && (s[i] <= '9')) {
            number += (int) (s[i] - '0') * pow(10, (index - i));
        } else {
            break;
        }
    }
    /* cout << "N: " << number << endl; */
    return number;
}


void parse_string(string s, int& r, int&g, int&b) {
    r = 0;
    g = 0;
    b = 0;
    
    int n = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if ((s[i+1] == 'r') || (s[i+1] == 'g') || (s[i+1] == 'b')) {
                n = get_number(s, i - 1);
                switch (s[i+1]) {
                    case 'r':
                        r = r < n ? n : r;
                        break;
                    case 'g':
                        g = g < n ? n : g;
                        break;
                    case 'b':
                        b = b < n ? n : b;
                        break;
                    default:
                        break;
                }
            }
        }
    }
}


int check_run(string s) {
    int r, g, b = 0;
    parse_string(s, r, g, b);

    cout << s << "-> " << r << " " << g << " " << b << endl;

    if ((r <= 12) && (g <= 13) && (b <= 14)) {
        int n_beg = s.find(' ');
        int n_end = s.find(':');
        return stoi(s.substr(n_beg, n_end));
    }
    return 0;
}


int main(int argc, char *argv[])
{
    string tmp;
    int sum = 0;
    while (getline(cin, tmp)) {
        cout << tmp << endl;
        sum += check_run(tmp);
    }
    cout << sum << endl;
}
