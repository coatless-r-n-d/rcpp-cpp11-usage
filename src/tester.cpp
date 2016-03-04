#include <RcppArmadillo.h>
#include <random>

// Quantile function

// [[Rcpp::export]]
arma::vec qexp( arma::vec& u, double lambda ){
  
  u = arma::log(0.1e1 - u);
  u = - u / lambda;
  
  return u;
}


// Simulate samples

// [[Rcpp::export]]
arma::vec rexp( unsigned int n, double lambda, const unsigned int& seed ){
  
  arma::vec u(n);
  
  // Generate a vector of uniform random variables
  // std::srand(seed);
  std::mt19937_64 engine(seed);  // Mersenne twister random number engine
  std::uniform_real_distribution<double> distr(0.0, 1.0);
  u.imbue( [&]() { return distr(engine); } );
  
  // Transform into Dagum random variables
  qexp(u,lambda);
  
  return u;
}