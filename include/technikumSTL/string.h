#pragma once
#include <string>
#include <iostream>
#include <iterator> // std::forward_iterator_tag
#include <cstddef>  // std::ptrdiff_t

namespace technikum
{
  class string{

   protected:
    // this is our char* => composing the string we need
    // Erstellung eines Strings mit const char*
    char* class_str;
    // this is what we need for the length of the string
    unsigned int str_len = 0;

   public:
    // we need to iterate through the chars in the "string" we have
    // this is why I have here a nested Iterator Class
    class Iterators
    {
      using iterator_category = std::forward_iterator_tag; // scan forward multiple times and read/write with value it points to
      using difference_type = std::ptrdiff_t; // identify distance between it steps
      using val_type = char*; // type it iterates over
      using pointer = char*;
      using reference = char&; // reference to type iterates over
     private:
      pointer it;
     public:
      Iterators(pointer ptr) : it(ptr) {}


      // overload
      reference operator*() const { return *it; }
      pointer operator->() { return it; }

      Iterators& operator++() // ++it
      {
        it++;
        return *this;
      }
      Iterators operator++(int) // it++
      {
        Iterators temp(*this);
        ++(*this);
        return temp;
      }
      Iterators& operator--() //--it
      {
        it--;
        return *this;
      }
      Iterators operator--(int) // it--
      {
        Iterators temp(*this);
        --(*this);
        return temp;
      }
      bool operator==(const Iterators& it2)
      {
        return it == it2.it;
      }
      bool operator!=(Iterators& it2)
      {
        return it != it2.it;
      }
      friend bool operator==(const Iterators& it1, const Iterators& it2)
      {
        return it1.it == it2.it;
      }
      friend bool operator!=(const Iterators& it1, const Iterators it2)
      {
        return it1.it != it2.it;
      }
    };


    // lets create some more stuff for our StringClass
    // we firstly need constructors and destrcutors
    string(); // empty constructor
    // one parameter constructor
    string(char* str); // simple one parameter char constructor
    // const char constructor
    string(const char* str); // the const char constructor


    // destructor
    ~string();


    // setter // TODO: what is that ? => eggsplain
    void setClassStr(const char* str);
    operator const char* () const; // TODO: what is that even :sob:


    // Zusammenfügen von Strings über eine append() member Funktion ==> here is our append function
    void append(const char* str);
    // display the string object
    // Erlauben Sie den Zugriff auf die intern verwaltete
    // Zeichenkette über die c_str() member Funktion (c string
    // equivalent)
    const char* c_str() const;
    // for the length of our string
    static size_t getLength(const char* str);

    // how do we iterate through the string ?
    Iterators begin() const ;
    Iterators end() const ;

  };
}
