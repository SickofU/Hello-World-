#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> calculateNGE(vector<int>& arr) {
    int N = arr.size();
    vector<int> result(N, -1);
    stack<int> s;

    for (int i = 0; i < N; i++) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    return result;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> result = calculateNGE(A);

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
