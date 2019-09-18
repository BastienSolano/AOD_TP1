#!/bin/sh

for i in 100 200 300 400 500 600 700 800 900 1000
do
  time ./tp1 ijk $i
done
for i in 100 200 300 400 500 600 700 800 900 1000
do
  time ./tp1 ikj $i
done
