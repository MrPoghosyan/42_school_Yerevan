#!/bin/bash

make
EXEC=./so_long
VALGRIND_OPTS="--leak-check=full --show-leak-kinds=all"

MAPS=(
  maps/valid.ber
  maps/4.ber
  maps/invalid_char.ber
  maps/invalid_extension.txt
  maps/multi_exit.ber
  maps/multi_player.ber
  maps/new_len.ber
  maps/no_collectible.ber
  maps/no_exit.ber
  maps/no_path.ber
  maps/no_path_collectible.ber
  maps/no_player.ber
  maps/not_surrounded.ber
  maps/valid1.ber
)

function run_tests() {
  for map in "${MAPS[@]}"; do
    echo "=============================="
    echo "Testing: $map"
    valgrind $VALGRIND_OPTS $EXEC "$map"
    echo "=============================="
    echo
  done
}

echo ">>> Compiling project..."
if [[ $? -ne 0 ]]; then
  echo "Compilation failed. Exiting."
  exit 1
fi

echo "=== [1] Running tests with valid textures ==="
run_tests

if [[ -f textures/exit.xpm ]]; then
  echo ">>> Simulating missing texture..."
  mv textures/exit.xpm textures/exit1.xpm

  echo "=== [2] Running tests with missing texture ==="
  run_tests

  echo ">>> Restoring texture..."
  mv textures/exit1.xpm textures/exit.xpm
else
  echo "ERROR: textures/exit.xpm not found!"
fi

echo ">>> Cleaning up..."
make fclean

echo ">>> Done."
