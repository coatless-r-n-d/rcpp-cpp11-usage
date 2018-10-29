#include <RcppArmadillo.h>
#include <random>

//' Quantile function for exponential
//' 
//' Compute the quantile given a probability
//' 
//' @param p      Vector of Probabilities.
//' @param lambda Double of lambda.
//' 
//' @return 
//' A vector of quantiles
//' 
//' @export
//' @examples
//' # Compute one quantile
//' qexp_arma(0.6, 2)
//' 
//' # Compute two quantiles
//' qexp_arma(c(0.5, 0.2), 3)
// [[Rcpp::export]]
arma::vec qexp_arma( arma::vec& p, double lambda = 2) {
  
  p = arma::log(0.1 - p);
  p = - p / lambda;
  
  return p;
}


//' Simulate samples from an Exponential Distribution
//' 
//' Generates random values from an exponential distribution.
//' 
//' @param n      Number of observations to generate
//' @param lambda Rate parameter
//' @param seed   Starting value for the Random Number Generator (RNG).
//' 
//' @return 
//' A vector of random numbers from an exponential distribution.
//' 
//' @export
//' @examples
//' # Generate a random number
//' rexp_arma(1, lambda = 2)
//' 
//' # Generate two random numbers
//' rexp_arma(2, lambda = 9, seed = 8235)
// [[Rcpp::export]]
arma::vec rexp_arma( unsigned int n, double lambda = 2, const unsigned int& seed = 183) {
  
  // Initialize a vector of length n
  arma::vec u(n);
  
  // Generate a vector of uniform random variables
  std::mt19937_64 engine(seed);  // Mersenne twister random number engine
  std::uniform_real_distribution<double> distr(0.0, 1.0);
  u.imbue( [&]() { return distr(engine); } );
  
  // Transform into Dagum random variables
  qexp_arma(u, lambda);
  
  return u;
}