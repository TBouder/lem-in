# lem_in

[PDF](https://mega.nz/#!osxnhSJR!2B0FDB6nnCJVM5uob_uENaLKznJcYk37wZh5JvP-bJU)  

###Gameplay  
>The project goal is to find the fastest way for X ants to reach END room from START room in a labyrinth of Y rooms.  
>The map has to be given on the standard entry (with '<') and must have the folowing structure :  
>	**ant**  
>	**rooms**  
>	**pipes**  
>The number of ants can be between 1 and 2147483647.  
>Room must be formatted according to this schema : **NAME X_coo Y_coo**, with one room per line.  
>Same room name or same coordinates lead to an error.  
>The starting room must be preceded by **##start** and the ending room by **##end**.  
>  
>Pipes must follow the room definition and must be formatted like this : **ROOM1-ROOM2**.  
>If both room are the same or if one room doesn't exist, the program stops reading the file and try to find a path with all the informations already acquired.  
>Two same pipes leads to an error in hard mode (possibility to switch to soft mode with -s).  
>   
>Line starting with **#** will be ignored at reading but displayed on result.  
>Line starting with **##** (excepted **##start** and **##end**) will be ignored on both reading and result.  
>   
>At the end, if no error occurred, the map and the move of the ants will be displayed with the following line format : **L1-a L2-b ... L3-z** where L1, L2 etc. gives us the number of the ant, and a, b, etc. gives us the room in which the ant just moved.  
>We can have only one ant per room and one ant can only moves to the next room (no double move).  

###Bonus :  
- [x] -s for soft mode  
- [x] -c for color mode  
- [x] -d to use distance rather than number of rooms  
- [x] -i to display some informations at the end  
- [x] -p to display the path used to solve the algo  
- [x] Possibility to use -scdip instead of -s -c -d -i -p  
- [x] Possibility to read multiple file one after the other (open needed)  
- [x] Explicits messages for errors  
- [x] Usage message  

###Requirements :  
- [FT_PRINTF](https://bitbucket.org/Tbouder/libft)  
- [LIBFT](https://bitbucket.org/Tbouder/libft)  
- C compiler  
- GNU  

###Installation :  
1. git clone https://bitbucket.org/Tbouder/lem_in && cd lem_in  
1. git clone https://bitbucket.org/Tbouder/ft_printf && cd ft_printf  
2. git clone https://bitbucket.org/Tbouder/libft  
3. cd ..  
4. make  
5. ./lem_in [-vcoia] < [map]  
