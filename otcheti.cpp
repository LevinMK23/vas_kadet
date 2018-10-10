#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct Pupil{
    string name, sername, fathername;
    vector<int> marks;

    double avg = 0;
    int c5 = 0, c2 = 0;
    int sum = 0, c = 0;
    
    void calculate(){
        for(auto i : marks){
            sum += i;
            c++;
            if(i == 2)c2++;
            if(i == 5)c5++;
        }
        avg = (double)sum / c;
    }
};

struct Class{
    string name;
    vector<Pupil> pupils;
    void sort(){
        
    }
};

struct School{
    string name;
    map<string, Class> classes;
};

int main() {
    int n;
    cin >> n;
    map<string, School> schools;
    
    return 0;
}
