#!/bin/bash

echo '    __                         _          __            __ '
echo '   / /   ___  ____ ___        (_)___     / /____  _____/ /_'
echo '  / /   / _ \/ __ `__ \______/ / __ \   / __/ _ \/ ___/ __/'
echo ' / /___/  __/ / / / / /_____/ / / / /  / /_/  __(__  ) /_  '
echo '/_____/\___/_/ /_/ /_/     /_/_/ /_/   \__/\___/____/\__/  '
echo '                                     Tbouder@student.42.fr '
echo

red=$(tput setaf 1)
green=$(tput setaf 2)
yellow=$(tput bold ; tput setaf 3)
blue=$(tput bold ; tput setaf 6)
normal=$(tput sgr0)

function signal
{
	signres=1
	if [[ $1 -eq 129 ]]; then
		printf "%34s\n" "$red[SIGHUP]$normal"
	elif [[ $1 -eq 130 ]]; then
		printf "%34s\n" "$red[SIGINT]$normal"
	elif [[ $1 -eq 131 ]]; then
		printf "%35s\n" "$red[SIGQUIT]$normal"
	elif [[ $1 -eq 132 ]]; then
		printf "%34s\n" "$red[SIGILL]$normal"
	elif [[ $1 -eq 133 ]]; then
		printf "%35s\n" "$red[SIGTRAP]$normal"
	elif [[ $1 -eq 134 ]]; then
		printf "%36s\n" "$red[SIGABORT]$normal"
	elif [[ $1 -eq 135 ]]; then
		printf "%34s\n" "$red[SIGEMT]$normal"
	elif [[ $1 -eq 136 ]]; then
		printf "%34s\n" "$red[SIGFPE]$normal"
	elif [[ $1 -eq 137 ]]; then
		printf "%35s\n" "$red[SIGKILL]$normal"
	elif [[ $1 -eq 138 ]]; then
		printf "%36s\n" "$red[BUSERROR]$normal"
	elif [[ $1 -eq 139 ]]; then
		printf "%36s\n" "$red[SEGFAULT]$normal"
	elif [[ $1 -eq 140 ]]; then
		printf "%36s\n" "$red[SIGSYS]$normal"
	else
		signres=0
	fi
}

# Extract args
# ---------------------------------------------------------------------------- #
WAY=/Volumes/USB/lem-in/lem-in_maps
i=0
all=0
autor=0
makefile=0
norme=0
all=0
leaks=""
while [ $# -ne 0 ];do
	if [ "$1" = "leaks" ]; then
		leaks="sh /Volumes/USB/.files/valgrind/vg-in-place -q --leak-check=full --error-exitcode=42"
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

# Errors tests
# ---------------------------------------------------------------------------- #
echo "$blue~ERRORS~$normal"
for f in lem-in_maps/error/*/*
do
	err=$($leaks ./lem-in < $f)
	lik=$?
	printf "%-35s\n" "$yellow$(basename $f)$normal" >> lemintest.log
	echo $err  >> lemintest.log
	printf "%-35s" "$yellow$(basename $f)$normal"
	signal $lik
	if [[ leaks == "" ]]; then
		if [ $signres -eq 0 ]; then
			if [[ $err == *"error"* || $err == *"ERROR"* || $err == *"Error"* ]]; then
				printf "%30s\n" "$green[OK]$normal"
			else
				printf "%30s\n" "$red[KO]$normal"
			fi
		fi
	else
		if [ $signres -eq 0 ]; then
			if [[ $err == *"error"* || $err == *"ERROR"* || $err == *"Error"* && $lik -ne 42 ]]; then
				printf "%30s\n" "$green[OK]$normal"
			else
				printf "%30s\n" "$red[KO]$normal"
			fi
		fi
	fi
done
# ---------------------------------------------------------------------------- #


# Tests with comments
# ---------------------------------------------------------------------------- #
echo "\n$blue~COMMENTS~$normal"
for f in lem-in_maps/comment/*
do
	leak=$($leaks ./lem-in < $f >> lemintest.log)
	lik=$?
	comm=$(bash -c 'diff -u <(cat '$f') <(./lem-in < '$f')')
	printf "%-35s\n" "$yellow$(basename $f)$normal" >> lemintest.log
	echo $leak  >> lemintest.log
	printf "%-35s" "$yellow$(basename $f)$normal"
	signal $lik
	if [[ leaks == "" ]]; then
		if [ $signres -eq 0 ]; then
			if [ "$comm" ]; then
				printf "%30s\n" "$red[KO]$normal"
			else
				printf "%30s\n" "$green[OK]$normal"
			fi
		fi
	else
		if [ $signres -eq 0 ]; then
			if [[ "$comm" || $lik -eq 42 ]]; then
				printf "%30s\n" "$red[KO]$normal"
			else
				printf "%30s\n" "$green[OK]$normal"
			fi
		fi
	fi
done
# ---------------------------------------------------------------------------- #

# Tests with cmd
# ---------------------------------------------------------------------------- #
echo "\n$blue~CMD~$normal"
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
	printf "%-35s\n" "$yellow$(basename $f)$normal" >> lemintest.log
	echo "$comm\n"  >> lemintest.log
	printf "%-35s" "$yellow$(basename $f)$normal"
	signal $lik
	if [[ leaks == "" ]]; then
		if [ $signres -eq 0 ]; then
			if [ "$comm" ]; then
				printf "%30s\n" "$red[KO]$normal"
			else
				printf "%30s\n" "$green[OK]$normal"
			fi
		fi
	else
		if [ $signres -eq 0 ]; then
			if [[ "$comm" || $lik -eq 42 ]]; then
				printf "%30s\n" "$red[KO]$normal"
			else
				printf "%30s\n" "$green[OK]$normal"
			fi
		fi
	fi
done
# ---------------------------------------------------------------------------- #

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
