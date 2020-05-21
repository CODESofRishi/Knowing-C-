#include <iostream>
#include <string>
#include <deque>
#include <cctype>
#include <iomanip>
using namespace std;

bool isPalindrome(const std::string &s) {
    std::deque<char> deq1 {};
    std::deque<char> deq2 {};
    for (auto const &ch: s) {
        if (isalpha(ch)) {
            deq1.emplace_front(tolower(ch));
            deq2.emplace_back(tolower(ch));
        }
    }
    for (size_t i {}; i < deq1.size(); ++i)  {
        if (deq1.at(i) != deq2.at(i))
            return false;
    }
    return true;
}

int main () {
    for (int i {}; i < 18; ++i) {
        string s {};
        getline(cin, s);
        cout << boolalpha;
        cout << setw(10) << left << isPalindrome(s) << right << s << endl;
    }
    return 0;
}
