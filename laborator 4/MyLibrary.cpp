#include "MyLibrary.h"
#include <iostream>

using namespace std;


MyLibrary::MyLibrary(std::ostream& output_stream):output_stream (output_stream), books_count(-1)
{
    books = nullptr;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books):output_stream (output_stream), books_count(books_count)
{
    if (books == nullptr && books_count > 0)
    {
        books = new int[books_count];
        for (unsigned i = 0;i < books_count;i++)
            books[i] = books[i];
    }
    else
        return;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max) :output_stream(output_stream), books_count(books_count)
{
    books = new int[books_count];
    for (unsigned i = 0; i < books_count; i++)
        books[i] = min + rand() % (max - min);
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values): output_stream(output_stream), books_count(0), books(nullptr)
{
    std::string books_str(books_values); // make a copy of books_values
    const char* pch = strtok(&books_str[0], ";"); // use the copy instead of books_values
    while (pch != nullptr)
    {
        ++books_count;
        pch = strtok(nullptr, ";");
    }
    if (books_count > 0)
    {
        books = new int[books_count];
        pch = strtok(&books_str[0], ";"); // use the copy instead of books_values
        unsigned i = 0;
        while (pch != nullptr)
        {
            books[i] = std::atoi(pch);
            i++;
            pch = strtok(nullptr, ";");
        }
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) :output_stream(output_stream), books_count(books_count)
{
    if (books_count > 0)
    {
        books = new int[books_count];
        va_list args;
        va_start(args, books_count);
        for (unsigned i = 0;i < books_count;i++)
            books[i] = va_arg(args, int);
        va_end(args);
    }
    else
        return;
}

MyLibrary::MyLibrary(std::initializer_list<int> v) :MyLibrary(std::cout,static_cast<unsigned>(v.size()),v.begin())
{

}

MyLibrary::MyLibrary(const MyLibrary& copied_library) : output_stream(copied_library.output_stream), books_count(books_count),books(new int[copied_library.books_count])
{
    for (unsigned i = 0; i < books_count; i++) {
        books[i] = copied_library.books[i];
    }
}

MyLibrary::~MyLibrary() {
    delete[] books;
}
