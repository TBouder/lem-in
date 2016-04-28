#!/bin/bash

make fclean
make
echo
if [ -e "auteur" ]; then
	user=$(cat auteur)
	iam=$(whoami)
	if [ "$user" = "$iam" ] ; then
		echo "Author file : \033[32;1mOK\033[00;0m"
	else
		echo "Author file : \033[31;1mError\033[00;0m"
	fi
else
	echo "\033[31;1mAuthor file missing\033[00;0m"
fi
echo

if [ $1 = "leaks" ]; then
	leaks="sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full -q"
else
	leaks=" "
fi

echo "Map opening"
# echo "\033[33;1mUnknow map\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/existepas
# echo "\033[33;1mFolder\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps
# echo "\033[33;1mWrong perm map\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/wrong_perm_map
# echo
# echo "Ants"
# echo "\033[33;1mNo ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/ants/no_ant
# echo "\033[33;1mSpace ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/ants/space_ant
# echo "\033[33;1mbackn ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/ants/backn_ant
# echo "\033[33;1mAlpha ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/ants/alpha_ant
# echo "\033[33;1mAlphanum ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/ants/alphanum_ant
# echo "\033[33;1m0 ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/ants/zero_ant
# echo
# echo "Rooms"
# echo "\033[33;1mNo room\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/no_room
# echo "\033[33;1mLroom\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/Lroom
# echo "\033[33;1mSame room\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/same_room
# echo "\033[33;1mSame room2\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/same_room2
# echo "\033[33;1mSame coo\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/same_coo
# echo "\033[33;1mNo pipe\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/no_pipe
# echo "\033[33;1mSpace middle of rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/space_middle_room
# echo "\033[33;1mSpace before rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/space_before_room
# echo "\033[33;1mSpace after of rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/space_after_room
# echo
# echo "Start & end"
# echo "\033[33;1mNo access after start\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/start_end/no_path_start
# echo "\033[33;1mNo access to end\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/start_end/no_access_end
# echo "\033[33;1mNo start rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/start_end/no_start
# echo "\033[33;1mNo end rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/start_end/no_end
# echo "\033[33;1mMultiple start rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/start_end/multi_start
# echo "\033[33;1mMultiple end rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/start_end/multi_end
# echo
echo "Comments (should work)"
echo "\033[33;1mComment_before_ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_before_ant
echo "\033[33;1mComment_after_ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_after_ant
echo "\033[33;1mComment_b_a_ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_b_a_ant

echo "\033[33;1mComment_before_end\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_before_end
echo "\033[33;1mComment_after_end\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_after_end

echo "\033[33;1mComment_before_pipes\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_before_pipes
echo "\033[33;1mComment_after_pipes\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_after_pipes
echo "\033[33;1mComment_b_a_pipes\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_b_a_pipes
echo "\033[33;1mComment_mass_pipes\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_mass_pipes

echo "\033[33;1mComment_before_rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_before_rooms
echo "\033[33;1mComment_after_rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_after_rooms
echo "\033[33;1mComment_b_a_rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_b_a_rooms
echo "\033[33;1mComment_mass_rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_mass_rooms

echo "\033[33;1mComment_before_start\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_before_start
echo "\033[33;1mComment_after_start\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/comment/comment_after_start



# echo "\033[33;1mPipe to itself\033[00;0m :" && ./lem-in < lem-in_maps/pipe_to_itself
# echo "\033[33;1mError middle pipe (Room not found)\033[00;0m :" && ./lem-in < lem-in_maps/error_middle_pipe
# echo "\033[33;1mSame pipe\033[00;0m :" && ./lem-in < lem-in_maps/same_pipe
# echo "\033[33;1mSame pipe2\033[00;0m :" && ./lem-in < lem-in_maps/same_pipe2
# echo "\033[33;1mSame pipe3\033[00;0m :" && ./lem-in < lem-in_maps/same_pipe3
# echo "\033[33;1mOne map\033[00;0m :" && ./lem-in < lem-in_maps/subject0.map
# echo "\033[33;1mTwo maps\033[00;0m :" && ./lem-in < lem-in_maps/subject0.map < lem-in_maps/subject1.map
# echo "\033[33;1mThree maps\033[00;0m :" && ./lem-in < lem-in_maps/subject0.map lem-in_maps/subject1.map lem-in_maps/subject2.map
# echo "\033[33;1mSpace middle of pipe\033[00;0m :" && ./lem-in < lem-in_maps/space_middle_pipe
# echo "\033[33;1mSpace after of pipe\033[00;0m :" && ./lem-in < lem-in_maps/space_after_pipe
