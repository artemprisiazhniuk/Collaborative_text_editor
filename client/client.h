#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QCloseEvent>
#include <QSessionManager>
#include <QPlainTextEdit>

#include <grpcpp/grpcpp.h>
#include "operationTransportation.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using operationTransportation::clientService;
using operationTransportation::editor_request;
using operationTransportation::empty;
using operationTransportation::file_from_server;
using operationTransportation::OP_type;
using operationTransportation::last_executed_operation;

class ClientService {
private:
    std::unique_ptr<clientService::Stub> stub_;
    std::string file_name;
    uint64_t last_op;
public:
    // default constructor with initialize of channel between server and client
    ClientService();
    ClientService(std::shared_ptr<Channel> channel, std::string& file_path);

    // command to initialize file in client side
    std::string initialize();

    // main method to send operation to server
    void OPs(OP_type operation, uint64_t pos, uint64_t line, char sym, uint32_t user_id);

    // call to write file from vector of strings to file in server file
    void writeToFile();
};

class client : public QMainWindow
{
    Q_OBJECT

public:
    client(std::string server_address="0.0.0.0:50052", std::string file="output.txt");
    virtual ~client() {}
protected:
    void closeEvent(QCloseEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *ev) override;

private slots:
    void newFile();
    bool save();
    bool saveAs();
    void undo();
    void redo();
    void about();
    void documentWasModified();
#ifndef QT_NO_SESSIONMANAGER
    void commitData(QSessionManager &);
#endif

private:
    ClientService service;
    void createActions();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool maybeSave();
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    QString askFilename();
    void receiveCursorsPositions(void);
    void highlightPosition(size_t pos, QColor color);
    void unhighlightPosition(size_t pos);
    void markCursors(void);
    QColor intToColor(int n);
    QMap<int, int> cursorsPositions;
    QPlainTextEdit *textEdit;
    QTextCursor cursor;
    QString curFile;
    QVector<QString> maintext;
    QVector<QColor> cursorColors = {Qt::yellow, Qt::blue, Qt::red, Qt::green};
};

#endif // MAINWINDOW_H

