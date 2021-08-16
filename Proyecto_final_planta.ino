int pinPot = A5; //Puerto analógico al cual está concectado el lm35 temperatura ambiente.
int pinPotl = A4;//Puerto analogico donde se recibe la entreda del sensor de intensidad de luz
int pinPot2 = A3; //Puerto analogico donde se recibe la entrada del hidrometro
#define E1 8  // Enable Pin para el motor de riego
#define I1 6     // Control para el motor de riego
#define E2 7     // Enable Pin para el ventilador
#define I2 9     // Control para el ventilador
#define E3 10     //Enable Pin para la tira rgb
#define I3 11     // Control para la tira rgb
#define E4 12     // Enable Pin para la termoresistencia
#define I4 13     //  Control para la termoresistencia

int var = 0;     //Variable que recibe la señal del lm35.
int varl = 0;  //variable que recube la señal de la fotoresistencia
int varh = 0; //variable que recibe la señal de hidrometro

const int pin=2;//Para actuador que detecta decremento de temperatura
const int pinT=3;//Para actuador que detecta aumento de temperatura
const int pinL=4; //Para actuador que detecta aumento de luz
const int pinh=5; //Para actuador que se encarga del riego por goteo

void setup() {
  // Iniciar comunicación serie
  Serial.begin(9600);
pinMode(pin, OUTPUT);
pinMode(pinT, OUTPUT);
pinMode(pinL, OUTPUT);
pinMode(pinh, OUTPUT);
pinMode( 6, OUTPUT);
pinMode( 7, OUTPUT);
pinMode( 8, OUTPUT);
pinMode( 9, OUTPUT);
pinMode( 10, OUTPUT);
pinMode( 11, OUTPUT);
pinMode( 12, OUTPUT);
pinMode( 13, OUTPUT);
}

void loop() {
  //Arduino tiene un conversor analógico-digital con una resolución de 8 bits. 
  //El voltaje de 0 a 5V se divide en 1023. 
  
 //Sensor de temperatura
  var = analogRead(pinPot); //Se lee el puerto del potenciómetro.
  // Mostrar valor pin analógico
  Serial.println(var);
  
  if (var < 300){
    digitalWrite (pin, HIGH);
    
    digitalWrite(E4, HIGH);     // Activamos termoresistencia
    digitalWrite(I4, HIGH);     // Arrancamos
  }else if  (var > 485){
    digitalWrite (pinT, HIGH);
    
    digitalWrite(E2, HIGH);     // Activamos ventilador
    digitalWrite(I2, HIGH);     // Arrancamos
  }else{
    //apagar actuadores
    digitalWrite(pin,LOW);
    digitalWrite(pinT,LOW);
    
    digitalWrite(E2, LOW);     // apagamos ventiladores 
    digitalWrite(I2, LOW);     // Arrancamos

   
    digitalWrite(E4, LOW);     // apagamos termoresistencia
    digitalWrite(I4, LOW);     // Arrancamos
  }

  //Sensor de luminosidad
    varl = analogRead(pinPotl); //Se lee el puerto del sensor de luminosidad.
  // Mostrar valor pin analógico
  Serial.println(varl);
  
  if (varl > 716){
    digitalWrite (pinL, HIGH);
    digitalWrite(E3, HIGH);     // Activamos led RGB
    digitalWrite(I3, HIGH);     // Arrancamos
  }else{
    //apagar actuadores
    digitalWrite(pinL,LOW);
    digitalWrite(E3, LOW);     // apagamos led RGB
    digitalWrite(I3, LOW);     // Arrancamos
  }

  //Hidrometro
    varh = analogRead(pinPot2); //Se lee el puerto del hidrometro
  // Mostrar valor pin analógico
  Serial.println(varl);
  
  if (varh > 558){
    digitalWrite (pinh, HIGH);
    digitalWrite(E1, HIGH);     // Activamos Motor para riego
    digitalWrite(I1, HIGH);     // Arrancamos
        
  }else{
    //apagar actuadores
    digitalWrite(pinh,LOW);
    digitalWrite(E1, LOW);     // apagamos Motor para riego
    digitalWrite(I1, LOW);     // Arrancamos
  }
  
  }
