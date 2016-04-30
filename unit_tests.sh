#!/bin/bash

echo '    __                         _          __            __ '
echo '   / /   ___  ____ ___        (_)___     / /____  _____/ /_'
echo '  / /   / _ \/ __ `__ \______/ / __ \   / __/ _ \/ ___/ __/'
echo ' / /___/  __/ / / / / /_____/ / / / /  / /_/  __(__  ) /_  '
echo '/_____/\___/_/ /_/ /_/     /_/_/ /_/   \__/\___/____/\__/  '
echo '                                     Tbouder@student.42.fr '
echo

red=$(tput bold ; tput setaf 1)
green=$(tput setaf 2)
yellow=$(tput bold ; tput setaf 3)
blue=$(tput bold ; tput setaf 6)
normal=$(tput sgr0)

function signalerr
{
	if [[ $1 -ge 129 && $1 -le 140 ]]; then
		errors[$i]=$(basename $4)
		motif[$i]="SEGFAULT"
		i=$((i+1))
		printf "%s" "$red[SEGFAULT]$normal"
	elif [[ $1 -eq 42 ]]; then
		errors[$i]=$(basename $4)
		motif[$i]="LEAKS"
		i=$((i+1))
		printf "%s" "$red[LEAKS]$normal"
	elif [[ $2 == *"error"* || $2 == *"ERROR"* || $2 == *"Error"* ]]; then
		printf "%s" "$green.$normal"
	else
		errors[$i]=$(basename $4)
		motif[$i]="KO"
		i=$((i+1))
		printf "%s" "$red[KO]$normal"
	fi
}

function signal
{
	if [[ $1 -ge 129 && $1 -le 140 ]]; then
		errors[$i]=$(basename $4)
		motif[$i]="SEGFAULT"
		i=$((i+1))
		printf "%s" "$red[SEGFAULT]$normal"
	elif [[ $1 -eq 42 ]]; then
		errors[$i]=$(basename $4)
		motif[$i]="LEAKS"
		i=$((i+1))
		printf "%s" "$red[LEAKS]$normal"
	elif [[ "$2" == "" ]]; then
		printf "%s" "$green.$normal"
	else
		errors[$i]=$(basename $4)
		motif[$i]="KO"
		i=$((i+1))
		printf "%s" "$red[KO]$normal"
	fi
}

# Extract args
# ---------------------------------------------------------------------------- #
	WAY=/Volumes/USB/lem-in/lem-in_maps
	i=0
	j=0
	all=0
	autor=0
	makefile=0
	norme=0
	all=0
	leaks=""
	while [ $# -ne 0 ];do
		if [ "$1" = "leaks" ]; then
			leaks="sh /Volumes/USB/.files/valgrind/vg-in-place -q --leak-check=full --suppressions=/Volumes/USB/.files/valgrind/osx.supp --error-exitcode=42"
		elif [ $1 = "autor" ]; then
			autor=1
		elif [ $1 = "makefile" ]; then
			makefile=1
		elif [ $1 = "norme" ]; then
			norme=1
		elif [ $1 = "all" ]; then
			all=1
		fi
		shift
	done
	if [[ autor -eq 1 || all -eq 1 ]]; then
		if [ -e "auteur" ]; then
			user=$(cat auteur)
			iam=$(whoami)
			if [ "$user" = "$iam" ] ; then
				echo "Author file : \033[32;1mOK\033[00;0m"
			else
				echo "Author file : \033[31;1mKO\033[00;0m"
			fi
		else
			echo "\033[31;1mAuthor file missing\033[00;0m"
		fi
		echo
	fi
	if [[ makefile -eq 1 || all -eq 1 ]]; then
		if [ -e "Makefile" ]; then
			make fclean
			make
			make2=$(make)
			make clean
			# make3=$(make)
			# make re
			make
			make fclean
			# if [ "$make2" = "make: Nothing to be done for \`all'." -a "$make3" = "make: Nothing to be done for \`all'." ] ; then
			if [ "$make2" = "make: Nothing to be done for \`all'." ] ; then
				echo "Makefile : \033[32;1mOK\033[00;0m"
			else
				echo "Makefile : \033[31;1mKO\033[00;0m"
			fi
		else
			echo "\033[31;1mMakefile missing\033[00;0m"
		fi
		echo
	fi
	if [[ norme -eq 1 || all -eq 1 ]]; then
		norme_error=$(norminette . | grep -B1 Error | grep -w "Error" -c)
		if [ $norme_error != 0 ] ; then
			echo "Norminette : \033[31;1mKO\033[00;0m"
			norminette . | grep -B1 Error
		else
			echo "Norminette : \033[32;1mOK\033[00;0m"
		fi
		echo
	fi
	if [ -e "lemintest.log" ]; then
		rm -rf lemintest.log
	else
		touch lemintest.log
	fi
	make fclean && make
# ---------------------------------------------------------------------------- #

# printf "%-35s\n" "$yellow$(basename $f)$normal" >> lemintest.log
# echo $err  >> lemintest.log

# Errors tests
# ---------------------------------------------------------------------------- #
# echo "$blue~ERRORS~$normal"
for d in lem-in_maps/error/*
do
	printf "%-40s" "$yellow$(basename $d) : $normal"
	for f in lem-in_maps/error/$(basename $d)/*
	do
		err=$($leaks ./lem-in < $f)
		lik=$?
		signalerr $lik "$err" $i $f
	done
	printf "\n"

done

printf "%-40s" "$yellow""Comments : ""$normal"
for f in lem-in_maps/comment/*
do
	leak=$($leaks ./lem-in < $f)
	lik=$?
	comm=$(bash -c 'diff -u <(cat '$f') <(./lem-in < '$f')')
	signal $lik "$comm" $i $f
done
printf "\n"


printf "%-40s" "$yellow""Cmd : ""$normal"
for f in lem-in_maps/cmd/*
do
	leak=$($leaks ./lem-in < $f)
	lik=$?
	if [ "$(basename $f)" = "cmd_before_end" ]; then
		comm=$(bash -c 'diff -u <(cat '$WAY'/cmd_trace/cmd_trace_beta) <(./lem-in < '$f')')
	elif [ "$(basename $f)" == "cmd_before_start" ]; then
		comm=$(bash -c 'diff -u <(cat '$WAY'/cmd_trace/cmd_trace_omega) <(./lem-in < '$f')')
	else
		comm=$(bash -c 'diff -u <(cat '$WAY'/cmd_trace/cmd_trace_alpha) <(./lem-in < '$f')')
	fi
	signal $lik "$comm" $i $f
done
printf "\n"


printf "%-40s" "$yellow""pipes_error : ""$normal"
for f in lem-in_maps/pipes_error/*
do
	leak=$($leaks ./lem-in < $f)
	lik=$?
	comm=$(bash -c 'diff -u <(cat '$WAY'/pipes_error_trace/'$(basename $f)') <(./lem-in < '$f')')
	signal $lik "$comm" $i $f
done
printf "\n"


if [ ${#errors[@]} -ne 0 ]; then
echo "-------------------------------------------------------------------------"
echo "$red""Errors in""$normal"
	for nb in "${errors[@]}"
	do
		echo "$nb : \c"
		echo $red${motif[$j]}$normal
		j=$((j+1))
	done
fi
printf "\n"




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
