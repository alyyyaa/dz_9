//Дано натуральное М и массив целых чисел размерности М. Отсортировать данный массив по убыванию методом простых обменов.В процессе сортировки
//отсортированную часть накапливать в начале массива.Вывести содержимое массива после каждой итерации сортировки.Одной итерацией сортировки считать такое
//действие в результате которого один элемент массива гарантированно встает на правильное место в отсортированном массиве.При выводе массива
//отсортированную часть отделять от неотсортированной с помощью символа | .
//Протокол сортировки выводить в текстовый файл с именем FilеNаmе.
#include<iostream>
#include <fstream>
#include <string>
using namespace std;
void main() 
{
    int M;
    cin >> M;
    int* m = new int[M];
    for (int i = 0; i < M; i++)
        cin >> m[i];
    string filename;
    cin >> filename;
    ofstream f;
    f.open(filename);

    int i, j, x, count = 0;
    for (i = M - 1; i > 0; i--) {
        for (j = M - 1; j > 0; j--)
            if (m[j] > m[j - 1]) {
                x = m[j];
                m[j] = m[j - 1];
                m[j - 1] = x;
            }

        count += 1;
        int k = 0;
        for (k; k < count; k++)
            f << m[k] << ' ';
        f << "| ";
        for (int x = count; x < M; x++)
            f << m[x] << ' ';
        f << endl;
    }
}