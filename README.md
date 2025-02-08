# Minecraft Interface Simulator
Original code by: J. Pumarejo :3
This repository is part of a Programming Assignment for the Advanced Programming Course.

## Setup
1. Clone this project inside an OpenFrameworks installation's "apps/myApps/" directory
2. Build & Run the project

## Submitting Assignment
To submit this assignment, create a Release with the branch that holds all the changes you have added. If no Release is made, the last commit to the master branch will be graded.
Don't forget that you must also fill out an evaluation form in Moodle to consider the project submitted.

## Grading

(STUDENT NUMBER) (STUDENT NAME) (STUDENT EMAIL)
(STUDENT NUMBER) (STUDENT NAME) (STUDENT EMAIL)

Any project that doesn't compile will receive a 0.

If a partner has no commits in the repositories, they'll will receive a 0.

## Student Notes
If you have any bonus specs, bonus or any details the TA's should know, you should include it here:


## SOLUTION NOTES FOR TA's
I added a //PHASE # comment alongside the solutions so CRTL+F all the way!

SUGGESTED SPECS:

PHASE ONE:
-Draw the items sprite from within itemContainer's draw() method.
-Add the item count. Only display said count if there is more than one item inside the container.
-Add the item display name ONLY when it is being hovered over. Make the display be highlighted for better contrast. ofDrawBitmapStringHighlight()
-Fix the state buttons vertical alignment and fix the crafting table button.

PHASE TWO:
-Add wooden tools to the chest state via the addItems() method. Must use the ItemHandler instantiator class.
-Look at the furnace smelt() method and take note of all the smeltable item numbers. Add all those numbers to the smeltableItems vector using the addSmeltableItems() method.
-Using the comment provided, implement the logic of the furnace's canSmelt() method.
-Fix the beacon recipie. Must provide said recipie within the PA instructions.

PHASE 3:
-Add Ender Tools sprites to sprites.png using paint.
-Add Ender Tools to ItemHandler.h itemList.
-Add Ender Tools recipies. The recipie must be. 
{50,50,50,
 50,##,50,
 50,42,50
} where 50 is an Eye of Ender, 42 is a beacon and ## is the corresponding diamond tool number.
-Make Ender Tools guarantee the best possible item (last item) inside their corresponding loot table.
 




