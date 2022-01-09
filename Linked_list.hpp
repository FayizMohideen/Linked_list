#pragma once
#include "Node.hpp"
#include <iostream>


#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Linked_list;

//input and output
std::ostream &operator<<( std::ostream &out, 
                          Linked_list const &list );
std::istream &operator>>( std::istream &input, 
                          Linked_list &list );

class Linked_list{
  public:
    Linked_list();
   ~Linked_list();

    //copy constructor
    Linked_list( Linked_list const &original );
    //move constructor
    Linked_list( Linked_list      &&original );
    //assignment operator
    Linked_list operator=( Linked_list const &rhs );
    //move operator
    Linked_list operator=( Linked_list       &&rhs );
    
    bool is_empty() const;
    std::size_t size() const;
    Node *p_head() const;
    Node *p_tail() const;

    double front() const;
    void push_front( double new_value );
    void pop_front();
    
    double back() const;
    void push_back( double new_value );
    void pop_back();

    //concantenation of 2 lists
    void swap( Linked_list &other );
    void push_front( Linked_list &other );
    void push_back( Linked_list &other );

    void reverse();
    int find( double const goal );
    void erase( std::size_t const index );
    void erase( std::size_t const first_index,
                std::size_t const last_index );
    
    bool operator+( Linked_list const &rhs );
    bool operator==( Linked_list const &rhs ) const;
    bool operator!=( Linked_list const &rhs ) const;

    void clear();

  private:
    Node *p_head_;
    Node *p_tail_;
    std::size_t size_;

  friend std::ostream &operator<<( std::ostream &out, 
                                   Linked_list const &list );
  friend std::istream &operator>>( std::istream &input, 
                                   Linked_list &list );
  
};

    

#endif

