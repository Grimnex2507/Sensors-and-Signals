/* Use a photoresistor (or photocell) to turn on an LED in the dark
   More info and circuit schematic: http://www.ardumotive.com/how-to-use-a-photoresistor-en.html
   Dev: Michalis Vasilakis // Date: 8/6/2015 // www.ardumotive.com */
   

// Constants
const int pResistor = A0;  // Photoresistor at Arduino analog pin A0
const int ledPin = 9;      // LED pin at Arduino pin 9

// Variables
int value;                 // Store value from photoresistor (0-1023)

void setup() {
  pinMode(ledPin, OUTPUT);   // Set lepPin - 9 pin as an output
  pinMode(pResistor, INPUT); // Set pResistor - A0 pin as an input (optional)

  Serial.begin(9600);        // Initialize serial communication
}

void loop() {
  value = analogRead(pResistor);

  // You can change the threshold value as needed
  if (value > 100) {
    digitalWrite(ledPin, LOW);  // Turn LED off
  } else {
    digitalWrite(ledPin, HIGH); // Turn LED on
  }

  // Send the sensor value through serial
  Serial.println(value);

  delay(5001); // Small delay
}


// //Constants
// const int pResistor = A0; // Photoresistor at Arduino analog pin A0
// const int ledPin=9;       // Led pin at Arduino pin 9

// //Variables
// int value;				  // Store value from photoresistor (0-1023)

// void setup(){
//  pinMode(ledPin, OUTPUT);  // Set lepPin - 9 pin as an output
//  pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
// }

// void loop(){
//   value = analogRead(pResistor);
  
//   //You can change value "25"
//   if (value > 25){
//     digitalWrite(ledPin, LOW);  //Turn led off
//   }
//   else{
//     digitalWrite(ledPin, HIGH); //Turn led on
//   }

//   delay(500); //Small delay
//   //int printf("%d", value);
// }