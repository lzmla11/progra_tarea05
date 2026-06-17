#pragma once
#include <vector>
#include "MesaElectoralObserver.h"
#include "Block.h"

// Subject del patrón Observer
class CentroElectoralSubject {
private:
    std::vector<MesaElectoralObserver*> mesas;

public:
    void attach(MesaElectoralObserver* mesa);
    void notificarNuevoBloque(Block b);
};
