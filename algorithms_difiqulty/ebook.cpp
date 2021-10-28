#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <numeric>

using namespace std;

class ReadingManager {
public:
  ReadingManager()
      : users_count(MAX_PAGE_COUNT_ + 1, 0),
        pages_rating(MAX_PAGE_COUNT_ + 1, 0) {}

  void Read(int user_id, int page_count) {
    if (users_on_page[user_id] != 0) {
      --users_count[users_on_page[user_id]];
    }
    users_on_page[user_id] = page_count;
    ++users_count[page_count];
    RecountRating();
  }

  double Cheer(int user_id) const {
    if(users_on_page.find(user_id) == users_on_page.end()) {
        return 0;
    } else if(users_on_page.size() == 1) {
        return 1;
    } else {
        return pages_rating[users_on_page.at(user_id)];
    }
  }

private:
  // Статическое поле не принадлежит какому-то конкретному
  // объекту класса. По сути это глобальная переменная,
  // в данном случае константная.
  // Будь она публичной, к ней можно было бы обратиться снаружи
  // следующим образом: ReadingManager::MAX_PAGE_COUNT.
  static const int MAX_PAGE_COUNT_ = 1000;

  map<int, int> users_on_page;
  vector<int> users_count;
  vector<double> pages_rating;

  void RecountRating() {
    double sum = 0;
    for(int i = 0; i <= MAX_PAGE_COUNT_; ++i) {
        pages_rating[i] = sum / (users_on_page.size() - 1);
        sum += users_count[i];
    }
  }

};


int main() {
  // Для ускорения чтения данных отключается синхронизация
  // cin и cout с stdio,
  // а также выполняется отвязка cin от cout
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ReadingManager manager;

  int query_count;
  cin >> query_count;

  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int user_id;
    cin >> user_id;

    if (query_type == "READ") {
      int page_count;
      cin >> page_count;
      manager.Read(user_id, page_count);
    } else if (query_type == "CHEER") {
      cout << setprecision(6) << manager.Cheer(user_id) << "\n";
    }
  }

  return 0;
}
