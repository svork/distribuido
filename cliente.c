// Amzn Foods
// Fazer pedidos de comida via um sistema distribuido
// Este é o programa CLIENTE, que envia os pedidos
// Rodrigo Costa 2018-MAI-18

// Bibliotecas Windows
#ifdef WIN32
  #include <windows.h>
  #include <winsock.h>

// Bibliotecas Linux
#else
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
#endif

// Biblioteca Padrão de Entrada/Saída de dados
#include <stdio.h>

// Biblioteca de Strings
#include <string.h>

// Variável nome guarda o nome do cliente
char nome[20] = {'J', 'o', 's', 'e'};

// Variável comida guarda o número do prato escolhido
int comida = 0;

// Variável bebida guarda o número da bebida escolhido
int bebida = 0;

// Variável pagamento guarda o número do pagamento escolhido
int pagamento = 0;

// Print na mesma posição, algo como um clear screen, dica do Tonight
void limpar(void) {
  printf("\e[2J\e[H");
}

// Função inicio - exibe a tela inicial, assim que o cliente conectar
void inicio(void) {
  printf ("\n");
  printf (" █████╗ ███╗   ███╗███████╗███╗   ██╗    ███████╗ ██████╗  ██████╗ ██████╗ ███████╗\n");
  printf ("██╔══██╗████╗ ████║╚══███╔╝████╗  ██║    ██╔════╝██╔═══██╗██╔═══██╗██╔══██╗██╔════╝\n");
  printf ("███████║██╔████╔██║  ███╔╝ ██╔██╗ ██║    █████╗  ██║   ██║██║   ██║██║  ██║███████╗\n");
  printf ("██╔══██║██║╚██╔╝██║ ███╔╝  ██║╚██╗██║    ██╔══╝  ██║   ██║██║   ██║██║  ██║╚════██║\n");
  printf ("██║  ██║██║ ╚═╝ ██║███████╗██║ ╚████║    ██║     ╚██████╔╝╚██████╔╝██████╔╝███████║\n");
  printf ("╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝    ╚═╝      ╚═════╝  ╚═════╝ ╚═════╝ ╚══════╝\n");
  printf ("\n");
  printf("(0) - Fazer pedido\n");
  printf("(1) - Sair\n");
  printf ("\n");
}

// Função escolher_nome - pede para o cliente digitar o nome
void escolher_nome(void) {
  char name[20];

  printf("=======================================================================\n");
  printf("Nome do Cliente\n");
  printf("\n");
  printf("Digite seu nome: \n");
  printf("\n");
  gets(name);

  // Copiar o que o usuário digitou para o vetor nome
  memcpy(nome, name, sizeof nome);
}

// Função escolher_comida - pede para o cliente digitar o número do prato
int escolher_comida(void) {
  int comida = 0;

  printf("=======================================================================\n");
  printf("Escolha um de nossos deliciosos pratos\n");
  printf("\n");
  printf("(0) - Marinado de salmão com lentilha puy\n");
  printf("(1) - Peixe à grega com tomates marinados\n");
  printf("(2) - Pescada amarela ao forno com purê de berinjela\n");
  printf("(3) - Camarão ao tamarindo e leite de coco\n");
  printf("(4) - Arroz de polvo com chips de alho-poró\n");
  printf("(5) - Polvo com páprica e purê de batata-doce\n");
  printf("(6) - Medalhões de lagosta e salada\n");
  printf("(7) - Siri mole com maionese de alga nori\n");
  printf("(8) - Empanada de banana-verde com recheio de siri\n");
  printf("(9) - Hambúrguer de salmão com maionese de lima da pérsia\n");
  printf("\n");
  printf("Digite o numero desejado: \n");
  printf("\n");
  scanf("%d", &comida);

  // Retornar o valor escolhido
  return comida;
}

// Função escolher_bebida - pede para o cliente digitar o número da bebida
int escolher_bebida(void) {
  int comida = 0;

  printf("=======================================================================\n");
  printf("Escolha a sua bebida favorita\n");
  printf("\n");
  printf("(0) - Vinho Azul\n");
  printf("(1) - Catuaba com açaí\n");
  printf("(2) - Vinho peçonhento\n");
  printf("(3) - Golden Coconut\n");
  printf("(4) - Cerveja de Chá Verde\n");
  printf("(5) - Whisky de ouro\n");
  printf("(6) - Vinho para gatos\n");
  printf("(7) - Suco de Farinha de Banana Verde\n");
  printf("\n");
  printf("Digite o numero desejado: \n");
  printf("\n");
  scanf("%d", &bebida);

  // Retornar o valor escolhido
  return bebida;
}

// Função escolher_pagamento - pede para o cliente digitar o número da forma de pagamento
int escolher_pagamento(void) {
  int pagamento = 0;

  printf("=======================================================================\n");
  printf("Qual será a forma de pagamento?\n");
  printf("\n");
  printf("(0) - Dinheiro\n");
  printf("(1) - Cartão de Crédito\n");
  printf("(2) - Cripto Moedas\n");
  printf("\n");
  printf("Digite o numero desejado: \n");
  printf("\n");
  scanf("%d", &pagamento);

  // Retornar o valor escolhido
  return pagamento;
}

// Função confirmar_pedido - exibe os detalhes do pedido do cliente
void confirmar_pedido(char nome[20], int comida, int bebida, int pagamento) {
  printf("=======================================================================\n");
  printf("Este é o seu pedido\n");
  printf("\n");
  printf ("Nome do Cliente: %s\n", nome);
  printf("Comida: %d\n", comida);
  printf("Bebida: %d\n", bebida);
  printf("Forma de Pagamento: %d\n", pagamento);
  printf("\n");
  printf ("Seu pedido será entregue em: 10 minutos.\n");
  printf ("Após 15 segundos essa mensagem se auto-destruirá.\n");
  printf("\n");
  printf("============================  FIM  ====================================\n");
}

// Função escolher_tela - recebe um inteiro e exibe a tela escolhida
void escolher_tela(int numero) {
  switch (numero) {
    case 0 :
      // Tela Inicial
      inicio();
      break;

    case 1 :
      // Número 1 sai do sistema
      //exit(1);
      break;

    case 2 :
      // Escolher Nome
      escolher_nome();
      break;

    case 3 :
      // Escolher Comida
      comida = escolher_comida();
      break;

    case 4 :
      // Escolher Bebida
      bebida = escolher_bebida();
      break;

    case 5 :
      // Escolher Pagamento
      pagamento = escolher_pagamento();
      break;

    case 6 :
      // Confirmar Pedido
      confirmar_pedido(nome, comida, bebida, pagamento);
      break;

    default :
      // Mensagem de erro
      printf("\nOpcao Invalida! Digite 'sair' para fechar o sistema.\n");
      break;
  }
}

// Função Main
int main(int argc, char **argv) {
  struct sockaddr_in me, server;
  int adl=sizeof(me);

  // Vetor linha contem o texto a ser enviado para o servidor
  char linha[80];

  // Variável tela define qual será enviada para o cliente
  int tela = 0;

  // Variáveis Windows
  #ifdef WIN32
	  WSADATA wsaData;
	  WORD wVersionRequested;
	  SOCKET sock=0;
 
	  wVersionRequested = MAKEWORD( 2, 2 );

	  WSAStartup(wVersionRequested, &wsaData);

  // Variáveis Linux
  #else
	  int sock=0;
  #endif

  sock=socket(AF_INET,SOCK_DGRAM,0);

  // Mostrar mensagem se o usuário não informar o IP do servidor
  if ( argc != 2 ) {

    // Comando para fechar conexão Windows
    #ifdef WIN32
		  closesocket(sock);

    // Comando para fechar conexão Linux
    #else
      close(sock);
    #endif

    // Mensagem ao usuário
		puts("Digite o IP do servidor. Exemplo 127.0.0.1");

    // Sair do programa
		exit(1);
	}
    
  // Alguma definição Windows ( ainda não sei o que é isso )
  #ifdef WIN32
	  memset(&me,0,adl);
	  memset(&server,0,adl);

  // Alguma definição Linux ( ainda não sei o que é isso )
  #else
	  bzero((char *)&me,adl);
    bzero((char *)&server,adl);
  #endif

  // Nesta parte, é definido o endereço IP do Cliente
  me.sin_family=AF_INET;
  me.sin_addr.s_addr=htonl(INADDR_ANY); /* endereco IP local */
  me.sin_port=htons(0); /* porta local (0=auto assign) */
  bind(sock,(struct sockaddr *)&me,adl);

  // Nesta parte, é definido o endereço IP do Servidor
  server.sin_family=AF_INET;
  /* endereco IP de destino */
  server.sin_addr.s_addr=inet_addr(argv[1]); /* host local */
  server.sin_port=htons(8450); /* porta do servidor */

  // Aqui as mensagens serão enviadas e recebidas, até que o usuário digite "sair"
  do {

    // Limpar a tela
    limpar();

    // Mostrar a tela
    escolher_tela(tela);

    // Ler o que o usuário digitar
    gets(linha);
    
    // Enviar o texto para o servidor
    sendto(sock,linha,80,0,(struct sockaddr *)&server,adl);

    // Exibir a próxima tela
    tela++;

    // Receber o texto do servidor
    recvfrom(sock,linha,80,0,(struct sockaddr *)&server,&adl);

    // Escrever na tela o que o servidor mandar
    puts(linha);

  } while ( strcmp (linha,"sair") );

  // Comando para fechar conexão Windows
  #ifdef WIN32
	  closesocket(sock);
	  WSACleanup( );

  // Comando para fechar conexão Linux
  #else
	  close(sock);
  #endif
}
