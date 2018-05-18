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
	char linha[80], *aux;
  
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

	if(-1!=bind(sock,(struct sockaddr *)&me,adl))
	do
    {
        recvfrom(sock,linha,74,0,(struct sockaddr *)&client,&adl);
        aux=linha;while(*aux) {*aux=toupper(*aux);aux++;}
        aux = strdup(linha);
        sprintf(linha, "Rodrigo : %s", aux);
        free(aux);
        sendto(sock,linha,81,0,(struct sockaddr *)&client,adl);
    } while(strcmp(linha+7,"EXIT"));
	else puts("Porta ocupada");

#ifdef WIN32
	closesocket(sock);
	WSACleanup( );
#else
	close(sock);
#endif
}
