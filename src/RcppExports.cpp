// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// qexp
arma::vec qexp(arma::vec& u, double lambda);
RcppExport SEXP rc11_qexp(SEXP uSEXP, SEXP lambdaSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< arma::vec& >::type u(uSEXP);
    Rcpp::traits::input_parameter< double >::type lambda(lambdaSEXP);
    __result = Rcpp::wrap(qexp(u, lambda));
    return __result;
END_RCPP
}
// rexp
arma::vec rexp(unsigned int n, double lambda, const unsigned int& seed);
RcppExport SEXP rc11_rexp(SEXP nSEXP, SEXP lambdaSEXP, SEXP seedSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< unsigned int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type lambda(lambdaSEXP);
    Rcpp::traits::input_parameter< const unsigned int& >::type seed(seedSEXP);
    __result = Rcpp::wrap(rexp(n, lambda, seed));
    return __result;
END_RCPP
}
