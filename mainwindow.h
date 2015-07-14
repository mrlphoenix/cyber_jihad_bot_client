#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QHash>
#include <QList>
#include <QListWidgetItem>
#include <QCloseEvent>
#include "partyservice.h"
#include "loginpassinputdialog.h"
#include "spamsystem.h"
namespace Ui {
class MainWindow;
}

struct partyDescriptor
{
    bool enabled;
    bool owner;
    QString name;
    QString pass;
    QList<QString> members;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setup();
    void loadAccounts();
    ~MainWindow();



    QString apikey, login;
    bool admin;


public slots:


    void loadAccountsResponse(getAccountsResult result);
    void addAccountResponse(nonQueryResult result);
    void removeAccountResponse(nonQueryResult result);
    void createPartyResponse(nonQueryResult result);
    void joinPartyResponse(joinPartyResult result);
    void leavePartyResponse(nonQueryResult result);
    void updatePartyResponse(partyUpdatesResult result);
    void savePartyParamsResponse(nonQueryResult result);


    void loadUpdates();
    void startAttack();
    void leavePartyOnExit();
    void applicationExit();
private slots:
    void connectingState(int max);
    void readingState(int max);
    void spammingState(int max);
    void wordAdded(QString word);
    void messageSent(int current);
    void socketConnected(int current);
    void messageRead(int current);

    void markBanned(QString nick);

    void closeEvent(QCloseEvent *event);




    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_create_party_button_clicked();
    void on_join_party_button_clicked();
    void on_leave_party_button_clicked();
    void on_ready_checkbox_clicked(bool checked);
    void on_party_status_returnPressed();
    void on_save_params_button_clicked();
    void on_lineEdit_3_returnPressed();
    void on_accounts_list_currentItemChanged(QListWidgetItem *current);
    void on_start_attack_button_clicked();
    void on_stop_attack_button_clicked();

private:
    Ui::MainWindow *ui;
    QStringList allAccounts_;
    QList<getAccountsResult::spamAccountDescriptor> myAccounts_;
    QList<getBannedResult::spamAccountBan> banned_;
    QStringList words_;
    QString spamMode_;

    partyServiceAllocator * psa;
    QHash<QString,partyService*> srv;

    partyDescriptor myParty;

    QTimer partyUpdateTimer;
    SpamSystem * spamSystem;

};

#endif // MAINWINDOW_H
