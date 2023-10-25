#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;

    Item(int w, int v) : weight(w), value(v) {}
};

int knapsackDP(vector<Item>& items, int capacity) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (items[i - 1].weight > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n; // Number of items
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;

    for (int i = 0; i < n; ++i) {
        int weight, value;
        cout << "Enter the weight and value of item " << i + 1 << ": ";
        cin >> weight >> value;
        items.emplace_back(weight, value);
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int maxValue = knapsackDP(items, capacity);

    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    return 0;
}

