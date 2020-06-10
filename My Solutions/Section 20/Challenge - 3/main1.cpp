// part -  1
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int main () {
    ifstream in_file {"TheWonderfulWizardOfOz - The Cyclone.txt"};
    if (!in_file) {
        in_file.close();
        cerr << "File inclusion error!" << endl;
        return 1;
    }

    string word;
    map<string, size_t> mp {};
    while (in_file >> word) {
        if (!isalpha(word.back())) word.pop_back();
        ++mp[word];
    }

    cout << setw(20) << left << "Word" << "Occurences" << endl;
    cout << setfill ('=') << setw(39) << "=" << endl;
    cout << setfill(' ');

    for (auto const &val: mp) {
        cout << setw(20) << left << val.first << val.second << endl;
    }

    in_file.close();
    return 0;
}
