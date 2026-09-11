/*
 * ESP32 Advanced LED Controller
 * Simulates a SensorGrid heartbeat or status indicator.
 * The LED is ON for 2000ms and OFF for 1000ms using non-blocking timing.
 */

const int ledPin = 2; // GPIO 2 (Built-in LED on most ESP32 boards)

// Define states for the LED
enum LedState {
  LED_ON,
  LED_OFF
};

LedState currentState = LED_OFF;
unsigned long previousMillis = 0;

// Timing configuration (in milliseconds)
const unsigned long onDuration = 2000;  // 2 seconds ON
const unsigned long offDuration = 1000; // 1 second OFF

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
  while (!Serial) {
    ; // Wait for serial port to connect
  }
  
  Serial.println("=================================");
  Serial.println("  ESP32 LED Controller Started   ");
  Serial.println("  ON: 2000ms | OFF: 1000ms       ");
  Serial.println("=================================");

  // Configure the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Set initial state
  digitalWrite(ledPin, LOW);
  currentState = LED_OFF;
}

void loop() {
  unsigned long currentMillis = millis();

  // Non-blocking state machine for LED control
  if (currentState == LED_OFF) {
    if (currentMillis - previousMillis >= offDuration) {
      // Time to turn ON
      previousMillis = currentMillis;
      currentState = LED_ON;
      digitalWrite(ledPin, HIGH);
      Serial.println("[STATUS] LED turned ON");
    }
  } 
  else if (currentState == LED_ON) {
    if (currentMillis - previousMillis >= onDuration) {
      // Time to turn OFF
      previousMillis = currentMillis;
      currentState = LED_OFF;
      digitalWrite(ledPin, LOW);
      Serial.println("[STATUS] LED turned OFF");
    }
  }
  
  // Here you can add other non-blocking tasks, such as reading sensors
  // or handling network requests, without the LED timing disrupting them.
}
