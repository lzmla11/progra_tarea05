#pragma once 

#include <vector>
#include <string>
#include "Vote.h"


class Block {
	private:
		int index; 
		std::string previousHash; 
		std::string currentHash;
		int nonce; 
		std::vector<Vote> votes; 
	public: 
		Block(int i, std::string pHash, const std::vector<Vote>& votes); 
		std::string generateHash(); 
		std::string getPreviousHash(); 
		std::string getCurrentHash(); 
		int getNonce(); 

		void setCurrentHash(std::string h); 
		void setNonce(int n); 
}; 
