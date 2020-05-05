#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main () {
    ifstream in_file {"myfile.txt"};
    ofstream out_file {"copied_file.txt"};

    if (!in_file || !out_file) {
        cerr << "Files incusion error or file creation error !!" << endl;
        return 1;
    }

    string line {};
    unsigned number {1};
    while (getline(in_file, line)) {
        if (line != "")
            out_file << left << setw(10) << number++ << line << endl;
        else
            out_file << endl;
    }

    cout << "Copied successfully !!" << endl;
    in_file.close();
    out_file.close();
    return 0;
}
