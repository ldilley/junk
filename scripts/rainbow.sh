#!/bin/sh
# Usage: rainbow.sh [string]
for i in {0..255}; do
  if [ -z "${1}" ]; then
    set "Default"
  fi
  printf "\x1b[38;5;${i}m$*\x1b[0m\n"
done
