#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char** argv)
{
  int winningDoor,initialDoor,otherDoor;
  int stayedWon = 0;
  int switchedWon = 0;
  int loop = 1;

  srand(time(NULL));

  int trials = atoi(argv[1]);
  int iterations = trials;

  while(iterations > 0)
  {
    // set up three element array that stores our three choices
    int doors[3] = {0,0,0};
    
    // randomly place our winning door
    winningDoor = rand() % 3;
    doors[winningDoor] = 1;
    
    // select a door at random
    initialDoor = rand() % 3;

    // open one of the other doors (not the winner though)
    while(loop)
    {
      otherDoor = rand() % 3;
      if(otherDoor == initialDoor || otherDoor == winningDoor)
        continue;
      else
        loop = 0;
    }

    // if the initialdoor was the winner, then we would win
    // if we stayed, otherwise we would have won by switching
    if(initialDoor == winningDoor)
      ++stayedWon;
    else
      ++switchedWon;

    --iterations;  
  }

  printf("Out of %d trials, %d wins from switching, %d wins from staying\n",trials,switchedWon,stayedWon);
}
