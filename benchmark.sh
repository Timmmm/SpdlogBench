#!/bin/bash

# Copy the `unit.cpp` file a load.
for n in {1..100}
do
	cp unit.cpp unit_$n.cpp
done

# Configure the builds.
for variant in a b c d e
do
	meson -Dvariant=$variant build_$variant
done

# Time compilation
for variant in a b c d e
do
	cd build_$variant
	time ninja
	cd ..
done
