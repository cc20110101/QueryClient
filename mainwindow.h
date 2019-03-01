#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QtWidgets>
#include <QSettings>
#include "define.h"
#include "setnatsinfo.h"
#include "indepinfotabwidget.h"
#include "slowspeedinfotabwidget.h"

// 主窗口
class MainWindow : public QMainWindow {
    Q_OBJECT
  public:
    explicit MainWindow(QWidget *parent = nullptr);

  signals:

  private:
    // 读取窗口位置大小信息
    void readSettings();
    // 创建菜单和工具条
    void createMenu();
    // 状态条
    void createStatusBar();
    QMenu *infoMenu;

    IndepInfoTabWidget *indepInfoTabWidget;
    SlowSpeedInfoTabWidget *slowSpeedInfoTabWidget;

  private slots:

    // 关于系统
    void about();
    // 保存窗口大小位置信息
    void writeSettings();
    // 退出系统
    void exit();
    // 查看用户信控信息
    void indepInfo();
    // 查看用户达量降速信息
    void slowSpeedInfo();
    // 设置查询用户NATS集群信息
    void setNatsInfo();
    // 清理连接配置
    void clearNatsInfo();
};

#endif // MAINWINDOW_H
