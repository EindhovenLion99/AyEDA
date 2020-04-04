#include <iostream>

using namespace std;

template <class TDato>

class queue_t {
 private:
  int size;
  TDato* buffer;
  TDato front;
  TDato rear;
  int counter = 0;

 public:
  queue_t(TDato n) {
    front = 0;
    rear = 0;
    size = n;
    buffer = new TDato[size];
    if (buffer != NULL) counter++;
  }

  ~queue_t(void) {  // destructor
    delete buffer;
    counter--;
  }

  void enqueue(TDato v) {  // add element at the end of queue
    if (rear < size)
      buffer[rear++] = v;
    else if (compact())
      buffer[rear++] = v;
  }

  TDato dequeue(void) {  // return and remove 1st element from queue
    if (front < rear)
      return buffer[front++];
    else {
      cout << "Error: Cola vacia" << endl;
      return -1;
    }
  }

  bool compact() {
    if (front == 0) {
      cout << "Error: Overflow" << endl;
      return false;
    } else {
      for (int i = 0; i < rear - front; i++) {
        buffer[i] = buffer[i + front];
      }
      rear = rear - front;
      front = 0;
      return true;
    }
  }
  
  void write(){
    cout << "[";
    for(int i = 0; i < rear; i++){
        cout << "[" << buffer[i] << "]";
    }
    cout << "] " << endl;
  }
};