#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double binomial_price(vector<double>& S, double K, double r, double sigma, double T, int N) {
    double dt = T / N;
    double u = exp(sigma * sqrt(dt));
    double d = 1 / u;
    double p = (exp(r * dt) - d) / (u - d);

    vector<double> v(N + 1);
    for (int i = 0; i <= N; ++i) {
        v[i] = max(S[0] * pow(u, i) * pow(d, N - i) - K, 0.0);
    }

    for (int n = N - 1; n >= 0; --n) {
        for (int i = 0; i <= n; ++i) {
            v[i] = exp(-r * dt) * (p * v[i + 1] + (1 - p) * v[i]);
        }
    }

    return v[0];
}

int main() {
    vector<double> S = {50, 55, 60, 65, 70};
    double K = 62;
    double r = 0.05;
    double sigma = 0.2;
    double T = 1;
    int N = 100;

    double price = binomial_price(S, K, r, sigma, T, N);

    cout << "Option price: " << price << endl;

    return 0;
}
