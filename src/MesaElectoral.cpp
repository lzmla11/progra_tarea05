#include "MesaElectoral.h"
#include <iostream>

MesaElectoral::MesaElectoral(std::string nombre) : nombre(nombre) {
    // Bloque génesis local (mismo que el de Blockchain)
    std::vector<Vote> emptyVotes;
    Block genesis(0, "0", emptyVotes);
    localChain.push_back(genesis);
}

void MesaElectoral::update(Block nuevoBloque) {
    // Verificación simple: el previousHash del nuevo bloque debe coincidir
    // con el currentHash del último bloque en la cadena local
    std::string expectedPrev = localChain.back().getCurrentHash();

    if (nuevoBloque.getPreviousHash() == expectedPrev) {
        localChain.push_back(nuevoBloque);
        std::cout << "[" << nombre << "] Bloque " << nuevoBloque.getIndex()
                  << " recibido y aceptado. Cadena local: "
                  << localChain.size() << " bloques.\n";
    } else {
        std::cout << "[" << nombre << "] Bloque rechazado: hash previo no coincide.\n";
    }
}

void MesaElectoral::addBlockToLocal(Block block) {
    localChain.push_back(block);
}

std::string MesaElectoral::getNombre() {
    return nombre;
}

int MesaElectoral::getLocalChainLength() {
    return (int)localChain.size();
}
