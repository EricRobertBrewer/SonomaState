#ifndef WORM_TMP
#define WORM_TMP

template<class T> class Worm;

template<class T>
class Worm{

private:
  class WNode{
    
  public:
    WNode();
    T data;
    WNode * next;
    WNode * prev; 
  };
  
public:
  Worm();
  Worm(const Worm & other);
  ~Worm();
  Worm & operator = (const Worm & other);
  int Size() const;
  bool growHead(const T & value);
  bool snipTail();
  T front();
  T back();
  
private:
  WNode * head;
  WNode * tail;
  int size;
};

template<class T>
Worm<T> :: WNode :: WNode(){
  next = NULL;
  prev = NULL;
}

template<class T>
Worm<T> :: Worm(){
  head = NULL;
  tail = NULL;
  size = 0;
}

template<class T>
Worm<T> :: Worm(const Worm & other){
  tail = NULL;
  size = 0;
  for(WNode * n = other.tail; n; n = n->prev)
    growHead(n->data);
}

template<class T>
Worm<T> :: ~Worm(){
  while(tail)
    snipTail();
}

template<class T>
Worm<T> & Worm<T> :: operator = (const Worm & other){
  if(this == &other)
    return *this;
  while(tail)
    snipTail();
  for(WNode * n = other.tail; n; n = n->prev)
    growHead(n->data);
  return *this;
}

template<class T>
int Worm<T> :: Size() const{
  return size;
}

template<class T>
bool Worm<T> :: growHead(const T & value){
  WNode * np = new WNode;
  if(np == NULL)
    return false;
  np->data = value;
  if(size == 0){
    head = np;
  tail = np;
  }
  else{
    head->prev = np;
    np->next = head;
    head = np;
  }
  size++;
  return true;
}

template<class T>
bool Worm<T> :: snipTail(){
  if(size == 0)
    return false;
  WNode * np = new WNode;
  np = tail;
  if(size == 1){
    head = NULL;
    tail = NULL;
  }
  else{
    tail = tail->prev;
    tail->next = NULL;
  }
  delete np;
  size--;
  return true;
}

template<class T>
T Worm<T> :: front(){
  return head;
}

template<class T>
T Worm<T> :: back(){
  return tail;
}

#endif

    
