#include <iostream>
#include <string>
#include <vector>
#include <math.h>


using namespace std;


bool is_symbol(char x) {
    bool outcome = (
        (!((x >= '0') && (x <= '9'))) &&
        (!(x == '.'))
    );
    return outcome;
}


void filter(vector<vector<char>> &s) {
    // Remove the items of the schematic that are not adjacent to a symbol
    int start;
    bool flag;
    for (int row = 0; row < s.size(); row++) {
        start = 0;
        flag = false;
        for (int col = 0; col < s[0].size(); col++) {
            if ((s[row][col] >= '0') && (s[row][col] <= '9')) {
                // Check in all the directions
                for (int row_off = -1; row_off < 2; row_off++) {
                    for (int col_off = -1; col_off < 2; col_off++) {
                        if (!flag) {
                            if ((0 <= row + row_off && row + row_off < s.size()) && (0 <= col + col_off && col + col_off < s[0].size())) {
                                flag = (is_symbol(s[row + row_off][col + col_off]));
                            }
                        }
                    }
                }
            } else {
                // Remove all the numbers between start and the cur idx
                if (!flag) {
                    for (int i = start; i < col; i++) {
                        s[row][i] = '.'; 
                    }
                }
                start = col+1;
                flag = false;
            }
        }
        if (!flag) {
            for (int i = start; i < s[0].size(); i++) {
                s[row][i] = '.'; 
            }
        }
    }
}


int parse_numbers(vector<vector<char>> &s) {
    int sum = 0;
    int n;
    int digits;
    for (int row = 0; row < s.size(); row++) {
        n = 0;
        digits = 0;
        for (int col = 0; col < s[0].size(); col++) {
            if ((s[row][col] >= '0') && (s[row][col] <= '9')) {
                n = n * 10;
                n += (s[row][col] - '0');
                digits++;
            } else {
                sum += n;
                n = 0;
                digits = 0;
            }
        }
        if (n != 0) {
            sum += n;
        }
    }
    return sum;
}


int main(int argc, char *argv[])
{
    // Fill the schematics
    vector<vector<char>> schematic;
    string tmp;
    while (getline(cin, tmp)) {
        vector<char> row;
        for (char x: tmp) {
            row.push_back(x);
        }
        schematic.push_back(row);
    }

    // Filter the numbers
    filter(schematic);

    for (int row = 0; row < schematic.size(); row++) {
        for (int col = 0; col < schematic[0].size(); col++) {
            cout << schematic[row][col];
        }
        cout << endl;
    }

    int sum = parse_numbers(schematic);
    cout << sum << endl;
}

