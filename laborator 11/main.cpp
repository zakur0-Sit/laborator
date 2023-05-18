#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "CircularQueue.h"
#include <iostream>
using namespace std;

TEST_CASE("CircularQueue tests for unsigned int (1)") 
{
    SECTION("Adding 2 elements and checking size") 
    {
        CircularQueue<unsigned int> queue(4);
        unsigned int a = 25;
        unsigned int b = 8;
        queue.push(a);
        queue.push(b);
        REQUIRE(queue.getSize() == 2);
    }
}

TEST_CASE("CircularQueue tests for string (1)") 
{
    SECTION("Add one element and pop one element, check if queue is empty") 
    {
        CircularQueue<string> queue(4);
        queue.push("Ion");
        queue.pop();
        REQUIRE(queue.empty() == true);
    }
}

TEST_CASE("CircularQueue tests for unsigned int (2)") 
{
    SECTION("Check the first and the last element without adding anything") 
    {
        CircularQueue<unsigned int> queue(4);
        REQUIRE_THROWS_AS(queue.front(), std::runtime_error);
        REQUIRE_THROWS_AS(queue.back(), std::runtime_error);
    }
}

TEST_CASE("CircularQueue tests for unsigned int (3)") 
{
    SECTION("Add 5 elements and check if first element is the 5th added element") 
    {
        CircularQueue<unsigned int> queue(4);
        queue.push(1);
        queue.push(2);
        queue.push(3);
        queue.push(4);
        queue.push(2);
        REQUIRE(queue.front() == 2); 
    }
}

TEST_CASE("CircularQueue tests for unsigned int (4)") 
{
    SECTION("Add 1000 elements; pop all of them and check that they are correct") 
{
        int n = 1000;
        CircularQueue<unsigned int> queue(4);
        for (unsigned int i = 0; i < n; ++i) {
            queue.push(i);
        }

        for (unsigned int i = n-4 ; !queue.empty(); ++i) {
            REQUIRE(queue.front() == i);
            queue.pop();
        }
    }
}

TEST_CASE("CircularQueue tests for string (2)") 
{
    SECTION("Add 2 elements and check queue size") 
    {
        CircularQueue<string> queue(4);
        queue.push("Hello");
        queue.push("World");
        REQUIRE(queue.getSize() == 2);
    }
}

TEST_CASE("CircularQueue tests for string (3)")
{
    SECTION("Add 3 elements, print them, pop one and check queue size")
    {
        CircularQueue<string> queue(4);
        queue.push("Cazacu ");
        cout << queue.back();
        queue.push("Ion ");
        cout << queue.back();
        queue.push("COOL ");
        cout << queue.back();
        
        queue.pop();
        REQUIRE(queue.getSize() == 2);
    }
}
 