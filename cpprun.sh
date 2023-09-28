#!/bin/bash

souceFile=$1
# check if $1
[[ -z $1 ]] && {
  echo -e ":requires source file"
  echo -e ":${0} test.cpp"
  exit 1
}

# check for source file
[[ ! -f $1 ]] && {
  echo -e ":source file $1 not found.."
  exit 1
}

BSNME_sourceFile=$( basename $souceFile )
outTemp=$(mktemp /tmp/$BSNME_sourceFile-XXX)

echo -e ":compiling $1 .."
time g++ -o $outTemp $souceFile

echo
echo "Exec..."
# exec
time $outTemp

# cleanup
rm $outTemp
