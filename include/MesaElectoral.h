#pragma once
#include <string>
#include <vector>
#include "MesaElectoralObserver.h"
#include "Block.h"

class MesaElectoral : public MesaElectoralObserver {
private:
    std::string nombre;
    // Cada mesa guarda su propia copia local de la cadena
    std::vector<Block> localChain;

public:
    MesaElectoral(std::string nombre);

    // Recibe un bloque nuevo desde el Subject, lo valida y lo agrega
    void update(Block nuevoBloque) override;

    // Permite a la mesa minar y propagar un bloque (usado en main)
    void addBlockToLocal(Block block);

    std::string getNombre();
    int getLocalChainLength();
};
