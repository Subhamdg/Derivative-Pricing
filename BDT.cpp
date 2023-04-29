#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double bdt(double r0, double dt, double sigma, double a, double b, double n, double t, bool call_option = true) {
    double u = exp(sigma * sqrt(dt));
    double d = 1 / u;
    double p = (exp(a * dt) - d) / (u - d);
    double q = 1 - p;

    // Initialize vectors to store short rate and option values
    vector<double> r(n + 1);
    vector<double> c(n + 1);

    // Initialize short rate vector at time n
    for (int i = 0; i <= n; i++) {
        r[i] = r0 * pow(u, n - i) * pow(d, i);
    }

    // Calculate option payoff at maturity
    if (call_option) {
        for (int i = 0; i <= n; i++) {
            c[i] = max(r[i] - a, 0.0);
        }
    } else {
        for (int i = 0; i <= n; i++) {
            c[i] = max(b - r[i], 0.0);
        }
    }

    // Calculate option value at each time step
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i <= j; i++) {
            r[i] = r[i] / u;
            c[i] = (p * c[i] + q * c[i + 1]) * exp(-sigma * sqrt(dt));
            if (call_option) {
                c[i] = max(c[i], r[i] - a);
            } else {
                c[i] = max(c[i], b - r[i]);
            }
        }
    }

    double result = c[0];

    return result;
}

int main() {
    double r0 = 0.05; // initial short rate
    double dt = 0.25; // time step size
    double sigma = 0.2; // volatility
    double a = 0.05; // strike price
    double b = 0.1; // ceiling
    double n = 3; // number of time steps
    double t = 1.0; // time to maturity

    // Calculate call option price
    double call_price = bdt(r0, dt, sigma, a, b, n, t);

    // Calculate put option price
    double put_price = bdt(r0, dt, sigma, a, b, n, t, false);

    // Output prices to console
    cout << "Call option price: " << call_price << endl;
    cout << "Put option price: " << put_price << endl;

    return 0;
}
