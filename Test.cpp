/**
*	@author
*	@date
*	@file Test.cpp
*/

#include "Test.h"
#include <exception>
using namespace std;

Test::Test(){
    tester = new LinkedListOfInts();
    ofstream file;
}

void Test::runTests(){

    file.open("buglist.txt");

    file << "BugList\n-------------------------------\n\n";

    isEmpty();
    addFront();
    addBack();
    removeBack();
    removeFront();
    size();
    search();

    file.close();
}


/*--------------------------------------------------------------------------
    Test Methods
--------------------------------------------------------------------------*/

bool Test::isEmpty(){

    cout << "------------------------------------\nTesting 'isEmpty()' method.\n------------------------------------\n";

    refreshList();
    cout << "Test 1: newly created list is empty: ";
    printResult(tester->isEmpty(), "Calling isEmpty() for a newly created list returns false.");

    refreshList();
    cout << "Test 2: Add to front of an empty list, check that list is not empty: ";
    tester->addFront(7);
    printResult(!tester->isEmpty(), "Adding to the front of an empty list, then calling isEmpty() returns true.");

    cout << "Test 3: Remove from front of list, check that list is empty: ";
    tester->removeFront();
    printResult(tester->isEmpty(), "Removing from a list with size 1, then calling isEmpty() returns true.");

    refreshList();
    cout << "Test 4: Add to back of an empty list, check that list is not empty: ";
    tester->addBack(7);
    printResult(!tester->isEmpty(), "Adding to the back of an empty list and calling isEmpty() returns true.");

    cout << "Test 5: Remove from back of list, check that list is empty: ";
    tester->removeBack();
    printResult(tester->isEmpty(), "Removing from the back of a (theoretically) 1-long list, then calling isEmpty() returns false.");

    cout << "\n";
    return true;
}

bool Test::addFront(){

    cout << "------------------------------------\nTesting 'addFront()' method.\n------------------------------------\n";

    refreshList();

    cout << "Test 1: Add '7' to the front and check the vector equivalent: ";
    tester->addFront(7);
    vector<int> check = tester->toVector();
    printResult(check[0] == 7,"Adding 1 element to the front of an empty list was not successful.");

    cout << "Test 2: Add '5' to the front and check the vector equivalent: ";
    tester->addFront(5);
    check = tester->toVector();
    printResult(check[0] == 5, "Adding 2 elements to the front of an empty list was not successful.");

    cout << "\n";
    return true;
}

bool Test::addBack(){
    cout << "------------------------------------\nTesting 'addBack()' method.\n------------------------------------\n";

    refreshList();

    cout << "Test 1: Add '7' to the back and check the vector equivalent: ";
    tester->addBack(7);
    vector<int> check = tester->toVector();
    printResult(check.back() == 7, "Adding one element to the back of an empty list was not successful.");

    cout << "Test 2: Add '5' to the back and check the vector equivalent: ";
    tester->addBack(5);
    check = tester->toVector();
    printResult(check.back() == 5, "Adding two elements to the back of an empty list was not successful.");

    cout << "\n";
    return true;
}

bool Test::removeBack(){

    cout << "------------------------------------\nTesting 'removeBack()' method.\n------------------------------------\n";

    refreshList();
    tester->addFront(3);
    tester->addFront(2);
    tester->addFront(1);

    //vector<int> check = tester->toVector();
    //printVector(check);
    int value = tester->removeBack();
    vector<int> test = tester->toVector();

    cout << "Test 1: Remove back from <1,2,3>, verify returned result is 3: ";
    printResult(value== 3, "Removing from the back of <1,2,3> does not return true.");
    if(!(value==3)) cout << "Returned: " << value << "\n\n";

    refreshList();
    tester->addFront(3);
    tester->addFront(2);
    tester->addFront(1);
    tester->removeBack();
    test = tester->toVector();

    cout << "Test 2: Remove back from <1,2,3>, verify that the size is now 2 long: ";
    printResult(test.size() == 2, "When removing from the back of <1,2,3>, the representative vector does not have a size of 2.");
    if(!(test.size() == 2)) cout << "Size: " << test.size() <<"\n\n";

    cout << "Test 3: Remove back from <1,2,3>, verify that remaining vector is <1,2>: ";
    printResult(test.back() == 2 && test.front() == 1, "When removing from the back of <1,2,3>, the representative vector does not start with 1, or end with 2.");
    if(!(test.back() == 2)) cout << "First Entry: " << test.back() <<"\n\n";

    cout << "Test 4: Try to break the Linked List by removing from an empty list: ";
    refreshList();
    try{
        tester->removeBack();
        printResult(true,"");
    }
    catch(const exception& e){
        printResult(false,"Removing from an empty list throws an exception.");
        std::cout << e.what();
    }

    cout << "\n";
    return true;
}

bool Test::removeFront(){

    cout << "------------------------------------\nTesting 'removeFront()' method.\n------------------------------------\n";

    refreshList();
    tester->addFront(3);
    tester->addFront(2);
    tester->addFront(1);

    //vector<int> check = tester->toVector();
    //printVector(check);
    int value = tester->removeFront();
    vector<int> test = tester->toVector();

    cout << "Test 1: Remove front from <1,2,3>, verify returned result is 1: ";
    printResult(value== 1, "When removing from the front of <1,2,3>, the return value does not equal 1.");
    if(!(value==1)) cout << "Returned: " << value << "\n";
    //printVector(test);
    //cout << "\n";

    refreshList();
    tester->addFront(3);
    tester->addFront(2);
    tester->addFront(1);
    tester->removeFront();
    vector<int> test2 = tester->toVector();

    cout << "Test 2: Remove front from <1,2,3>, verify that the size is now 2 long: ";
    printResult(test.size() == 2, "When removing the front entry from <1,2,3>, the size of the representative vector is not 2.");
    if(!(test.size() == 2)) cout << "Size: " << test.size() <<"\n";
    //printVector(test2);
    //cout << "\n";

    cout << "Test 3: Remove front from <1,2,3>, verify that remaining vector is <2,3>: ";
    printResult(test.back() == 3 && test.front() == 2, "When removing from the front entry from <1,2,3>, the representative vector does not equal <2,3>.");
    if(!(test.back() == 2)) cout << "Last Entry: " << test.back() <<"\n";
    //printVector(test);
    //cout << "\n";

    cout << "Test 4: Try to break the Linked List by removing from an empty list: ";
    refreshList();
    try{
        tester->removeFront();
        printResult(true,"");
    }
    catch(const exception& e){
        printResult(false,"Calling removeFront() for an empty list produces an exception.");
        std::cout << e.what();
    }

    cout << "\n";
    return true;
}

bool Test::size(){

    cout << "------------------------------------\nTesting 'size()' method.\n------------------------------------\n";

    refreshList();
    int num = 5;
    for(int i=0;i<num;i++){
        tester->addFront(1);
    }
    int size1 = tester->size();
    cout << "Test 1: Add several items, and check the size of the list: ";
    printResult( size1 == num, "Adding 5 items to list, then calling size() does not return 5.");
    cout << "Test 2: Double check this size against the vector size: ";
    printResult(size1 == (int) tester->toVector().size(),"After adding 5 items, the size of the vector representation did not match the result of calling size().");

    cout << "Test 3: Remove 1 item from list and check if the size has changed: ";
    tester->removeBack();
    int size2 = tester->size();
    printResult((size2 == size1-1), "Add items to list, check size. Remove 1 item. Check that the new size is less. This test failed.");


    cout << "Test 4: Check the size of an empty list: ";
    refreshList();
    printResult(tester->size() == 0, "For an empty list, size() does not return 0.");

    cout << "Test 5: (Stress Test) Add 1000 items, and check that the size is 1000: ";
    refreshList();
    num = 1000;
    for(int i=0;i<num;i++){
        tester->addFront(1);
    }
    printResult(tester->size() == num, "After adding 1000 items to list, the size was not 1000.");

    cout << "\n";
    return true;
}

bool Test::search(){

    cout << "------------------------------------\nTesting 'search()' method.\n------------------------------------\n";

    cout << "Test 1: Search an empty list: ";
    refreshList();
    printResult(tester->search(1) == 0, "Searching an empty list did not return 0.");

    cout << "Test 2: Add several items to a list, then search for those items: ";
    refreshList();
    int num = 10;
    for(int i =1; i <= num; i++){
        tester->addFront(i);
    }
    bool found = true;
    for(int i =1; i <= num; i++){
        if(tester->search(i) == 0){
            found = false;
        }
    }
    printResult(found, "Adding several items to a list, then searching for all of those items was not successful.");

    cout << "Test 3: Using the same list, search for an item that is not in the list: ";
    printResult(tester->search(100) == 0, "Adding several items to a list, then searching for an item that was not found produced a result other than 0.");

    cout << "\n";
    return true;
}


/*--------------------------------------------------------------------------
    Helper Methods
--------------------------------------------------------------------------*/

void Test::refreshList(){

    delete tester;
    tester = new LinkedListOfInts();
}


void Test::printResult(bool condition, string bugMessage){
    if(condition){
        cout << "Passed\n";
    }
    else{
        cout << "Failed\n";
        file << bugMessage << "\n";
    }
}

void Test::printVector(vector<int> input){

    cout << "Result Vector: <";
    for(unsigned int i=0; i<input.size()-1;i++){
        cout << input[i] << ",";
    }
    cout << input[input.size()-1];
    cout << ">\n";
}
