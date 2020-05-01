#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main () {
    ifstream in_file {"resource.txt"};
    if (!in_file) {
        cerr << "File inclusion error" << endl;
        return 1;
    }

    string key {};
    in_file >> key;
    string name {}, response {};
    cout << setw(20) << left << "Students" << setw(20) << right << "Score" << endl;
    cout << setw(40) << setfill('-') << "" << endl;
    int ttl {};
    double sum {};
    while (in_file >> name >> response) {
        int points {};
        for (size_t i {}; i < key.size(); ++i) {
            if (response.at(i) == key.at(i))
                ++points;
        }
        cout << setw(20)<< setfill(' ') << left << name << setw(20) << right << points << endl;
        ++ttl;
        sum += points;
    }
    cout << setw(40) << setfill('-') << "" << endl;
    cout << setw(20) << setfill(' ') << left << "Average Score" << setw(20) << right << (ttl ? (sum/ttl): 0) << endl;
    in_file.close();
    return 0;
}
