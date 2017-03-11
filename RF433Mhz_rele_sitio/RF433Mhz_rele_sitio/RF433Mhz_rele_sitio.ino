#include <RFremote.h>

SignalPatternParams params;
RFrecv rfrecv;

/* Conectar o data da RF433Mhz no pino D2 do arduino */
const int botao1 = 9;
boolean botao1St = false;

const int botao2 = 10;
boolean botao2St = false;

const int botao3 = 11;
boolean botao3St = false;

const char *cmd1[]={
                "0110100110100110110110110110110100100100100110100100110110100110110110100100110100110",
                "0110100110110110110110110100110100100100110110110100110110100110110110100100110100110",
                "0110100100110100110110110110110110110100110100100100100100100100100110100100110100110"
              };

const char *cmd2[]={
                "0110100110100110110110110110110100100100100110100100110110100110110100110100110100110",
                "0110100110110110110110110100110100100100110110110100110110100110110100110100110100110",
                "0110100100110100110110110110110110110100110100100100100100100100100100110100110100110"
              };

/* O Controle PPA só tem 2 botões */
const char *cmd3[]={
                "0110100110100110110110110110110100100100100110100100110110100110110110110100110100110",
                "0110100110110110110110110100110100100100110110110100110110100110110110110100110100110"
              };

void setup()
{
  pinMode(botao1, OUTPUT);
  pinMode(botao2, OUTPUT);
  pinMode(botao3, OUTPUT);
  
  Serial.begin(9600);
  delay(500);

  // Parametros para PPA + Controle IPEC (Comprado Mercado livre):
  params.spaceMin = 10000;
  params.spaceMax = 15000;
  params.dotMin = 330;
  params.dotMax = 580;
  params.traceMin = 830;
  params.traceMax = 1080;
  params.skipFirst = 0;
  params.skipLast = 0;

  Serial.println("RF433Mhz - Relay_Control");
  Serial.println("www.eletroafinidade.com.br");
  Serial.println("Versao 1.0 - Marco/2017");
  Serial.println("--------------------------------------");
  Serial.print("Botao 1 aciona Pino - ");
  Serial.println(botao1);
  Serial.print("Botao 2 aciona Pino - ");
  Serial.println(botao2);
  Serial.print("Botao 3 aciona Pino - ");
  Serial.println(botao3);
  Serial.println("--------------------------------------");
  Serial.println("INICIO");
  
  rfrecv = RFrecv(&params);
  rfrecv.begin();

}

void loop()
{
  boolean achou = false;
  
  if (rfrecv.available())
  {
    //Serial.println("RECEBIDO!");
    //Serial.println((char*)rfrecv.cmd);
    
    /* VERIFICA SE O BOTAO 1 ACIONADO */
    for (int i = 0; i < (sizeof(cmd1)); i++) {
      if (strncmp((char*)rfrecv.cmd, cmd1[i], CMD_SIZE) == 0){
        botao1St = !botao1St;
        digitalWrite(botao1, botao1St);
        gravaLog( 1, botao1, botao1St);
        achou = true;
      }
    }

    /* VERIFICA SE O BOTAO 2 ACIONADO  */
    if(!achou){
      for (int j = 0; j < (sizeof(cmd2)); j++) {
        if (strncmp((char*)rfrecv.cmd, cmd2[j], CMD_SIZE) == 0){
          botao2St = !botao2St;
          digitalWrite(botao2, botao2St);
          gravaLog( 2, botao2, botao2St);
          achou = true;
        }
      }
    }
    

    /* VERIFICA SE O BOTAO 3 ACIONADO */
    if(!achou){
      for (int k = 0; k < (sizeof(cmd3)); k++) {
        if (strncmp((char*)rfrecv.cmd, cmd3[k], CMD_SIZE) == 0){
          botao3St = !botao3St;
          digitalWrite(botao3, botao3St);
          gravaLog( 3, botao3, botao3St);
          achou = true;
        }
      }      
    }
  }  
}

void gravaLog( int botao, int porta, boolean btStatus){
  Serial.print("Bt-");
  Serial.print(botao);
  Serial.print("(");
  Serial.print(porta);
  Serial.print(") => ");
  Serial.println(btStatus);

};

  

