//*********************************************************************
//
// winmain.cpp
//
// Windows seems to require it's own entry point, so I'm defining it
// here as an alternative to main.
//
// Author: Jeff Bassett
//
// Updates:
//    09/14/2016  Created
// 
//*********************************************************************

#include <windows.h>

#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Game.h"
#include "Win32UI.h"


const char* g_szClassName = "myWindowClass";
//const LPCWSTR g_szClassName = {L"myWindowClass"};

// Game states
const int NEW_GAME = 0;
const int PLAYER_TURN = 1;
const int DEALER_TURN = 2;
const int GAME_OVER = 3;

int gameState;
Game *game;
Win32UI *ui;



LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            HFONT g_font = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
            COLORREF g_rgbText = RGB(0, 0, 0);
            SetTextColor(hdc, g_rgbText);

            RECT clientRect;
            GetClientRect(hwnd, &clientRect);

            if(ui != NULL)
            {
                ui->setContext(hdc);
                //TextOut(hdc, 0, 0, "hello", 5);
                //ui->text("Hello");
                game->displayState(*ui, !(gameState==GAME_OVER));
                ui->releaseContext();
            }

            DeleteObject(g_font);
            EndPaint(hwnd, &ps);
        }
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Blackjack",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    gameState = NEW_GAME;
    ui = new Win32UI();
    game = new Game();
    Player *dealer = game->getDealer();
    Player *user = game->getUser();
    Deck &deck = game->getDeck();

    // Step 3: The Message Loop/
    while(TRUE)
    {
        // Check to see if any messages are waiting in the queue
        while(PeekMessage(&Msg, NULL, 0, 0, PM_REMOVE))
        {
            // Translate the message and dispatch it to
            // WindowProc()
            TranslateMessage(&Msg);
            DispatchMessage(&Msg);
        }

        // If the message is WM_QUIT, exit the while loop
        if(Msg.message == WM_QUIT)
            break;

        // Run game code here
        switch(gameState)
        {
            case NEW_GAME:
                game->deal();
                gameState = PLAYER_TURN;
                InvalidateRect(hwnd, NULL, TRUE); 
                break;

            case PLAYER_TURN:
                if (user->handValue() > 21)
                {
                    gameState = DEALER_TURN;
                }
                else
                {
                    int another = MessageBox(NULL,
                          "Another card?\nYes = hit\nNo = stay",
                          "Hit or Stay",
                          MB_ICONQUESTION | MB_YESNO);
                    if(another == IDYES)
                    {
                        user->addCard(deck.takeTopCard());
                    }
                    else
                    {
                        gameState = DEALER_TURN;
                    }
                }
                InvalidateRect(hwnd, NULL, TRUE); 
                break;

            case DEALER_TURN:
                if (dealer->handValue() <= 21 
                       && dealer->decideAction(*ui, *game) == HIT)
                {
                    dealer->addCard(deck.takeTopCard());
                }
                else
                {
                    gameState = GAME_OVER;
                }
                InvalidateRect(hwnd, NULL, TRUE); 
                break;

            case GAME_OVER:
                string message;
                int winner=game->score();
                switch(winner)
                {
                    case -1:
                        message = "You lost.\n\n";
                        break;
                    case 0:
                        message = "Push.  It's a tie.\n\n";
                        break;
                    case 1:
                        message = "You won!!\n\n";
                }
                message = message + "Play another hand?";

                int again = MessageBox(NULL, message.c_str(), "Game over",
                        MB_ICONQUESTION | MB_YESNO);
                if(again == IDNO)
                    PostMessage(hwnd, WM_QUIT, 0, 0);
                else
                {
                    gameState = NEW_GAME;
                    game->cleanup();
                }
        }
    }

    delete game;
    delete ui;

    return Msg.wParam;
}


/*
int main()
{
    Game game;
    ConsoleUI ui;

    const char* char_yes_no[] = {"yes", "no"};
    vector<string> yes_no(char_yes_no, char_yes_no + 2);

    int answer = 1;
    while(yes_no[answer] == "no")
    {
        game.deal();
        game.play(ui);

        game.displayState(ui, false);  // Show all cards
        int result = game.score();
        switch(result)
        {
            case -1:
                ui.text("The Dealer won.\n");
                break;
            case 0:
                ui.text("Push. No winner.\n");
                break;
            case 1:
                ui.text("You won!\n");
                break;
        }

        game.cleanup();
        answer = ui.choose("Would you like to quit?", yes_no, 1);
    }
}
*/

