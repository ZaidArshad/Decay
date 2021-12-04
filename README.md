# Decay

## Description
Decay is a puzzle game coded in C++ that makes use of the SFML framework for graphics, input, sound. The objective of the game is to strategically clear every platform in the level. The game ends when the user completes level 10.

## Experience
This was my first major C++ project. I did not know about heaps so all of the data is accessed from the stack in this game. I put a large focus and made clean, readable files while also building on my fundamentals of game development from the Bounce game. I think I could’ve made a tool for creating levels because I made them manually in ```Level.cpp```. 

## Controls
Left Arrow / A: Move left.

Right Arrow / D: Move right.

Up Arrow / W: Jump.

R: Reset level.

Esc: Pause menu.

## Joypad Controls 
<div align="center">
  <img src="https://user-images.githubusercontent.com/52565263/144463177-9e8fb257-9cee-4523-949e-9b30d750498f.png" width="500"/>
</div>


## Platforms
Each platform has its own health bar indicated by the color of the rainbow, the closer it is to red the closer it is to disappearing. You can only lower the health of a platform if you touch another platform previously. 
<div align="center">
  <img src="https://user-images.githubusercontent.com/52565263/144451953-71f9ef08-825e-4579-8016-a742c08d1d52.gif" width="200" height="40"/>
</div>

## SFML
I did not use a game engine for this game for the purpose of gaining the most from developing it. The physics, buttons, transitions, text prompts and many other features were all done from scratch. The pause menu is able to showcase all the extra work I put in to create a more polished experience.

## Hitboxes
The hitboxes for this game were a nightmare but a great learning experience. It was difficult because the platforms would show a melting effect when destroyed messing with the size. I tried my best to keep the code clean with comments because there is a lot going on in ```Game.cpp```. 

## Sound
I revisited the game a year after development and thought that the game could be improved greatly with added features of sound effects and music.

<div>
 <video src='https://user-images.githubusercontent.com/52565263/144437378-ff92c7c6-57a5-4b45-90a1-9d0086ac8872.mov'/>
</div>
  
<div>
 <video src='https://user-images.githubusercontent.com/52565263/144437375-3a918091-5479-4cc8-81ec-c68196e1b02d.mov'/>
</div>

<div>
 <video src='https://user-images.githubusercontent.com/52565263/144437376-0d97fc86-2728-4ff7-8f66-f01f3b148d11.mov'/>
</div>

## Demo Video
<div align="center">
  <video src='https://user-images.githubusercontent.com/52565263/144463495-e99b49ba-b62d-4aef-b372-d04477d43e59.mp4'/>
</div>
