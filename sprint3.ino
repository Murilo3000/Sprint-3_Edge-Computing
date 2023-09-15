#include "Arduino.h"
#include "WiFi.h"
#include "DHT.h"
#include <HTTPClient.h>

#define APP_NAME    "IoT Tago+Wifi"
#define APP_VERSION "1.0.0"
#define SEPARATOR_LINE "****************************************************"

char wifiSsid[] = "Casa Nova"; // Nome da rede Wi-Fi
char wifiPass[] = "19691969"; // Senha da rede Wi-Fi
char serverAddress[] = "https://admin.tago.io/devices/65009b87762a8c00087f0996"; // Endereço do servidor TagoIO
char contentHeader[] = "application/json";
char tokenHeader[] = "74b11b4e-878c-4be6-801b-de29aaae68ba"; // Token de autenticação TagoIO

HTTPClient client;
int dhtHumidity;
int  dhtTemperature;

void setup(){
  Serial.begin(9600);
  Serial.println(SEPARATOR_LINE);
  Serial.print(APP_NAME );
  Serial.print("_");
  Serial.println(APP_VERSION);
  Serial.println(SEPARATOR_LINE);
  init_wifi();
}

void loop() {
  // Código principal que é executado repetidamente
  dhtHumidity++;
  dhtTemperature++;
  send_temperature();
  send_humidity();
  delay(5000);
}

void init_wifi(void){
   Serial.println("Conectando Wifi...");
  Serial.print("SSID: ");
  Serial.println(wifiSsid);
  Serial.print("PASS: ");
  Serial.println(wifiPass);
  WiFi.begin(wifiSsid, wifiPass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void send_temperature(void) {
  char anyData[30];
  char postData[300];
  char anyData1[30];
  char bAny[30];
  int statusCode = 0;

  // Inicialização de variáveis para armazenar os dados
  strcpy(postData, "{\n\t\"variable\": \"temperature\",\n\t\"value\": ");

  // Converte o valor da temperatura (dhtTemperature) para uma string formatada
  // com 6 dígitos no total, incluindo 2 casas decimais e armazena em anyData
  dtostrf(dhtTemperature, 6, 2, anyData);

  // Concatena a string anyData na string postData
  strncat(postData, anyData, 100);

  // Continua a construção da string postData com informações adicionais
  strcpy(anyData1, ",\n\t\"unit\": \"C\"\n\t}\n");
  strncat(postData, anyData1, 100);

  // Exibe a string postData no monitor serial (para fins de depuração)
  Serial.println(postData);

  // Inicializa o cliente HTTP para se comunicar com o servidor Tago.io
  client.begin(serverAddress);

  // Adiciona cabeçalhos HTTP necessários (Content-Type e Device-Token)
  client.addHeader("Content-Type", contentHeader);
  client.addHeader("Device-Token", tokenHeader);

  // Realiza uma solicitação HTTP POST para o servidor Tago.io com os dados
  statusCode = client.POST(postData);

  // Espera por um curto período após a solicitação (2 segundos neste caso)
  delay(2000);
}

void send_humidity(void) {
  char anyData[30];
  char postData[300];
  char anyData1[30];
  int statusCode = 0;

  // Inicialização de variáveis para armazenar os dados
  strcpy(postData, "{\n\t\"variable\": \"humidity\",\n\t\"value\": ");

  // Converte o valor da umidade (dhtHumidity) para uma string formatada
  // com 6 dígitos no total, incluindo 2 casas decimais e armazena em anyData
  dtostrf(dhtHumidity, 6, 2, anyData);

  // Concatena a string anyData na string postData
  strncat(postData, anyData, 100);

  // Continua a construção da string postData com informações adicionais
  strcpy(anyData1, ",\n\t\"unit\": \"%\"\n\t}\n");
  strncat(postData, anyData1, 100);

  // Exibe a string postData no monitor serial (para fins de depuração)
  Serial.println(postData);

  // Inicializa o cliente HTTP para se comunicar com o servidor Tago.io
  client.begin(serverAddress);

  // Adiciona cabeçalhos HTTP necessários (Content-Type e Device-Token)
  client.addHeader("Content-Type", contentHeader);
  client.addHeader("Device-Token", tokenHeader);

  // Realiza uma solicitação HTTP POST para o servidor Tago.io com os dados
  statusCode = client.POST(postData);

  // Espera por um curto período após a solicitação (5 segundos neste caso)
  delay(5000);

  // Lê e exibe o código de status HTTP retornado pela resposta do servidor
  Serial.print("Status code: ");
  Serial.println(statusCode);

  // Exibe uma mensagem indicando o fim da postagem para Tago.io
  Serial.println("End of POST to TagoIO");
  Serial.println();
}