#include <iostream>
#include <cmath>
#include <vector>
#include <random>

using namespace std;

double black_scholes_price(double S, double K, double r, double sigma, double T) {
    double d1 = (log(S / K) + (r + sigma * sigma / 2) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    double N_d1 = 0.5 * (1 + erf(d1 / sqrt(2)));
    double N_d2 = 0.5 * (1 + erf(d2 / sqrt(2)));
    double price = S * N_d1 - K * exp(-r * T) * N_d2;
    return price;
}

double monte_carlo_price(double S, double K, double r, double sigma, double T, int N) {
    default_random_engine generator;
    normal_distribution<double> distribution(0.0, 1.0);
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        double z = distribution(generator);
        double ST = S * exp((r - sigma * sigma / 2) * T + sigma * sqrt(T) * z);
        double payoff = max(ST - K, 0.0);
        sum += payoff;
    }
    double price = exp(-r * T) * sum / N;
    return price;
}

int main() {
    double S = 100.0;
    double K = 110.0;
    double r = 0.05;
    double sigma = 0.2;
    double T = 1.0;
    int N = 100000;
    double bs_price = black_scholes_price(S, K, r, sigma, T);
    double mc_price = monte_carlo_price(S, K, r, sigma, T, N);
    cout << "Black-Scholes price: " << bs_price << endl;
    cout << "Monte Carlo price: " << mc_price << endl;
    return 0;
}
