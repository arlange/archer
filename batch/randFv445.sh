#!/bin/bash

# get all primes
data=/home/alex/research/data/fv445/19_2

for n in 19
do
    for t in {1..1000}
    do
	name=${n}_${t}
	./randFv445 ${n} ${data}/log.txt ${data}/${name} | /home/alex/research/archer/archer
	sleep 2
    done
done
