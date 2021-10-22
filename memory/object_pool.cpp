#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
  T* Allocate() {
    T* newT;
    if(deallocated.empty()) {
      newT = new T;
    } else {
      newT = deallocated.front();
      deallocated.pop();
    }
    allocated.insert(newT);
    return newT;
  }

  T* TryAllocate() {
    if(deallocated.empty()) {
      return nullptr;
    }
    return Allocate();
  }

  void Deallocate(T* object) {
    if(allocated.find(object) == allocated.end()) {
      throw invalid_argument("There is no such object");
    }
    deallocated.push(object);
    allocated.erase(object);
  }

  ~ObjectPool() {
    while(!deallocated.empty()) {
      delete deallocated.front();
      deallocated.pop();
    }
    while(!allocated.empty()) {
      delete *allocated.begin();
      allocated.erase(*allocated.begin());
    }
  }

private:
  queue<T*> deallocated;
  set<T*> allocated; 
  // Добавьте сюда поля
};

void TestObjectPool() {
  ObjectPool<string> pool;

  auto p1 = pool.Allocate();
  auto p2 = pool.Allocate();
  auto p3 = pool.Allocate();

  *p1 = "first";
  *p2 = "second";
  *p3 = "third";

  pool.Deallocate(p2);
  ASSERT_EQUAL(*pool.Allocate(), "second");

  pool.Deallocate(p3);
  pool.Deallocate(p1);
  ASSERT_EQUAL(*pool.Allocate(), "third");
  ASSERT_EQUAL(*pool.Allocate(), "first");

  pool.Deallocate(p1);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestObjectPool);
  return 0;
}
