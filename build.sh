#!/bin/bash

cd builddir
meson compile &&
mv a.out ../a.out