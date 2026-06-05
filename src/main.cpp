//CO TO ROBI: funkcja sterująca diodą włączana przyciskiem

#include <Arduino.h>

// variables and constants
constexpr int MY_LED_PIN = 2;   // wbudowana LED; constexpr lepsze niż define
constexpr int BTN_PIN = 15;     // przycisk podłączony do pinu 15 (GPIO15) - wciśnięcie przycisku połączy ten pin z masą (GND), co pozwoli na odczyt stanu przycisku (HIGH lub LOW) w programie
bool ledBlinking = false;       // informacja o tym, czy dioda ma migać (zał. przyciskiem)


// function declarations
void blinkLED(int pin, int interval);


void setup() {
  // put your setup code here, to run once:
  pinMode(MY_LED_PIN, OUTPUT); // konfiguruje pin jako wyjście (LOW 0V / HIGH 3,3V) - w tym przypadku do sterowania diodą LED; defaultowo pin jest wejściem (INPUT) i może być używany do odczytu stanu przycisku, czujnika itp.  

}

void loop() {
  // put your main code here, to run repeatedly:

}

// function definitions
void blinkLED(int pin, int interval) {  
  static unsigned long last = 0; // zmienna statyczna przechowująca czas ostatniego przełączenia stanu diody
  static bool state = false; // zmienna statyczna przechowująca aktualny stan diody (włączona/wyłączona)
  
  if (!ledBlinking) return; // jeśli dioda nie ma migać, to nie wykonujemy żadnych operacji

  unsigned long now = millis(); // zmienna przechowująca aktualny czas
  if (now - last >= interval) { 
    last = now; // aktualizujemy czas ostatniego przełączenia
    state = !state; // zmieniamy stan diody (włączona/wyłączona)
    digitalWrite(pin, state); // ustawiamy stan diody na podstawie zmiennej state (HIGH - włączona, LOW - wyłączona) 

  }


}