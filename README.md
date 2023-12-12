# Code for 74100A Worlds robot 2023.
![](https://i.pinimg.com/originals/b3/ee/c0/b3eec03459b57860fe1f898b7584683b.jpg)
## Warning ARMS is depreciated!!!
  If you want a good library nowadays check out [LemLib](https://github.com/LemLib/LemLib)
## Cata.cpp
  Uses "states" that can be changed in code or by the driver to determine how the catapult reacts. The catapult had a distance sensor that was monitoring the back of the catapult to determine how far down it was.

## Driver_control.cpp
  Uses basic arcade control and also allows the user to change wether the roller is spinning, the catapult state, and wether to fire endgame

## Global.cpp
  Just where I defined all the globals to avoid any import errors

## Lack of Certain Files
  I forgot to properly back up the auton.cpp so that is why you won't find anything, however it was mostly just chassis commands and roller/cata manipulation
