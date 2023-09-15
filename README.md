<h1># Sprint-3_Edge-Computing</h1>

Este é um projeto sobre enviar os dados recebidos de temperatura e humidade pela placa ESP32 para a plataforma Tago.io. Dados esses ficticios, mas com suas devidas alterações, pode ser calculada por sensores reais.<br><br>
A proposta do dispositivo tem como função: 
  - medir a temperatura da geladeira
  - verificar sua humidade.

Assim, auxiliando na funcionabilidade dela, garantindo assim que ela esteja com o ambiente interno apropriado, evitando que o conteúdo que ela esteja armazenando seja prejudicado das mais variadas formas.

<h2>## Requisitos</h2>

- Arduíno compatível com Wifi (No caso, o utilizado foi o Esp32).
- Sensor de temperatura e humidade (DHT).
- As bibliotecas: WiFi.h, DHT.h, Arduino.h e HTTPCliente.
- Conta no Tago.io com um dipositivo configurado e Token de autenticação para dar um destino aos dados recebidos.

<h2>## Configuração</h2>

Antes de usar o código, é necessário realizar algumas configurações:

1. Altere as informações da rede Wifi:

   ```cpp
   char wifiSsid[] = "SUA_REDE_WIFI"; // Nome da rede Wi-Fi
   char wifiPass[] = "SUA_SENHA_WIFI"; // Senha da rede Wi-Fi

2. Altere as informações do Tago.io e seu Token de autenticação
   
   ```cpp
   char serverAddress[] = "https://admin.tago.io/devices/SEU_DISPOSITIVO"; // Endereço do servidor TagoIO
   char tokenHeader[] = "SEU_TOKEN_TAGO"; // Token de autenticação TagoIO

<h2>## Uso</h2>

- O dispositivo medira a temperatura em intervalos regulares e as enviará para o Tago.io
- Certifique-sede que os dispositivos estejam conectados à rede Wifi, para que assim os dados possam ser enviados

<h2>## Monitoramento</h2>
  
Você pode monitorar os dados enciados para o Tago.io através da palataforma Tago.
Certifique=se de que seu dispositivo e variáveis estejam configurados corretamente no Tago.io

<h2>## Contribuição</h2>

Fique à cnotade para contribuir com melhorias e correções neste projeto. Basta fazer um fork deste repositório, fazer suas alterações e enviar um pull request

<h2>## Problemas reconhecidos</h2>

Devido a falta do equipamento ESP32 em mãos, foi utilizado o código disponível no Teams em aula, então qualquer problema relacionado ao próprio equipamento, não foi antes reconhecido
Devido a falta dos sensores de temperatura e humidade, foi realizado uma função int dhtHumidity e int dhtTemperature para simular valores, caso possua os equipamentos em mãos, necessária a alteração de certas linhas do código

<h2>## Recursos Adicionais</h2>

- Para obter mais informações sobre o Tago.io e como configurar dispositivos e variáveis, consulte a documentação oficial em [Tago.io Documentation](https://tago.io/docs/).
- Para informações sobre o sensor DHT e como usá-lo com o Arduino, consulte a documentação da biblioteca DHT em [Arduino DHT Library](https://github.com/adafruit/DHT-sensor-library).
- ChatGPT foi utilizado para corrigir e explicar certas partes do código. Recomendado a utilização do mesmo para corrigir futuros erros ou duvidas especificas sobre.
