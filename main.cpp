#include <iostream>
#include <string>
using namespace std;

int size_n, num, hor = 0, ver = 0;
string number;

void printHor(int hor) {
    for (int n = 0; n < num; ++n) {
        cout << " ";
        if (number[n] == '1' ||
            (number[n] == '0' && hor == 1) ||
            (number[n] == '4' && (hor == 0 || hor == 2)) ||
            (number[n] == '7' && (hor == 1 || hor == 2)) )
            for (int i = 0; i < size_n; ++i) cout << " ";
        else
            for (int i = 0; i < size_n; ++i) cout << "-";
        cout << " ";
        if (n < num-1) cout << " ";
    }
    cout << endl;
}
void printVer(int ver) {
    for (int n = 0; n < num; ++n) {
        if (number[n] == '1' || number[n] == '7' ||
           ((number[n] == '2' || number[n] == '3') && ver == 0) ||
           (ver == 1 && (number[n] == '4' || number[n] == '5' ||
            number[n] == '3' || number[n] == '9')) )
            cout << " ";
        else cout << "|";
        for (int i = 0; i < size_n; ++i) cout << " ";
        if ((ver == 0 && (number[n] == '5' || number[n] == '6')) ||
            (ver == 1 && number[n] == '2') )
            cout << " ";
        else cout << "|";
        if (n < num-1) cout << " ";
    }
    cout << endl;
}

void printNumber() {
    printHor(hor++);
    for (int i = 0; i < size_n; ++i) printVer(ver);
    printHor(hor++); ver++;
    for (int i = 0; i < size_n; ++i) printVer(ver);
    printHor(hor);
    cout << endl;
    hor = ver = 0;
}

int main(int argc, char const *argv[]) {
    cin >> size_n >> number;
    
    while (size_n != 0 || number != "0") {
        num = number.size();
        printNumber();
        cin >> size_n >> number;
    }
    
    return 0;
}