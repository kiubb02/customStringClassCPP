#include "technikumSTL/string.h"

void technikum::string::setClassStr(const char* str)
{
  str_len = this->getLength(str);
  class_str = new char[str_len + 1];
  for (int i = 0; str[i] != '\0'; i++) class_str[i] = str[i];
  class_str[str_len] = '\0';
}

technikum::string::string()
{
  class_str = nullptr;
  str_len = 0;
}

technikum::string::string(char * str)
{
  setClassStr(str);
  str_len = this->getLength(str);
}

technikum::string::string(const char* str)
{
  setClassStr(str);
  str_len = this->getLength(str);
}

// destructor
technikum::string::~string()
{
  if (class_str)
  {
    str_len = 0; // set length to 0
    delete class_str; // delete the object
  }
}

// TODO: What happens here even :sob:
void technikum::string::append(const char* str)
{
  int newStrLen = str_len + this->getLength(str);
  char* newClassStr = new char[newStrLen + 1];

  for (size_t i = 0; i < str_len; i++) newClassStr[i] = class_str[i];
  int j = 0;
  for (int i = str_len; i < newStrLen; i++) {
    newClassStr[i] = str[j];
    j++;
  }
  newClassStr[newStrLen] = '\0';
  setClassStr(newClassStr);
  delete[] newClassStr;
}

const char* technikum::string::c_str() const
{
  return class_str;
}

size_t technikum::string::getLength(const char* str)
{
  size_t len = 0;
  if (str == nullptr) return len; // return 0 if nullptr

  for (int i = 0; str[i] != '\0'; i++) { len++; }
  return len;
}

technikum::string::Iterators technikum::string::begin() const
{
  return Iterators(&class_str[0]);
}

technikum::string::Iterators technikum::string::end() const
{
  return Iterators(&class_str[str_len]);
}



