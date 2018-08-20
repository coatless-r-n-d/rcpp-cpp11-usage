## Compiling Code Under C++11

[![Travis-CI Build Status](https://travis-ci.org/r-pkg-examples/rcpp-cpp11-usage.svg?branch=master)](https://travis-ci.org/r-pkg-examples/rcpp-cpp11-usage)

The `r11` R package provides an example of setting a package to use C++11
as the language specification.

### Usage

To install the package, you must first have a compiler on your system that is 
compatible with R. For help on obtaining a compiler consult either
[macOS](http://thecoatlessprofessor.com/programming/r-compiler-tools-for-rcpp-on-os-x/)
or 
[Windows](http://thecoatlessprofessor.com/programming/rcpp/install-rtools-for-rcpp/)
guides.

With a compiler in hand, one can then install the package from GitHub by:

```r
# install.packages("devtools")
devtools::install_github("r-pkg-examples/rcpp-cpp11-usage")
library("r11")
```

### Implementation Details

To do

## License

GPL (\>= 2)