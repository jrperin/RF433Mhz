#include <RFremote.h>

RFrecv rfrecv;

int botao1 = 9;
boolean botao1St = false;

int botao2 = 10;
boolean botao2St = false;

const char *cmd1 = "0110100100110100110110110110110110110100110100100100100100100100100110100100110100110";
const char *cmd2 = "0110100100110100110110110110110110110100110100100100100100100100100100110100110100110";

void setup()
{
  pinMode(botao1, OUTPUT);
  pinMode(botao2, OUTPUT);
  
  Serial.begin(9600);
  delay(500);
  Serial.println("INICIADO!");
  
  rfrecv.begin();
}

void loop()
{
  if (rfrecv.available())
  {
    //Serial.println("RECEBIDO!");
    //Serial.println((char*)rfrecv.cmd);
    
    /* VERIFICA SE O BOTAO 1 DO CONTROLE FOI APERTADO */
    if (strncmp((char*)rfrecv.cmd, cmd1, CMD_SIZE) == 0){
      botao1St = !botao1St;
      digitalWrite(botao1, botao1St);
    }

    /* VERIFICA SE O BOTAO 2 DO CONTROLE FOI APERTADO */
    if (strncmp((char*)rfrecv.cmd, cmd2, CMD_SIZE) == 0){
      botao2St = !botao2St;
      digitalWrite(botao2, botao2St);
    }
    

  }
}
