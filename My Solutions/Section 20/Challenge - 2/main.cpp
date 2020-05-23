#include <iostream>
#include <list>
#include <iomanip>
#include <string>
using namespace std;

class Songs {
    friend ostream& operator<<(ostream &os, const Songs &rhs);
    friend bool operator<(const Songs &lhs, const Songs &rhs);
    friend bool operator==(const Songs &lhs, const Songs &rhs);
    string name;
    string artist;
    int rating;

public:
    Songs() = default;
    Songs(const string &name = "None", const string &artist = "None", const int &rating = 0);

    string getName() const { return name; }
    string getArtist() const { return artist; }
    int getRating() const { return rating; }
};

Songs::Songs(const string &name, const string &artist, const int &rating)
    :name {name}, artist {artist}, rating {rating} {};

ostream& operator<<(ostream &os, const Songs &rhs) {
    os << setw(25) << left << rhs.name << setw(25) << right << rhs.artist << setw(10) << right << rhs.rating;
    return os;
}

bool operator<(const Songs &lhs, const Songs &rhs) { return lhs.name < rhs.name; }
bool operator==(const Songs &lhs, const Songs &rhs) { return lhs.name == rhs.name; }

// ------------------------------------------------------------------------------------

void DisplayMenu() {
    cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "\n=====================================Menu============================================" << endl;
    cout << "F - Play First Song" << endl;
    cout << "N - Play Next Song" << endl;
    cout << "P - Play previous Song" << endl;
    cout << "A - Add & Play A New Song At Current Location" << endl;
    cout << "R - Remove Current Song" << endl;
    cout << "L - List The Current Playlist" << endl;
    cout << "=======================================================================================" << endl;
}

void PlayCurrentSong(std::list<Songs>::iterator &current_song) {
    cout << "<< Playing Song: " << *current_song << " >>" << endl << endl;
}

void DisplayPlaylist(const std::list<Songs> &playlist) {
    cout << "\n=====================================PLAYLIST========================================" << endl;
    for (auto const &song: playlist)
        cout << song << endl;
    cout << "\n=====================================================================================" << endl << endl;
}

int main () {
    std::list<Songs> playlist {
        {"God's Plan", "Drake", 5},
        {"Never Be The Same", "Camila Cabella", 5},
        {"Pray For Me ", "The Weekend & K. Lamar", 4},
        {"The Middle", "Zedd, Maren Morris & Grey", 5},
        {"Wait", "Maroon 5", 4},
        {"Whatever It Takes", "Imagine Dragons", 3}
    };

    std::list<Songs>::iterator current_song {playlist.begin()};
    DisplayPlaylist(playlist);
    PlayCurrentSong(current_song);

    char option {};
    do {
        DisplayMenu();

        if (playlist.empty()) {
        	cout << "!! Playlist is empty !!" << endl;
        	option = 'a';
        	cout << "Add a Song!" << endl;
        }

        cout << "Choose an option (Q to quit): ";
        cin >> option;
        switch (option) {
            case 'F':
            case 'f': {
                current_song = playlist.begin();
                PlayCurrentSong(current_song);
                break;
            }
            case 'N':
            case 'n': {
                ++current_song;
                if (current_song == playlist.end())
                    current_song = playlist.begin();
                PlayCurrentSong(current_song);
                break;
            }
            case 'P':
            case 'p': {
                if (current_song == playlist.begin())
                    current_song = --playlist.end();
                else --current_song;
                PlayCurrentSong(current_song);
                break;
            }
            case 'A':
            case 'a': {
                string new_song {};
                string new_artist {};
                int new_rating {};

                cin.ignore();
                cout << "\nName of the song: ";
                getline(cin, new_song);
                cout << "Name of the artist: ";
                getline(cin, new_artist);
                cout << "Rate the song (1 - 5): ";
                cin >> new_rating;

                playlist.emplace(current_song, new_song, new_artist, new_rating);
                --current_song;
                cout << endl;
                PlayCurrentSong(current_song);
                break;
            }
            case 'R':
            case 'r': {
                auto curr_song {current_song};
                if (current_song == playlist.end())
                    current_song = playlist.begin();
                else ++current_song;
                playlist.erase(curr_song);
                cout << "\nERASED: " << *curr_song << endl;
                PlayCurrentSong(current_song);
                break;
            }
            case 'L':
            case 'l': {
                DisplayPlaylist(playlist);
                PlayCurrentSong(current_song);
                break;
            }
            case 'Q':
            case 'q': break;
            default: cout << "WRONG OPTION: Please enter a valid option!" << endl; break;
        }
    } while (option != 'q' && option != 'Q');
    return 0;
}
