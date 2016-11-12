int bascules ;
int compteur ; 
const int pinD13 = 13;
int countA ; 
void setup() {
 // Initialisation du port série
  Serial.begin(9600);
  Serial.println("test pluviometre a bascule");
  compteur = 0 ;
  countA=0 ;
}

void loop() {
// quand la bscule ne fait rien sa valeur est à 1

    bascules = digitalRead(13);
   
  // Serial.print(bascules);

        if (bascules ==0 )
// si on met bascules=0 on affecte bascules à 0 si l'on veut comparer il faut == alors il ne rentre jamais dans le if il doit affecterla valeur ???
        {
          for ( bascules ==0 ; countA<9 ; countA++) 
              {
              Serial.print("la boucle for tourne countA=");
              Serial.println(countA);
              } // fermeture du for
    countA=0 ;
    compteur ++ ;
     Serial.print("nombre de bascule =");
     Serial.println(compteur);
              
        }  //fermeture du if
    

}
