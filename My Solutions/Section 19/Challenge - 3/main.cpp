#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main () {
	ifstream in_file {"romeo_and_juliet.txt"};
	if (!in_file) {
		cerr << "File inclusion error !!" << endl;
		return 1;
	}

	string word {};
	cout << "Enter a word to search: ";
	cin >> word;

	string fword {};
	size_t ttl {}, occ {};
	while (in_file >> fword) {
		size_t ind {fword.find(word)};
		while (ind != string::npos) {
			++occ;
			fword.at(ind) = '9';
			ind = fword.find(word);
		}
		++ttl;
	}
	cout << ttl << " words were searched..." << endl;
	cout << "The word " << word << " was matched " << occ << " times !!" << endl;
	in_file.close();
	return 0;
}
