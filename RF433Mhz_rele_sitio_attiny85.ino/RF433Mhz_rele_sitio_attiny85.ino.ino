#include <RFremote.h>

RFrecv rfrecv;

int botao1 = 0; //--> Led embutido pode ser no 0 ou no 1...
boolean botao1St = false;

int botao2 = 1; //--> Led embutido pode ser no 0 ou no 1...
boolean botao2St = false;

const char *cmd1 = "0110100100110100110110110110110110110100110100100100100100100100100110100100110100110";
//const char *cmd2 = "0110100100110100110110110110110110110100110100100100100100100100100100110100110100110";

void setup()
{
  pinMode(botao1, OUTPUT);
  pinMode(botao2, OUTPUT);

  
  rfrecv.begin();
}

void loop()
{
  if (rfrecv.available())
  {
    
    /* VERIFICA SE O BOTAO 1 DO CONTROLE FOI APERTADO */
    if (strncmp((char*)rfrecv.cmd, cmd1, CMD_SIZE) == 0){
      botao1St = !botao1St;
      botao2St = !botao2St;
      digitalWrite(botao1, botao1St);
      digitalWrite(botao2, botao2St);
    }

  }
}
