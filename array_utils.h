#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <windows.h>

using namespace std;

inline void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor | (bgColor << 4));
}

inline void printArray(const vector<int>& arr) {
    setColor(11, 1);
    cout << "[ ";
    for (int v : arr) {
        setColor(14, 1);
        cout << v << " ";
    }
    setColor(11, 1); 
    cout << "]";
    setColor(7, 0); // Сброс
}

inline void generateRandom(vector<int>& arr, int size) {
    arr.clear();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);
    for (int i = 0; i < size; i++) arr.push_back(dist(gen));
}
