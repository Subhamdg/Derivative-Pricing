# Derivative Pricing

This codebase contains C++ algorithms for pricing financial derivatives, including the Black-Scholes, Binomial, Monte Carlo, and Black-Derman-Toy models. The code is well-documented, adaptable, and open-source.

## Getting Started

To get started, clone this repository to your local machine:

```
git clone https://github.com/subhamdg/derivative-pricing.git
```

The code is written in C++ and can be compiled using a C++ compiler. The code has been tested on Linux and macOS.

## Usage

Each pricing model is implemented in its own source file. To use a particular model, include the corresponding header file in your code:

```
#include "black_scholes.h"
```

Then, call the pricing function with the necessary parameters:

```
double price = black_scholes_price(S, K, r, sigma, T);
```

where `S` is the stock price, `K` is the strike price, `r` is the risk-free rate, `sigma` is the volatility, and `T` is the time to expiration.

## Contributing

Contributions to this codebase are welcome. If you find a bug or would like to add a new feature or model, please open an issue or submit a pull request.

## Acknowledgments

This code is based on the book *Options, Futures, and Other Derivatives* by John C. Hull.
