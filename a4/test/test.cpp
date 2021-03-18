#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
int main() {
    string s = "hello";
    string output;
    stringstream ss;
    ss.str(s);
    ss >> output;
    cout << output << endl;

    return 0;
}
