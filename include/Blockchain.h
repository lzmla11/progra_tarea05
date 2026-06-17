#pragma once
#include <vector>
#include <string>
#include "Block.h"

class Blockchain {
private:
    std::vector<Block> chain;

    // Constructor privado para el patrón Singleton
    Blockchain();

public:
    // Singleton: devuelve la única instancia
    static Blockchain& getInstance();

    // Deshabilitar copia y asignación
    Blockchain(const Blockchain&) = delete;
    Blockchain& operator=(const Blockchain&) = delete;

    void addBlock(Block block);
    void mineBlock(Block& block, int difficulty);
    bool isChainValid();
    int getLength();
    std::string getLastHash();
};
