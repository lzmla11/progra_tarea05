#pragma once
#include <vector>
#include <string>
#include "Block.h"

class Blockchain {
private:
    std::vector<Block> chain;

    Blockchain();

public:
    static Blockchain& getInstance();
    Blockchain(const Blockchain&) = delete;
    Blockchain& operator=(const Blockchain&) = delete;

    void addBlock(Block block);
    void mineBlock(Block& block, int difficulty);
    bool isChainValid();
    int getLength();
    std::string getLastHash();
};
