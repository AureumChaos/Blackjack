CC=g++ -c
LN=g++

SRC=.
OBJ=../obj
LIB=../lib
BIN=../bin
OBJECTS=$(OBJ)/Hand.o $(OBJ)/Deck.o $(OBJ)/Card.o


$(BIN)/main:$(OBJ)/main.o $(OBJECTS)
	${LN} $^ -o $@

$(OBJ)/main.o:$(SRC)/main.cpp $(SRC)/Hand.h $(SRC)/Deck.h $(SRC)/Card.h
	${CC} $< -o $@

$(OBJ)/Hand.o:$(SRC)/Hand.cpp $(SRC)/Hand.h $(SRC)/Card.h
	${CC} $< -o $@

$(OBJ)/Deck.o:$(SRC)/Deck.cpp $(SRC)/Deck.h $(SRC)/Card.h
	${CC} $< -o $@

$(OBJ)/Card.o:$(SRC)/Card.cpp $(SRC)/Card.h
	${CC} $< -o $@

clean:
	rm -f $(OBJ)/* $(LIB)/* $(BIN)/* $(SRC)/*~


