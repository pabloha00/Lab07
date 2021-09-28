#include <SPI.h>
#include <SD.h>

int menu;
File myFile;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  SPI.setModule(0);


  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(PA_3, OUTPUT);

  if (!SD.begin(PA_3)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  myFile = SD.open("/");


  printDirectory(myFile, 0);

  Serial.println("done!");
  Serial.println("Escoger imagen 1, 2, 3 o 4");
  Serial.println("1. Star");
  Serial.println("2. Pokeball");
  Serial.println("3. Hyrules Shield");
  Serial.println("4. Gato");
  Serial.println("\n");


}

void loop()
{
  menu = Serial.read();
  if (menu == 49) {
    // re-open the file for reading:
    myFile = SD.open("Star.txt");
    if (myFile) {
      Serial.println("Star.txt:");

      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());

      }
      // close the file:
      myFile.close();
      Serial.println("\n");
    } else {
      // if the file didn't open, print an error:
      Serial.println("Error: No se ha encontrado archivo");
      Serial.println("\n");
    }
    Serial.println("Escoger imagen 1, 2 o 3 ");
    Serial.println("1. Star");
    Serial.println("2. Pokeball");
    Serial.println("3. Hyrules Shield");
    Serial.println("4. Gato");
    Serial.println("\n");

  }
  if (menu == 50) {
    // re-open the file for reading:
    myFile = SD.open("Pokeball.txt");
    if (myFile) {
      Serial.println("Pokeball.txt:");

      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());

      }
      // close the file:
      myFile.close();
      Serial.println("\n");
    } else {
      // if the file didn't open, print an error:
      Serial.println("Error: No se ha encontrado archivo");
      Serial.println("\n");
    }
    Serial.println("Escoger imagen 1, 2 o 3 ");
    Serial.println("1. Star");
    Serial.println("2. Pokeball");
    Serial.println("3. Hyrules Shield");
    Serial.println("4. Gato");
    Serial.println("\n");

  }
  if (menu == 51) {
    // re-open the file for reading:
    myFile = SD.open("LINK_S~1.txt");
    if (myFile) {
      Serial.println("LINK_S~1.txt:");

      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());

      }
      // close the file:
      myFile.close();
      Serial.println("\n");
    } else {
      // if the file didn't open, print an error:
      Serial.println("Error: No se ha encontrado archivo");
      Serial.println("\n");
    }
    Serial.println("Escoger imagen 1, 2 o 3 ");
    Serial.println("1. Star");
    Serial.println("2. Pokeball");
    Serial.println("3. Hyrules Shield");
    Serial.println("4. Gato");
    Serial.println("\n");
  }

  if (menu == 52) {
    // re-open the file for reading:
    myFile = SD.open("Michi.txt");
    if (myFile) {
      Serial.println("Michi.txt:");

      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());

      }
      // close the file:
      myFile.close();
      Serial.println("\n");
    } else {
      // if the file didn't open, print an error:
      Serial.println("Error: No se ha encontrado archivo");
      Serial.println("\n");
    }
    Serial.println("Escoger imagen 1, 2 o 3 ");
    Serial.println("1. Star");
    Serial.println("2. Pokeball");
    Serial.println("3. Hyrules Shield");
    Serial.println("4. Gato");
    Serial.println("\n");
  }
}

void printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println(" ");

    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size());
    }
    entry.close();
  }
}
