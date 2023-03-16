#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <cstdlib>
#include <cstdarg>
#include <ostream>
#include <iostream>
#include <initializer_list>
#include <cstdlib>
#include <cstring>

using namespace std;

class MyLibrary {
    std::ostream& output_stream;
    unsigned books_count;
    int* books;
public:

    MyLibrary(std::ostream& output_stream);

    MyLibrary(std::ostream& output_stream, unsigned books_count, int* books);

    MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max);

    MyLibrary(std::ostream& output_stream, const char* books_values);

    MyLibrary(std::ostream& output_stream, unsigned books_count, ...);

    MyLibrary(std::initializer_list<int> v);

    MyLibrary(const MyLibrary& copied_library);

    ~MyLibrary();

    void print_books() const
    {
        if (books_count == 0)
        {
            output_stream << "Found -1 books" << endl;
            return;
        }
        output_stream << "Found " << books_count << " books: ";
        for (unsigned i = 0;i < books_count;i++)
        {
            if (books != nullptr)
            {
                output_stream << books[i];
                if (i != books_count - 1)
                    output_stream << ";";
            }
            else
                return;
        }
        output_stream << endl;
    }

    void update_book_id_by_index(unsigned book_index, int book_id)
    {
        if (book_index < books_count)
            books[book_index] = book_id;
    }

    unsigned get_books_count() const
    {
        return books_count;
    }

    int get_book_id_by_index(int x) const {
        if (books != nullptr) {
            if (x >= 0 && x < books_count) {
                return books[x];
            }
            return -1;
        }
        else {
            return 0; // default value when books is not nullptr
        }
    }
};
