#!/bin/bash

make fclean
make
echo "Map opening"
# echo "No map\033[00;0m : \c" && ./lem-in
echo "\033[33;1mUnknow map\033[00;0m : \c" && ./lem-in lem-in_maps/existepas
echo "\033[33;1mFolder\033[00;0m : \c" && ./lem-in lem-in_maps
echo "\033[33;1mWrong perm map\033[00;0m : \c" && ./lem-in lem-in_maps/wrong_perm_map
echo
echo "\033[33;1mNo ant\033[00;0m : \c" && ./lem-in lem-in_maps/no_ant
echo "\033[33;1mSpace ant\033[00;0m : \c" && ./lem-in lem-in_maps/space_ant
echo "\033[33;1mbackn ant\033[00;0m : \c" && ./lem-in lem-in_maps/backn_ant
echo "\033[33;1mAlpha ant\033[00;0m : \c" && ./lem-in lem-in_maps/alpha_ant
echo "\033[33;1mAlphanum ant\033[00;0m : \c" && ./lem-in lem-in_maps/alphanum_ant
echo "\033[33;1m0 ant\033[00;0m : \c" && ./lem-in lem-in_maps/zero_ant
echo
echo "\033[33;1mOne map\033[00;0m : \c" && ./lem-in lem-in_maps/subject0.map
echo "\033[33;1mTwo maps\033[00;0m : \c" && ./lem-in lem-in_maps/subject0.map lem-in_maps/subject1.map
echo "\033[33;1mThree maps\033[00;0m : \c" && ./lem-in lem-in_maps/subject0.map lem-in_maps/subject1.map lem-in_maps/subject2.map
