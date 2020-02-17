        #include <Servo.h>// pour le cmmande du cerveau moteur
        // paramettre cerveau moteur
        int pinservo=3;
        Servo cerv;
        // paramettre ultra son
        int trig=5;
        int echo=4;
        long temps;
        long distance;
        // paramettre led
        int led=2;
        // parammettre buzer
        int buzz=6;
         
        void setup() {
          Serial.begin(9600);
          // initialisation des paramettres du cerveau moteur
          cerv.attach(pinservo); //définir le pin de commande du cerveau moteur
          // initialisation des paramettre de l'utra son
          pinMode(trig,OUTPUT);
          pinMode(echo,INPUT);
          digitalWrite(trig,LOW);
          // initialisation paramettres led
          pinMode(led,OUTPUT);
          digitalWrite(led,LOW);
          // initialisation parramettre buzer
          pinMode(buzz,OUTPUT);
          digitalWrite(buzz,LOW);
          // put your setup code here, to run once:
        
        }
        
        void loop() {
    
         fonction_rotation_cerveau();
        
        }
         // fonction permetant de recuperé la distance messurer par le capteur ultra son
        long Mesure_distance(){
        long   temps=0;
          long distance=0;
          digitalWrite(trig,HIGH);
          delayMicroseconds(10);
          digitalWrite(trig,LOW);
          temps=pulseIn(echo,HIGH);// pour calculer le temps d'emissin du son et reception du son par le capteur utra son
          distance=temps/58; //pour calculer la distance mesurer en cm 
         return(distance);
         }
         
         
         // fonction permettant de faire tourne le cerveau moteur d'un angle donné
         void servoMoteur(int angle) {
           
    cerv.write(angle); //pour faire tourne le cerveau moteur d'un angle angle
    }
    
    void fonction_rotation_cerveau(){
        long a=0;
         a= Mesure_distance();// pour recupére la distance messure l'ultra son et stocker dans a
           if(a<=30){
            digitalWrite(buzz,HIGH); // alummer le buzer
            
            servoMoteur(0);}
            delay(10);
            a= Mesure_distance();
             if(a<=30){
            digitalWrite(buzz,HIGH); // alummer le buzer
            servoMoteur(180);}
                   
               a= Mesure_distance();
             if (a==0){
                    digitalWrite(buzz,LOW);
                        digitalWrite(led,LOW);
                       
           
                   }
                   a= Mesure_distance();
                  if(a>=30){
                        digitalWrite(led,HIGH);
                      servoMoteur(90);}
                       digitalWrite(buzz,LOW);
                        }
