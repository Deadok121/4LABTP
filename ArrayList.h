//
// Created by Roman Oborin on 2019-05-17.
//

#ifndef LABA4_ARRAYLIST_H
#define LABA4_ARRAYLIST_H

#include <initializer_list>
#include <cstring>
#include <cstddef>
#include <new>

using namespace std;

//Создайте шаблон класса массива, в котором есть методы для вычисления суммы и
//        среднего значения хранимых в массиве чисел.
//
// Создайте шаблон класса массива, в котором есть методы для вычисления суммы и
//среднего значения хранимых в массиве чисел. Перегрузите потоковый ввод/вывод,
//оператор + для сложения двух массивов, - для вычитания массивов, != для сравнения
//массивов, < для сравнения массивов.

template<typename TYPE>
class ArrayList {
private:
    TYPE *aList = new TYPE;
    int lastIndex = -1;
public:
    ArrayList() = default;

    ArrayList(initializer_list<TYPE> list) {
        aList = new TYPE;
        for (auto &element : list) {
            aList[lastIndex] = element;
            ++lastIndex;
        }
        if (lastIndex > -1) {
            lastIndex--;
        }
    }

    ~ArrayList() = default;

    ArrayList(const ArrayList &p2) {
        aList = new TYPE;
        for (int i = 0; i < p2.lastIndex + 1; i++) {
            aList[i] = *(new TYPE(p2.aList[i]));
            lastIndex++;
        }
        if (lastIndex > -1) {
            lastIndex--;
        }
    }

    void display() const {
        for (int i = 0; i < lastIndex; ++i) {
            cout << aList[i] << " ";
        }
        cout << endl;
    };

    void insert() {
        TYPE elem;
        cin >> elem;
        lastIndex++;
        aList[lastIndex] = elem;
    }

    TYPE sum() {
        TYPE res{};
        for (int i = 0; i < lastIndex + 1; ++i) {
            res += aList[i];
        }
        return res;
    }

    TYPE average() {
        TYPE res = sum();
        try {
            if (lastIndex + 1 == 0) throw 1;
            res /= (lastIndex + 1);
        }
        catch (int a) {
            cout << "Divide by zero exception ";
        }
        return res;
    }

    TYPE get(int index) const {
        TYPE res = aList[index];
        if (res == NULL) {
            cout << "No value present at index " << index << endl;
        }
        return res;
    }

    void remove(int index) {
        if (index > lastIndex)
            return;

        lastIndex--;
        for (int i = index; i < lastIndex; ++i) {
            aList[i] = aList[i + 1];
        }
    }

    int getLenght() {
        return lastIndex;
    }

    ArrayList operator[](int index) {
        return get(index);
    }


    void replace(int index, TYPE newElem) {
        aList[index] = newElem;
    };

    ArrayList operator=(ArrayList &other) {
        for (int i = 0; i < other.lastIndex + 1; ++i) {
            aList[i] = other.aList[i];
            lastIndex++;
        }
        return *this;
    }

    bool operator!=(ArrayList &other) {
        if (lastIndex != other.lastIndex) {
            return true;
        }

        for (int i = 0; i < other.lastIndex + 1; ++i) {
            if (aList[i] != other.aList[i]) {
                return true;
            }
        }
        return false;
    }

    bool operator<(ArrayList &other) {
        if (lastIndex > other.lastIndex) {
            return false;
        }

        for (int i = 0; i < other.lastIndex + 1; ++i) {
            if (aList[i] > other.aList[i]) {
                return false;
            }
        }
        return true;
    }

    void sqrt() {
        for (int i = 0; i < lastIndex + 1; ++i) {
            aList[i] *= aList[i];
        }
    }

    ArrayList operator+(ArrayList &c2) {
        ArrayList result;
        for (int i = 0; i < lastIndex + 1; i++) {
            result.aList[i] = *(new TYPE(aList[i]));
            result.lastIndex++;
        }
        result.lastIndex++;
        for (int i = 0; i < c2.lastIndex + 1; ++i) {
            result.aList[result.lastIndex] = *(new TYPE(c2.aList[i]));
            result.lastIndex++;
        }
        if (result.lastIndex > -1) {
            result.lastIndex -= 1;
        }
        return result;
    }

    ArrayList operator-(ArrayList &c2) {
        ArrayList result;
        for (int i = 0; i < lastIndex + 1; i++) {
            result.aList[i] = aList[i] - *(new TYPE(c2.aList[i]));
            result.lastIndex++;
        }
        return result;
    }


    friend ostream &operator<<(ostream &out, const ArrayList &list) {
        for (int i = 0; i < list.lastIndex + 1; i++) {
            out << list.aList[i] << " ";
        }
        if (list.lastIndex == -1) {
            out << "Empty";
        }
        out << endl;
        return out;
    }


    friend istream &operator>>(std::istream &is, TYPE &elem) {
        is >> elem;
        return is;
    };


    friend ostream &operator<<(ostream &out, const TYPE &element) {
        out << element << " ";
        return out;
    }
};


#endif //LABA4_ARRAYLIST_H
