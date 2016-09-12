CC=g++ -c
LN=g++

SRC=.
OBJ=../obj
LIB=../lib
BIN=../bin
OBJECTS=\
   $(OBJ)/Hand.o \
   $(OBJ)/Deck.o \
   $(OBJ)/Card.o \
   $(OBJ)/Player.o \
   $(OBJ)/Dealer.o \
   $(OBJ)/UserPlayer.o \
   $(OBJ)/Game.o \
   $(OBJ)/ConsoleUI.o


$(BIN)/main:$(OBJ)/main.o $(OBJECTS)
	${LN} $^ -o $@

$(OBJ)/main.o:$(SRC)/main.cpp $(SRC)/Game.cpp $(SRC)/Game.h $(SRC)/Player.h \
              $(SRC)/UserPlayer.h $(SRC)/Dealer.h $(SRC)/Hand.h \
              $(SRC)/Deck.h $(SRC)/Card.h $(SRC)/BaseUI.h $(SRC)/ConsoleUI.h
	${CC} $< -o $@

$(OBJ)/ConsoleUI.o:$(SRC)/ConsoleUI.cpp $(SRC)/ConsoleUI.h $(SRC)/BaseUI.h
	${CC} $< -o $@

$(OBJ)/Game.o:$(SRC)/Game.cpp $(SRC)/Game.h $(SRC)/Player.h \
              $(SRC)/UserPlayer.h $(SRC)/Dealer.h $(SRC)/Hand.h $(SRC)/Deck.h \
              $(SRC)/Card.h
	${CC} $< -o $@

$(OBJ)/Dealer.o:$(SRC)/Dealer.cpp $(SRC)/Dealer.h $(SRC)/Player.h \
                $(SRC)/Hand.h $(SRC)/Card.h
	${CC} $< -o $@

$(OBJ)/UserPlayer.o:$(SRC)/UserPlayer.cpp $(SRC)/UserPlayer.h $(SRC)/Player.h \
                    $(SRC)/Hand.h $(SRC)/Card.h
	${CC} $< -o $@

$(OBJ)/Player.o:$(SRC)/Player.cpp $(SRC)/Player.h $(SRC)/Hand.h $(SRC)/Card.h
	${CC} $< -o $@

$(OBJ)/Hand.o:$(SRC)/Hand.cpp $(SRC)/Hand.h $(SRC)/Card.h
	${CC} $< -o $@

$(OBJ)/Deck.o:$(SRC)/Deck.cpp $(SRC)/Deck.h $(SRC)/Card.h
	${CC} $< -o $@

$(OBJ)/Card.o:$(SRC)/Card.cpp $(SRC)/Card.h $(SRC)/BaseUI.h
	${CC} $< -o $@

clean:
	rm -f $(OBJ)/* $(LIB)/* $(BIN)/* $(SRC)/*~

run:$(BIN)/main
	$(BIN)/main


