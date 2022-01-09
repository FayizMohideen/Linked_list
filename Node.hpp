#pragma once 
#include <iostream>

#ifndef NODE_HPP
#define NODE_HPP

class Node;

std::ostream &operator<<( std::ostream &out, 
                          Node const &node );
std::istream &operator>>( std::istream &in,
                          Node const &node );

class Node
{
	public:
		Node( double const new_value,
			    Node *const p_new_next_node,
			    Node *const p_new_prev_node );
	 ~Node();
	   
     //copy constructor
	   Node( Node const &original );
     //move constructor
	   Node( Node      &&original );
	   
     //assignment operator
	   Node operator=( Node const &rhs );
     //move operator 
	   Node operator=( Node &&rhs );
	   
	   double value() const;
	   Node *p_next_node() const;
	   Node *p_prev_node() const;
	   
	   void value( double const new_value );
     void p_next_node( Node *const new_next_node );
     void p_prev_node( Node *const new_prev_node );

     void swap( Node &other );
     void reverse();
     
	   
	protected:
		double value_;
		Node *p_next_node_;
		Node *p_prev_node_;

  friend std::ostream &operator<<( std::ostream &out, 
                                   Node const &node );
  friend std::istream &operator>>( std::istream &input,
                                   Node &node );
		
};



#endif

