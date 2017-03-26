Name: Grant Lindberg

Last 5 digits of student ID: 06993

Email: grant.lindberg@wsu.edu

Project: TicTacToe

Description: This program simulates the game of tictactoe on the command line.
The player may select his token as well as who starts. He is always against
the computer.

How to build: Type 'make' into your terminal. If the project has been made
already, type 'make clean && make" to start afresh.

How to run: Type './build/tictactoe' into your terminal.

How to play 4x4 game: This feature has not been implemented. At this time, you
are only able to play the normal 3x3 game.

1. What is inheritance in OOP and how is it used in this project:

Inheritance refers to the is-a relationship amongst languages such as C++ and
Java. It means that a class can have subclasses, in which the subclasses are
given the fields and methods of the classes they inherit from. In addition,
the parent is sometimes able to have access to its childrens' fields and
methods. It is used in this project because the Grid class inherits from the
TicTacToe class. Since the TicTacToe class is the parent class, it makes simple
function calls that sometimes hide the child's function calls in a layer of
abstraction. In addition, the TicTacToe class is able to manipulate the fields
of the grid.

2. What is object composition in OOP and how it is used in this project:

Object composition is the practice of storing smaller objects as fields of
other objects, thus referring to the has-a relationship commonly described by
C++ and Java. This allows the creation of more complex data structures by the
combination of smaller ones. An example of this practice in this program is the
use of placing a Grid object inside the GridGame class. This allows GridGame
the ability to change the values of the Grid object inside of it, yet since
GridGame is an abstract class, it is allowed to have virtual functions that
cannot be manipulated by the its Grid attribute. This way, GridGame is able
to handle important calls to the game interface and transmit them to the Grid
attribute and thus provide a simpler layer of abstraction.

3. What is running time polymorphism and how is it used in this project:

Running time polymorphism refers to the ability to override functions that
are the same by either signature or its parameters at runtime. In particular,
this is achieved in this program by the use of virtual functions, which are
called only in the context of runtime because the compiler cannot possibly
determine ahead of time whether the virtual function or the non-virtual
function should be called. This process is more dynamic and flexible, as it
allows the determination of the function to be resolved as the program is being
executed rather than ahead of time. The GridGame class contains virtual
functions which are implemented by the TicTacToe class, the correct one being
called depending on the context at any given point in the execution process.
The TicTacToe class also contains two place_mark() methods that differ only in
the types and number of arguments passed to it. Only during runtime will the
program be able to determine the proper one to use.

4. What algorithms do you use for the place_mark method in the two game classes
   respectively. Is it a perfect algorithm? Explain how it works?

I did not actually use the place_mark(Player player) method in my program, but
I did use the other one. It is difficult to say whether it is a perfect
algorithm or not. Essentially, the one I use, place_mark(int i, int j,
Player player) takes the row and column of the spot to place the token as well
as the player that is making the move. The function is able to determine
whether an X or an O should be placed just based on the player sent as a
parameter, regardless of how the user specifies each symbol should be when the
game starts. This provides reassurance that it is being used correctly. It only
operates on the main grid that it inherits as an attribute, so it was unable
to be reused when implementing the artificial intelligence. To circumvent this
issue, I had to make a copy of the main grid where necessary and call
set_cell() on the copy explicitly. This lack of reusability is one area in
which it is flawed, however, if the place_mark() method took a grid as an
argument, it would completely defeat the purpose of inheriting the grid from
GridGame in the first place. Since the method returns a boolean, it makes use
of checking to make sure that the coordinates it is being given is a free spot
on the board. If it is not free, it returns false; otherwise, it sets the cell
on the grid and returns true. The program is implemented to check for valid
moves beforehand anyway, as seen with the parser in do_player_turn().
Therefore, it is actually unnecessary to check for an empty spot on the board
in the place_mark() function, and it could essentially return void if it
wanted.
