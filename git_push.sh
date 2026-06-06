#!/bin/bash
read -p "Commit message: " msg
git add .
git commit -m "$msg"
git push

read -p "Naciśnij Enter aby zamknąć..."