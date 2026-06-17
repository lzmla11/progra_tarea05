#include "Blockchain.h"
#include <iostream>

Blockchain::Blockchain() {
    std::vector<Vote> emptyVotes;
    Block genesis(0, "0", emptyVotes);
    chain.push_back(genesis);
}

Blockchain& Blockchain::getInstance() {
    static Blockchain instance;
    return instance;
}

void Blockchain::addBlock(Block block) {
    chain.push_back(block);
}

void Blockchain::mineBlock(Block& block, int difficulty) {
    // Construir el prefijo requerido: ej. difficulty=2 -> "00"
    std::string target(difficulty, '0');

    int nonce = 0;
    std::string hash = block.generateHash();

    while (hash.substr(0, difficulty) != target) {
        nonce++;
        block.setNonce(nonce);
        hash = block.generateHash();
    }

    block.setCurrentHash(hash);
    std::cout << "[Minería] Bloque " << block.getIndex()
              << " sellado. Nonce: " << nonce
              << " | Hash: " << hash << "\n";
}

bool Blockchain::isChainValid() {
    for (int i = 1; i < (int)chain.size(); i++) {
        Block& current  = chain[i];
        Block& previous = chain[i - 1];

        if (current.getCurrentHash() != current.generateHash()) {
            return false;
        }

        if (current.getPreviousHash() != previous.getCurrentHash()) {
            return false;
        }
    }
    return true;
}

int Blockchain::getLength() {
    return (int)chain.size();
}

std::string Blockchain::getLastHash() {
    return chain.back().getCurrentHash();
}
