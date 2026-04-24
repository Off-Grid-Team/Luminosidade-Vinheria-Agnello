# 🍷 Vinheria Agnello - Sistema de Monitoramento (Luminosidade)

Sistema embarcado com Arduino que realiza a leitura da luminosidade e executa ações com base nos dados coletados.

# 📋 Descrição do Projeto

Este projeto consiste em um sistema de monitoramento de luminosidade usando um sensor fotorresistor (LDR) conectado a um Arduino Uno. O sistema lê continuamente a intensidade luminosa do ambiente e aciona LEDs coloridos e um buzzer para informar o estado atual:

| Faixa | LED | Buzzer | Ação |
|:-----:|:---:|:------:|:-----|
| 🟢 Ideal | Verde **ON** | OFF | Luminosidade dentro do nível seguro para conservação dos vinhos |
| 🟡 Atenção |  Amarelo **ON** | OFF | Luminosidade elevada — recomenda-se verificar o ambiente
| 🔴 Crítico | Vermelho **ON** | ON/OFF (3s/3s) | Luminosidade acima do limite — ação imediata necessária para proteger os vinhos


# 🛠️ Lista de Componentes

| Quantidade | Componente |
| :----------| :--------------------: |
|1| Arduino Uno
|1| Protoboard
|1| Led Verde
|1| Led Amarelo
|1| Led Vermelho
|1| Buzzer
|1| Fotorresistor
|1| Resistor de 1kΩ
|3| Resistor de 220kΩ
|-| Jumpers Macho-Macho

# ⚙️ Tecnologias Utilizadas

- **Arduino IDE** — Ambiente de desenvolvimento
- **Linguagem C/C++ (Arduino)** — Linguagem de programação
- **Tinkercad** — Simulação e diagrama do circuito

# 💻 Código-Fonte


```
// Vinheria Agnello - Sistema de Monitoramento de Luminosidade

// Definicao dos pinos dos componentes
int green = 5;
int yellow = 2;
int red = 3;
int buzz = 4;
int photo = A0;
int lightValue = 100;

// Limiares de leitura do sensor LDR
int lowThreshold = 226;
int midThreshold = 452;

// Variavel de controle para evitar disparos repetidos do buzzer
bool buzzerSounded;

void setup()
{
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(photo, INPUT);

  // Inicializa a comunicacao serial para monitoramento
  Serial.begin(9600);
}

void loop()
{
  // Leitura do valor de luminosidade no sensor LDR
  lightValue = analogRead(photo);

  // Exibe o valor lido no Monitor Serial
  Serial.print("Light level: ");
  Serial.println(lightValue);

  // Faixa 1: Luminosidade baixa (ambiente ideal para vinhos)
  if (lightValue < lowThreshold){
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
  }
  // Faixa 2: Luminosidade media (nivel de atencao)
  else if (lightValue < midThreshold){
    digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
  }
  // Faixa 3: Luminosidade alta (nivel critico)
  else {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    if (!buzzerSounded){
      buzzer();
    }
  }
}

// Funcao que aciona o buzzer por 3 segundos
void buzzer(){
  buzzerSounded = true;
  digitalWrite(buzz, HIGH);
  delay(3000);
  digitalWrite(buzz, LOW);
  delay(3000);
  buzzerSounded = false;
}
```



# 📐 Diagramas

### 🖼️ Diagrama do Circuito
![alt text](assets/circ.png)
### 🖼️ Diagrama Esquético
![alt text](assets/cp1edgeesq.png)

# 🎥 Tutorial

| Link |
| :------------ |
| https://youtu.be/sZEokD0zTMY |


# 👥 Partipantes

| Nomes         | RM             |
| :-------------| :------------: |
| Felipe Rabelo |  570340
| Gustavo Ferreira Tavares | 569928 |
| Ricardo Salmerón | 572916 |