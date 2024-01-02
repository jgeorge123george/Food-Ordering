#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book{
 private:
    int book_id;
    string book_name;

 public:

    Book(int book_id,string book_name){
      this->book_id = book_id;
      this->book_name = book_name;
    }

    friend std::ostream& operator<<(std::ostream& os,  const Book& b)    {
    os << "(" << b.book_id << "," << b.book_name << ")" << endl;
    return os;
  }

  bool operator==(const Book& other) const {
    return book_id == other.book_id ;
  }

 bool operator<(const Book& other) const {
      return book_id > other.book_id ;
 }

};



#endif
