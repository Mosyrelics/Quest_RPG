### Paths of Fate

A game about adventure, where the decision player make will impact for most of the game. The decisions if based around the encounters the playet get. Written in C++.

## Features

- Character role: Players able to choose the role for their character, and the role will affect the future choices.
- View stats: Players able to view their current stats, such as HP, Mana, and Gold.
- View abilities: Players able to view their abilities for the role they choose.
- View progress: Players able to track their own progress.
- Story: Players must progress the game story until the end.
- Encounters: When encounter occured, a random game will be chosen and it will reward based on the encounters.
- Shop: Players able to purchase items with their gold when reaching the shop.

## Installation

A latest version of C++ compiler is required to run this program. The most recommended compiler is MSYS2. To install the compiler in Visual Studio Code, search for the C++ compiler in the extensions menu.

## How to run

1. Open terminal and locate the directory to this file.
2. Type this command in terminal: `g++ 535250050_Quest1_Moses.cpp -o play`
3. Type `./play` to run the program.

## Found a bug?

If you found an issue or would like to submit an improvement to this project, please submit an issue using the issues tab above.

## Known issues

Currently no issues have been known.

## Package Used

- iostream
- cstdlib
- ctime

## Program appearance

### When first time being run

```Paths of Fate
-----------------------------------------------------------
Press enter to continue.

===========================================================

Welcome to Paths of Fate. In this game, you will have to choose your decisions based on the encounters you get.
-----------------------------------------------------------
Press enter to continue.

===========================================================

Please name your character.
-----------------------------------------------------------
Name:
```

### Lore and choices

```In the gloomy forest, the forest is dark, so Mosy and the troops walk slowly.
-----------------------------------------------------------
Press enter to continue.
Or type: E to view stats. C to view abilities. Q to view your progress.

===========================================================

Suddenly, Mosy and the troops are surrounded by the hordes.
-----------------------------------------------------------
Press enter to continue.
Or type: E to view stats. C to view abilities. Q to view your progress.

===========================================================

There are two choices:
1. Fight them
2. Escape through risky path
-----------------------------------------------------------
Pick your choice (1-2): 1

===========================================================

Mosy and troops fights.
Current mana: 70
-----------------------------------------------------------
Press enter to continue.
Or type: E to view stats. C to view abilities. Q to view your progress.

===========================================================
```

### Shop

```SHOP
-----------------------------------------------------------
Gold: 300 / HP: 100 / Mana: 70
1. Health potion (+25 HP): 250 gold
2. Mana potion (+35 mana): 300 gold
3. Mega potion (+15 HP & 20 mana): 350 gold
-----------------------------------------------------------
Type 1/2/3 to buy, or type 4 to quit:
```

### Encounter

```Mosy have encountered an event: Rock Paper Scissors!
-----------------------------------------------------------
Press enter to continue.
Or type: E to view stats. C to view abilities. Q to view your progress.

===========================================================

If you win, Mosy will get 300 gold. But, if you lose, Mosy will lose 200 gold and 25 mana.
-----------------------------------------------------------
Press enter to continue.
Or type: E to view stats. C to view abilities. Q to view your progress.

===========================================================

Pick your choice:
1. Rock
2. Paper
3. Scissor
-----------------------------------------------------------
Answer (1/2/3): 1

===========================================================

You answered wrong! Mosy lose 200 gold!
Current gold: 0
-----------------------------------------------------------
Press enter to continue.
Or type: E to view stats. C to view abilities. Q to view your progress.

===========================================================

Encounter over. Story will continue.
-----------------------------------------------------------
Press enter to continue.
Or type: E to view stats. C to view abilities. Q to view your progress.

===========================================================
```
