// Amzn Foods
// Fazer pedidos de comida via um sistema distribuido
// Este é o programa SERVIDOR, que recebe os pedidos
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

// Função Main
int main(void) {
	struct sockaddr_in me, client;
	int adl=sizeof(me);

  // Vetor linha contém o texto a ser enviado para o cliente
	char linha[2000];

  // Variável tela define qual será enviada para o cliente
  int tela = 0;

  // Variável nome guarda o nome do cliente
  char nome[20];

  // Variável comida guarda o número do prato escolhido
  int comida = 0;

  // Variável bebida guarda o número da bebida escolhido
  int bebida = 0;

  // Variável pagamento guarda o número do pagamento escolhido
  int pagamento = 0;

  // Função inicio - exibe a tela inicial, assim que o cliente conectar
  void inicio() {
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
  void escolher_nome() {
    printf("=======================================================================\n");
    printf("\n");
    printf("Digite seu nome: \n");
    printf("\n");
  }

  // Função escolher_comida - pede para o cliente digitar o número do prato
  void escolher_comida() {
    printf("=======================================================================\n");
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
  }

  // Função escolher_bebida - pede para o cliente digitar o número da bebida
  void escolher_bebida() {
    printf("=======================================================================\n");
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
  }

  // Função escolher_pagamento - pede para o cliente digitar o número da forma de pagamento
  void escolher_pagamento() {
    printf("=======================================================================\n");
    printf("\n");
    printf("0) - Dinheiro\n");
    printf("1) - Cartão de Crédito\n");
    printf("2) - Cripto Moedas\n");
    printf("\n");
    printf("Digite o numero desejado: \n");
    printf("\n");
  }

  // Função confirmar_pedido - exibe os detalhes do pedido do cliente
  void confirmar_pedido() {
    printf("=======================================================================\n");
    printf ("Cliente %s",nome,", seu pedido foi: ",comida,bebida,", e a forma de pagamento escolhida foi: ",pagamento);
    printf ("\nSeu pedido será entregue em: 10 minutos.\n");
    printf ("Após 15 segundos essa mensagem se auto-destruirá.\n");
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
        escolher_comida();
        break;

      case 4 :
        // Escolher Bebida
        escolher_bebida();
        break;

      case 5 :
        // Escolher Pagamento
        escolher_pagamento();
        break;

      case 6 :
        // Confirmar Pedido
        confirmar_pedido();
        break;

      default :
        // Mensagem de erro
        printf("Opcao Invalida\n");
        break;
    }
  }

  
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

  // Alguma definição Windows ( ainda não sei o que é isso )	
  #ifdef WIN32
	  memset(&me,0,adl);

  // Alguma definição Linux ( ainda não sei o que é isso )
  #else
	  bzero((char *)&me,adl);
  #endif

  // Nesta parte, é definido o endereço IP do Servidor
	me.sin_family=AF_INET;
	me.sin_addr.s_addr=htonl(INADDR_ANY); /* endereco IP local */
	me.sin_port=htons(8450); /* porta local  */

  // Verificar se a porta de comunicação está ocupada
	if(-1!=bind(sock,(struct sockaddr *)&me,adl)) {
	  do {
        
        // Receber o que o cliente enviar
        recvfrom(sock,linha,2000,0,(struct sockaddr *)&client,&adl);

        // Mostrar a tela
        escolher_tela(tela);

        // Enviar para o cliente a resposta
        sendto(sock,linha,2000,0,(struct sockaddr *)&client,adl);
        
        // Exibir a próxima tela
        tela++;

    } while (strcmp (linha,"sair") );
  }
	else {
    // Exibir mensagem
    puts("Porta ocupada");
  }

  // Comando para fechar conexão Windows
  #ifdef WIN32
	  closesocket(sock);
	  WSACleanup( );
  // Comando para fechar conexão Linux
  #else
	  close(sock);
  #endif
}
