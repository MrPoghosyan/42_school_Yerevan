#!/bin/bash
git status --ignored --porcelain | grep '^[[:space:]]*!!' | cut -c 4-
