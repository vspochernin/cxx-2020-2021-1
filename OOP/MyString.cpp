#include <exception>

#include "MyString.h"
#include "Functions.h"

// ����������� ��� ����������.
MyString::MyString() : string_(nullptr), size_(0) {}

// ����������� � ���������� (�� ������� ������).
MyString::MyString(const char* string)
{
  size_t size = myStrLen(string);
  string_ = new char[size + 1];
  size_ = size;

  for (size_t i = 0; i < size; i++)
  {
    string_[i] = string[i];
  }

  string_[size] = '\0';
}

// ����������� �����������.
MyString::MyString(const MyString& myString)
{
  size_t size = myString.size_;
  string_ = new char[size + 1];
  size_ = size;

  for (size_t i = 0; i < size; i++)
  {
    string_[i] = myString.string_[i];
  }

  string_[size] = '\0';
}

// ����������.
MyString::~MyString()
{
  delete[] string_;
}

// �������� ������.
char* MyString::get() const
{
  return string_;
}

// ���������� ��������� =.
MyString& MyString::operator=(const MyString& myString2)
{
  if (this == &myString2)
  {
    return *this;
  }

  // ������� ������.
  if (string_ != nullptr)
  {
    delete[] string_;
  }

  size_ = myString2.size_;
  string_ = new char[size_ + 1];

  for (size_t i = 0; i < size_; i++)
  {
    string_[i] = myString2.string_[i];
  }

  string_[size_] = '\0';

  return *this;
}

// ���������� ��������� +.
MyString MyString::operator+(const MyString& myString2) const
{
  size_t size1 = size_;
  size_t size2 = myString2.size_;
  size_t newSize = size1 + size2;

  MyString newString;
  newString.size_ = newSize;
  newString.string_ = new char[newSize + 1];
  size_t i = 0;
  for (size_t j = 0; j < size1; j++)
  {
    newString.string_[i] = string_[i];
    i++;
  }
  for (size_t j = 0; j < size2; j++)
  {
    // TODO: ��� ������ � ���� �������?
    newString.string_[i] = myString2.string_[j];
    i++;
  }
  newString.string_[newSize] = '\0';

  return newString;
}

// ���������� �������� ==.
bool MyString::operator==(const MyString& myString2) const
{
  if (size_ != myString2.size_)
  {
    return false;
  }

  for (size_t i = 0; i < size_; i++)
  {
    if (string_[i] != myString2.string_[i])
    {
      return false;
    }
  }

  return true;
}

// ���������� �������� !=.
bool MyString::operator!=(const MyString& myString2) const
{
  if (size_ != myString2.size_)
  {
    return true;
  }

  for (size_t i = 0; i < size_; i++)
  {
    if (string_[i] != myString2.string_[i])
    {
      return true;
    }
  }

  return false;
}

// ���������� ��������� [].
char& MyString::operator[](size_t index)
{
  if ((index < 0) || (index >= size_))
  {
    // TODO: ��������, ��������� �� �����.
    throw (std::out_of_range("������������ ������, ����� �� ������� �������."));
  }

  return string_[index];
}