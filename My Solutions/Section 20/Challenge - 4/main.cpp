#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
using namespace std;

bool isPalindrome(const string &line) {
    std::stack<char> st {};  // for checking back of the string
    std::queue<char> qu {};  // for checking front of the string
    for (auto const &ch: line) {
        if (isalpha(ch)) {
            st.push(tolower(ch));
            qu.push(tolower(ch));
        }
    }

    while (!st.empty()) {
        if (st.top() ^ qu.front())
            return false;
        st.pop();
        qu.pop();
    }
    return true;
}

int main () {
    ifstream in_file {"Myfile.txt"};
    if (!in_file) {
        in_file.close();
        cerr << "File inlusion error!" << endl;
        return 1;
    }

    cout << setw(10) << left << "Result" << "Phrase" << endl;
    cout << setfill('-') << setw(19) << "-" << endl;
    cout << setfill(' ');

    string line {};
    while (getline(in_file, line)) {
        cout << boolalpha << setw(10) << isPalindrome(line) << line << endl;
    }
    in_file.close();
    return 0;
}
