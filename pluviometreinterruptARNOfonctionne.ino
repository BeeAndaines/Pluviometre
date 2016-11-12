int bascules ;
int compteur ; 
const int pinD3 = 3;
//attazhc interrupt ne fonctionne que sur le pin D2 ou D3
int  temporisation;

void setup() {
  Serial.begin(9600);
  Serial.println("test pluviometre a bascule");
  compteur = 0 ;
  pinMode(pinD3, INPUT_PULLUP); 

 // https://www.arduino.cc/en/Reference/AttachInterrupt
 //attachInterrupt(digitalPinToInterrupt(numero du pin qui subit l'interrupt) , nom de la fonction d'interruption, que doit regarde l'interruption pour se declancher);

 
attachInterrupt(digitalPinToInterrupt(3) , interrupt1, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:

    bascules = digitalRead(13);
    // ligne suivante pour verifier que le pluviometre bascule 
    Serial.print("compteur vaut  ");
    delay (1000);
    Serial.println(compteur);
/* if (bascules ==0  )
        {
          Serial.println(compteur);

        }
*/
}

void interrupt1 ()
  {
        if((millis() - temporisation) > 15 ) 
        { // debounce of sensor signal / anti-rebond
          // dans la fonction d'interruption il doit y avoir le moins de commande possible 
              
               compteur ++ ;
               temporisation = millis();
      }
        
  }

