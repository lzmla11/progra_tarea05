#include ../include/Block.h
#include ../include/Vote.h

#include <functional>
#include <iostream>

Block::Block(int i, std::string pHash, const std::vector<Vote>& votes) :
	index(i),
	previousHash(pHash),
	votes(votes) 
{
	this->nonce = 0; 
	this->currentHash = generateHash(); 
} 

std::string Block::generateHash() {
	std::string chain = std::to_string(index) + previousHash + std::to_string(nonce); 

	for (const Vote& v: votes) {
		chain += v.voter_id + v.candidate;  
	}
	size_t numericHash = std::hash<std::string>{}(chain); 
	return std::to_string(numericHash); 
}

std::string Block::getPreviousHash() {
	return previousHash; 
}

std::string Block::getCurrentHash() {
	return currentHash; 
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
