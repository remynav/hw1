#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr testList;
  std::cout<< "Empty list has size: " << testList.size()<< std::endl;
  testList.push_back("a");
  testList.push_back("b");
  testList.push_back("c");
  std::cout << "pushed " <<testList.size() << "elements"<<std::endl;
  std::cout <<"front: " << testList.front() << ", back: " << testList.back() << std::endl;

  testList.push_front("x");
  testList.push_front("y");
  testList.push_front("z");
  std::cout << "size after pushing three more elements:  " <<testList.size() << "elements"<<std::endl;
  std::cout <<"front: " << testList.front() << ", back: " << testList.back() << std::endl;

  //std::cout<<"element at 4th index: " << testList.getValAtLoc(4) << std::endl;

  testList.pop_back();
  std::cout << "size after popping back: " << testList.size() << ", and new last element is:  " << testList.back() << std::endl;
  testList.pop_front();
  std::cout << "size after popping front: " << testList.size() << ", and new first element is:  " << testList.front() << std::endl;

  std::cout << "the final list is: ";
  for(size_t i = 0; i < testList.size(); i++){
    std::cout << testList.get(i) << ", ";
  }
  std::cout << std::endl;

  return 0;
}
