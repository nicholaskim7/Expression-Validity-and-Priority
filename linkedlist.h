#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct node{
  string data;
  double priority;
  node* next;
};

class ll
{
private:
  node* head;
  node* tail;
  int size;
public:
  ll(){
    head = tail = nullptr;
    size = 0;
  }

  ~ll(){ delete head;}

  node* createNode(string data, double pri){
    node* temp = new node;
    temp->data = data;
    temp->priority = pri;
    temp->next = nullptr;
  
    return temp;
  }

  void add(string data, double pri){
    node* temp = createNode(data, pri);
    if(isEmpty()){
      head = tail = temp;
    } else {
      tail->next = temp;
      tail = temp;
    }
    size++;
  }

  void remove(node* x){
    if(x == head){
      head = head->next;
    }
    else if(x == tail){
      node* curr = head;
      while(curr->next->next){
        curr = curr->next;
      }

      curr->next = nullptr;
      tail = curr;
    } else {
      node* curr = head;
      while(curr->next != x){
        curr = curr->next;
      }

      curr->next = x->next;
    }
  }

  bool isEmpty(){
    if(!head) return true;

    return false;
  }

  void print(ofstream &out, double pri){
    node* curr = head;
    while(curr){
      if(curr->priority == pri){
        
        if(curr->next != nullptr){
        out << curr->data << endl;
        }
        else {
          out << curr->data; //last does not have empty space - nick
        }
        remove(curr);
        return;
      }  
      curr = curr->next;
    }
  }

};
