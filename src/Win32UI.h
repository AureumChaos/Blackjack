//*********************************************************************
//
// Win32UI.h
//
// A class that defines a GUI interface using the Win32 API.
//
// Author: Jeff Bassett
//
// Updates:
//    09/14/2016  Created
// 
//*********************************************************************

#ifndef WIN32UI_H
#define Win32UI_H

#include <string>
#include <vector>
using namespace std;

#include "BaseUI.h"


#undef DLL_SIG
#ifdef __cplusplus
extern "C" {
#endif

#ifdef BUILD_DLL
#define DLL_SIG __declspec(dllexport)
#else
#define DLL_SIG __declspec(dllimport)
#endif

#ifdef __cplusplus
}
#endif

//#define DLL_SIG 


class DLL_SIG Win32UI : public BaseUI
{
    public:
        static const string RANK_ABBR[];
        static const string SUIT_UNICODE[];

        Win32UI() {};
        ~Win32UI() {};
        virtual void text(const string &str);
        virtual void drawCard(int rank, int suit);
        virtual int choose(const string &question,
                           const vector<string> &choices,
                           int myDefault=0);
};

#endif
