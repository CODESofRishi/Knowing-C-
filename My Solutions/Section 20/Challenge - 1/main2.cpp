#include <iostream>
#include <string>
#include <deque>
#include <cctype>
#include <iomanip>
#include <algorithm>
using namespace std;

bool isPalindrome(const std::string &s) {
    std::deque<char> deq {};
    copy_if(s.begin(), s.end(), front_inserter(deq), [](const char &ch) {
        return isalpha(ch);
    });
    while (!deq.empty()) {
        if (tolower(deq.front()) != tolower(deq.back()))
            return false;
        deq.pop_front();
        if (!deq.empty())
            deq.pop_back();
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
