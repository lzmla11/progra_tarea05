#include "CentroElectoralSubject.h"

void CentroElectoralSubject::attach(MesaElectoralObserver* mesa) {
    mesas.push_back(mesa);
}

void CentroElectoralSubject::notificarNuevoBloque(Block b) {
    for (MesaElectoralObserver* mesa : mesas) {
        mesa->update(b);
    }
}
