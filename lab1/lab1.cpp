#include <iostream>
#include <string>
using namespace std;

struct Pipe {
    string name;
    float lenght;
    int diametr;
    bool repair;
};

struct Kp {
    string name;
    int workshops_count;
    int workshops_working;
    string type;
};

int main()
{
    std::cout << "Hello World!\n";
}
