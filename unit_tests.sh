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

if [ "$1" = "leaks" ]; then
	leaks="sh /Volumes/USB/.files/valgrind/vg-in-place --leak-check=full -q"
else
	leaks=""
fi

echo "Map opening"
echo "\033[33;1mUnknow map\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/existepas
echo "\033[33;1mFolder\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps
echo "\033[33;1mWrong perm map\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/wrong_perm_map
echo
echo "Ants"
echo "\033[33;1mNo ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/ants/no_ant
echo "\033[33;1mSpace ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/ants/space_ant
echo "\033[33;1mbackn ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/ants/backn_ant
echo "\033[33;1mAlpha ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/ants/alpha_ant
echo "\033[33;1mAlphanum ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/ants/alphanum_ant
echo "\033[33;1m0 ant\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/ants/zero_ant
echo
echo "Rooms"
echo "\033[33;1mNo room\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/no_room
echo "\033[33;1mLroom\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/Lroom
echo "\033[33;1mSame room\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/same_room
echo "\033[33;1mSame room2\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/same_room2
echo "\033[33;1mSame coo\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/same_coo
echo "\033[33;1mNo pipe\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/no_pipe
echo "\033[33;1mSpace middle of rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/space_middle_room
echo "\033[33;1mSpace before rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/space_before_room
echo "\033[33;1mSpace after of rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/rooms/space_after_room
echo
echo "Start & end"
echo "\033[33;1mNo access after start\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/start_end/no_path_start
echo "\033[33;1mNo access to end\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/start_end/no_access_end
echo "\033[33;1mNo start rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/start_end/no_start
echo "\033[33;1mNo end rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/start_end/no_end
echo "\033[33;1mMultiple start rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/start_end/multi_start
echo "\033[33;1mMultiple end rooms\033[00;0m : \c" && $leaks ./lem-in < lem-in_maps/error/start_end/multi_end
echo
echo "Comments (should work)"
if [ "$leaks" = "" ] ; then
	fonc[0]=$(bash -c 'diff -u <(cat lem-in_maps/comment/comment_before_ant) <(./lem-in < lem-in_maps/comment/comment_before_ant)')
	name[0]="\033[33;1mComment_before_ant\033[00;0m"
	fonc[1]=$(bash -c 'diff <(cat < lem-in_maps/comment/comment_after_ant) <(./lem-in < lem-in_maps/comment/comment_after_ant)')
	name[1]="\033[33;1mComment_after_ant\033[00;0m"
	fonc[2]=$(bash -c 'diff <(cat < lem-in_maps/comment/comment_b_a_ant) <(./lem-in < lem-in_maps/comment/comment_b_a_ant)')
	name[2]="\033[33;1mComment_b_a_ant\033[00;0m"
	fonc[3]=$(bash -c 'diff <(cat < lem-in_maps/comment/comment_before_end) <(./lem-in < lem-in_maps/comment/comment_before_end)')
	name[3]="\033[33;1mComment_before_end\033[00;0m"
	fonc[4]=$(bash -c 'diff <(cat < lem-in_maps/comment/comment_after_end) <(./lem-in < lem-in_maps/comment/comment_after_end)')
	name[4]="\033[33;1mComment_after_end\033[00;0m"
	fonc[5]=$(bash -c 'diff <(cat < lem-in_maps/comment/comment_before_pipes) <(./lem-in < lem-in_maps/comment/comment_before_pipes)')
	name[5]="\033[33;1mComment_before_pipes\033[00;0m"
	fonc[6]=$(bash -c 'diff <(cat < lem-in_maps/comment/comment_after_pipes) <(./lem-in < lem-in_maps/comment/comment_after_pipes)')
	name[6]="\033[33;1mComment_after_pipes\033[00;0m"
	fonc[7]=$(bash -c 'diff <(cat < lem-in_maps/comment/comment_b_a_pipes) <(./lem-in < lem-in_maps/comment/comment_b_a_pipes)')
	name[7]="\033[33;1mComment_b_a_pipes\033[00;0m"
	fonc[8]=$(bash -c 'diff <(cat < lem-in_maps/comment/comment_mass_pipes) <(./lem-in < lem-in_maps/comment/comment_mass_pipes)')
	name[8]="\033[33;1mComment_mass_pipes\033[00;0m"
	fonc[9]=$(bash -c 'diff <(cat < lem-in_maps/comment/comment_before_rooms) <(./lem-in < lem-in_maps/comment/comment_before_rooms)')
	name[9]="\033[33;1mComment_before_rooms\033[00;0m"
	fonc[10]=$(bash -c 'diff <(cat < lem-in_maps/comment/comment_after_rooms) <(./lem-in < lem-in_maps/comment/comment_after_rooms)')
	name[10]="\033[33;1mComment_after_rooms\033[00;0m"
	fonc[11]=$(bash -c 'diff <(cat < lem-in_maps/comment/comment_b_a_rooms) <(./lem-in < lem-in_maps/comment/comment_b_a_rooms)')
	name[11]="\033[33;1mComment_b_a_rooms\033[00;0m"
	fonc[12]=$(bash -c 'diff <(cat < lem-in_maps/comment/comment_mass_rooms) <(./lem-in < lem-in_maps/comment/comment_mass_rooms)')
	name[12]="\033[33;1mComment_mass_rooms\033[00;0m"
	fonc[13]=$(bash -c 'diff <(cat < lem-in_maps/comment/comment_before_start) <(./lem-in < lem-in_maps/comment/comment_before_start)')
	name[13]="\033[33;1mComment_before_start\033[00;0m"
	fonc[14]=$(bash -c 'diff <(cat < lem-in_maps/comment/comment_after_start) <(./lem-in < lem-in_maps/comment/comment_after_start)')
	name[14]="\033[33;1mComment_after_start\033[00;0m"
	i=0
	while [ $i -ne ${#fonc[@]} ]; do
		if [ "${fonc[i]}" ]; then
			echo "${name[i]} : \033[31;1mKO\033[00;0m"
		else
			echo "${name[i]} : \033[32;1mOK\033[00;0m"
		fi
	i=$((i+1))
	done
else
	echo "\033[33;1mComment_before_ant\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_before_ant
	echo "\033[33;1mComment_after_ant\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_after_ant
	echo "\033[33;1mComment_b_a_ant\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_b_a_ant
	echo "\033[33;1mComment_before_end\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_before_end
	echo "\033[33;1mComment_after_end\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_after_end
	echo "\033[33;1mComment_before_pipes\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_before_pipes
	echo "\033[33;1mComment_after_pipes\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_after_pipes
	echo "\033[33;1mComment_b_a_pipes\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_b_a_pipes
	echo "\033[33;1mComment_mass_pipes\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_mass_pipes
	echo "\033[33;1mComment_before_rooms\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_before_rooms
	echo "\033[33;1mComment_after_rooms\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_after_rooms
	echo "\033[33;1mComment_b_a_rooms\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_b_a_rooms
	echo "\033[33;1mComment_mass_rooms\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_mass_rooms
	echo "\033[33;1mComment_before_start\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_before_start
	echo "\033[33;1mComment_after_start\033[00;0m :" && $leaks ./lem-in < lem-in_maps/comment/comment_after_start
fi

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
