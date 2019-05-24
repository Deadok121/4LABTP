#include <iostream>
#include <unordered_map>
#include <string>
#include "ArrayList.h"
#include "typeinfo"

using namespace std;

template<typename TYPE>
void runTask(ArrayList<TYPE> list);

int main() {
    cout << "Choose array types:" << endl;
    cout << "1- int,2 - float,3 - double" << endl;
    int c;
    bool sucess = false;
    cin >> c;
    ArrayList<int> listInt;
    ArrayList<float> listFloat;
    ArrayList<double> listDouble;
    if (c == 1) {
        runTask(listInt);
    }
    if (c == 2) {
        runTask(listFloat);
    }
    if (c == 3) {
        runTask(listDouble);
    }

    if (c > 0 && c < 4) {
        sucess = true;
    }

    if (sucess) {
        return 0;
    }

    main();
    return 0;
}

template<typename TYPE>
void runTask(ArrayList<TYPE> list) {
    ArrayList first = list;
    ArrayList second = list;
    int choice;
    cout << "1.Insert elem to first array" << endl;
    cout << "2.Insert elem to second array" << endl;
    cout << "3.Sum two arrays and display" << endl;
    cout << "4.Subtract from the first second" << endl;
    cout << "5.Subtract from the first two" << endl;
    cout << "6.Compare with no equals to arrays" << endl;
    cout << "7.Check for first less than second" << endl;
    cout << "8.Check for second less than second" << endl;
    cout << "9.Find first average" << endl;
    cout << "10.Find second average" << endl;
    cout << "11.Pow 2 and display first" << endl;
    cout << "12.Pow 2 and display second" << endl;
    cout << "13.Display first" << endl;
    cout << "14.Display second" << endl;
    do {
        cout << "Enter your choice : " << endl;
        cin >> choice;
        int i = 0;
        switch (choice) {
            case 1: {
                cout << "Enter elem : ";
                first.insert();
                break;
            }
            case 2: {
                cout << "Enter elem : ";
                second.insert();
                break;
            }
            case 3: {
                cout << first + second << endl;
                break;
            }
            case 4: {
                cout << first - second << endl;
                break;
            }
            case 5: {
                cout << second - first << endl;
                break;
            }
            case 6: {
                bool notEqual = first != second;
                notEqual ? cout << "Not equals" : cout << "Equals";
                cout << endl;
                break;
            }
            case 7: {
                first < second ? cout << "First less" : cout << "First greater";
                cout << endl;
                break;
            }
            case 8: {
                second < first ? cout << "First greater" : cout << "First less";
                cout << endl;
                break;
            }
            case 9: {
                cout << first.average() << endl;
                break;
            }
            case 10: {
                cout << second.average() << endl;
                break;
            }
            case 11: {
                first.sqrt();
                cout << first << endl;
                break;
            }
            case 12: {
                second.sqrt();
                cout << second << endl;
                break;
            }
            case 13: {
                cout << first << endl;
                break;
            }
            case 14: {
                cout << second << endl;
                break;
            }
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 15);
}
