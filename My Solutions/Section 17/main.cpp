#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Test {
private:
    int data;

public:
    Test() :data {0} { cout<<"\tTest Constructor ("<<data<<")"<<endl; }
    Test(int data) :data {data} { cout<<"\tTest Constructor ("<<data<<")"<<endl; }
    int get_data() const { return data; }
    ~Test() { cout<<"\tTest Destructor ("<<data<<")"<<endl; }
};

// function prototype
std::unique_ptr<vector<shared_ptr<Test>>> make();
void fill(vector<shared_ptr<Test>> &vec, int num);
void display(const vector<shared_ptr<Test>> &vec);

std::unique_ptr<vector<shared_ptr<Test>>> make() {
    unique_ptr<vector<shared_ptr<Test>>> temp = make_unique<vector<shared_ptr<Test>>> ();
    return temp;
}

void fill(vector<shared_ptr<Test>> &vec, int num) {
    while (num--) {
        int value {};
        cout<<"\nEnter a number to insert: ";
        cin >> value;
        vec.emplace_back(make_shared<Test> (value));
    }
}

void display(const vector<shared_ptr<Test>> &vec) {
    cout<<"\n========================================"<<endl;
    cout<<"The number inserted into Test object are:"<<endl;
    for (auto const &val: vec)
        cout<<"\t"<<val->get_data()<<endl;
    cout<<"========================================"<<endl;
}

int main() {
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    cout<<"How many data points do you want to enter: ";
    int num {};
    cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}
