CC=g++ -c
LN=g++

SRC=.
OBJ=../obj
# One of the places windows looks for DLLs is with the executable,
# so I'll put it there.
LIB=../bin
BIN=../bin
OBJECTS=\
   $(OBJ)/Game.o \
   $(OBJ)/UserPlayer.o \
   $(OBJ)/Dealer.o \
   $(OBJ)/Player.o \
   $(OBJ)/Hand.o
#   $(OBJ)/Deck.o \
#   $(OBJ)/Card.o
LIBRARIES=$(LIB)/Deck.dll
#LIBRARIES=


winmain:$(BIN)/winmain
	echo $< built

main:$(BIN)/main
	echo $< built

all::winmain main

# Somehow some win32 stuff has crept in here, so this doesn't link anymore.
$(BIN)/main:$(OBJ)/main.o $(OBJECTS) $(OBJ)/ConsoleUI.o $(LIBRARIES)
	${LN} -L$(LIBS) -lDeck $^ -o $@

$(OBJ)/main.o:$(SRC)/main.cpp $(SRC)/Game.cpp $(SRC)/Game.h $(SRC)/Player.h \
              $(SRC)/UserPlayer.h $(SRC)/Dealer.h $(SRC)/Hand.h \
              $(SRC)/Deck.h $(SRC)/Card.h $(SRC)/BaseUI.h $(SRC)/ConsoleUI.h
	${CC} $< -o $@

$(BIN)/winmain:$(OBJ)/winmain.o $(OBJECTS) $(OBJ)/Win32UI.o $(LIBRARIES)
	${LN} -mwindows -L$(LIB) -lDeck $^ -o $@

$(OBJ)/winmain.o:$(SRC)/winmain.cpp $(SRC)/Game.cpp $(SRC)/Game.h $(SRC)/Player.h \
              $(SRC)/UserPlayer.h $(SRC)/Dealer.h $(SRC)/Hand.h \
              $(SRC)/Deck.h $(SRC)/Card.h $(SRC)/BaseUI.h $(SRC)/Win32UI.h
	${CC} $< -o $@

$(OBJ)/Game.o:$(SRC)/Game.cpp $(SRC)/Game.h $(SRC)/Player.h \
              $(SRC)/UserPlayer.h $(SRC)/Dealer.h $(SRC)/Hand.h $(SRC)/Deck.h \
              $(SRC)/Card.h $(SRC)/BaseUI.h
	${CC} $< -o $@

$(OBJ)/Dealer.o:$(SRC)/Dealer.cpp $(SRC)/Dealer.h $(SRC)/Player.h \
                $(SRC)/Hand.h $(SRC)/Card.h $(SRC)/BaseUI.h
	${CC} $< -o $@

$(OBJ)/UserPlayer.o:$(SRC)/UserPlayer.cpp $(SRC)/UserPlayer.h $(SRC)/Player.h \
                    $(SRC)/Hand.h $(SRC)/Card.h $(SRC)/BaseUI.h
	${CC} $< -o $@

$(OBJ)/Player.o:$(SRC)/Player.cpp $(SRC)/Player.h $(SRC)/Hand.h $(SRC)/Card.h \
                $(SRC)/BaseUI.h
	${CC} $< -o $@

$(OBJ)/Hand.o:$(SRC)/Hand.cpp $(SRC)/Hand.h $(SRC)/Card.h $(SRC)/BaseUI.h
	${CC} $< -o $@

$(LIB)/Deck.dll:$(OBJ)/Deck.o $(OBJ)/Card.o $(OBJ)/ConsoleUI.o $(OBJ)/Win32UI.o
	$(LN) -mwindows -shared -o $@ $? -Wl,--out-implib,$(LIB)/Deck.a

$(OBJ)/Deck.o:$(SRC)/Deck.cpp $(SRC)/Deck.h $(SRC)/Card.h $(SRC)/BaseUI.h
	${CC} -DBUILD_DLL $< -o $@
#	${CC} $< -o $@

$(OBJ)/Card.o:$(SRC)/Card.cpp $(SRC)/Card.h $(SRC)/BaseUI.h
	${CC} -DBUILD_DLL $< -o $@
#	${CC} $< -o $@

$(OBJ)/Win32UI.o:$(SRC)/Win32UI.cpp $(SRC)/Win32UI.h $(SRC)/BaseUI.h
	${CC} -DBUILD_DLL $< -o $@
#	${CC} $< -o $@

$(OBJ)/ConsoleUI.o:$(SRC)/ConsoleUI.cpp $(SRC)/ConsoleUI.h $(SRC)/BaseUI.h
	${CC} -DBUILD_DLL $< -o $@
#	${CC} $< -o $@

clean:
	rm -f $(OBJ)/* $(LIB)/* $(BIN)/* $(SRC)/*~

run:$(BIN)/winmain
	$(BIN)/winmain

#run:$(BIN)/main
#	$(BIN)/main


