#include <iostream>

#include "Book.hpp"
#include "Course.hpp"
#include "Repository.hpp"

using namespace std;


int main() {
    
  // Rubric - Testing with two User defined types

  Repository<Book> bookRepository;
  //Add new items to book repo
  bookRepository.push(Book(600,"C++"));
  bookRepository.push(Book(100,"Java"));
  bookRepository.show_repo();
  //update an ityem in book repo
  bookRepository.push(Book(100,"C Plus Plus"));
  bookRepository.show_repo();
  //add more than one book to the repo
  vector<Book> books;
  books.push_back(Book(300,"Python"));
  books.push_back(Book(400,"JavaScript"));
  books.push_back(Book(400,"OS"));
  bookRepository.push_items(books);
  bookRepository.show_repo();
  //Rank
  cout <<"The rank of 300 " << bookRepository.rank(Book(300,"Python")) << endl;
  cout <<"The rank of 1000 " << bookRepository.rank(Book(1000,"X")) << endl;
  //Remove one Book
  bookRepository.remove(Book(200,"Java"));
  bookRepository.show_repo();
  //Remove few books
  bookRepository.remove_items(books);
  bookRepository.show_repo();
  cout<<"The count of books is" << bookRepository.item_count() << endl;

  Repository<Course> courseRepository;
  //Add items to course repo
  courseRepository.push(Course(100,"Math"));
  courseRepository.push(Course(200,"English"));
  courseRepository.show_repo();
  //updates items in course repo
  courseRepository.push(Course(200,"English 101"));
  courseRepository.show_repo();
  //add more than one Course
  vector<Course> courses;
  courses.push_back(Course(300,"Physics"));
  courses.push_back(Course(400,"chemistry"));
  //Rank
  cout <<"The rank of 300 " << courseRepository.rank(Course(300,"Physics")) << endl;
  cout <<"The rank of 1300 " << courseRepository.rank(Course(1300,"X")) << endl;
  courseRepository.push_items(courses);
  courseRepository.show_repo();
  // remove one course
  courseRepository.remove(Course(100,"Math"));
  courseRepository.show_repo();
  //remove few courses
  courseRepository.remove_items(courses);
  courseRepository.show_repo();
  cout<<"The count of Courses is " << courseRepository.item_count() << endl;
    
    
  // Rubric - Testing with two generics
    
  Repository<int> ints;
  ints.push(100);
  ints.push(200);
  ints.show_repo();
  vector<int> myints = { 300,400};
  ints.push_items(myints);
  ints.show_repo();
  //ranks
  cout <<"The rank of 300 " << ints.rank(300) << endl;
  cout <<"The rank of 1000 " << ints.rank(1000) << endl;
  //remove one int
  ints.remove(100);
  ints.show_repo();
  // remove more than one number
  ints.remove_items(myints);
  ints.show_repo();


  Repository<float> floats_repo;
  floats_repo.push(100.15);
  floats_repo.push(200.15);
  floats_repo.show_repo();
  vector<float> flots = { 300.15,400.15};
  //ranks
  cout <<"The rank of 100.15 " << floats_repo.rank(100.15) << endl;
  cout <<"The rank of 1000.1 " << floats_repo.rank(1000) << endl;
  floats_repo.push_items(flots);
  floats_repo.show_repo();
  //remove one int
  floats_repo.remove(100.15);
  floats_repo.show_repo();
  // remove more than one number
  floats_repo.remove_items(flots);
  floats_repo.show_repo();
    
}

