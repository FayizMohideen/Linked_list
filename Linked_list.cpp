#include "Linked_list.hpp"
#include <iostream>

Linked_list::Linked_list():
p_head_{ nullptr }, 
size_{ 0 },
p_tail_{ nullptr }
{ std::cout << "Calling the List Constructor" << std::endl; }

Linked_list::~Linked_list() {
  clear();
  std::cout << "Calling the List Destructor" << std::endl;
}

//copy constructor
Linked_list::Linked_list( Linked_list const &original ):
p_head_{},
p_tail_{},
size_{} 
{ 
  std::cout << "Calling the List Copy Constructor " << std::endl;
  for( Node *p_iterator{ original.p_head_}; p_iterator != nullptr;               p_iterator = p_iterator->p_next_node() ) {
    push_back( p_iterator->value());  
  } 
}

//move constructor WIP
Linked_list::Linked_list( Linked_list      &&original ):
p_head_{ nullptr },
p_tail_{ nullptr },
size_{ 0 }
{
  swap( original );
  std::cout << "Calling the List Move Constructor" << std::endl;
} 

//assignment operator WIP
Linked_list Linked_list::operator=( Linked_list const &rhs ) {
  Linked_list copy{ rhs };
  swap( copy );
  return *this;
  std::cout << "Calling the List Assignment Operator" << std::endl;
} 

//move operator WIP 
Linked_list Linked_list::operator=( Linked_list       &&rhs ) {
  Linked_list copy{ rhs };
  swap( copy );
  return *this;
  std::cout << "Calling the List Assignment Operator" << std::endl;
} 


bool Linked_list::is_empty() const {
  return ( p_head_ == nullptr );
}

std::size_t Linked_list::size() const {
  return size_;
}

Node *Linked_list::p_head() const {
  return p_head_;
}

Node *Linked_list::p_tail() const {
  return p_tail_;
}

double Linked_list::front() const {
  if ( !is_empty() ) {
    return p_head_->value();
  }
}

void Linked_list::push_front( double new_value ) {
  Node* new_head{ new Node{ new_value, p_head(), nullptr } };
  if ( is_empty() ){
    p_head_ = new_head;
    p_tail_ = p_head();
  }

  else {
    p_head_->p_prev_node( new_head );
    p_head_ = new_head;
  }

  ++size_;
}

void Linked_list::pop_front() {
  
  if ( !is_empty() ) {
    Node *old_head{ p_head_ };
    p_head_ = p_head_->p_next_node();
    //if size() == 1
    if ( p_head_ == nullptr ) {
      p_tail_ = nullptr;
    }
    else {
      p_head_->p_prev_node( nullptr ); 
    }

    --size_;
    old_head->p_next_node( nullptr );
    delete old_head;
    old_head = nullptr;

  }
}

double Linked_list::back() const {
  if ( !is_empty() ) {
    return p_tail_->value(); 
  }
}

void Linked_list::push_back( double new_value ) {
  if ( is_empty() ) {
    push_front( new_value );
  }
  else {
    Node *new_tail{ new Node{ new_value, nullptr, p_tail()} };
    p_tail_->p_next_node( new_tail );
    p_tail_ = new_tail;
    ++size_;
  }
}

void Linked_list::pop_back() {
  if ( !is_empty() ) {
    if ( p_head() == p_tail() ) {
      pop_front();
    }
    else {
      Node *new_tail{ p_tail_->p_prev_node() };
      p_tail_->p_prev_node( nullptr );
      new_tail->p_next_node( nullptr );
      delete p_tail_;
      p_tail_= new_tail;
      --size_;
    }
  }
}

void Linked_list::swap( Linked_list &other ) {
  std::swap(p_head_, other.p_head_ );
  std::swap(p_tail_, other.p_tail_ );
  std::swap(size_, other.size_ );
}

void Linked_list::push_front( Linked_list &other ) {
  if ( this != &other && !other.is_empty() ) {
    if ( is_empty() ) {
      swap( other );
    }
    else {
      other.p_tail_->p_next_node( p_head_ );
      p_head_->p_prev_node( other.p_tail_ );
      p_head_ = other.p_head_;
      size_ += other.size();
      other.p_head_ = nullptr;
      other.p_tail_ = nullptr;
      other.size_ = 0; 
    }
  }
}

void Linked_list::push_back( Linked_list &other ) {
  swap( other );
  push_front( other );
}

void Linked_list::reverse() {
  if( p_head() != nullptr && p_head() != p_tail() ) {
    for ( Node *p_iterator{ p_head() }; p_iterator != nullptr; 
          p_iterator = p_iterator->p_prev_node() ) {
            p_iterator->reverse();
        }
    std::swap( p_head_, p_tail_ );
  }
}

int Linked_list::find( double const goal ) {
  int count{ 0 };
  for (Node *p_iterator{ p_head() }; p_iterator!= nullptr;
       p_iterator = p_iterator->p_next_node() ) {
         if ( p_iterator->value() == goal ) {
           return count;
         }
         else {
           count++;
         }
       }
  return -1;
}

void Linked_list::erase( std::size_t const index ) {
  std::size_t count{ 0 };
  if ( index == 0 ) {
    pop_front();
  }
  
  else if ( index == size() - 1 ) {
    pop_back();
  }
  else {
    for (Node *p_iterator{ p_head() }; p_iterator != nullptr;
      p_iterator = p_iterator->p_next_node() ) {
        if ( count == index ) {
          Node *p_to_erase{ new Node{ *p_iterator } } ;
          p_iterator = p_to_erase->p_prev_node();
          p_iterator->p_next_node( p_to_erase->p_next_node() );
          p_iterator = p_to_erase->p_next_node();
          p_iterator->p_prev_node ( p_to_erase->p_prev_node() );
          p_iterator = p_to_erase;
          --size_;
        }
        count++;
      }
  }
}

void Linked_list::erase( std::size_t const first_index,
                std::size_t const last_index ) {
  std::size_t count{ 0 };
  std::size_t start{ first_index };
  std::size_t end{ last_index };
  
  for (Node *p_iterator{ p_head() }; p_iterator != nullptr;
       p_iterator = p_iterator->p_next_node() ) {
        if ( count >= start && count <= end ) {
          Node *p_to_erase{ new Node{ *p_iterator } } ;
          p_iterator = p_to_erase->p_prev_node();
          p_iterator->p_next_node( p_to_erase->p_next_node() );
          p_iterator = p_to_erase->p_next_node();
          p_iterator->p_prev_node ( p_to_erase->p_prev_node() );
          p_iterator = p_to_erase;
          --size_;

        }
        count++;
      } 
}

void Linked_list::operator+( Linked_list const &rhs ) {
  Linked_list copy{ rhs };
  push_back( copy );
}


bool Linked_list::operator==( Linked_list const &rhs ) const {
  bool result{ true };
  Node *p_rhs_iterator{ rhs.p_head() };
  for (Node *p_iterator{ p_head() }; p_iterator != nullptr;
       p_iterator = p_iterator->p_next_node() ) {
         if ( p_iterator->value() != p_rhs_iterator->value() ) {
           result = false;
         }
         p_rhs_iterator = p_rhs_iterator->p_next_node();
       }
  return result;
}

bool Linked_list::operator!=( Linked_list const &rhs ) const {
  return !( operator==( rhs ) );
}

void Linked_list::clear() {
  while ( !is_empty() ) {
    pop_front();
  }
}

std::ostream &operator<<( std::ostream &out, 
                          Linked_list const &list ) {
  out << "List:-" << std::endl;
  out << "  head: " << list.p_head() << std::endl;
  out << "  tail: " << list.p_tail() << std::endl;
  out << "  size: " << list.size() << std::endl;
  
  out << "head <-> ";

  for ( Node *p_node{ list.p_head_ }; p_node != nullptr; 
        p_node = p_node->p_next_node() ) {
        out << p_node->value() << " <-> ";
  }

  out << "tail" << std::endl;
  return out;
}

std::istream &operator>>( std::istream &input, 
                          Linked_list &list ) {
  double value;
  input >> value;
  list.push_front( value );
  return input;
}
