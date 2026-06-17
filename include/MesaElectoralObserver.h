#pragma once
#include "Block.h"

// Interfaz Observer
class MesaElectoralObserver {
public:
    virtual void update(Block nuevoBloque) = 0;
    virtual ~MesaElectoralObserver() = default;
};
