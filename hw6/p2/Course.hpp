#ifndef COURSE_H
#define COURSE_H

using namespace std;

class Course{
 private:
   int course_id;
   string course_name;

 public:

   Course(int course_id,string course_name){
     this->course_id = course_id;
     this->course_name = course_name;
   }

 friend std::ostream& operator<<(std::ostream& os,  const Course& c)  {
    os << "(" << c.course_id << "," << c.course_name << ")" << endl;
    return os;
  }

  bool operator==(const Course& other) const {
    return course_id == other.course_id ;
  }

 bool operator<(const Course& other) const {
         return course_id > other.course_id ;
 }


};

#endif
