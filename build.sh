#!/bin/bash

# This script runs Precompile on every file that starts with '@PC'.
# Running Precompile on @PCindex.html will generate a new index.html file,
# so be careful not to overwrite any files you may be working on. 

make
./Precompile @PC*


# Open website (for convenience)
open index.html
