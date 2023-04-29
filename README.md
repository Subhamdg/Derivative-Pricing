## Black-Derman-Toy (BDT) model for pricing interest rate derivatives

This C++ code implements the Black-Derman-Toy (BDT) model for pricing interest rate derivatives. The BDT model is a one-factor short-rate model that assumes that the short-term interest rate follows a log-normal process.

The code is organized into several functions:
- `BDTModel`: This function takes the current short-term interest rate, the time to maturity of the option, and the volatility of the short-term interest rate as inputs, and returns a vector containing the binomial tree of interest rates.
- `OptionPrice`: This function takes the binomial tree of interest rates and the strike price of the option as inputs, and returns the price of the option.
- `main`: This function sets the initial parameters, calls the `BDTModel` function to generate the binomial tree of interest rates, and then calls the `OptionPrice` function to calculate the price of the option.

To use the code, simply compile it using a C++ compiler and run the executable. You will be prompted to enter the initial short-term interest rate, the time to maturity of the option, the volatility of the short-term interest rate, and the strike price of the option. The code will then calculate and output the price of the option.

The code can be made more complex by adding additional functions to calculate the implied volatility of the short-term interest rate, the delta and gamma of the option, or by allowing the user to input the binomial tree of interest rates directly. Additionally, the code can be optimized for performance by using more efficient data structures, such as matrices or arrays, instead of vectors, and by implementing parallelization techniques to speed up the calculation.
