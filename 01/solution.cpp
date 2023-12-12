#include <iostream>
#include <string>


using namespace std;


int get_code_line(string s) {
    int value = 0;
    int last = -1;
    for (char c: s) {
        if ((c >= '0') && (c <= '9')) {
            last = (int) (c - '0');
            if (value == 0) {
                value += last * 10;
            }
        }
    }
    cout << s << ": " << value << " " << last << endl;
    value += last;
    return value;
}


int main(int argc, char *argv[])
{
    int sum = 0;
    string s;
    while (cin >> s) {
        sum += get_code_line(s);
    }
    cout << sum << endl;
}
