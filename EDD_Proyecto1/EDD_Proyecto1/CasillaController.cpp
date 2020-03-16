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


void CasillaController::Insert(int x1, int y1, bool esDoble, bool esTriple) {
    
        if (esDoble)
        {

            for (int i = 0; i < 100; i++)
            {
                if (doubleList[i].getEmpty())
                {
                    doubleList[i].setData(x1, y1, esDoble, esTriple);
                    break;
                }
            }
        
        }
        else {
            for (int i = 0; i < 100; i++)
            {
                if (tripleList[i].getEmpty())
                {
                    tripleList[i].setData(x1, y1, esDoble, esTriple);
                    break;
                }
            }
        }


        
    
}

void CasillaController::Show() {
    for (int i = 0; i < 100; i++)
    {
        if (!doubleList[i].getEmpty())
        {
            doubleList[i].toString();
        }
    }
}

bool CasillaController::getCasillaTriple(int x1, int y1) {
    for (int i = 0; i < 100; i++)
    {
        if (!tripleList[i].getEmpty())
        {
            if (tripleList[i].getX() == x1 && tripleList[i].getY() == y1)
            {
                return true;
                break;
            }

        }
    }
    return false;
}


bool CasillaController::getCasillaDoble(int x1, int y1) {
    for (int i = 0; i < 100; i++)
    {
        if (!doubleList[i].getEmpty())
        {
            if (doubleList[i].getX() == x1 && doubleList[i].getY() == y1)
            {
                return true;
                break;
            }

        }
    }
    return false;
}