
# Blackjack
A blackjack game, to test my programming skills.
Jeff Bassett
jbassett2@gmail.com

INSTALLATION

First, you should install a git client if you don't already have one.  I chose
to install "git dor windows" here: https://git-scm.com/download/win

As I recall, this installation was pretty straight forward, but I don't
rememeber all the details.

The next step is to install MinGW.  It is essentially a windows implementation
of the GNU compiler suite.  It also has a bunch of UNIXy tools called MSYS,
which I found to be pretty handy, including the make utility.

The install instruction are here: mingw.org/wiki/Getting_Started

I followed them basically verbatim, and I had no problems.  When choosing
which packages to install, I remember not installing the Fortran or Ada
compilers, but I think I chose just about everything else.

Start an msys terminal by running \MinGW\msys\1.0\msys.bat

And finally download my code from my git repository.  Find an appropriate
directory where you want to put the code, and type:
git clone https://github.com/AureumChaos/Blackjack.git


BUILDING and RUNNING

Change directory into the Blackjack/src directory.  Because msys is a more
unix-like system, you will need to use forward slashes "/" instead of
backslashes "\" to delineate between directories. 

Type: cd Blackjack/src

I generally did all my work from this directory, and I used the make utility
to get a lot of that work done.  I created a Makefile that will build and run
everything you need.  Here are some useful commands:

To build the default program:
Type: make
or: make winmain

To run the program:
Type: Make run

To erase all the object files, libraries and executables:
Type: Make clean

When the program is build, two files will be placed in the Blackjack/bin
directory.  They are "winmain" and "Deck.dll".  "winmain" is the blackjack
program (I probably could have given it a better name).


DISCUSSION

I had one big constraint when I started this project that may not be
immediately obvious.  I realized that I did not have any machines available to
me that ran Window.  I decided to do some of the initial work on my Mac, and I
did the "GUI" work for input and output on standard console using iostreams.

I got a basic version working over the weekend, and then I bought Parallels
and Windows 10 on Monday or Tuesday.  From there I was able to get MinGW
working and start developing the rest of it in a windows environment.

Taking this path affected the design a bit.  I decided to create some UI
wrappers to the specific UI capabilities that I needed.  This way when I moved
to windows it would be a simple matter of porting the UI elements, and
hopefully make the transition fairly smooth.  This is why I created the
BaseUI, ConsoleUI and Win32UI classes.  Unfortunately, it didn't quite work out
that way.

While this seemed like a good idea at the time, I think this approach may have
created as many problems as it solved.  I didn't anticipate some limitations
of the windows API, and at certain times I was worried that I had painted
myself into a corner.  I also didn't anticipate how much Windows' event model
would affect the structure of the main loop.  As a result of these problems,
much of the functionality of the low level UI classes and the high level Game
glass has bled into the main windows program.  With some work I think things
could be cleaned up a little, but I decided it was more important to get you
something that was working by the deadline you had set.

I had also hoped to make the UI a little more impressive.  There are some
unicode characters that could have made for some nicer displays.
Unfortunately I discovered that using unicode in a windows program is a big
undertaking.  Everything has to be designed with that in mind, and it really
affects what functions, classes and structures you can use.  It was getting in
the way of getting the other functionality to work, so I backed out of it and
just decided to use plain text to describe the cards.  I was also hoping to
use some color and drawing functions to make the cards a little nicer.  Again
I opted for just making sure the key pieces were working instead.

DESIGN

BaseUI, ConsoleUI and Win32UI:

As I described above, this family of classes were designed to make it easy to
build the software with either a console interface or a Windows GUI interface.
Other classes throughout the system would just have a reference to the
abstract base class (BaseUI), and would not need to know which interface they
were currently using.  Some of the main functionality of these classes
involved getting user input, displaying text and displaying a card.

Card:

The card class is fairly simple, and an instance is used to describe a single
playing card.  A card stores information about it's suit and rank (face
value).  It can draw itself, and it can return information about it's point
value.  The point value is somewhat specific to Blackjack, although other card
games use similar point systems.

Deck:

The deck class is a collection of cards.  The constructor will build a
standard 52 card deck, and the destructor will destroy all the cards that are
currently in the deck.  Any cards not in the deck are not the responsibility
of the deck class.  The deck can be shuffled, and queried for the number of
cards it contains.  It is possible to take a card off the top of the deck, and
it is also possible to add a card to the top of the deck.  Often adding a card
is used to just return cards that were previously taken from it.

Hand:

This is essentially a Blackjack hand.  Because it inherits from vector, all
the function of a vector are available, like size() and push_back().  A hand
can be queried for its current value, which takes the dual nature of aces into
account.  The evalHand function calculates both the hand value, and determines
if the had is "soft" (i.e. if there are any aces that are currently counted as
high value).  Finally, two hands can be compared to see which is superior.
This function counts natural blackjack (an ace and a 10 or face card) as
superior to other hands with a value of 21.  The return values are similar to
a compare operator, with 1 indicating the had wins, 0 indicating a tie or
push, and -1 indicating the hand loses.

Player, UserPlayer and Dealer:

This family of classes is used to manage the information and behaviors of the
various types of players in the game.  The Player base class defines a set of
functions that are common to all players, such as adding a card to their hand,
returning cards to the deck, calculating the hand value, displaying the
current hand (and hiding one card if necessary) and comparing hands with
another player.  The one method that must be defined by sub classes is 
decideAction, which determines whether to stay or hit.  The dealer subclass
will always hit if the value of the hand is 16 or less, unless it has a soft
ace, in which case it will hit at 17 or less.  The UserPlayer class will ask
the user what decision they wish to make.  Note that in the current windows
version, UserPlayer::decideAction is never actually called, but the code could
and should be modified so that it is structured this way again.

Game:

This class was designed to keep track of high level classes like the deck and
the players, and to handle many aspects of the overall game flow.  The Game
takes care of actually dealing the cards (not the dealer), managing player
turns, determining the winner (with the score method), and collecting the
players cards (the cleanup method).  It also can display the current state of
the game.  Note that some of this functionality has migrated into the winmain
file, but much if it can and should be moved back into this class.

winmain:

The winmain file contains the Win32 WinMain and WndProc functions.  These deal
mainly with the windows event handling, user interraction and managing the
display.  The main game is run as an extension to the main event handling
loop.  If there are currently no events to handle, the next step in the game
will take place.  These steps are referred to as "game states", and include this
initial deal (NEW_GAME), User player decisions to hit or stay (PLAYER_TURN),
Dealer decisions to hit or stay (DEALER_TURN) and the end game, in which
hidden cards are shown, the winner is determined, and the player is asked if
they want to play again (GAME_OVER).

main:

The was the main function for the console version of the game.  It probably
does not compile or run currently, but I couldn't think of any reason to
remove it.  If development continues, this could be useful for testing or
debugging.


FINAL THOUGHTS

Well, I think that's everything you asked for.  It's not necessarily pretty,
but it works, and there are a few things I would likely clean up if I were to
continue with it.  Let me know if you have any questions.

- Jeff


