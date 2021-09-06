#include "test_runner.h"

#include <vector>

using namespace std;

// Реализуйте здесь шаблонный класс Table
template<typename T>
class Table {
public:
    Table(size_t x, size_t y) {
        Resize(x, y);
    }

    pair<size_t, size_t> Size() const {
        if(!table.empty() && !table[0].empty()) {
            return {table.size(), table[0].size()};
        }
        return {0, 0};
    }

    void Resize(size_t x, size_t y) {
        table.resize(x);
        for(auto& i : table) {
            i.resize(y);
        }
    }

    vector<T>& operator[](size_t i) {
        return table[i];
    }

    vector<T>& operator[](size_t i) const {
        return table[i];
    }

private:
    vector<vector<T>> table;
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}