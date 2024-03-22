int ledVermelhoCarro = 12;
int ledAmareloCarro = 11;
int ledVerdeCarro = 10;
int ledVermelhoPedestre = 4;
int ledVerdePedestre = 3;
int botao = 2;
int tempoTravessia = 5000;
int conclusaoPedestre = 0;
int tempoPassagemCarros = 8000;

void setup()
{
    Serial.begin(9600);
    pinMode(ledVermelhoCarro, OUTPUT);
    pinMode(ledAmareloCarro, OUTPUT);
    pinMode(ledVerdeCarro, OUTPUT);
    pinMode(ledVermelhoPedestre, OUTPUT);
    pinMode(ledVerdePedestre, OUTPUT);
    pinMode(botao, INPUT);
  
    digitalWrite(ledVerdeCarro, HIGH);
    digitalWrite(ledAmareloCarro, LOW);
    digitalWrite(ledVermelhoCarro, LOW);
    digitalWrite(ledVermelhoPedestre, HIGH);
    digitalWrite(ledVerdePedestre, LOW);
}

void loop()
{
  
  Serial.print("millis(): ");
  Serial.println(millis());
  
  Serial.print("conclusaoPedestre: ");
  Serial.println(conclusaoPedestre);
  
  Serial.print("Tempo desde ultimo ciclo de pedestres: ");
  Serial.println(millis() - conclusaoPedestre);
  
  if(digitalRead(botao) && (millis() - conclusaoPedestre) > tempoPassagemCarros)
  {
    pararCarros();
    passarPedestre();
    conclusaoPedestre = millis();
  }
  
  passarCarros();
  delay(10000);
  pararCarros();
  passarPedestre();
}


void pararCarros()
{
  delay(1000);
    digitalWrite(ledVerdeCarro, LOW);
    digitalWrite(ledAmareloCarro, HIGH);
    delay(1000);
    digitalWrite(ledAmareloCarro, LOW);
    digitalWrite(ledVermelhoCarro, HIGH);
    delay(2000); 
}  

void passarPedestre(){
  digitalWrite(ledVermelhoPedestre, LOW);
  digitalWrite(ledVerdePedestre, HIGH);
  delay(tempoTravessia);
}

void passarCarros()
{
  digitalWrite(ledVermelhoPedestre, HIGH);
  digitalWrite(ledVerdePedestre, LOW);
  delay(1000);
  digitalWrite(ledVermelhoCarro, LOW);
  digitalWrite(ledVerdeCarro, HIGH);
}

