#!/bin/sh

set -euo pipefail

function finally() {
    make clean
}

function main() {
    trap finally EXIT
    make clean
    make test
    ./exe.out
}

main
