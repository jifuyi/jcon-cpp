#ifndef JSON_RPC_WEBSOCKET_H
#define JSON_RPC_WEBSOCKET_H

#include "jcon.h"
#include "json_rpc_socket.h"

class QWebSocket;

namespace jcon {

class JCON_API JsonRpcWebSocket : public JsonRpcSocket
{
    Q_OBJECT

public:
    /**
     * Default constructor. Create a new QWebSocket.
     */
    JsonRpcWebSocket();

    /**
     * Constructor taking a previously created socket. This is used by
     * JsonRpcServer, since QWebSocketServer::nextPendingConnection() returns
     * an already created socket for the client connection.
     *
     * @param[in] socket The WebSocket to use.
     */
    JsonRpcWebSocket(QWebSocket* socket);

    virtual ~JsonRpcWebSocket();

    void connectToHost(QString host, int port) override;
    bool waitForConnected(int msecs) override;
    void disconnectFromHost() override;
    bool isConnected() const override;
    void send(const QByteArray& data) override;
    QString errorString() const override;
    QHostAddress localAddress() const override;
    int localPort() const override;
    QHostAddress peerAddress() const override;
    int peerPort() const override;

private slots:
    void dataReady(const QString& data);

private:
    void setupSocket();

    QWebSocket* m_socket;
};

}

#endif
