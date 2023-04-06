#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Vector {
private:
    vector<T> data;
public:
    Vector() {}

    // copy constructor
    Vector(const Vector& other) {
        data = other.data;
    }

    // move constructor
    Vector(Vector&& other) {
        data = move(other.data);
    }

    void insert(int index, const T& element) {
        if (index < 0 || index > data.size()) {
            throw out_of_range("Index out of range");
        }
        data.insert(data.begin() + index, element);
    }

    void remove(int index) {
        if (index < 0 || index >= data.size()) {
            throw out_of_range("Index out of range");
        }
        data.erase(data.begin() + index);
    }

    void sort() {
        for (int i = 0; i < data.size(); i++) {
            for (int j = i + 1; j < data.size(); j++) {
                if (data[i] > data[j]) {
                    T temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }

    void sort(int (*cmp)(const T&, const T&)) {
        for (int i = 0; i < data.size(); i++) {
            for (int j = i + 1; j < data.size(); j++) {
                if (cmp(data[i], data[j]) > 0) {
                    T temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }

    void print() const {
        for (const auto& element : data) {
            cout << element << ' ';
        }
        cout << endl;
    }

    // overloaded [] operator
    T& operator[](int index) {
        if (index < 0 || index >= data.size()) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }
};
int compare_ints(const int& x, const int& y);