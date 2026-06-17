#include <iostream>
#include <vector>
#include "Vote.h"
#include "Block.h"
#include "Blockchain.h"
#include "MesaElectoral.h"
#include "CentroElectoralSubject.h"

int main() {
    const int DIFFICULTY = 2;

    // --- Crear las 3 mesas electorales (Observers) ---
    MesaElectoral mesa1("Mesa-01");
    MesaElectoral mesa2("Mesa-02");
    MesaElectoral mesa3("Mesa-03");

    // --- Crear el Subject y registrar las mesas ---
    CentroElectoralSubject red;
    red.attach(&mesa1);
    red.attach(&mesa2);
    red.attach(&mesa3);

    // --- Obtener la cadena global (Singleton) ---
    Blockchain& blockchain = Blockchain::getInstance();

    std::cout << "=== SIMULACION DE BLOCKCHAIN DE VOTACION ===\n\n";

    // --- Bloque 1 ---
    std::cout << "-- Mesa-01 registra y mina el Bloque 1 --\n";

    std::vector<Vote> votos1 = {
        {"VOT-001", "Candidato A"},
        {"VOT-002", "Candidato B"},
        {"VOT-003", "Candidato A"}
    };

    Block bloque1(1, blockchain.getLastHash(), votos1);
    blockchain.mineBlock(bloque1, DIFFICULTY);
    blockchain.addBlock(bloque1);

    std::cout << "\n[Red] Notificando a todas las mesas...\n";
    red.notificarNuevoBloque(bloque1);

    // --- Bloque 2 ---
    std::cout << "\n-- Mesa-02 registra y mina el Bloque 2 --\n";

    std::vector<Vote> votos2 = {
        {"VOT-004", "Candidato B"},
        {"VOT-005", "Candidato A"}
    };

    Block bloque2(2, blockchain.getLastHash(), votos2);
    blockchain.mineBlock(bloque2, DIFFICULTY);
    blockchain.addBlock(bloque2);

    std::cout << "\n[Red] Notificando a todas las mesas...\n";
    red.notificarNuevoBloque(bloque2);

    // --- Validacion final ---
    std::cout << "\n=== VALIDACION FINAL ===\n";
    std::cout << "Cadena global valida: "
              << (blockchain.isChainValid() ? "SI" : "NO") << "\n";
    std::cout << "Bloques en la cadena global: " << blockchain.getLength() << "\n";

    return 0;
}
