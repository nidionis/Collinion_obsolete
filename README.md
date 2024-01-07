# collinion

A cellular automaton/simulator generator
Make your own fancy game of life

Inspired by Dimitri Collignon,
Here some of his (musical) work:
  - KanDi
    https://www.youtube.com/watch?v=dtM9G354OAw
    
  - Charlotte NARTZ
    https://www.youtube.com/watch?v=Ngixp7VVpNY

  - Dr. K.
    https://www.youtube.com/watch?v=Finzub0FzHA

  - Own Blow
    https://www.youtube.com/channel/UCsQjYpATXG1AHtzDS2i60Gg

dependencies : make, gcc, libX
  sudo apt install make
  sudo apt install gcc
  sudo apt install libx11-dev
  sudo apt-get install libxext-dev

"run_collinion" is a shell script compiling and executing the algo you write.

download:
  - git clone https://git@github.com/presk0/Collinion.git

go directory:
  - cd collinion 

try it:
  - ./run_collinion game_of_life.c\
or
  - ./run_collinion example/<the_example_of_your_choice>\
and even:
  - ./run_collinion <path_to_the_algo_you_made>\

Drop your mouse and quit the window with ESC

Check the folder "tuto" if you want to discover more.

ENJOY
