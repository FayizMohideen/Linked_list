#include "Node.hpp"
#include <iostream>


 void Node_test() {
  //Testing Initializer and Destructor 
  //Testing output  
  Node node { Node( 1, nullptr, nullptr ) };
  std::cout << node;

  //Testing Copy Constructor
  Node copy { Node( node ) };
  std::cout << copy;

  //Testing Move Constructor ####WIP

  //Testing assignment Operator ####WIP
  Node test2 { Node( 2, nullptr, nullptr ) };
  copy = test2;
  std::cout << copy;

  //Testing Move Operator ####WIP
  
  //Testing Accessor Functions;
  std::cout << "Value(): " << node.value() << std::endl;
  std::cout << "Next Node(): " << node.p_next_node() << std::endl;
  std::cout << "Prev Node(): " << node.p_prev_node() << std::endl;

  //Testing Mutator Functions;
  node.value( 7 );
  node.p_next_node( new Node( copy ) );
  node.p_prev_node( new Node( test2 ) );
  std::cout << node << std::endl;
  
  //Testing swap
  node.swap( test2 );
  std::cout << node << test2 << std::endl;

  //Testing reverse
  node.reverse();
  std::cout << test2;

  //Testing input 
  Node input{ 0, nullptr, nullptr };
  std::cin >> input; 
  std::cout << std::endl;
  std::cout << input;

}