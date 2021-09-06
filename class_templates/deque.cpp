#include "deque.h"
#include "test_runner.h"

using namespace std;

void TestDeque() {
    Deque<int> d;
    ASSERT_EQUAL(d.Empty(), true);
    d.PushFront(1);
    d.PushBack(2);
    ASSERT_EQUAL(d.Size(), 2);
    ASSERT_EQUAL(d[0], 1);
    ASSERT_EQUAL(d.Back(), 2);
    ASSERT_EQUAL(d.Front(), 1);
    d[0] = 3;
    ASSERT_EQUAL(d.At(0), 3);
    try
    {
        ASSERT_EQUAL(d.At(2), 0);
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestDeque);
    return 0;
}
