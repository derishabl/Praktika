#include <iostream>
#include <vector>
#include <chrono>
#include <windows.h>

#include "array_utils.h"
#include "heap_sort.h"

using namespace std;

void showMenu() {
    setColor(15, 1); 
    cout << "\n=============================================\n";
    cout << "     БИНАРНАЯ СОРТИРОВКА (HEAP SORT)       \n";
    cout << "===========================================\n";

    setColor(10, 1); cout << "   [1] Ввести массив вручную\n";
    setColor(14, 1); cout << "   [2] Сгенерировать случайный массив\n";
    setColor(11, 1); cout << "   [3] Выполнить бинарную сортировку\n";
    setColor(13, 1); cout << "   [4] Показать текущий массив\n";
    setColor(12, 1); cout << "   [0] Выход\n";

    setColor(15, 1);
    cout << "===========================================\n";
    setColor(14, 1);
    cout << "Ваш выбор: ";
    setColor(7, 0);
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<int> arr;
    int choice;
    bool hasData = false;

    setColor(15, 1); 

    do {
        showMenu();
        setColor(7, 0);
        cin >> choice;

        switch (choice) {
        case 1: {
            int n;
            setColor(14, 1); cout << "Введите кол-во элементов: "; setColor(7, 0);
            cin >> n;
            arr.resize(n);
            setColor(14, 1); cout << "Введите " << n << " чисел: "; setColor(7, 0);
            for (int i = 0; i < n; i++) cin >> arr[i];
            hasData = true;
            setColor(10, 1); cout << "Массив сохранён.\n";
            break;
        }
        case 2: {
            int n;
            setColor(14, 1); cout << "Введите кол-во элементов: "; setColor(7, 0);
            cin >> n;
            generateRandom(arr, n);
            hasData = true;
            setColor(10, 1); cout << "Сгенерирован массив: ";
            printArray(arr);
            cout << "\n";
            break;
        }
        case 3: {
            if (!hasData || arr.empty()) {
                setColor(12, 1); cout << "Ошибка: Сначала создайте массив!\n";
            } else {
                setColor(14, 1); cout << "Исходный: "; printArray(arr); cout << "\n";
                
                auto start = chrono::high_resolution_clock::now();
                heapSort(arr);
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> diff = end - start;

                setColor(10, 1); cout << "Результат: "; printArray(arr); cout << "\n";
                setColor(11, 1); cout << "Время: " << diff.count() << " сек.\n";
            }
            break;
        }
        case 4: {
            if (!hasData || arr.empty()) {
                setColor(12, 1); cout << "Массив пуст.\n";
            } else {
                setColor(14, 1); cout << "Текущий массив: "; printArray(arr); cout << "\n";
            }
            break;
        }
        case 0:
            setColor(12, 1); cout << "Выход...\n";
            setColor(7, 0);
            return 0;
        default:
            setColor(12, 1); cout << "Неверный пункт!\n";
        }
    } while (true);

    return 0;
}
