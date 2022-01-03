// AdventOfCodeDay1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int timesIncreased = 0;
    ifstream inputFile;
    inputFile.open("puzzle_input.txt", ios::in);
    std:string inputString;
    if (inputFile.is_open()) {
        getline(inputFile,inputString);
        int previousValue1 = stoi(inputString);
        getline(inputFile, inputString);
        int previousValue2 = stoi(inputString);
        getline(inputFile, inputString);
        int previouseValue3 = stoi(inputString);
        int previousSum = previousValue1 + previousValue2 + previouseValue3;
        while (getline(inputFile, inputString)) {
            int currentValue = stoi(inputString);
            int currentSum = currentValue + previouseValue3 + previousValue2;
            if (currentSum > previousSum) {
                timesIncreased++;
            }
            previousValue2 = previouseValue3;
            previouseValue3 = currentValue;
            previousSum = currentSum;
        }
    }
    inputFile.close();
    cout << "Times Increased: " << timesIncreased << endl;
    cout << "Press enter 'e' to exit" << endl;
    cin >> inputString;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
