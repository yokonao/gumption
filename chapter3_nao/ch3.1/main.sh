#!/bin/sh

set -euo pipefail

function main() {
    make clean
    make test
    ./exe.out
    make clean
    make
    ./exe.out
    make clean
}

main
