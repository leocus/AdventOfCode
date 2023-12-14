#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <deque>


using namespace std;


// Let's use lists for searching the numbers - no need for fancy stuff 
int check_numbers(vector<int> winning, vector<int> mynumbers) {
    int cnt = 0;

    for (int w: winning) {
        for (int n: mynumbers) {
            if (w == n) {
                cnt++;
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

    deque<int> fringe;
    vector<vector<int>> win_ids;

    int i = 0;
    int n;

    // Process original cards
    while (getline(cin, tmp)) {
        winning = vector<int>();
        mynumbers = vector<int>();

        parse_line(tmp, winning, mynumbers);
        n = check_numbers(winning, mynumbers);

        vector<int> ids;
        for (int j = 0; j < n; j++) {
            ids.push_back(i + j + 1);
            fringe.push_back(i + j + 1);
        }
        win_ids.push_back(ids);

        sum++;
        i++;
    }

    // Process copies
    int id;
    while (fringe.size() > 0) {
        id = fringe.front();
        fringe.pop_front();
        for (int win_id: win_ids[id]) {
            fringe.push_back(win_id);
        }
        sum++; 
    }

    cout << sum << endl;
}
