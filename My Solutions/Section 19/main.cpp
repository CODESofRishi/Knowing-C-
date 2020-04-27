#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class City {
public:
    string name;
    long long population;
    double cost;
};

class Country {
public:
    string name;
    vector<City> cities;
};

class Tour {
public:
    string title;
    vector<Country> countries;
};

void ruler(const int &&len) {
    for (int i {}; i < len; ++i) {
        cout << "1234567890";
    }
    cout << endl;
}

int main () {
    Tour tour {
        "Tour ticket prices from Gangtok", {
            {"India", {
                {"Indoor", 990054, 887.32},
                {"Shilong", 78231, 994.12},
                {"Kohima", 7821, 883.13}
            }},
            {"Norway", {
                {"Oslo", 322421, 88923.44},
                {"Bergen", 892342, 9783.65},
                {"Stavanger", 82311, 4432.12}
            }},
            {"Japan",{
                {"Tokyo", 342341, 992.33},
                {"Kyoto", 23111, 8823.55},
                {"Osaka", 99332, 7821.67}
            }},
        }
    };

    ruler(8);

//    cout << tour.title << endl;
//    for (auto const &count: tour.countries) {
//        cout << count.name << endl;
//        for (auto const &cit: count.cities) {
//            cout << "\t" << setw(5) << cit.name << " " << cit.population << " " << cit.cost << endl;
//        }
//    }

    cout << setw(55) << tour.title << endl;
    cout << left;
    cout << setw(20) << "Country" << setw(20) << "City" << right << setw(20) << "Population" << setw(20) << "Price" << endl;
    cout << setfill('-') << setw(80) << "" << endl; cout << setfill(' ');
//    cout << "--------------------------------------------------------------------------------" << endl;
    for (auto const &count: tour.countries) {
        cout << left << setw(20) << count.name;
        bool first {true};
        for (auto const &cit: count.cities) {
            if (first) {
                cout << left << setw(20) << cit.name << setw(20) << right << cit.population << setw(20) << cit.cost << endl;
                first = false;
            }
            else
                cout << setw(20) << " " << left << setw(20) << cit.name << right << setw(20) << cit.population << setw(20) << cit.cost << endl;
        }
    }
    return 0;
}
