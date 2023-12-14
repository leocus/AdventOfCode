#include <iostream>
#include <string>
#include <vector>
#include <sstream>


using namespace std;


// Let's use lists for searching the numbers - no need for fancy stuff 
int check_numbers(vector<int> winning, vector<int> mynumbers) {
    int cnt = 0;

    for (int w: winning) {
        for (int n: mynumbers) {
            if (w == n) {
                if (cnt == 0) {
                    cnt = 1;
                } else {
                    cnt = cnt * 2;
                }
            }
        }
    }
    return cnt;
}


void parse_line(string &s, vector<int> &winning, vector<int> &mynumbers) {
    istringstream winning_string, mynums_string;

    int start, end;
    start = s.find(": ");
    end = s.find(" | ");

    winning_string = istringstream(s.substr(start + 2, end - start - 1));
    mynums_string = istringstream(s.substr(end + 3, -1));
    string buffer;

    while (getline(winning_string, buffer, ' ')) {
        if (buffer.size() > 0) {
            winning.push_back(stod(buffer.c_str()));
        }
    }

    while (getline(mynums_string, buffer, ' ')) {
        if (buffer.size() > 0) {
            mynumbers.push_back(stof(buffer.c_str()));
        }
    }
}


int main(int argc, char *argv[])
{
    int sum;
    string tmp;
    vector<int> winning;
    vector<int> mynumbers;

    while (getline(cin, tmp)) {
        winning = vector<int>();
        mynumbers = vector<int>();

        parse_line(tmp, winning, mynumbers);
        sum += check_numbers(winning, mynumbers);
    }

    cout << sum << endl;
}
