/**
*	@author
*	@date
*	@brief A header file for test class
*/


#ifndef TEST_H
#define TEST_H

#include "LinkedListOfInts.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Test
{
    public:
        Test();
        void runTests();

        //methods to test
        bool isEmpty();
        bool size();
        bool search();
        bool addBack();
        bool addFront();
        bool removeBack();
        bool removeFront();

        //helper methods
        void refreshList();
        void printResult(bool condition, std::string bugMessage);
        void printVector(std::vector<int> input);

        LinkedListOfInts* tester;
        std::ofstream file;

};

#endif
