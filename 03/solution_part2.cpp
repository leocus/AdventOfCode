#include <iostream>
#include <string>
#include <vector>
#include <math.h>


using namespace std;


bool is_digit(char x) {
    return ((x >= '0') && (x <= '9'));
}


int parse_numbers(vector<vector<char>> &s) {
    int sum = 0;
    int n1, n2, tmp;
    int c, cprime;
    for (int row = 0; row < s.size(); row++) {
        for (int col = 0; col < s[0].size(); col++) {
            if (s[row][col] == '*') {
                n1 = -1;
                n2 = -1;
                for (int r = row - 1; r <= row + 1; r++) {
                    c = col - 1;
                    while (c <= col + 1) {
                        if (is_digit(s[r][c])) {
                            cprime = c;

                            // Go to the beginning
                            while (cprime > 0 && is_digit(s[r][cprime])) {
                                cprime--;
                            }
                            if (!is_digit(s[r][cprime])) {
                                // If we're at the beginning of the line
                                // we need to check if this is a number or not
                                cprime++;
                            }

                            tmp = 0;

                            while (cprime < s[0].size() && is_digit(s[r][cprime])) {
                                tmp *= 10;
                                tmp += s[r][cprime] - '0';
                                cprime++;
                            }

                            if (n1 == -1) {
                                n1 = tmp;
                            } else if (n2 == -1) {
                                n2 = tmp;
                            } else {
                                cout << "I found more than 2 numbers touching the same gear";
                                cout << "(" << row << ", " << col << ") is touching " << n1 << " and "<< n2 << endl;
                                exit(2);
                            }
                            c = cprime; 
                        }
                        c++;
                    }
                }
                if (n1 > -1) {
                    if (n2 != -1) {
                        cout << "Adding " << n1 << " * " << n2 << endl;
                        sum += n1 * n2;
                    }
                }
            }
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

    for (int row = 0; row < schematic.size(); row++) {
        for (int col = 0; col < schematic[0].size(); col++) {
            cout << schematic[row][col];
        }
        cout << endl;
    }

    int sum = parse_numbers(schematic);
    cout << sum << endl;
}

