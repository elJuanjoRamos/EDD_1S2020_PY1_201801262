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
        CasillaNode c;
        c.setData(x1, y1, esDoble, esTriple);

        if (esDoble)
        {
            doubleList.push_back(c);

           /* for (int i = 0; i < 100; i++)
            {
                if (doubleList[i].getEmpty())
                {
                    doubleList[i].setData(x1, y1, esDoble, esTriple);
                    break;
                }
            }*/
        
        }
        else {
            /*for (int i = 0; i < 100; i++)
            {
                if (tripleList[i].getEmpty())
                {
                    tripleList[i].setData(x1, y1, esDoble, esTriple);
                    break;
                }
            }*/
            tripleList.push_back(c);
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
    for (auto& d : tripleList) // access by reference to avoid copying
    {
        if (d.getX() == x1 && d.getY() == y1)
        {
            return true;
            break;
        }
    }
    return false;
}


bool CasillaController::getCasillaDoble(int x1, int y1) {
    for (auto& d : doubleList) // access by reference to avoid copying
    {
        if (d.getX() == x1 && d.getY() == y1)
        {
            return true;
            break;
        }
    }
    return false;
}


void CasillaController::Clear() {
    doubleList.clear();
    tripleList.clear();
}