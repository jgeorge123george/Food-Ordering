#ifndef REPOSITORY_H 
#define REPOSITORY_H

#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Repository {
    
private:
    vector<T>  repo ;
    
    
public:
    
    Repository() {}
    
    //Rubric - Repository System : Add Item or Set
    void push(T object){
        //update if the item is allready there
        bool is_new_object = true;
        for (int i = 0; i < repo.size(); i++) {
            T old_object = repo[i];
            if(old_object == object){
                repo[i] = object;
                is_new_object = false;
            }
        }
        //add new object
        if(is_new_object){
            repo.push_back(object);
        }
    }
    
    //Rubric - Repository System : Add multiple Item or Set
    void push_items(vector<T>  repo_in){
        for(int i=0; i < repo_in.size();i++){
            push(repo_in[i]);
        }
    }
    
    
    //Rubric Remove item
    void remove(T object){
        for (int i = 0; i < repo.size(); i++) {
            T old_object = repo[i];
            if(old_object == object){
                repo.erase(repo.begin() + i);
            }
        }
    }

    void show_repo(){
         cout << "------------------------------"<<endl;
         for (int i = 0; i < repo.size(); i++) {
             cout<< repo[i] << endl;;
         }
     }

    //Rubric - remove more items
    void remove_items(vector<T>  repo_in){
        for(int i=0; i < repo_in.size();i++){
            remove(repo_in[i]);
        }
    }

    //Rubric  Return size of repo Size
    int item_count(){
        return repo.size();
    }
    
    // Rubric rank
    int rank(T object){
        for (int i = 0; i < repo.size(); i++) {
            if(repo[i] == object){
                return i;
            }
        }
        return -1;
    }
    
};



#endif 

