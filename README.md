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

To compile code with _C++11_ or greater, you must specify the dependency in
either the `DESCRIPTION` or `Makevars{.win}` files. For convenience, both
are specified here. More details can be found in 
[Writing R Extensions: 1.2.4 Using C++11 code](https://cran.r-project.org/doc/manuals/r-release/R-exts.html#Using-C_002b_002b11-code). 
Furthermore, to test a _C++-11_ package on Travis-CI, you will need to change
the default compiler. Details may be found after the jump.

### `DESCRIPTION`

The `DESCRIPTION` file acts as a way to set the meta data for the _R_ package. 
Using the `SystemRequirements` field and specifying `C++11` will cause the
package to default into using _C++11_. This is a popular option to take 
if the _R_ package omits the `Makevars`/`Makevars.win` files.

```bash
SystemRequirements: C++11
```

### `Makevars`

The `Makevars` file, as specified in [Writing R Extensions: 1.2.1 Using Makevars](https://cran.r-project.org/doc/manuals/r-release/R-exts.html#Using-Makevars), is a variant of [`Make`](https://www.gnu.org/software/make/manual/make.html) that is _unique_ to _R_. One custom variable that _R_ defines is the `CXX_STD`. Specifying this
alongside of a standard like `CXX98`, `CXX11`, `CXX14`, and so on will cause
the appropriate language standard flag to be set. 

```bash
CXX_STD = CXX11
```

### Travis CI

To switch different compilers under the default Trusty image served by
Travis-CI, you will need to use the PPA associated with the
[toolchain test builds](https://launchpad.net/~ubuntu-toolchain-r/+archive/ubuntu/test). 
In addition, you will also have to set different configuration variables. Each
step is broken down in the next portions. All steps are present in the
`.travis.yml` file.

Within `addons`, we establish a connection to the [toolchain test builds](https://launchpad.net/~ubuntu-toolchain-r/+archive/ubuntu/test) PPA
and request the latest versions of `gcc-8`, `gfortran-8`, and `g++-8`.

```yaml
addons:
  apt:
    sources: ['ubuntu-toolchain-r-test']
    packages:
      - gcc-8
      - g++-8
      - gfortran-8
```

We then set different environment configuration flags to use
`gcc-8`, `gfortran-8`, and `g++-8`. In addition, we opt to use both cores available
in the Travis CI container via the `MAKEFLAGS` statement.

```yaml
env:
  global:
  - MAKEFLAGS="-j 2"
  - COMPILER=g++-8
  - CC=gcc-8
  - CXX=g++-8
```

Lastly, we setup environmental variables for _R_'s `Makevars` file and 
specify compiler alternative with their respective priorities. 

```yaml
before_install:
  - mkdir -p ~/.R && touch ~/.R/Makevars
  - VER=-8
  - echo "CC=gcc$(VER)"        >> ~/.R/Makevars
  - echo "CXX=g++$(VER)"       >> ~/.R/Makevars
  - echo "CXX1X=g++$(VER)"     >> ~/.R/Makevars
  - echo "FC=gfortran$(VER)"   >> ~/.R/Makevars
  - echo "F77=gfortran$(VER)"  >> ~/.R/Makevars
  - sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-8 60 --slave /usr/bin/g++ g++ /usr/bin/g++-8
  - sudo update-alternatives --install /usr/bin/gfortran gfortran /usr/bin/gfortran-8 60
```

## License

GPL (\>= 2)