#include "Linked_list.hpp"
#include "Node.cpp"
#include <iostream>

int main() {
  //Testing empty list and accessor/output functions
  Linked_list list{};
  std::cout << list;
  //Testing is_empty() true
  std::cout << "Empty List: 1 == " << list.is_empty() << std::endl;

  //Testing Copy Constructor  
  //Linked_list list2_copy{ list2 };
  //std::cout << list2;


  //Testing push_front and output of size = 0,1 and > 1
  //Testing is_empty() false
  Linked_list list1{};
  list1.push_front( 1 );
  std::cout << list1;
  std::cout << "Not Empty: 0 == " << list1.is_empty() << std::endl;

  Linked_list list2{};
  list2.push_front( 1 );
  list2.push_front( 2 );
  list2.push_front( 3 );
  std::cout << list2;

  //Testing Front
  //std::cout << "List 0 Front: " << list.front() << std::endl;
  //std::cout << "List 1 Front: " << list1.front() << std::endl;
  //std::cout << "List 2 Front: " << list2.front() << std::endl;

  //Testing pop_front on size = 0,1, > 1
  //list.pop_front();
  //list1.pop_front();
  //list2.pop_front();
  //std:: cout << list << list1 << list2 << std::endl;


  //Testing push_back on size = 0,1, > 1
  list.push_back( 4 );
  list1.push_back( 4 );
  list2.push_back( 4 );
  list2.push_back( 5 );
  std::cout << list << list1 << list2 << std::endl;

  //Testing pop_back on size = 0,1, >1
  list.pop_back();
  list1.pop_back();
  list2.pop_back();
  std::cout << list << list1 << list2 << std::endl;

  
  //Testing back()
  //std::cout << "List 0 Back: " << list.back() << std::endl;
  //std::cout << "List 1 Back: " << list1.back() << std::endl;
  //std::cout << "List 2 Back: " << list2.back() << std::endl;

  //Testing swap()
  //list.swap(list2);
  //std::cout << list << list2;

  //Testing concantenating 2 lists adding to front and back
  //For both front and back -> 10 test cases
  //Can safely assume that one test is sufficient for push_back 
  //so long as swap and push_front work 
  //                  other
  //              0           1        > 1
  //        0     Nothing     Swap     Swap
  //        
  // this   1     Nothing     General  General
  //
  //       >1     Nothing     General  General
  //Can't concantenate a list to itself
  //Linked_list list_copy{ list };
  //Linked_list list1_copy{ list1 }; 
  //Linked_list list2_copy{ list2 };

  //list.push_front( list_copy );
  //std::cout << list << list_copy << std::endl;
  //list.push_front( list1_copy );
  //std::cout << list << list1_copy << std::endl;
  //list.push_front( list2_copy );
  //std::cout << list << list2_copy << std::endl;
  //list1.push_front( list_copy );
  //std::cout << list1 << list_copy << std::endl;
  //list1.push_front( list1_copy );
  //std::cout << list1 << list1_copy << std::endl;
  //list1.push_front( list2_copy );
  //std::cout << list1 << list2_copy << std::endl;
  //list2.push_front( list_copy );
  //std::cout << list2 << list_copy << std::endl;
  //list2.push_front( list1_copy );
  //std::cout << list2 << list1_copy << std::endl;
  //list2.push_front( list2_copy );
  //std::cout << list2 << list2_copy << std::endl;
  //list.push_front( list );
  //std::cout << list;
  //list2.push_back( list2_copy );

  //Testing reverse()
  //list2.reverse();
  //std::cout << list2;

  //Testing find() true
  std::cout << "In List 2, 4 is found at index 0 == " 
            <<list2.find( 4 ) << std::endl;
    std::cout << "In List 2, 5 is found at index -1 == " 
            <<list2.find( 5 ) << std::endl;

  //Testing erase singular
  //list2.erase(1);
  //std::cout << list2;

  //Testing erase group
  //list2.erase(1,1);
  //std::cout << list2;

  //Testing +operator
  //list1 + list2;
  //std::cout << list1;
  
  //Testing ==operator
  //Linked_list list2_copy{ list2 };
  //std::cout << list2 << list2_copy;
  //std::cout << "List 2 == List 2 1 == " 
  //          << ( list2_copy == list2 ) << std::endl;

  //Testing != operator
  //std::cout << "List 1 == List 2 0 == " 
  //          << ( list1 == list2 ) << std::endl;

  //Testing clear
  //list2.clear();
  //std::cout << list2;
  
  //Testing >> operator
  std::cin >> list;
  std::cout << list;
  
   
  






}