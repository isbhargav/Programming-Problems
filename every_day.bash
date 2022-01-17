#!/bin/bash

# output = `git ls-files --others --exclude-standard`
# for i in $(git ls-files --others --exclude-standard); do echo "$i"; done;
op=$(git ls-files --others --exclude-standard | head -n 1);
log=$(git add "$op")
log=$(git commit -m "$op")
log=$(git push origin master)
