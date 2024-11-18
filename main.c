#include<LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#include<Adafruit_Fingerprint.h>
SoftwareSerial mySerial(8, 9);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
int id;
int buzzer = 13;
#definemotor A0

void setup() {
    pinMode(buzzer, OUTPUT);
    pinMode(motor, OUTPUT);
    digitalWrite(buzzer, LOW);
    digitalWrite(motor, Low);
    finger.begin(57600);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("FINGERPRINT  ");
    lcd.setCursor(0, 1);
    lcd.print("VEHICLE STARTER");
    delay(4000);
    lcd.clear();
}

void loop() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SCAN YOUR FINGER");
    lcd.setCursor(0, 1);
    lcd.print("TO START ENGINE");
    id = getFingerprintID();
    if (id == 7) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("WELCOME HARSHITHA");
        lcd.setCursor(0, 1);
        lcd.print("  ENGINE ON  ");
        digitalWrite(buzzer, HIGH);
        delay(300);
        digitalWrite(buzzer, LOW);
        digitalWrite(buzzer, HIGH);
        while(1);
    }
    else if (id == 3) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("WELCOME PERSON 2");
        lcd.setCursor(0, 1);
        lcd.print("  ENGINE ON  ");
        digitalWrite(buzzer, HIGH);
        delay(300);
        digitalWrite(buzzer, LOW);
        digitalWrite(buzzer, HIGH);
        while(1);
    }
    delay(200);
}

uint8_tgetFingerprintID() {
    uint8_t p = finger.getImage();
    switch (p) {
        case FINGRPRINT_OK:
        //Serial.println("Image taken");
        break;
        case FINGRPRINT_NOFINGER:
        //Serial.println("No finger detected");
        return p;
        case FINGRPRINT_PACKETRECEIVER:
        //Serial.println("Communication error");
        return p;
        case FINGRPRINT_IMAGEFAIL:
        //Serial.println("Imaging error");
        return p;
        default:
        //Serial.println("Unknown error");
        return p;
    }

//OK success!!!!

    p = finger.getImage2Tz();
    switch (p) {
        case FINGRPRINT_OK:
        //Serial.println("Image converted");
        break;
        case FINGRPRINT_IMAGEMESS:
        //Serial.println("Image too messy");
        return p;
        case FINGRPRINT_PACKETRECEIVER:
        //Serial.println("Communication error");
        return p;
        case FINGRPRINT_FEATUREFAIL:
        //Serial.println("Could not find fingerprint features");
        return p;
        case FINGRPRINT_INVALIDIMAGE:
        //Serial.println("Could not find fingerprint features");
        return p;
        default:
        //Serial.println("Unknown error");
        return p;
    }

//OK CONVERTED!!!!

    p = finger.fingerSearch();
    if (p = FINGERPRINT_OK) {
        //Serial.println("Found a print match!");
    }
    else if (p == FINGRPRINT_PACKETRECEIVER) {
        //Serial.println("Communication error");
        return p;
    }
    else if (p == FINGRPRINT_NOTFOUND); {
        lcd.setCursor(0, 0);
        lcd.print("FINGERPRINT NOT");
        lcd.setCursor(0, 1);
        lcd.print("FOUND ");
        digitalWrite(buzzer, HIGH);
        delay(3000);
        digitalWrite(buzzer, LOW);
        //Serial.println("Did not find a match");
        return p;
    }
    else {
         //Serial.println("Unknown error");
        return p;
    }
    //found a match 
    //Serial.println("Found ID #");  Serial.println(finger.fingerID);
    //Serial.println(" with confidence of");Serial.println(finger.confidence);

    returnfinger.fingerID;
    }

    //returns -1 if failed, otherwise returns ID #
    intgetFingerprintIDez() {
        uint8_t p = finger.getImage();
        if (p != FINGERPRINT_OK) return -1;

        p = finger.image2Tz();
        if (p != FINGERPRINT_OK) return -1;

        p = finger.fingerFastSearch();
        if (p != FINGERPRINT_OK) return -1;

        // found a match!!
        //Serial.println("Found ID #");  Serial.println(finger.fingerID);
        //Serial.println(" with confidence of"); Serial.println(finger.confidence);
        returnfinger.fingerID;
    }

