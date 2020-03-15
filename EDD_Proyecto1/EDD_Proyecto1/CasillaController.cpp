#include "CasillaController.h"


//SINGLETON
CasillaController* CasillaController::instance = 0;

CasillaController* CasillaController::getInstance()
{
    if (instance == 0)
    {
        instance = new CasillaController();
    }

    return instance;
}

CasillaController::CasillaController() {}


void CasillaController::Insert(int x, int y, bool d, bool t) {
    
    for (int i = 0; i < 100 ; i++)
    {
        if (doubleList[i].isEmpty)
        {
            doubleList[i].setData(x, y, d, t);
            break;
        }
    }
}

void CasillaController::Show() {
    for (int i = 0; i < 100; i++)
    {
        if (!doubleList[i].isEmpty)
        {
            doubleList[i].toString();
        }
    }
}