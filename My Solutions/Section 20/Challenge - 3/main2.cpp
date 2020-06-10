// Part - 2
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>
#include <fstream>
#include <iomanip>
using namespace std;

int main () {
    ifstream in_file {"TheWonderfulWizardOfOz - The Cyclone.txt"};
    if (!in_file) {
        in_file.close();
        cerr << "File inclusion error!" << endl;
        return 1;
    }

    map<string, set<int>> mp {};
    string line {};
    for (int i {1}; getline(in_file, line); ++i) {
        line += ' ';
        string word {};
        for (size_t j {}; j < line.size(); ++j) {
            if (line.at(j) == ' ' &&  !word.empty()) {
                mp[word].emplace(i);
                word.clear();
            }
            else {
                word += line.at(j);
                if (!isalpha(word.back()))
                    word.pop_back();
            }
        }
    }

    cout << setw(10) << left << "Word" << "Lines" << endl;
    cout << setfill('-') << setw(19) << "-" << endl;
    cout << setfill(' ');

    for (auto const &val: mp) {
        cout << setw(10) << val.first << " [ ";
        for (auto const &st: val.second) cout << st << " ";
        cout << "]" << endl;
    }

    in_file.close();
    return 0;
}
