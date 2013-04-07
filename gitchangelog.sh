#!/bin/sh
# Convert git log to GNU-style ChangeLog file.

if test -d ".git"; then
    git log --date-order --date=short |     sed -e '/^commit.*$/d' > ChangeLog
    exit 0
else
    echo "No git repository present."
    exit 1
fi

