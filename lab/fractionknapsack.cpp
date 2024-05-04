#include <iostream>
using namespace std;

int main() {
    int kw = 25;
    int n = 5;
    int p[] = {1, 2, 3, 4, 5};
    int w[] = {5, 6, 7, 3, 5};
    float r[n];

    for (int i = 0; i < n; i++) {
        r[i] = (float)p[i] / w[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (r[j] < r[j + 1]) {
                float temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;

                int tempInt = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tempInt;

                tempInt = w[j];
                w[j] = w[j + 1];
                w[j + 1] = tempInt;
            }
        }
    }

    int P = 0;
    for (int i = 0; i < n; i++) {
        if (kw > 0 && w[i] <= kw) {
            P += p[i];
            kw -= w[i];
        } else {
            P += (p[i] * kw) / w[i];
            break;
        }
    }

    cout << P << endl;

    return 0;
}
