#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;


vector<string> DIGITS = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};


int search(string query, string text) {
    int i = 0;
    while (i < text.length()) {
        if ((text[i] == query[0]) && (text.length() - i >= query.length())) {
            int j;
            for (j = 0; j < query.length(); j++) {
                if (text[i+j] != query[j]) {
                    break;
                }
            }
            if (j == query.length()) {
                return i;
            }
        }
        i++;
    }
    return -1;
}


int get_code_line(string s) {
    int first_value = 0;
    int second_value = 0;
    int first_index = s.length();
    int second_index = s.length();

    cout << s << endl;

    // Find the first occurrence
    for (int d_i = 0; d_i < DIGITS.size(); d_i++) {
        int txt_idx = search(DIGITS[d_i], s);
        int dig_idx = search(to_string(d_i+1), s);
        txt_idx = txt_idx >= 0 ? txt_idx : s.length() + 1;    
        dig_idx = dig_idx >= 0 ? dig_idx : s.length() + 1;    

        if (first_index > txt_idx) {
            first_index = txt_idx;
            first_value = d_i + 1;
        }
        if (first_index > dig_idx) {
            first_index = dig_idx;
            first_value = d_i + 1;
        }
    }

    // Find the second occurrence
    /* s = s.substr(first_index + 1); */
    // Reverse the string to speed up search
    reverse(s.begin(), s.end());
    for (int d_i = 0; d_i < DIGITS.size(); d_i++) {
        string cur_dig = DIGITS[d_i];
        reverse(cur_dig.begin(), cur_dig.end());
        int txt_idx = search(cur_dig, s);
        int dig_idx = search(to_string(d_i+1), s);
        txt_idx = txt_idx >= 0 ? txt_idx : s.length() + 1;    
        dig_idx = dig_idx >= 0 ? dig_idx : s.length() + 1;    

        /* cout << "Second index " << second_index << endl; */
        /* cout << "Search " << DIGITS[d_i] << "-> " << txt_idx << endl; */
        /* cout << "Search " << d_i + 1 << "-> " << dig_idx << endl; */

        if (second_index > txt_idx) {
            second_index = txt_idx;
            second_value = d_i + 1;
        }
        if (second_index > dig_idx) {
            second_index = dig_idx;
            second_value = d_i + 1;
        }
    }

    cout << first_value << " " << second_value << endl;

    return first_value * 10 + second_value;
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
