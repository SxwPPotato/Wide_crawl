#include <iostream>
#include <fstream>


int main()
{
    setlocale(LC_ALL, "russian");
    int size;
    int mass[7];
    int** matrix;
    int firstrows = 0;
    bool trueorfalse;
    int position = 1;

    std::ifstream file("input.txt");
    if (file.is_open() == 0)
    {
        std::cout << "Не получилось открыть файл!" << std::endl;
        return 0;
    }

    file >> size;

    matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];
        }
    }

    std::cout << "В графе " << size << " вершин. Введите номер вершины, с которой начнётся обход: ";
    std::cin >> firstrows;

    mass[0] = firstrows;
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[firstrows - 1][j] == 1) {
                for (int k = 0; k < position; ++k) {
                    if (j + 1 == mass[k]) {
                        trueorfalse = false;
                        break;
                    }
                    else  trueorfalse = true;
                }
                if (trueorfalse) {    
                    mass[position] = j + 1;
                    position++;
                }
            }
        }
        firstrows = mass[i];

    }

    std::cout << "Порядок обхода вершин: ";
    for (int i = 0; i < size; ++i) {
        std::cout << mass[i] << ' ';
    }
    return 0;
}
