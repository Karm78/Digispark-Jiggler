#include <DigiMouse.h>  // Inclure la bibliothèque DigiMouse / Includes the DigiMouse library

void setup() {
  DigiMouse.begin();  // Initialisation de la souris / Initialize the mouse
}

void loop() {
  DigiMouse.update();  // Mise à jour de la souris / Update the mouse status
  delay(5000);  // Attendre 5 secondes / Wait for 5 seconds

  int verticalMovement = random(-10, 10);  // Valeur aléatoire pour le mouvement vertical / Random value for vertical movement

  // Mouvement aléatoire de la souris avec un délai aléatoire
  // Random mouse movement with random delay
  int x = random(-10, 10);  // Mouvement horizontal / Horizontal movement
  int y = random(-10, 10) + verticalMovement;  // Mouvement vertical  / Vertical movement
  DigiMouse.move(x, y, 0);  // Déplace la souris / Move the mouse 
  DigiMouse.update();  // Met à jour après le mouvement pour envoyer les actions / Update after movement to send the actions
  delay(random(50, 200));  // Attente aléatoire entre 50 ms et 200 ms / Random waiting between 50 ms and 200 ms

  // Clic aléatoire
  // Random click
  if (random(0, 10) > 7) {  // Probabilité de 30% de clic / 30% probability of a click
    DigiMouse.setButtons(1);  // Clic gauche / Left click
    DigiMouse.update();
    delay(random(50, 200));  // Délai aléatoire entre 50 ms et 200 ms / Random delay between 50 ms and 200 ms
    DigiMouse.setButtons(0);  // Relâcher le clic / Release the click
    DigiMouse.update();
  }

  // Défilement aléatoire
  // Random scroll
  if (random(0, 10) > 7) {  // Probabilité de 30% de défilement / 30% probability of a scroll
    int scroll = random(-3, 4);  // Défilement vers le haut ou vers le bas avec une puissance aléatoire entre -3 et 3 / Scroll up or down with a random power between -3 and 3
    DigiMouse.scroll(scroll);
    DigiMouse.update();
  }

  delay(500);  // Attendre avant de répéter le cycle / Wait before repeating the cycle
}
