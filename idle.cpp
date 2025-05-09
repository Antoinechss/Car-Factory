#include "manufacture.h"
#include <Imagine/Graphics.h>
using namespace Imagine;

#include <iostream>
#include <sstream> // pour std::ostringstream
#include <string>

int main()
{
    std::cout << "Welcome to the Car Factory Idle Game!" << std::endl;
    std::cout << "Start building now" << std::endl;

    // CREATING A NEW GAME WITH REINITIALIZED PARAMETERS

    Factory factory;
    openWindow(800, 800, "Imagine++ Window");
    while (true) {
        std::ostringstream oss_budget;
        oss_budget << "Budget: $" << factory.wallet.budget;
        drawString(20, 20, oss_budget.str(), BLACK, 20); // Affichage du budget

        std::ostringstream oss_inventory;
        oss_inventory << "Car Inventory: " << factory.car_inventory << " Cars";
        drawString(20, 60, oss_inventory.str(), BLACK, 20); // Affichage de l'inventaire

        int y_offset = 100;
        for (const auto &item : factory.inventory) {
            std::ostringstream oss_inventory;
            // Format : Material name - Price - Quantity
            oss_inventory << item.first                                // Nom du matériau
                          << ": " << item.second.first                 // Prix
                          << " USD, Quantity: " << item.second.second; // Quantité
            drawString(20, y_offset, oss_inventory.str(), BLACK, 20);
            y_offset += 40; // Décale chaque ligne pour l'affichage suivant
        }
        fillRect(300, 75, 150, 30, BLUE);
        fillRect(300, 115, 150, 30, BLUE);
        fillRect(300, 155, 150, 30, BLUE);
        fillRect(300, 195, 150, 30, BLUE);
        fillRect(300, 235, 150, 30, BLUE);
        drawString(310, 100, "Buy electronics", WHITE, 20);
        drawString(330, 140, "Buy engine", WHITE, 20);
        drawString(330, 180, "Buy frame", WHITE, 20);
        drawString(330, 220, "Buy glass", WHITE, 20);
        drawString(330, 260, "Buy wheel", WHITE, 20);

        milliSleep(2000); // Attendre 1 seconde avant de redessiner
    }

    click(); // attend un clic de souris

    return 0;
}
