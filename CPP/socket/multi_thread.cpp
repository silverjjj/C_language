#include <iostream>
#include <thread>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
using namespace std;

#define PACKET_SIZE 1024
#define serverPort 7000

struct ClientInfo { // 클라이언트 정보 필드
	int socket;
	sockaddr_in clientAddress;
};

vector<pthread_t> clientThreads;    // 스레드들을 관리할 vector 선언
vector<ClientInfo*> clientPool;     // 클라이언트 정보 구조체를 관리할 vector 선언

int server_socket;                  // 서버 소켓
void* handle_client(void* data);    // 클라이언트 관리 thread 함수
void* client_accept(void* data);    // 클라이언트 연결 thread 함수

int main(){
    int optvalue = 1;
    struct sockaddr_in serverAddr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        cerr << "서버 소켓 생성 실패" << endl;
        perror("socket");
        
        return 1;
    }
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optvalue, sizeof(optvalue));

    memset(&serverAddr, 0, sizeof(serverAddr));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(serverPort);

    // 서버 소켓을 주소와 바인딩
    int bindResult = bind(server_socket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if (bindResult < 0) {
        cerr << "바인딩 실패" << endl;
        perror("bind");

        close(server_socket);
        return 1;
    }

    listen(server_socket, 5); // 5는 백로그 크기 = 동시에 처리 가능한 연결 요청의 최대 수
    cout << "서버가 "<< serverPort << " 포트에서 대기 중..." << endl;

    pthread_t thread_listen;
    if (pthread_create(&thread_listen, nullptr, client_accept, nullptr) != 0) {
        cerr << "스레드 생성 실패" << endl;
        return 1;
    }

    char msg[PACKET_SIZE] = {0};

    while (1) {
        // 메세지 버퍼 초기화하고 입력받기
        memset(msg, 0, PACKET_SIZE);
        cin >> msg;
        if ((string)msg == "list") { // 입력한 값이 "list"면 연결된 Client 목록 출력
            cout << "연결된 Client IP Address 목록" << endl;
			for (ClientInfo* c : clientPool) {
				cout << inet_ntoa(c->clientAddress.sin_addr) << ":" << ntohs(c->clientAddress.sin_port) << endl;
			}
        } else if ((string)msg == "exit") {
            cout << "Server를 종료합니다." << endl;
            pthread_detach(thread_listen);
            break;
        } 
        else { // 입력한 값이 "list", "exit"가 아니면 연결된 Client들에게 메세지 전송
            for (ClientInfo* c : clientPool) {
				send(c->socket, msg, strlen(msg), 0);
			}
        }
    }

    pthread_join(thread_listen, nullptr);
    /* 메모리 할당 해제 */
    for (ClientInfo* c : clientPool){
        cout << "clientPool 메모리 할당 해제: " << c->socket << endl;
        delete c;
    }
    for(pthread_t hThread : clientThreads){
        cout << "clientThreads 메모리 할당 해제: " << hThread << endl;
        pthread_detach(hThread);
    }
    /* 메모리 할당 해제 */

    close(server_socket);
    return 0;
}

void* client_accept(void* data){    // 클라이언트 연결 thread 함수
    while(1) {
        int client_socket;
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);

        client_socket = accept(server_socket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (client_socket == -1) {
            // 클라이언트 연결 실패 시 소켓을 닫고 다음 while 회차로 넘어감
            std::cerr << "클라이언트 연결 수락 실패" << std::endl;
            perror("client");
            close(client_socket);
            continue;
        }

        cout << "클라이언트와 연결이 완료되었습니다" << endl;
        cout << "Client IP: " << inet_ntoa(clientAddr.sin_addr) << endl;
		cout << "Port: " << ntohs(clientAddr.sin_port) << endl;
        
        // 클라이언트의 데이터를 담은 구조체를 생성하고
        // 연결된 클라이언트의 구조체 정보를 관리하기 위해 vector를 사용
        ClientInfo* clientData = new ClientInfo;
		clientData->socket = client_socket;
		clientData->clientAddress = clientAddr;

        clientPool.push_back(clientData);

        // 클라이언트를 처리할 스레드 생성
        pthread_t thread_client;
        pthread_create(&thread_client, nullptr, handle_client, (void*)clientData);
        clientThreads.push_back(thread_client);
    }
    return nullptr;
}

void* handle_client(void* data){
    ClientInfo* clientData = static_cast<ClientInfo*>(data);
    int clientSocket = clientData->socket;
	sockaddr_in clientAddr = clientData->clientAddress;

    char buffer[1024];
	int recvSize;

    do {
        memset(buffer, 0, PACKET_SIZE);
		recvSize = recv(clientSocket, buffer, sizeof(buffer), 0);
		if (recvSize > 0) {
			cout << inet_ntoa(clientAddr.sin_addr) << ":" << ntohs(clientAddr.sin_port) << "로부터 받은 메세지: [" << buffer << "]를 echo합니다." << endl;
			send(clientSocket, buffer, recvSize, 0);
		}
	} while (recvSize > 0);

    for (size_t i = 0; i < clientPool.size(); ++i) {
		if (clientPool[i]->socket == clientSocket) {
			// 클라이언트 정보 삭제
			cout << "클라이언트와 연결이 종료되었습니다: " << inet_ntoa(clientPool[i]->clientAddress.sin_addr) << ":" << ntohs(clientPool[i]->clientAddress.sin_port) << endl;
			clientPool.erase(clientPool.begin() + i);
			break;
		}
	}
    delete clientData;
    close(clientSocket);
    //pthread_detach(pthread_self());
    return nullptr;
}