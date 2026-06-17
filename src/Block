#include "Block.h"
#include "Vote.h"
#include <functional>
#include <iostream>
#include <sstream>
#include <iomanip>

Block::Block(int i, std::string pHash, const std::vector<Vote>& votes)
    : index(i), previousHash(pHash), votes(votes)
{
    this->nonce = 0;
    this->currentHash = generateHash();
}

std::string Block::generateHash() {
    std::string chain = std::to_string(index) + previousHash + std::to_string(nonce);
    for (const Vote& v : votes) {
        chain += v.voter_id + v.candidate;
    }
    size_t numericHash = std::hash<std::string>{}(chain);
    // Formatear como hexadecimal para que pueda empezar por "000..."
    std::ostringstream oss;
    oss << std::hex << std::setw(16) << std::setfill('0') << numericHash;
    return oss.str();
}

std::string Block::getPreviousHash() {
    return previousHash;
}

std::string Block::getCurrentHash() {
    return currentHash;
}

int Block::getIndex() {
    return index;
}

int Block::getNonce() {
    return nonce;
}

void Block::setCurrentHash(std::string h) {
    currentHash = h;
}

void Block::setNonce(int n) {
    nonce = n;
}
