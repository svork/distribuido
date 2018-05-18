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

// Função Main
int main(int argc, char **argv) {
  struct sockaddr_in me, server;
  int adl=sizeof(me);

  // Vetor linha contem o texto a ser enviado para o servidor
  char linha[80];

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

    // Ler o que o usuário digitar
    gets(linha);
    
    // Enviar o texto para o servidor
    sendto(sock,linha,81,0,(struct sockaddr *)&server,adl);

    // Receber o texto do servidor
    recvfrom(sock,linha,81,0,(struct sockaddr *)&server,&adl);

    // Escrever na tela o que o servidor mandar
    puts(linha);

  } while ( strcmp (linha+7,"sair") );

  // Comando para fechar conexão Windows
  #ifdef WIN32
	  closesocket(sock);
	  WSACleanup( );

  // Comando para fechar conexão Linux
  #else
	  close(sock);
  #endif
}
