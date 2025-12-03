# Desenvolvimento do aplicativo:
O aplicativo utilizado no projeto foi desenvolvido na plataforma do MIT App Inventor.
Sua concepção foi baseada em usabilidade e praticidade, consistindo em layout simples de apenas uma tela, com organizadores  para melhor acomodar os botões responsáveis por comandar o atuador no sistema por conexão Bluetooth clássico.
O código consiste em “objetos” visíveis como os botões e não visível como a conexão Bluetooth.
Quando o usuários clicar em “Conectar-se ao comedouro”, ira deparar com todas as conexões disponíveis para conexão. Assim que pareado com o RacaoExpress, o usuário terá pleno controle para abrir e fechar a porta para despejar a ração.

# Desenvolvimento do Hardware:
	Montagem:
	A montagem do sistema foi feita por impressão 3D realizada no laboratório JARVIS de Engenharia de Computação da PUC Minas Lourdes, juntamente com a montagem de controle com ESP-32 na protoboard.
	A montagem do sistema de controle consiste em: 
	⁃	“Fonte” 4 Pilhas serie AA (aprox.6V) para alimentação dedicada ao servo motor afim de garantir estabilidade;
	⁃	O comando do servo esta ligado em pino PWM do ESP;
	⁃	ESP-32 energizado via micro-usb PowerBank 5Vcc, garantindo mobilidade e independência de alimentação por computador;
	⁃	O sensor ultrassônico 4 pinos é alimentado pelo ESP-32 na saída 5V(Vin / 5V);
	⁃	O sistema contém terra (GND) comum entre o ESP e a fonte pilhas série 6V.

# Código:
	O código do projeto foi realizado na IDE do Arduino em linguagem C/C++. 
	Para seu desenvolvimento foi necessário incluir as bibliotecas <ESPServo.h>, para tratar do objeto “servo motor”, juntamente com a biblioteca <BluetoothSerial.h> responsável para fazer a conexão BT Clássica com smartphone/dispositivo.
	O código transcorre com declarações de constantes e macros anteriores ao “setup” para facilitar a leitura e entendimento do mesmo. Chegado setup, indicamos ao ESP  as portas em que cada dispositivo esta conectada e, indicamos como as mesmas devem ser interpretadas(OUTPUT ou INPUT).
	No loop do programa, parte que será mantida em execução constante, o código é responsável por verificar a entrada de dados via Bluetooth e a leitura de dados de distância medidas pelo sensor. Nesta parte foi definido tempo de abertura, distância para acionamento do servo e lógica de acionamento via Bluetooth, onde valor 1 (bool TRUE) abre e 0(bool FALSE) fecha.
# Comunicação App e Hardware:
	A comunicação entre o hardware e app(frontend) ocorre por meio de Bluetooth clássico entre o ESP-32 e o dispositivo conectado a ele. 
	Caso a conexão seja concluída com sucesso, o usuário terá controle completo ao funcionamento da porta de comidas do comedouro.
