#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double normal_cdf(double x) {
    return 0.5 * erfc(-x / sqrt(2));
}

double black_scholes_price(double S, double K, double r, double sigma, double T) {
    double d1 = (log(S / K) + (r + sigma * sigma / 2) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    double N_d1 = normal_cdf(d1);
    double N_d2 = normal_cdf(d2);
    double call_price = S * N_d1 - K * exp(-r * T) * N_d2;
    double put_price = K * exp(-r * T) * (1 - N_d2) - S * (1 - N_d1);
    return call_price;
}

int main() {
    double S = 100; // stock price
    double K = 110; // strike price
    double r = 0.05; // risk-free rate
    double sigma = 0.2; // volatility
    double T = 1; // time to maturity
    vector<double> option_prices;

    for (double t = 0.1; t <= T; t += 0.1) {
        double option_price = black_scholes_price(S, K, r, sigma, t);
        option_prices.push_back(option_price);
    }

    for (int i = 0; i < option_prices.size(); i++) {
        cout << "Option price at time " << (i + 1) * 0.1 << ": " << option_prices[i] << endl;
    }

    return 0;
}
