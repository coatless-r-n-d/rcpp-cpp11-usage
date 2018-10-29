#include <RcppArmadillo.h>
#include <random>

//' Simulate samples from a Uniform Distribution
//' 
//' Generates random values from the C++11 Uniform Distribution.
//' 
//' @param n      Number of observations to generate
//' @param start  Beginning range of values
//' @param end    End range of values
//' @param seed   Starting value for the Random Number Generator (RNG).
//' 
//' @return 
//' A vector of random numbers from the Uniform distribution.
//' 
//' @export
//' @examples
//' # Generate a random number
//' runif_arma(1, start = 2, end = 20)
//' 
//' # Generate two random numbers
//' runif_arma(2, start = 5, end = 30)
// [[Rcpp::export]]
arma::vec runif_arma( unsigned int n, double start = 0.0, double end = 1.0,
                      const unsigned int& seed = 183) {
  
  // Initialize a vector of length n
  arma::vec u(n);
  
  // Generate a vector of uniform random variables
  std::mt19937_64 engine(seed);  // Mersenne twister random number engine
  std::uniform_real_distribution<double> u_dist(start, end);
  u.imbue( [&]() { return u_dist(engine); } );
  
  return u;
}