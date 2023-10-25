#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;

    Item(int w, int v) : weight(w), value(v) {}
};

bool compareByValuePerWeight(const Item& item1, const Item& item2) {
    double valuePerWeight1 = static_cast<double>(item1.value) / item1.weight;
    double valuePerWeight2 = static_cast<double>(item2.value) / item2.weight;
    return valuePerWeight1 > valuePerWeight2;
}

double fractionalKnapsack(vector<Item>& items, int capacity) {
    sort(items.begin(), items.end(), compareByValuePerWeight);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const Item& item : items) {
        if (currentWeight + item.weight <= capacity) {
            totalValue += item.value;
            currentWeight += item.weight;
        } else {
            double remainingWeight = capacity - currentWeight;
            totalValue += (remainingWeight / item.weight) * item.value;
            break; // Knapsack is full
        }
    }

    return totalValue;
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

    double maxValue = fractionalKnapsack(items, capacity);

    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    return 0;
}

