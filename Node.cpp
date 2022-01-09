#include "Node.hpp"
#include <iostream>

Node::Node( double const new_value,
		        Node *const p_new_next_node,
		        Node *const p_new_prev_node ): 
value_  { new_value },
p_next_node_ { p_new_next_node },
p_prev_node_ { p_new_prev_node } 
{ std::cout << "Calling the Node Initializer"
            << std::endl; }

Node::~Node() {
  //std::cout << value() << std::endl;
  value_ = 0;
  delete p_next_node_;
  p_next_node_ = nullptr;
  delete p_prev_node_;
  p_prev_node_ = nullptr;
  std::cout << "Calling the Node Destructor"
            << std::endl;
}

Node::Node( Node const &original ):
value_{ original.value() },
p_next_node_{ original.p_next_node() },
p_prev_node_{ original.p_prev_node() }
{ std::cout << "Calling the Node Copy Constructor"
            << std::endl; };

Node::Node( Node       &&original):
value_{ 0 },
p_next_node_{ nullptr },
p_prev_node_{ nullptr } { 
  swap( original );
  std::cout << "Calling the Node Move Constructor"
            << std::endl; 
} 


Node Node::operator=( Node const &rhs ) {
Node copy{ rhs };
swap( copy );
return *this;
std::cout << "Calling the Node Assignment Operator"
          << std::endl; 
}

Node Node::operator=( Node      &&rhs ) {
  Node copy{ rhs };
  swap( copy );
  return *this;
  std::cout << "Calling the Node Move Operator"
            << std::endl; 
}

double Node::value() const {
  return value_;
}

Node *Node::p_next_node() const {
  return p_next_node_;
}

Node *Node::p_prev_node() const {
  return p_prev_node_;
}

void Node::value( double const new_value ) {
  value_ = new_value;
}

void Node::p_next_node( Node *const new_next_node ) {
  p_next_node_ = new_next_node;
}

void Node::p_prev_node( Node *const new_prev_node ) {
  p_prev_node_ = new_prev_node;
}

void Node::swap( Node &other ) {
  std::swap( value_, other.value_ );
  std::swap( p_next_node_, other.p_next_node_ );
  std::swap( p_prev_node_, other.p_prev_node_ ); 
}

void Node::reverse() {
  std::swap( p_next_node_, p_prev_node_);
}

std::ostream &operator<<( std::ostream &out, 
                          Node const &node ) {
  out << "Node:-  " << std::endl 
      << "  Value: " << node.value() << std::endl
      << "  Next Node: " << node.p_next_node() << std::endl
      << "  Prev Node: " << node.p_prev_node() << std::endl;
  return out;
}


std::istream &operator>>( std::istream &input ,
                          Node &node ) {
  double new_value;
  input >> new_value;
  node.value( new_value );
  return input; 
}

