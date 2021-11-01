#ifndef CYBERBOX_H
#define CYBERBOX_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CyberBox; }
QT_END_NAMESPACE

class CyberBox : public QMainWindow
{
    Q_OBJECT

public:
    CyberBox(QWidget *parent = nullptr);
    ~CyberBox();

private:
    Ui::CyberBox *ui;
};
#endif // CYBERBOX_H
