#!/bin/sh

set -euo pipefail

function catch() {
    make clean
}

function main() {
    trap catch EXIT
    make test
    ./exe.out
}

main
