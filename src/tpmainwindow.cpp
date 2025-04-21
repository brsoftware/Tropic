#include <QClipboard>
#include <QCloseEvent>
#include <QDateTime>

#if QT_VERSION_MAJOR <= 5
#include <QTextCodec>
#include <QTextStream>
#endif

#include <Dialogs/TpDialogOpen>
#include <Dialogs/TpDialogOpenDir>
#include <Dialogs/TpDialogSave>
#include <Dialogs/TpDialogSaveCopyTo>
#include <Dialogs/TpMessageConfirmClose>
#include <Dialogs/TpMessageCritical>
#include <Utilities/TpFileSystemAssistants>
#include <Utilities/TpOpenAssistant>
#include <Utilities/TpSaveAssistant>
#include <Views/TpDocumentView>
#include <Views/TpFileView>
#include <Widgets/TpFindContainer>
#include <Widgets/TpGeneralComboBox>
#include <TpApplication>
#include <TpEditor>
#include <TpMainWindow>
#include <TpTabSplitter>
#include <TpTabWidget>

#include <Qsci/qsciscintilla.h>

TP_NAMESPACE

TpMainWindow::TpMainWindow(bool create, bool open, QWidget *parent)
    : QMainWindow(parent),
    m_confirmClose(new TpMessageConfirmClose(this))
{
    setAcceptDrops(true);
    setAnimated(true);
    setDockNestingEnabled(true);
    setDockOptions(AllowTabbedDocks | GroupedDragging);
    setDocumentMode(true);
    setEnabled(true);
    setObjectName("mainWindow");
    setUnifiedTitleAndToolBarOnMac(true);
    resize(1000, 800);

    m_menuBar = new TpMenuBar(this);
    setMenuBar(m_menuBar);

    m_widget = new TpStackedWidget(this);
    setCentralWidget(m_widget);

    m_fileDock = new TpFileDock(this);
    addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, m_fileDock);
    m_fileDock->setVisible(true);

    m_documentDock = new TpDocumentDock(this);
    addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, m_documentDock);
    m_documentDock->setVisible(true);

    m_bookmarkDock = new TpBookmarkDock(this);
    addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, m_bookmarkDock);
    m_bookmarkDock->setVisible(false);

    m_findDock = new TpFindDock(this);
    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, m_findDock);
    m_findDock->setVisible(false);

    m_findInFilesDock = new TpFindInFilesDock(this);
    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, m_findInFilesDock);
    tabifyDockWidget(m_findDock, m_findInFilesDock);
    m_findInFilesDock->setVisible(false);

    m_findToolBar = new TpFindToolBar(this);
    addToolBar(Qt::ToolBarArea::BottomToolBarArea, m_findToolBar);
    m_findToolBar->setVisible(false);

    m_statusBar = new TpStatusBar(this);
    setStatusBar(m_statusBar);

    connect(qobject_cast<TpApplication*>(qApp),
            &TpApplication::messageReceived,
            this,
            &TpMainWindow::onAppMessageReceived);

    connect(m_menuBar->F_N_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_N_T);
    connect(m_menuBar->F_N_W,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_N_W);
    connect(m_menuBar->F_O_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_O_T);
    connect(m_menuBar->F_O_W,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_O_W);

    for (auto &action : m_menuBar->m_recentFileActions)
        connect(action,
                &QAction::triggered,
                this,
                &TpMainWindow::onAction_F_R);

    connect(m_menuBar->F_R_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_R_C);
    connect(m_menuBar->F_R_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_R_O);
    connect(m_menuBar->F_R_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_R_L);
    connect(m_menuBar->F_T_F,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_T_F);
    connect(m_menuBar->F_T_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_T_C);
    connect(m_menuBar->F_T_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_T_T);
    connect(m_menuBar->F_E,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_E);
    connect(m_menuBar->F_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_D);
    connect(m_menuBar->F_W,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_W);
    connect(m_menuBar->F_B_R,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_B_R);
    connect(m_menuBar->F_B_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_B_D);
    connect(m_menuBar->F_B_F,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_B_F);
    connect(m_menuBar->F_B_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_B_A);
    connect(m_menuBar->F_B_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_B_N);
    connect(m_menuBar->F_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_S);
    connect(m_menuBar->F_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_A);
    connect(m_menuBar->F_Y,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_Y);
    connect(m_menuBar->F_d,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_d);
    connect(m_menuBar->F_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_C);
    connect(m_menuBar->F_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_L);
    connect(m_menuBar->F_p,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_p);
    connect(m_menuBar->F_M_B,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_M_B);
    connect(m_menuBar->F_M_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_M_L);
    connect(m_menuBar->F_M_R,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_M_R);
    connect(m_menuBar->F_M_U,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_M_U);
    connect(m_menuBar->F_Q,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_F_Q);
    connect(m_menuBar->E_U,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_U);
    connect(m_menuBar->E_R,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_R);
    connect(m_menuBar->E_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_C);
    connect(m_menuBar->E_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_O);
    connect(m_menuBar->E_P,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_P);
    connect(m_menuBar->E_D_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_D_D);
    connect(m_menuBar->E_D_B,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_D_B);
    connect(m_menuBar->E_D_I,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_D_I);
    connect(m_menuBar->E_D_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_D_L);
    connect(m_menuBar->E_D_R,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_D_R);
    connect(m_menuBar->E_D_E,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_D_E);
    connect(m_menuBar->E_D_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_D_N);
    connect(m_menuBar->E_M_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_A);
    connect(m_menuBar->E_M_B,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_B);
    connect(m_menuBar->E_M_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_C);
    connect(m_menuBar->E_M_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_D);
    connect(m_menuBar->E_M_E,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_E);
    connect(m_menuBar->E_M_F,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_F);
    connect(m_menuBar->E_M_G,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_G);
    connect(m_menuBar->E_M_H,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_H);
    connect(m_menuBar->E_M_I,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_I);
    connect(m_menuBar->E_M_J,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_J);
    connect(m_menuBar->E_M_K,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_K);
    connect(m_menuBar->E_M_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_L);
    connect(m_menuBar->E_M_M,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_M);
    connect(m_menuBar->E_M_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_N);
    connect(m_menuBar->E_M_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_O);
    connect(m_menuBar->E_M_P,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_P);
    connect(m_menuBar->E_M_Q,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_Q);
    connect(m_menuBar->E_M_R,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_R);
    connect(m_menuBar->E_M_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_S);
    connect(m_menuBar->E_M_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_T);
    connect(m_menuBar->E_M_U,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_U);
    connect(m_menuBar->E_M_V,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_V);
    connect(m_menuBar->E_M_W,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_W);
    connect(m_menuBar->E_M_X,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_X);
    connect(m_menuBar->E_M_Y,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_Y);
    connect(m_menuBar->E_M_Z,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_M_Z);
    connect(m_menuBar->E_S_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_A);
    connect(m_menuBar->E_S_B,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_B);
    connect(m_menuBar->E_S_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_C);
    connect(m_menuBar->E_S_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_D);
    connect(m_menuBar->E_S_E,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_E);
    connect(m_menuBar->E_S_F,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_F);
    connect(m_menuBar->E_S_G,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_G);
    connect(m_menuBar->E_S_H,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_H);
    connect(m_menuBar->E_S_I,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_I);
    connect(m_menuBar->E_S_J,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_J);
    connect(m_menuBar->E_S_K,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_K);
    connect(m_menuBar->E_S_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_L);
    connect(m_menuBar->E_S_M,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_M);
    connect(m_menuBar->E_S_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_N);
    connect(m_menuBar->E_S_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_O);
    connect(m_menuBar->E_S_P,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_P);
    connect(m_menuBar->E_S_Q,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_Q);
    connect(m_menuBar->E_S_R,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_R);
    connect(m_menuBar->E_S_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_S);
    connect(m_menuBar->E_S_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_T);
    connect(m_menuBar->E_S_U,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_U);
    connect(m_menuBar->E_S_V,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_V);
    connect(m_menuBar->E_S_W,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_W);
    connect(m_menuBar->E_S_X,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_X);
    connect(m_menuBar->E_S_Y,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_Y);
    connect(m_menuBar->E_S_Z,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_S_Z);
    connect(m_menuBar->E_I_I,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_I_I);
    connect(m_menuBar->E_I_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_I_D);
    connect(m_menuBar->E_L_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_L_D);
    connect(m_menuBar->E_L_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_L_C);
    connect(m_menuBar->E_L_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_L_O);
    connect(m_menuBar->E_L_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_L_T);
    connect(m_menuBar->E_L_U,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_L_U);
    connect(m_menuBar->E_L_W,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_L_W);
    connect(m_menuBar->E_A_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_A_L);
    connect(m_menuBar->E_A_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_A_S);
    connect(m_menuBar->E_G,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_G);
    connect(m_menuBar->E_E_F,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_E_F);
    connect(m_menuBar->E_E_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_E_N);
    connect(m_menuBar->E_E_P,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_E_P);
    connect(m_menuBar->E_E_X,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_E_X);
    connect(m_menuBar->E_E_U,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_E_U);
    connect(m_menuBar->E_E_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_E_L);
    connect(m_menuBar->E_E_M,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_E_M);
    connect(m_menuBar->E_E_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_E_S);
    connect(m_menuBar->E_B_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_B_T);
    connect(m_menuBar->E_B_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_B_N);
    connect(m_menuBar->E_B_P,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_B_P);
    connect(m_menuBar->E_B_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_B_C);
    connect(m_menuBar->E_B_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_B_O);
    connect(m_menuBar->E_B_R,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_B_R);
    connect(m_menuBar->E_B_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_B_A);
    connect(m_menuBar->E_B_h,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_B_h);
    connect(m_menuBar->E_B_I,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_E_B_I);
    connect(m_menuBar->V_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_A);
    connect(m_menuBar->V_F,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_F);
    connect(m_menuBar->V_h,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_h);
    connect(m_menuBar->V_Y_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_Y_S);
    connect(m_menuBar->V_Y_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_Y_A);
    connect(m_menuBar->V_Y_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_Y_T);
    connect(m_menuBar->V_Y_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_Y_N);
    connect(m_menuBar->V_Y_W,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_Y_W);
    connect(m_menuBar->V_Y_I,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_Y_I);
    connect(m_menuBar->V_Z_I,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_Z_I);
    connect(m_menuBar->V_Z_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_Z_O);
    connect(m_menuBar->V_Z_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_Z_T);
    connect(m_menuBar->V_T_1,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_1);
    connect(m_menuBar->V_T_2,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_2);
    connect(m_menuBar->V_T_3,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_3);
    connect(m_menuBar->V_T_4,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_4);
    connect(m_menuBar->V_T_5,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_5);
    connect(m_menuBar->V_T_6,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_6);
    connect(m_menuBar->V_T_7,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_7);
    connect(m_menuBar->V_T_8,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_8);
    connect(m_menuBar->V_T_9,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_9);
    connect(m_menuBar->V_T_0,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_0);
    connect(m_menuBar->V_T_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_L);
    connect(m_menuBar->V_T_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_N);
    connect(m_menuBar->V_T_F,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_F);
    connect(m_menuBar->V_T_P,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_P);
    connect(m_menuBar->V_T_M,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_M);
    connect(m_menuBar->V_T_R,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_R);
    connect(m_menuBar->V_T_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_S);
    connect(m_menuBar->V_T_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_T_T);
    connect(m_menuBar->V_W_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_W_N);
    connect(m_menuBar->V_W_W,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_W_W);
    connect(m_menuBar->V_W_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_W_C);
    connect(m_menuBar->V_W_H,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_W_H);
    connect(m_menuBar->V_L_M,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_L_M);
    connect(m_menuBar->V_I,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_I);
    connect(m_menuBar->V_C_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_C_D);
    connect(m_menuBar->V_C_U,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_C_U);
    connect(m_menuBar->V_C_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_C_S);
    connect(m_menuBar->V_C_E,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_C_E);
    connect(m_menuBar->V_C_V,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_C_V);
    connect(m_menuBar->V_O_H,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_O_H);
    connect(m_menuBar->V_O_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_O_A);
    connect(m_menuBar->V_O_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_O_C);
    connect(m_menuBar->V_O_E,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_O_E);
    connect(m_menuBar->V_O_S_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_O_S_D);
    connect(m_menuBar->V_O_S_P,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_O_S_P);
    connect(m_menuBar->V_O_S_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_O_S_C);
    connect(m_menuBar->V_O_S_B,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_O_S_B);
    connect(m_menuBar->V_O_S_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_O_S_T);
    connect(m_menuBar->V_O_S_X,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_V_O_S_X);
    connect(m_menuBar->I_F,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_I_F);
    connect(m_menuBar->I_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_I_T);
    connect(m_menuBar->I_V,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_I_V);
    connect(m_menuBar->I_N_W,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_I_N_W);
    connect(m_menuBar->I_N_M,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_I_N_M);
    connect(m_menuBar->I_N_U,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_I_N_U);
    connect(m_menuBar->I_D_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_I_D_D);
    connect(m_menuBar->I_D_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_I_D_T);
    connect(m_menuBar->I_D_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_I_D_A);
    connect(m_menuBar->O_L_p,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_p);
    connect(m_menuBar->O_L_A_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_A_C);
    connect(m_menuBar->O_L_A_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_A_S);
    connect(m_menuBar->O_L_A_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_A_A);
    connect(m_menuBar->O_L_B_B,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_B_B);
    connect(m_menuBar->O_L_B_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_B_T);
    connect(m_menuBar->O_L_B_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_B_S);
    connect(m_menuBar->O_L_B_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_B_A);
    connect(m_menuBar->O_L_B_F,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_B_F);
    connect(m_menuBar->O_L_C_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_C_C);
    connect(m_menuBar->O_L_C_pl,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_C_pl);
    connect(m_menuBar->O_L_C_p,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_C_p);
    connect(m_menuBar->O_L_C_s,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_C_s);
    connect(m_menuBar->O_L_C_M,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_C_M);
    connect(m_menuBar->O_L_C_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_C_O);
    connect(m_menuBar->O_L_C_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_C_S);
    connect(m_menuBar->O_L_D_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_D_D);
    connect(m_menuBar->O_L_D_I,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_D_I);
    connect(m_menuBar->O_L_F_F,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_F_F);
    connect(m_menuBar->O_L_F_7,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_F_7);
    connect(m_menuBar->O_L_G_G,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_G_G);
    connect(m_menuBar->O_L_H_H,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_H_H);
    connect(m_menuBar->O_L_H_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_H_T);
    connect(m_menuBar->O_L_I_I,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_I_I);
    connect(m_menuBar->O_L_I_H,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_I_H);
    connect(m_menuBar->O_L_J_J,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_J_J);
    connect(m_menuBar->O_L_J_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_J_S);
    connect(m_menuBar->O_L_J_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_J_O);
    connect(m_menuBar->O_L_L_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_L_T);
    connect(m_menuBar->O_L_L_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_L_L);
    connect(m_menuBar->O_L_M_F,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_M_F);
    connect(m_menuBar->O_L_M_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_M_D);
    connect(m_menuBar->O_L_M_M,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_M_M);
    connect(m_menuBar->O_L_M_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_M_L);
    connect(m_menuBar->O_L_N_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_N_N);
    connect(m_menuBar->O_L_O_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_O_O);
    connect(m_menuBar->O_L_P_P,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_P_P);
    connect(m_menuBar->O_L_P_E,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_P_E);
    connect(m_menuBar->O_L_P_H,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_P_H);
    connect(m_menuBar->O_L_P_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_P_O);
    connect(m_menuBar->O_L_P_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_P_S);
    connect(m_menuBar->O_L_P_V,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_P_V);
    connect(m_menuBar->O_L_P_R,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_P_R);
    connect(m_menuBar->O_L_P_2,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_P_2);
    connect(m_menuBar->O_L_P_3,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_P_3);
    connect(m_menuBar->O_L_P_X,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_P_X);
    connect(m_menuBar->O_L_Q_Q,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_Q_Q);
    connect(m_menuBar->O_L_Q_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_Q_S);
    connect(m_menuBar->O_L_Q_U,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_Q_U);
    connect(m_menuBar->O_L_R_R,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_R_R);
    connect(m_menuBar->O_L_S_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_S_S);
    connect(m_menuBar->O_L_S_Q,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_S_Q);
    connect(m_menuBar->O_L_S_R,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_S_R);
    connect(m_menuBar->O_L_T_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_T_T);
    connect(m_menuBar->O_L_T_H,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_T_H);
    connect(m_menuBar->O_L_T_X,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_T_X);
    connect(m_menuBar->O_L_V_V,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_V_V);
    connect(m_menuBar->O_L_V_H,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_V_H);
    connect(m_menuBar->O_L_X_X,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_X_X);
    connect(m_menuBar->O_L_Y_Y,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_L_Y_Y);
    connect(m_menuBar->O_N_U,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_N_U);
    connect(m_menuBar->O_N_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_N_C);
    connect(m_menuBar->O_N_E,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_N_E);
    connect(m_menuBar->O_N_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_N_T);
    connect(m_menuBar->O_N_M,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_N_M);
    connect(m_menuBar->O_N_X,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_N_X);
    connect(m_menuBar->O_I_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_I_T);
    connect(m_menuBar->O_I_B,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_I_B);
    connect(m_menuBar->O_I_I,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_I_I);
    connect(m_menuBar->O_R_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_R_L);
    connect(m_menuBar->O_R_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_R_S);
    connect(m_menuBar->O_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_S);
    connect(m_menuBar->O_h,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_h);
    connect(m_menuBar->O_A_U,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_A_U);
    connect(m_menuBar->O_A_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_O_A_L);
    connect(m_menuBar->T_A_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_A_C);
    connect(m_menuBar->T_A_F,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_A_F);
    connect(m_menuBar->T_A_R,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_A_R);
    connect(m_menuBar->T_A_W_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_A_W_N);
    connect(m_menuBar->T_A_W_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_A_W_O);
    connect(m_menuBar->T_A_W_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_A_W_D);
    connect(m_menuBar->T_A_S_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_A_S_D);
    connect(m_menuBar->T_A_S_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_A_S_A);
    connect(m_menuBar->T_A_S_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_A_S_O);
    connect(m_menuBar->T_A_S_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_A_S_L);
    connect(m_menuBar->T_A_T_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_A_T_A);
    connect(m_menuBar->T_A_T_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_A_T_D);
    connect(m_menuBar->T_A_T_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_A_T_L);
    connect(m_menuBar->T_h_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_h_A);
    connect(m_menuBar->T_h_S_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_h_S_A);
    connect(m_menuBar->T_h_S_M,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_h_S_M);
    connect(m_menuBar->T_h_S_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_h_S_O);
    connect(m_menuBar->T_h_S_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_h_S_C);
    connect(m_menuBar->T_B_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_B_N);
    connect(m_menuBar->T_B_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_B_S);
    connect(m_menuBar->T_B_B,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_B_B);
    connect(m_menuBar->T_C_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_C_T);
    connect(m_menuBar->T_C_P_B,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_C_P_B);
    connect(m_menuBar->T_C_P_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_C_P_A);
    connect(m_menuBar->T_C_S_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_C_S_D);
    connect(m_menuBar->T_C_S_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_C_S_N);
    connect(m_menuBar->T_C_S_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_C_S_A);
    connect(m_menuBar->T_C_S_W,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_C_S_W);
    connect(m_menuBar->T_E_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_E_N);
    connect(m_menuBar->T_E_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_E_L);
    connect(m_menuBar->T_E_B,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_E_B);
    connect(m_menuBar->T_V_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_V_S);
    connect(m_menuBar->T_V_M,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_V_M);
    connect(m_menuBar->T_V_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_V_A);
    connect(m_menuBar->T_V_P,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_V_P);
    connect(m_menuBar->T_V_V_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_V_V_D);
    connect(m_menuBar->T_V_V_R,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_V_V_R);
    connect(m_menuBar->T_V_V_U,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_V_V_U);
    connect(m_menuBar->T_V_V_W,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_V_V_W);
    connect(m_menuBar->T_V_R_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_V_R_C);
    connect(m_menuBar->T_V_R_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_V_R_A);
    connect(m_menuBar->T_V_C_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_V_C_O);
    connect(m_menuBar->T_V_C_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_V_C_N);
    connect(m_menuBar->T_V_C_W,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_V_C_W);
    connect(m_menuBar->T_S_R_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_S_R_N);
    connect(m_menuBar->T_S_R_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_S_R_S);
    connect(m_menuBar->T_S_R_P,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_S_R_P);
    connect(m_menuBar->T_S_R_pl,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_S_R_pl);
    connect(m_menuBar->T_S_C,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_S_C);
    connect(m_menuBar->T_S_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_S_O);
    connect(m_menuBar->T_S_W,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_S_W);
    connect(m_menuBar->T_S_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_S_S);
    connect(m_menuBar->T_S_G,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_S_G);
    connect(m_menuBar->T_W_I_P,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_W_I_P);
    connect(m_menuBar->T_W_I_S,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_W_I_S);
    connect(m_menuBar->T_W_I_I,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_W_I_I);
    connect(m_menuBar->T_W_I_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_W_I_D);
    connect(m_menuBar->T_W_S_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_W_S_N);
    connect(m_menuBar->T_W_S_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_W_S_T);
    connect(m_menuBar->T_W_S_B,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_W_S_B);
    connect(m_menuBar->T_W_S_M,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_W_S_M);
    connect(m_menuBar->T_W_E_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_W_E_N);
    connect(m_menuBar->T_W_E_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_W_E_T);
    connect(m_menuBar->T_W_E_B,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_W_E_B);
    connect(m_menuBar->T_W_E_M,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_W_E_M);
    connect(m_menuBar->T_M_B,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_M_B);
    connect(m_menuBar->T_M_P_O,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_M_P_O);
    connect(m_menuBar->T_M_P_T,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_M_P_T);
    connect(m_menuBar->T_M_P_M,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_M_P_M);
    connect(m_menuBar->T_M_Q_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_M_Q_D);
    connect(m_menuBar->T_M_Q_N,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_M_Q_N);
    connect(m_menuBar->T_M_Q_A,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_M_Q_A);
    connect(m_menuBar->T_M_Q_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_T_M_Q_L);
    connect(m_menuBar->W_F,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_W_F);
    connect(m_menuBar->W_L,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_W_L);
    connect(m_menuBar->W_B,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_W_B);
    connect(m_menuBar->W_D,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_W_D);
    connect(m_menuBar->W_I,
            &QAction::triggered,
            this,
            &TpMainWindow::onAction_W_I);

    connect(m_widget->tabs(),
            &TpTabSplitter::tabChanged,
            this,
            &TpMainWindow::onTabChanged);
    connect(m_widget->tabs(),
            &TpTabSplitter::tabCloseRequested,
            this,
            &TpMainWindow::onTabCloseRequested);

    connect(this,
            &TpMainWindow::wrapVisualFlagChanged,
            this,
            &TpMainWindow::onWrapVisualFlagChanged);

    connect(m_fileDock,
            &TpFileDock::visibilityChanged,
            this,
            &TpMainWindow::onFileDockVisibilityChanged);
    connect(m_fileDock,
            &TpFileDock::fileDoubleClicked,
            this,
            &TpMainWindow::onFileDockDoubleClicked);
    connect(m_documentDock,
            &TpDocumentDock::visibilityChanged,
            this,
            &TpMainWindow::onDocumentDockVisibilityChanged);
    connect(m_documentDock,
            &TpDocumentDock::fileDoubleClicked,
            this,
            &TpMainWindow::onDocumentDockDoubleClicked);
    connect(m_bookmarkDock,
            &TpBookmarkDock::visibilityChanged,
            this,
            &TpMainWindow::onBookmarkDockVisibilityChanged);
    connect(m_findDock,
            &TpFindDock::visibilityChanged,
            this,
            &TpMainWindow::onFindDockVisibilityChanged);
    connect(m_findInFilesDock,
            &TpFindInFilesDock::visibilityChanged,
            this,
            &TpMainWindow::onFindInFilesDockVisibilityChanged);
    connect(m_findInFilesDock,
            &TpFindInFilesDock::resultClicked,
            this,
            &TpMainWindow::onFindInFilesDockDoubleClicked);

    connect(m_findToolBar,
            &TpFindToolBar::textChanged,
            this,
            &TpMainWindow::onFindToolBarTextChanged);

    connect(m_statusBar->m_spinBoxTabWidth,
            qOverload<int>(&QSpinBox::valueChanged),
            this,
            &TpMainWindow::onStatusBarSpinBoxTabWidthChanged);
#if QT_VERSION_MAJOR >= 6
    connect(m_statusBar->m_comboBoxLang,
            &TpGeneralComboBox::currentIndexChanged,
            this,
            &TpMainWindow::onStatusBarComboBoxLangIndexChanged);
    connect(m_statusBar->m_comboBoxNewLine,
            &TpGeneralComboBox::currentIndexChanged,
            this,
            &TpMainWindow::onStatusBarComboBoxNewLineIndexChanged);
#else
    connect(m_statusBar->m_comboBoxLang,
            SIGNAL(currentIndexChanged(int)),
            this,
            SLOT(onStatusBarComboBoxLangIndexChanged(int)));
    connect(m_statusBar->m_comboBoxNewLine,
            SIGNAL(currentIndexChanged(int)),
            this,
            SLOT(onStatusBarComboBoxNewLineIndexChanged(int)));
#endif

    if (create)
        onAction_F_N_T(0);

    if (open)
        onAction_F_O_T(0);

    DEF_SETTINGS;

    if (GET_SETTINGS("App/Geometry", QString) != "")
        restoreState(GET_SETTINGS("App/Geometry", QByteArray));

    if (!create && !open)
    {
        QMap<QString, QVariant> editorsMap = qvariant_cast<QMap<QString, QVariant>>(settings.value("App/Editors"));
        QMap<QString, QVariant> settingsMap =
            qvariant_cast<QMap<QString, QVariant>>(settings.value("App/EditorSettings"));

        if (!editorsMap.isEmpty())
        {
            for (const auto &key : editorsMap.keys())
            {
                QFile file(key);
                QFileInfo fileInfo(file);
                QString content;
                if (file.open(QFile::OpenModeFlag::ReadOnly))
                    content = file.readAll();
                TpEditor *editor = m_widget->tabs()->tab()->addEditor((fileInfo.exists() ? key : ""), "", content);
                editor->setText(editorsMap[key].toString());
                QString potentialError = editor->fromMap(settingsMap[key].toMap());

                if (!potentialError.isEmpty())
                {
                    TpMessageCritical *critical = new TpMessageCritical(this);
                    critical->genericSay(tr("Error while parsing settings file"), potentialError, "", true);
                }

                else
                {
                    onTabChanged(m_widget->tabs()->tab(), m_widget->tabs()->tab()->currentIndex());
                }
            }
        }

        QStringList args = qApp->arguments();
        args.takeFirst();  // [[Tropic]] file
        QStringList filteredArgs = {};

        for (const auto &item : args)
        {
            if (QFile(item).exists())
                filteredArgs.append(item);
        }

        TpOpenAssistant *assistant = new TpOpenAssistant(this);
        assistant->openFiles(filteredArgs);
    }

    updateRecentFiles();
}

TpMainWindow::~TpMainWindow()
{}

Languages TpMainWindow::currentLexer() const
{
    if (m_widget->tabs()->tab()->hasTab())
        return m_widget->tabs()->tab()->tab()->currentLexer();

    return None;
}

void TpMainWindow::closeEvent(QCloseEvent *event)
{
    DEF_SETTINGS;
    SET_SETTINGS("App/Geometry", saveState());

    event->accept();
}

void TpMainWindow::onAppMessageReceived(int, QByteArray message)
{
    QList<QByteArray> split = message.split('\f');
    split.takeFirst();  // b"[[Tropic]] source file"
    QStringList filtered = {};

    for (const auto &item : split)
        if (QFile(QString::fromUtf8(item)).exists())
            filtered.append(QString::fromUtf8(item));

    TpOpenAssistant *assistant = new TpOpenAssistant(this);
    assistant->openFiles(filtered);
}

void TpMainWindow::onAction_F_N_T(bool)
{
    m_widget->tabs()->tab()->addEditor();
}

void TpMainWindow::onAction_F_N_W(bool)
{
    TpMainWindow *mainwindow = new TpMainWindow(true);
    mainwindow->show();
}

void TpMainWindow::onAction_F_O_T(bool)
{
    TpDialogOpen *dialog = new TpDialogOpen(this);
    dialog->exec();
}

void TpMainWindow::onAction_F_O_W(bool)
{
    TpMainWindow *mainwindow = new TpMainWindow(false, true);
    mainwindow->show();
}

void TpMainWindow::onAction_F_R(bool)
{
    TpGeneralAction *action = qobject_cast<TpGeneralAction*>(sender());

    if (action)
    {
        TpOpenAssistant *assistant = new TpOpenAssistant(this);
        assistant->openFile(action->data().toString());
    }
}

void TpMainWindow::onAction_F_R_C(bool)
{
    DEF_SETTINGS;

    SET_SETTINGS("App/RecentFiles", QStringList());

    for (const auto &item : std::as_const(m_menuBar->m_recentFileActions))
        item->setVisible(false);

    for (QWidget *widget : qApp->topLevelWidgets())
    {
        TpMainWindow *mainWindow = qobject_cast<TpMainWindow*>(widget);

        if (mainWindow)
            mainWindow->updateRecentFiles();
    }
}

void TpMainWindow::onAction_F_R_O(bool)
{
    for (const auto &item : std::as_const(m_menuBar->m_recentFileActions))
    {
        if (item->data().toString() == "")
            break;

        if (item->isVisible())
        {
            TpOpenAssistant *assistant = new TpOpenAssistant(this);
            assistant->openFile(item->data().toString());
        }
    }
}

void TpMainWindow::onAction_F_R_L(bool)
{
    TpOpenAssistant *assistant = new TpOpenAssistant(this);
    assistant->openFile(m_menuBar->m_recentFileActions.at(0)->data().toString());
}

void TpMainWindow::onAction_F_T_F(bool)
{
    revealInExplorer(m_widget->tabs()->tab()->tab()->m_filePath);
}

void TpMainWindow::onAction_F_T_C(bool)
{
    openInCMD(m_widget->tabs()->tab()->tab()->m_filePath);
}

void TpMainWindow::onAction_F_T_T(bool)
{
    QDir dir(QFileInfo(QFile(m_widget->tabs()->tab()->tab()->m_filePath)).path());
    TpFileView *view = m_fileDock->fileView();
    view->fileModel()->setRootPath(QDir::rootPath());
    view->setRootIndex(view->fileModel()->index(QFileInfo(QFile(m_widget->tabs()->tab()->tab()->m_filePath)).path()));
    m_fileDock->setVisible(true);
}

void TpMainWindow::onAction_F_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->beginUndoAction();

        const QString &path = editor->m_filePath;

        QFile file(path);

        if (!file.exists())
        {
            TpMessageCritical *critical = new TpMessageCritical(this);
            critical->say(
                tr("File Error"),
                tr("The file of the following file path could not be reloaded: '%1'").arg(path),
                tr("The file does not exist on your computer.\nError code: 0x0000F001")
            );
        }

        if (file.open(QFile::OpenModeFlag::ReadOnly | QFile::OpenModeFlag::Text))
        {
            QTextStream textStream(&file);
#if QT_VERSION_MAJOR >= 6
        textStream.setEncoding(QStringConverter::Encoding::Utf8);
#else
        QTextCodec *textCodec = QTextCodec::codecForName("UTF-8");
        textStream.setCodec(textCodec);
#endif

            QString content = textStream.readAll();
            editor->clear();
            editor->insert(content);
        }

        else
        {
            TpMessageCritical *critical = new TpMessageCritical(this);
            critical->say(
                tr("File Error"),
                tr("The file of the following file path could not be reloaded: '%1'").arg(path),
                tr(fileErrorReason(file.error()))
            );
        }

        file.close();

        editor->endUndoAction();
    }
}

void TpMainWindow::onAction_F_D(bool)
{
    revealInDefaultViewer(m_widget->tabs()->tab()->tab()->m_filePath);
}

void TpMainWindow::onAction_F_B_R(bool)
{
    QString path = m_widget->tabs()->tab()->tab()->m_filePath;
    QDir dir = QDir(QDir(path).absolutePath());
    TpFileView *view = m_fileDock->fileView();
    m_fileDock->setVisible(true);
    QModelIndex index = view->fileModel()->index(path);

    if (path.startsWith(view->fileModel()->filePath(view->rootIndex())))
    {
        view->expand(index);
        view->edit(index);
    }

    else
    {
        TpMessageCritical *critical = new TpMessageCritical(this);
        critical->say(
            tr("File Error"),
            tr("The file of the following file path could not be renamed: '%1'").arg(path),
            tr("You have not opened the corresponding directory in the Tropic File Browser to let it rename your file "
               "%1 yet.\nError code: 0x0000B001").arg(path)
        );
    }
}

void TpMainWindow::onAction_F_B_D(bool)
{
    QString path = m_widget->tabs()->tab()->tab()->m_filePath;
    QFile file(path);

    if (!file.moveToTrash())
    {
        TpMessageCritical *critical = new TpMessageCritical(this);
        critical->say(
            tr("File Error"),
            tr("The file of the following file path could not be opened: '%1'").arg(path),
            tr(fileErrorReason(file.error()))
        );
    }
}

void TpMainWindow::onAction_F_B_F(bool)
{
    QString path = QFileInfo(QFile(m_widget->tabs()->tab()->tab()->m_filePath)).fileName();
    QClipboard *clipboard = qApp->clipboard();
    clipboard->setText(path, QClipboard::Mode::Clipboard);
}

void TpMainWindow::onAction_F_B_A(bool)
{
    QString path = m_widget->tabs()->tab()->tab()->m_filePath;
    QClipboard *clipboard = qApp->clipboard();
    clipboard->setText(path, QClipboard::Mode::Clipboard);
}

void TpMainWindow::onAction_F_B_N(bool)
{
    QString path = QFileInfo(QFile(m_widget->tabs()->tab()->tab()->m_filePath)).path();
    QClipboard *clipboard = qApp->clipboard();
    clipboard->setText(path, QClipboard::Mode::Clipboard);
}

void TpMainWindow::onAction_F_W(bool)
{
    TpDialogOpenDir *dialog = new TpDialogOpenDir(this);
    dialog->exec();
}

bool TpMainWindow::onAction_F_S(bool)
{
    onTabChanged(m_widget->tabs()->tab(), m_widget->tabs()->tab()->currentIndex());

    if (m_widget->tabs()->tab()->tab()->m_filePath != "")
    {
        QString file = m_widget->tabs()->tab()->tab()->m_filePath;
        TpSaveAssistant *assistant = new TpSaveAssistant(this);
        return assistant->saveFile(file);
    }

    else
    {
        return onAction_F_A(0);
    }
}

bool TpMainWindow::onAction_F_A(bool)
{
    onTabChanged(m_widget->tabs()->tab(), m_widget->tabs()->tab()->currentIndex());

    TpDialogSave *dialog = new TpDialogSave(this);
    dialog->exec();
    return dialog->successful();
}

bool TpMainWindow::onAction_F_Y(bool)
{
    TpDialogSaveCopyTo *dialog = new TpDialogSaveCopyTo(this);
    dialog->exec();
    return dialog->successful();
}

void TpMainWindow::onAction_F_d(bool)
{
    for (auto &i : m_widget->tabs()->tab()->acquire(TpTabWidget::AllEditors))
    {
        m_widget->tabs()->tab()->setCurrentWidget(i);
        m_widget->tabs()->tab()->currentWidget()->setFocus();

        onAction_F_S(0);
    }
}

int TpMainWindow::onAction_F_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (editor)
    {
        bool isSame = (editor->content() == editor->text());

        if (!isSame)
        {
            switch (m_confirmClose->say())
            {
            case TpMessageConfirmClose::Save:
                if (!onAction_F_S(0))
                    return TpMessageConfirmClose::Cancel;
            case TpMessageConfirmClose::Cancel:
                return TpMessageConfirmClose::Cancel;
            }
        }

        DEF_SETTINGS;

        QMap<QString, QVariant> editors = qvariant_cast<QMap<QString, QVariant>>(settings.value("Apps/Editor"));
        QString key = (editor->filePath() == "") ? (tr("Untitled %1").arg(editor->m_untitled)) : editor->filePath();

        if (editors.contains(key))
        {
            editors.remove(key);
        }

        SET_SETTINGS("App/Editors", editors);

        m_widget->tabs()->tab()->removeEditor(editor);

        if (tab)
            if (tab->count() <= 0)
                m_widget->tabs()->removeTab(tab);

        if (m_widget->tabs()->tab())
            if (m_widget->tabs()->tab()->tab())
                m_widget->tabs()->tab()->tab()->setFocus();

        emit m_widget->tabs()->tab()->tabNameChanged();

        return TpMessageConfirmClose::Discard;
    }

    return TpMessageConfirmClose::Cancel;
}

void TpMainWindow::onAction_F_L(bool)
{
    for (auto &i : m_widget->tabs()->m_tabs)
    {
        if (i->isVisible())
        {
            i->currentWidget()->setFocus();

            TpTabWidget *currentTab = m_widget->tabs()->tab();
            TpEditor *current = currentTab->tab();

            for (auto &i : currentTab->acquire(TpTabWidget::AllEditors))
            {
                currentTab->setCurrentWidget(i);
                currentTab->currentWidget()->setFocus();

                onAction_F_C(0);
            }

        }
    }

    if (!m_widget->tabs()->hasTab())
        m_widget->setCurrentIndex(0);
}

void TpMainWindow::onAction_F_p(bool)
{
    TpTabWidget *currentTab = m_widget->tabs()->tab();
    TpEditor *current = currentTab->tab();

    for (auto &i : currentTab->acquire(TpTabWidget::AllEditors))
    {
        currentTab->setCurrentWidget(i);
        currentTab->currentWidget()->setFocus();

        onAction_F_C(0);
    }

    if (currentTab == m_widget->tabs()->tab())
    {
        if (currentTab->hasTab())
        {
            if (currentTab->contains(current))
            {
                currentTab->setCurrentIndex(currentTab->indexOf(current));
                current->setFocus();
            }
        }

        else
        {
            currentTab->hide();
            emit currentTab->tabNameChanged();

            bool allInvisible = true;

            for (int index = 0; index < m_widget->tabs()->m_tabs.count(); index++)
            {
                if (!m_widget->tabs()->m_tabs.at(index)->isHidden())
                {
                    allInvisible = false;
                    break;
                }
            }

            if (allInvisible)
                m_widget->setCurrentIndex(0);
            else
                m_widget->tabs()->tab()->currentWidget()->setFocus();
        }
    }
}

void TpMainWindow::onAction_F_M_B(bool)
{
    TpTabWidget *currentTab = m_widget->tabs()->tab();
    TpEditor *current = currentTab->tab();

    for (auto &i : currentTab->acquire(TpTabWidget::ExceptCurrent))
    {
        currentTab->setCurrentWidget(i);
        currentTab->currentWidget()->setFocus();

        onAction_F_C(0);
    }

    if (currentTab == m_widget->tabs()->tab())
    {
        if (currentTab->hasTab())
        {
            if (currentTab->contains(current))
            {
                currentTab->setCurrentIndex(currentTab->indexOf(current));
                current->setFocus();
            }
        }

        else
        {
            currentTab->hide();
            emit currentTab->tabNameChanged();

            bool allInvisible = true;

            for (int index = 0; index < m_widget->tabs()->m_tabs.count(); index++)
            {
                if (!m_widget->tabs()->m_tabs.at(index)->isHidden())
                {
                    allInvisible = false;
                    break;
                }
            }

            if (allInvisible)
                m_widget->setCurrentIndex(0);
            else
                m_widget->tabs()->tab()->currentWidget()->setFocus();
        }
    }
}

void TpMainWindow::onAction_F_M_L(bool)
{
    TpTabWidget *currentTab = m_widget->tabs()->tab();
    TpEditor *current = currentTab->tab();

    for (auto &i : currentTab->acquire(TpTabWidget::ToTheLeft))
    {
        currentTab->setCurrentWidget(i);
        currentTab->currentWidget()->setFocus();

        onAction_F_C(0);
    }

    if (currentTab == m_widget->tabs()->tab())
    {
        if (currentTab->hasTab())
        {
            if (currentTab->contains(current))
            {
                currentTab->setCurrentIndex(currentTab->indexOf(current));
                current->setFocus();
            }
        }

        else
        {
            currentTab->hide();
            emit currentTab->tabNameChanged();

            bool allInvisible = true;

            for (int index = 0; index < m_widget->tabs()->m_tabs.count(); index++)
            {
                if (!m_widget->tabs()->m_tabs.at(index)->isHidden())
                {
                    allInvisible = false;
                    break;
                }
            }

            if (allInvisible)
                m_widget->setCurrentIndex(0);
            else
                m_widget->tabs()->tab()->currentWidget()->setFocus();
        }
    }
}

void TpMainWindow::onAction_F_M_R(bool)
{
    TpTabWidget *currentTab = m_widget->tabs()->tab();
    TpEditor *current = currentTab->tab();

    for (auto &i : currentTab->acquire(TpTabWidget::ToTheRight))
    {
        currentTab->setCurrentWidget(i);
        currentTab->currentWidget()->setFocus();

        onAction_F_C(0);
    }

    if (currentTab == m_widget->tabs()->tab())
    {
        if (currentTab->hasTab())
        {
            if (currentTab->contains(current))
            {
                currentTab->setCurrentIndex(currentTab->indexOf(current));
                current->setFocus();
            }
        }

        else
        {
            currentTab->hide();
            emit currentTab->tabNameChanged();

            bool allInvisible = true;

            for (int index = 0; index < m_widget->tabs()->m_tabs.count(); index++)
            {
                if (!m_widget->tabs()->m_tabs.at(index)->isHidden())
                {
                    allInvisible = false;
                    break;
                }
            }

            if (allInvisible)
                m_widget->setCurrentIndex(0);
            else
                m_widget->tabs()->tab()->currentWidget()->setFocus();
        }
    }
}

void TpMainWindow::onAction_F_M_U(bool)
{
    TpTabWidget *currentTab = m_widget->tabs()->tab();
    TpEditor *current = currentTab->tab();

    for (auto &i : currentTab->acquire(TpTabWidget::Unchanged))
    {
        currentTab->setCurrentWidget(i);
        currentTab->currentWidget()->setFocus();

        onAction_F_C(0);
    }

    if (currentTab == m_widget->tabs()->tab())
    {
        if (currentTab->hasTab())
        {
            if (currentTab->contains(current))
            {
                currentTab->setCurrentIndex(currentTab->indexOf(current));
                current->setFocus();
            }
        }

        else
        {
            currentTab->hide();
            emit currentTab->tabNameChanged();

            bool allInvisible = true;

            for (int index = 0; index < m_widget->tabs()->m_tabs.count(); index++)
            {
                if (!m_widget->tabs()->m_tabs.at(index)->isHidden())
                {
                    allInvisible = false;
                    break;
                }
            }

            if (allInvisible)
                m_widget->setCurrentIndex(0);
            else
                m_widget->tabs()->tab()->currentWidget()->setFocus();
        }
    }
}

void TpMainWindow::onAction_F_Q(bool)
{
    QApplication::quit();
}

void TpMainWindow::onAction_E_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_UNDO);
    }
}

void TpMainWindow::onAction_E_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_REDO);
    }
}

void TpMainWindow::onAction_E_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CUT);
    }
}

void TpMainWindow::onAction_E_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_COPY);
    }
}

void TpMainWindow::onAction_E_P(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PASTE);
    }
}

void TpMainWindow::onAction_E_D_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CLEAR);
    }
}

void TpMainWindow::onAction_E_D_B(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DELETEBACK);
    }
}

void TpMainWindow::onAction_E_D_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DELETEBACKNOTLINE);
    }
}

void TpMainWindow::onAction_E_D_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DELWORDLEFT);
    }
}

void TpMainWindow::onAction_E_D_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DELWORDRIGHT);
    }
}

void TpMainWindow::onAction_E_D_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DELWORDRIGHTEND);
    }
}

void TpMainWindow::onAction_E_D_N(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DELLINELEFT);
    }
}

void TpMainWindow::onAction_E_D_G(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DELLINERIGHT);
    }
}

void TpMainWindow::onAction_E_M_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEDOWN);
    }
}

void TpMainWindow::onAction_E_M_B(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEUP);
    }
}

void TpMainWindow::onAction_E_M_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEEND);
    }
}

void TpMainWindow::onAction_E_M_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEENDDISPLAY);
    }
}

void TpMainWindow::onAction_E_M_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEENDWRAP);
    }
}

void TpMainWindow::onAction_E_M_F(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PARADOWN);
    }
}

void TpMainWindow::onAction_E_M_G(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PARAUP);
    }
}

void TpMainWindow::onAction_E_M_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CHARLEFT);
    }
}

void TpMainWindow::onAction_E_M_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CHARRIGHT);
    }
}

void TpMainWindow::onAction_E_M_J(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDLEFT);
    }
}

void TpMainWindow::onAction_E_M_K(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDRIGHT);
    }
}

void TpMainWindow::onAction_E_M_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDLEFTEND);
    }
}

void TpMainWindow::onAction_E_M_M(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDRIGHTEND);
    }
}

void TpMainWindow::onAction_E_M_N(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDPARTLEFT);
    }
}

void TpMainWindow::onAction_E_M_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDPARTRIGHT);
    }
}

void TpMainWindow::onAction_E_M_P(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_HOME);
    }
}

void TpMainWindow::onAction_E_M_Q(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_HOMEDISPLAY);
    }
}

void TpMainWindow::onAction_E_M_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_HOMEWRAP);
    }
}

void TpMainWindow::onAction_E_M_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_VCHOME);
    }
}

void TpMainWindow::onAction_E_M_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_VCHOMEWRAP);
    }
}

void TpMainWindow::onAction_E_M_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DOCUMENTSTART);
    }
}

void TpMainWindow::onAction_E_M_V(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DOCUMENTEND);
    }
}

void TpMainWindow::onAction_E_M_W(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PAGEUP);
    }
}

void TpMainWindow::onAction_E_M_X(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PAGEDOWN);
    }
}

void TpMainWindow::onAction_E_M_Y(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_STUTTEREDPAGEUP);
    }
}

void TpMainWindow::onAction_E_M_Z(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_STUTTEREDPAGEDOWN);
    }
}

void TpMainWindow::onAction_E_S_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SELECTALL);
    }
}

void TpMainWindow::onAction_E_S_B(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEDOWNEXTEND);
    }
}

void TpMainWindow::onAction_E_S_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEDOWNRECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEUPEXTEND);
    }
}

void TpMainWindow::onAction_E_S_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEUPRECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_F(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEENDEXTEND);
    }
}

void TpMainWindow::onAction_E_S_G(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEENDRECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEENDDISPLAYEXTEND);
    }
}

void TpMainWindow::onAction_E_S_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEENDWRAPEXTEND);
    }
}

void TpMainWindow::onAction_E_S_J(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PARADOWNEXTEND);
    }
}

void TpMainWindow::onAction_E_S_K(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PARAUPEXTEND);
    }
}

void TpMainWindow::onAction_E_S_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CHARLEFTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_M(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CHARLEFTRECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_N(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CHARRIGHTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CHARRIGHTRECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_P(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDLEFTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_Q(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDRIGHTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDLEFTENDEXTEND);
    }
}

void TpMainWindow::onAction_E_S_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDRIGHTENDEXTEND);
    }
}

void TpMainWindow::onAction_E_S_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDPARTLEFTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDPARTRIGHTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_V(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_HOMEEXTEND);
    }
}

void TpMainWindow::onAction_E_S_W(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_HOMERECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_X(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_HOMEDISPLAYEXTEND);
    }
}

void TpMainWindow::onAction_E_S_Y(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_HOMEWRAPEXTEND);
    }
}

void TpMainWindow::onAction_E_S_Z(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_VCHOMEEXTEND);
    }
}

void TpMainWindow::onAction_E_S_0(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_VCHOMERECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_1(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_VCHOMEWRAPEXTEND);
    }
}

void TpMainWindow::onAction_E_S_2(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DOCUMENTSTARTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_3(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DOCUMENTENDEXTEND);
    }
}

void TpMainWindow::onAction_E_S_4(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PAGEUPEXTEND);
    }
}

void TpMainWindow::onAction_E_S_5(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PAGEUPRECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_6(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PAGEDOWNEXTEND);
    }
}

void TpMainWindow::onAction_E_S_7(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PAGEDOWNRECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_8(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_STUTTEREDPAGEUPEXTEND);
    }
}

void TpMainWindow::onAction_E_S_9(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_STUTTEREDPAGEDOWNEXTEND);
    }
}

void TpMainWindow::onAction_E_I_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_TAB);
    }
}

void TpMainWindow::onAction_E_I_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_BACKTAB);
    }
}

void TpMainWindow::onAction_E_L_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEDELETE);
    }
}

void TpMainWindow::onAction_E_L_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINECUT);
    }
}

void TpMainWindow::onAction_E_L_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINECOPY);
    }
}

void TpMainWindow::onAction_E_L_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINETRANSPOSE);
    }
}

void TpMainWindow::onAction_E_L_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_MOVESELECTEDLINESUP);
    }
}

void TpMainWindow::onAction_E_L_W(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_MOVESELECTEDLINESDOWN);
    }
}

void TpMainWindow::onAction_E_A_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEDUPLICATE);
    }
}

void TpMainWindow::onAction_E_A_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SELECTIONDUPLICATE);
    }
}

void TpMainWindow::onAction_E_G(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_EDITTOGGLEOVERTYPE);
    }
}

void TpMainWindow::onAction_E_E_F(bool)
{
    m_findDock->setVisible(true);
    m_findDock->container()->m_findEdit->setFocus();
}

void TpMainWindow::onAction_E_E_N(bool)
{
    if (m_findToolBar->m_findEdit->hasFocus() && m_findDock->container())
    {
        m_widget->tabs()->tab()->tab()->findFirst(
            m_findToolBar->m_findEdit->text(),
            m_findDock->container()->m_checkSimpleRegex->isChecked(),
            m_findDock->container()->m_checkCase->isChecked(),
            m_findDock->container()->m_checkWord->isChecked(),
            m_findDock->container()->m_checkWrap->isChecked(),
            true, -1, -1, true,
            m_findDock->container()->m_checkPosixRegex->isChecked(),
            m_findDock->container()->m_checkCppRegex->isChecked()
        );
    }

    else
    {
        if (m_findDock->container())
            m_findDock->container()->onFindButtonClicked(0);
    }
}

void TpMainWindow::onAction_E_E_P(bool)
{
    if (m_findToolBar->m_findEdit->hasFocus() && m_findDock->container())
    {
        m_widget->tabs()->tab()->tab()->findFirst(
            m_findToolBar->m_findEdit->text(),
            m_findDock->container()->m_checkSimpleRegex->isChecked(),
            m_findDock->container()->m_checkCase->isChecked(),
            m_findDock->container()->m_checkWord->isChecked(),
            m_findDock->container()->m_checkWrap->isChecked(),
            false, -1, -1, true,
            m_findDock->container()->m_checkPosixRegex->isChecked(),
            m_findDock->container()->m_checkCppRegex->isChecked()
        );
    }

    else
    {
        if (m_findDock->container())
        {
            m_findDock->container()->m_checkPrevious->setChecked(true);
            m_findDock->container()->onFindButtonClicked(0);
        }
    }
}

void TpMainWindow::onAction_E_E_X(bool)
{
    if (m_findToolBar->m_findEdit->hasFocus() && m_findDock->container())
    {
        m_widget->tabs()->tab()->tab()->findFirstInSelection(
            m_findToolBar->m_findEdit->text(),
            m_findDock->container()->m_checkSimpleRegex->isChecked(),
            m_findDock->container()->m_checkCase->isChecked(),
            m_findDock->container()->m_checkWord->isChecked(),
            true, true,
            m_findDock->container()->m_checkPosixRegex->isChecked(),
            m_findDock->container()->m_checkCppRegex->isChecked()
        );
    }

    else
    {
        if (m_findDock->container())
        {
            m_findDock->container()->m_checkSelection->setChecked(true);
            m_findDock->container()->onFindButtonClicked(0);
        }
    }
}

void TpMainWindow::onAction_E_E_U(bool)
{
    if (m_findToolBar->m_findEdit->hasFocus() && m_findDock->container())
    {
        m_widget->tabs()->tab()->tab()->findFirstInSelection(
            m_findToolBar->m_findEdit->text(),
            m_findDock->container()->m_checkSimpleRegex->isChecked(),
            m_findDock->container()->m_checkCase->isChecked(),
            m_findDock->container()->m_checkWord->isChecked(),
            false, true,
            m_findDock->container()->m_checkPosixRegex->isChecked(),
            m_findDock->container()->m_checkCppRegex->isChecked()
        );
    }

    else
    {
        if (m_findDock->container())
        {
            m_findDock->container()->m_checkPrevious->setChecked(true);
            m_findDock->container()->m_checkSelection->setChecked(true);
            m_findDock->container()->onFindButtonClicked(0);
        }
    }
}

void TpMainWindow::onAction_E_E_L(bool)
{
    m_findToolBar->setVisible(true);
    m_findToolBar->m_findEdit->setFocus();
}

void TpMainWindow::onAction_E_E_M(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->moveToMatchingBrace();
    }
}

void TpMainWindow::onAction_E_E_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->selectToMatchingBrace();
    }
}

void TpMainWindow::onAction_E_B_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    editor->onMarginClicked(1, editor->currentLine(), Qt::KeyboardModifier::NoModifier);
}

void TpMainWindow::onAction_E_B_N(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    editor->setCurrentLine(editor->markerFindNext(
        editor->currentLine() + (m_menuBar->E_B_T->isChecked() ? 1 : 0),
        (editor->marginMarkerMask(1) & (editor->m_bookmarkMarker + 1)))
    );
}

void TpMainWindow::onAction_E_B_P(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    editor->setCurrentLine(editor->markerFindPrevious(
        editor->currentLine() - (m_menuBar->E_B_T->isChecked() ? 1 : 0),
        (editor->marginMarkerMask(1) & (editor->m_bookmarkMarker + 1)))
    );
}

void TpMainWindow::onAction_E_B_C(bool isChecked)
{
    QString bookmarked = onAction_E_B_A(isChecked);
    QClipboard *clipboard = qApp->clipboard();

    if (bookmarked != "")
        clipboard->setText(bookmarked);
}

void TpMainWindow::onAction_E_B_O(bool)
{
    QString bookmarked = "";
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    const QString content = editor->text();
    int lines = editor->lines();

    for (int line = 0; line < lines; line++)
    {
        if (editor->markersAtLine(line) & (editor->m_bookmarkMarker + 1))
        {
            bookmarked += content.split('\n').at(line);
            bookmarked += '\n';
        }
    }

    QClipboard *clipboard = qApp->clipboard();

    if (bookmarked != "")
        clipboard->setText(bookmarked);
}

void TpMainWindow::onAction_E_B_R(bool)
{
    m_widget->tabs()->tab()->tab()->markerDeleteAll(m_widget->tabs()->tab()->tab()->m_bookmarkMarker);
}

QString TpMainWindow::onAction_E_B_A(bool)
{
    QString bookmarked = "";
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    int lines = editor->lines();

    editor->beginUndoAction();

    for (int line = 0; line < lines; line++)
    {
        editor->setCurrentLine(line);

        if (editor->markersAtLine(line) & (editor->m_bookmarkMarker + 1))
        {
            // To not contaminate the other lines
            editor->markerDelete(line);

            editor->SendScintilla(TpEditor::SCI_LINEENDEXTEND);
            editor->SendScintilla(TpEditor::SCI_CHARRIGHTEXTEND);
            bookmarked += (editor->selectedText());
            editor->removeSelectedText();
            line--;
        }
    }

    editor->endUndoAction();

    editor->adjustBookmarks();

    return bookmarked;
}

QString TpMainWindow::onAction_E_B_h(bool)
{
    QString bookmarked = "";
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    int lines = editor->lines();

    editor->beginUndoAction();

    for (int line = 0; line < lines; line++)
    {
        editor->setCurrentLine(line);

        if (!(editor->markersAtLine(line) & (editor->m_bookmarkMarker + 1)))
        {
            editor->SendScintilla(TpEditor::SCI_LINEENDEXTEND);
            editor->SendScintilla(TpEditor::SCI_CHARRIGHTEXTEND);
            bookmarked += (editor->selectedText());
            editor->removeSelectedText();
        }
    }

    editor->endUndoAction();

    editor->adjustBookmarks();

    return bookmarked;
}

void TpMainWindow::onAction_E_B_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    for (int line = 0; line < editor->lines(); line++)
    {
        if (editor->markersAtLine(line) & (editor->m_bookmarkMarker + 1))
            editor->markerDelete(line, editor->m_bookmarkMarker);
        else
            editor->markerAdd(line, editor->m_bookmarkMarker);
    }

    editor->adjustBookmarks();
}

void TpMainWindow::onAction_V_A(bool isChecked)
{
    if (isChecked)
        setWindowFlags(Qt::WindowType::WindowStaysOnTopHint | windowFlags());
    else
        setWindowFlag(Qt::WindowType::WindowStaysOnTopHint, false);

    show();
}

void TpMainWindow::onAction_V_F(bool isChecked)
{
    if (isChecked)
        showFullScreen();
    else
        showNormal();
}

void TpMainWindow::onAction_V_h(bool isChecked)
{
    if (isChecked)
        setWindowFlags(Qt::WindowType::FramelessWindowHint | windowFlags());
    else
        setWindowFlag(Qt::WindowType::FramelessWindowHint, false);

    show();
}

void TpMainWindow::onAction_V_Y_S(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        if (isChecked)
        {
            editor->setWhitespaceVisibility(TpEditor::WhitespaceVisibility::WsVisible);
            SET_SETTINGS("View/ShowSymbols/SpacesAndTabsAll", true);
        }

        else
        {
            editor->setWhitespaceVisibility(TpEditor::WhitespaceVisibility::WsInvisible);
            SET_SETTINGS("View/ShowSymbols/SpacesAndTabsAll", false);
        }
    }
}

void TpMainWindow::onAction_V_Y_A(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        if (isChecked)
        {
            editor->setWhitespaceVisibility(TpEditor::WhitespaceVisibility::WsVisibleAfterIndent);
            SET_SETTINGS("View/ShowSymbols/SpacesAndTabsAfterIndentation", true);
        }

        else
        {
            editor->setWhitespaceVisibility(TpEditor::WhitespaceVisibility::WsInvisible);
            SET_SETTINGS("View/ShowSymbols/SpacesAndTabsAfterIndentation", false);
        }
    }
}

void TpMainWindow::onAction_V_Y_T(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        if (isChecked)
        {
            editor->setWhitespaceVisibility(TpEditor::WhitespaceVisibility::WsVisibleOnlyInIndent);
            SET_SETTINGS("View/ShowSymbols/SpacesAndTabsInIndentation", true);
        }

        else
        {
            editor->setWhitespaceVisibility(TpEditor::WhitespaceVisibility::WsInvisible);
            SET_SETTINGS("View/ShowSymbols/SpacesAndTabsInIndentation", false);
        }
    }
}

void TpMainWindow::onAction_V_Y_N(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEolVisibility(isChecked);
        SET_SETTINGS("View/ShowSymbols/NonPrintable", isChecked);
    }
}

void TpMainWindow::onAction_V_Y_W(bool isChecked)
{
    if (isChecked)
    {
        m_menuBar->T_W_S_B->trigger();
        m_menuBar->T_W_E_B->trigger();
    }

    else
    {
        m_menuBar->T_W_S_N->trigger();
        m_menuBar->T_W_E_N->trigger();
    }
}

void TpMainWindow::onAction_V_Y_I(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setIndentationGuides(isChecked);
        SET_SETTINGS("View/ShowSymbols/IndentationGuides", isChecked);
    }
}

void TpMainWindow::onAction_V_Z_I(bool isChecked)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->zoomIn();
    }
}

void TpMainWindow::onAction_V_Z_O(bool isChecked)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->zoomOut();
    }
}

void TpMainWindow::onAction_V_Z_T(bool isChecked)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->zoomTo(0);
    }
}

void TpMainWindow::onAction_V_T_1(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(0);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_2(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(1);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_3(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(2);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_4(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(3);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_5(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(4);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_6(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(5);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_7(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(6);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_8(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(7);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_9(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(8);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_0(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(9);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_L(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(tab->count() - 1);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_N(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        if (tab->currentIndex() == tab->count() - 1)
            tab->setCurrentIndex(0);
        else
            tab->setCurrentIndex(tab->currentIndex() + 1);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_F(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(0);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_P(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(tab->currentIndex() - 1);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_M(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        if (tab->currentIndex() == 0)
            return;

        tab->tabBar()->moveTab(tab->currentIndex(), tab->currentIndex() - 1);
    }
}

void TpMainWindow::onAction_V_T_R(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        if (tab->currentIndex() == (tab->count() - 1))
            return;

        tab->tabBar()->moveTab(tab->currentIndex(), tab->currentIndex() + 1);
    }
}

void TpMainWindow::onAction_V_T_S(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->tabBar()->moveTab(tab->currentIndex(), 0);
    }
}

void TpMainWindow::onAction_V_T_T(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->tabBar()->moveTab(tab->currentIndex(), tab->count() - 1);
    }
}

void TpMainWindow::onAction_V_W_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapMode(TpEditor::WrapMode::WrapNone);
        SET_SETTINGS("View/WordWrap/None", true);
        SET_SETTINGS("View/WordWrap/Word", false);
        SET_SETTINGS("View/WordWrap/Character", false);
        SET_SETTINGS("View/WordWrap/Whitespace", false);
    }
}

void TpMainWindow::onAction_V_W_W(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapMode(TpEditor::WrapMode::WrapWord);
        SET_SETTINGS("View/WordWrap/None", false);
        SET_SETTINGS("View/WordWrap/Word", true);
        SET_SETTINGS("View/WordWrap/Character", false);
        SET_SETTINGS("View/WordWrap/Whitespace", false);
    }
}

void TpMainWindow::onAction_V_W_C(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapMode(TpEditor::WrapMode::WrapCharacter);
        SET_SETTINGS("View/WordWrap/None", false);
        SET_SETTINGS("View/WordWrap/Word", false);
        SET_SETTINGS("View/WordWrap/Character", true);
        SET_SETTINGS("View/WordWrap/Whitespace", false);
    }
}

void TpMainWindow::onAction_V_W_H(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapMode(TpEditor::WrapMode::WrapWhitespace);
        SET_SETTINGS("View/WordWrap/None", false);
        SET_SETTINGS("View/WordWrap/Word", false);
        SET_SETTINGS("View/WordWrap/Character", false);
        SET_SETTINGS("View/WordWrap/Whitespace", true);
    }
}

void TpMainWindow::onAction_V_L_M(bool)
{
    TpTabWidget *oldTab = m_widget->tabs()->tab();
    TpEditor *editor = oldTab->tab();

    TpTabSplitter *splitter = m_widget->tabs();

    TpTabWidget *tab;

    if (oldTab)
    {
        if (splitter->m_tabs.indexOf(oldTab) <= (splitter->m_tabs.count() - 1))
        {
            tab = new TpTabWidget(splitter);
            splitter->addTab(tab);
        }

        else
        {
            tab = splitter->m_tabs.at(splitter->m_tabs.indexOf(oldTab) + 1);
        }

        if (editor)
            tab->addEditor(editor);
    }

    for (int index = 0; index < splitter->m_tabs.count(); index++)
        if (!splitter->m_tabs.at(index)->hasTab())
            splitter->removeTab(splitter->m_tabs.at(index));
}

void TpMainWindow::onAction_V_I(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLineNumbers(isChecked);
        SET_SETTINGS("View/LineNumbers", isChecked);
    }
}

void TpMainWindow::onAction_V_C_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINESCROLLDOWN);
    }
}

void TpMainWindow::onAction_V_C_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINESCROLLUP);
    }
}

void TpMainWindow::onAction_V_C_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SCROLLTOSTART);
    }
}

void TpMainWindow::onAction_V_C_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SCROLLTOEND);
    }
}

void TpMainWindow::onAction_V_C_V(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SCROLLCARET);
    }
}

void TpMainWindow::onAction_V_O_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->foldLine(editor->currentLine());
    }
}

void TpMainWindow::onAction_V_O_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->foldAll(false);
    }
}

void TpMainWindow::onAction_V_O_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->foldAll(true);
    }
}

void TpMainWindow::onAction_V_O_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->clearFolds();
    }
}

void TpMainWindow::onAction_V_O_S_D(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setFolding(TpEditor::FoldStyle::NoFoldStyle);
        SET_SETTINGS("View/Folding/DisableFolding", true);
        SET_SETTINGS("View/Folding/Plain", false);
        SET_SETTINGS("View/Folding/Circled", false);
        SET_SETTINGS("View/Folding/Boxed", false);
        SET_SETTINGS("View/Folding/CircledTree", false);
        SET_SETTINGS("View/Folding/BoxedTree", false);
    }
}

void TpMainWindow::onAction_V_O_S_P(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setFolding(TpEditor::FoldStyle::PlainFoldStyle);
        SET_SETTINGS("View/Folding/DisableFolding", false);
        SET_SETTINGS("View/Folding/Plain", true);
        SET_SETTINGS("View/Folding/Circled", false);
        SET_SETTINGS("View/Folding/Boxed", false);
        SET_SETTINGS("View/Folding/CircledTree", false);
        SET_SETTINGS("View/Folding/BoxedTree", false);
    }
}

void TpMainWindow::onAction_V_O_S_C(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setFolding(TpEditor::FoldStyle::CircledFoldStyle);
        SET_SETTINGS("View/Folding/DisableFolding", false);
        SET_SETTINGS("View/Folding/Plain", false);
        SET_SETTINGS("View/Folding/Circled", true);
        SET_SETTINGS("View/Folding/Boxed", false);
        SET_SETTINGS("View/Folding/CircledTree", false);
        SET_SETTINGS("View/Folding/BoxedTree", false);
    }
}

void TpMainWindow::onAction_V_O_S_B(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setFolding(TpEditor::FoldStyle::BoxedFoldStyle);
        SET_SETTINGS("View/Folding/DisableFolding", false);
        SET_SETTINGS("View/Folding/Plain", false);
        SET_SETTINGS("View/Folding/Circled", false);
        SET_SETTINGS("View/Folding/Boxed", true);
        SET_SETTINGS("View/Folding/CircledTree", false);
        SET_SETTINGS("View/Folding/BoxedTree", false);
    }
}

void TpMainWindow::onAction_V_O_S_T(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setFolding(TpEditor::FoldStyle::CircledTreeFoldStyle);
        SET_SETTINGS("View/Folding/DisableFolding", false);
        SET_SETTINGS("View/Folding/Plain", false);
        SET_SETTINGS("View/Folding/Circled", false);
        SET_SETTINGS("View/Folding/Boxed", false);
        SET_SETTINGS("View/Folding/CircledTree", true);
        SET_SETTINGS("View/Folding/BoxedTree", false);
    }
}

void TpMainWindow::onAction_V_O_S_X(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setFolding(TpEditor::FoldStyle::BoxedTreeFoldStyle);
        SET_SETTINGS("View/Folding/DisableFolding", false);
        SET_SETTINGS("View/Folding/Plain", false);
        SET_SETTINGS("View/Folding/Circled", false);
        SET_SETTINGS("View/Folding/Boxed", false);
        SET_SETTINGS("View/Folding/CircledTree", false);
        SET_SETTINGS("View/Folding/BoxedTree", true);
    }
}

void TpMainWindow::onAction_I_F(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert("\f");
    }
}

void TpMainWindow::onAction_I_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert("\t");
    }
}

void TpMainWindow::onAction_I_V(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert("\v");
    }
}

void TpMainWindow::onAction_I_N_W(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert("\r\n");
    }
}

void TpMainWindow::onAction_I_N_M(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert("\r");
    }
}

void TpMainWindow::onAction_I_N_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert("\n");
    }
}

void TpMainWindow::onAction_I_D_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert(QDate::currentDate().toString(Qt::DateFormat::ISODate));
    }
}

void TpMainWindow::onAction_I_D_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert(QTime::currentTime().toString(Qt::DateFormat::ISODate));
    }
}

void TpMainWindow::onAction_I_D_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert(QDateTime::currentDateTime().toString(Qt::DateFormat::ISODate));
    }
}

void TpMainWindow::onAction_O_L_p(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->adjustAppearance();
        // editor->setLexer(editor->m_lexers[None]);
        editor->setLexer(nullptr);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_A_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[ActionScript]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_A_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[ASP]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_A_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[AviSynth]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_B_B(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Bash]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_B_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Batch]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_B_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[BlitzBasic]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_B_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[PureBasic]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_B_F(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[FreeBasic]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_C_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[C]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_C_pl(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[CPP]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_C_p(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[CPPQt]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_C_s(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[CS]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_C_M(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[CMake]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_C_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[CoffeeScript]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_C_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[CSS]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_D_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[D]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_D_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Diff]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_F_F(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Fortran]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_F_7(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Fortran77]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_G_G(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[GDScript]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_H_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[HTML]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_H_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[HTMLFull]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_I_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[IDL]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_I_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[IntelHex]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_J_J(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Java]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_J_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[JavaScript]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_J_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[JSON]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_L_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[LaTeX]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_L_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Lua]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_M_F(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Makefile]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_M_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Markdown]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_M_M(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[MASM]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_M_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Matlab]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_N_N(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[NASM]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_O_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Octave]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_P(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Pascal]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Perl]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[PHP]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[PO]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[PostScript]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_V(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[POV]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Properties]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_2(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Python2]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_3(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Python3]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_X(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Python3Extended]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_Q_Q(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[QML]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_Q_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[QSS]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_Q_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[QUI]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_R_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Ruby]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_S_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Spice]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_S_Q(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[SQL]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_S_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[SRecord]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_T_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[TCL]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_T_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[TektronixHex]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_T_X(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[TeX]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_V_V(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Verilog]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_V_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[VHDL]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_X_X(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[XML]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_Y_Y(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[YAML]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_N_U(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEolMode(TpEditor::EolMode::EolWindows);
        updateNewLineComboBox();
        SET_SETTINGS("Format/Newline/UseWindows", true);
        SET_SETTINGS("Format/Newline/UseClassicalMac", false);
        SET_SETTINGS("Format/Newline/UseUnix", false);
    }
}

void TpMainWindow::onAction_O_N_C(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEolMode(TpEditor::EolMode::EolMac);
        updateNewLineComboBox();
        SET_SETTINGS("Format/Newline/UseWindows", false);
        SET_SETTINGS("Format/Newline/UseClassicalMac", true);
        SET_SETTINGS("Format/Newline/UseUnix", false);
    }
}

void TpMainWindow::onAction_O_N_E(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEolMode(TpEditor::EolMode::EolUnix);
        updateNewLineComboBox();
        SET_SETTINGS("Format/Newline/UseWindows", false);
        SET_SETTINGS("Format/Newline/UseClassicalMac", false);
        SET_SETTINGS("Format/Newline/UseUnix", true);
    }
}

void TpMainWindow::onAction_O_N_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->convertEols(TpEditor::EolMode::EolWindows);
    }
}

void TpMainWindow::onAction_O_N_M(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->convertEols(TpEditor::EolMode::EolMac);
    }
}

void TpMainWindow::onAction_O_N_X(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->convertEols(TpEditor::EolMode::EolUnix);
    }
}

void TpMainWindow::onAction_O_I_T(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setIndentationsUseTabs(isChecked);
        SET_SETTINGS("Format/Indentation/UseTabsToIndent", isChecked);
    }
}

void TpMainWindow::onAction_O_I_B(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setBackspaceUnindents(isChecked);
        SET_SETTINGS("Format/Indentation/BackspaceUnindents", isChecked);
    }
}

void TpMainWindow::onAction_O_I_I(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setTabIndents(isChecked);
        SET_SETTINGS("Format/Indentation/TabToIndent", isChecked);
    }
}

void TpMainWindow::onAction_O_R_L(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setTabDrawMode(TpEditor::TabDrawMode::TabLongArrow);
        SET_SETTINGS("Format/RepresentingTabs/LongArrow", true);
        SET_SETTINGS("Format/RepresentingTabs/StrikeOut", false);
    }
}

void TpMainWindow::onAction_O_R_S(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setTabDrawMode(TpEditor::TabDrawMode::TabStrikeOut);
        SET_SETTINGS("Format/RepresentingTabs/LongArrow", false);
        SET_SETTINGS("Format/RepresentingTabs/StrikeOut", true);
    }
}

void TpMainWindow::onAction_O_S(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        if (isChecked)
        {
            editor->setMarginOptions(TpEditor::MoSublineSelect);
        }

        else
        {
            editor->setMarginOptions(TpEditor::MoNone);
        }

        SET_SETTINGS("Format/SelectFirstWrappedLineOnly", isChecked);
    }
}

void TpMainWindow::onAction_O_h(bool isChecked)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setReadOnly(isChecked);
    }
}

void TpMainWindow::onAction_O_A_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_UPPERCASE);
    }
}

void TpMainWindow::onAction_O_A_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LOWERCASE);
    }
}

void TpMainWindow::onAction_T_A_C(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionCaseSensitivity(isChecked);
        SET_SETTINGS("Tools/Autocompletion/CaseSensitive", isChecked);
    }
}

void TpMainWindow::onAction_T_A_F(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionFillupsEnabled(isChecked);
        SET_SETTINGS("Tools/Autocompletion/FillupsEnabled", isChecked);
    }
}

void TpMainWindow::onAction_T_A_R(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionReplaceWord(isChecked);
        SET_SETTINGS("Tools/Autocompletion/ReplaceWord", isChecked);
    }
}

void TpMainWindow::onAction_T_A_W_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionUseSingle(TpEditor::AutoCompletionUseSingle::AcusNever);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/DoNotDisplay", true);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/OnlyManually", false);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/AlwaysDisplay", false);
    }
}

void TpMainWindow::onAction_T_A_W_O(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionUseSingle(TpEditor::AutoCompletionUseSingle::AcusExplicit);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/DoNotDisplay", false);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/OnlyManually", true);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/AlwaysDisplay", false);
    }
}

void TpMainWindow::onAction_T_A_W_D(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionUseSingle(TpEditor::AutoCompletionUseSingle::AcusAlways);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/DoNotDisplay", false);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/OnlyManually", false);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/AlwaysDisplay", true);
    }
}

void TpMainWindow::onAction_T_A_S_D(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionSource(TpEditor::AutoCompletionSource::AcsNone);
        SET_SETTINGS("Tools/Autocompletion/Sources/DoNotDisplay", true);
        SET_SETTINGS("Tools/Autocompletion/Sources/All", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/Document", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/Lexer", false);
    }
}

void TpMainWindow::onAction_T_A_S_A(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionSource(TpEditor::AutoCompletionSource::AcsAll);
        SET_SETTINGS("Tools/Autocompletion/Sources/DoNotDisplay", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/All", true);
        SET_SETTINGS("Tools/Autocompletion/Sources/Document", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/Lexer", false);
    }
}

void TpMainWindow::onAction_T_A_S_O(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionSource(TpEditor::AutoCompletionSource::AcsDocument);
        SET_SETTINGS("Tools/Autocompletion/Sources/DoNotDisplay", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/All", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/Document", true);
        SET_SETTINGS("Tools/Autocompletion/Sources/Lexer", false);
    }
}

void TpMainWindow::onAction_T_A_S_L(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionSource(TpEditor::AutoCompletionSource::AcsAPIs);
        SET_SETTINGS("Tools/Autocompletion/Sources/DoNotDisplay", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/All", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/Document", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/Lexer", true);
    }
}

void TpMainWindow::onAction_T_A_T_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->autoCompleteFromAll();
    }
}

void TpMainWindow::onAction_T_A_T_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->autoCompleteFromDocument();
    }
}

void TpMainWindow::onAction_T_A_T_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->autoCompleteFromAPIs();
    }
}

void TpMainWindow::onAction_T_h_A(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoIndent(isChecked);
        SET_SETTINGS("Tools/Autoindentation/Autoindentation", isChecked);
    }
}

void TpMainWindow::onAction_T_h_S_A(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        int sty = /*TpEditor::AiMaintain*/ 0;
        // if (m_menuBar->T_h_S_O->isChecked())
        //     sty |= TpEditor::AiOpening;
        // if (m_menuBar->T_h_S_C->isChecked())
        //     sty |= TpEditor::AiClosing;

        editor->setAutoCompletionStyle(sty);

        bool isMaintain = /*(isChecked ?*/ false /*: (editor->autoCompletionStyle() | TpEditor::AiMaintain))*/;
        bool isOpening = /*(isChecked ?*/ false /*: (editor->autoCompletionStyle() | TpEditor::AiOpening))*/;
        bool isClosing = /*(isChecked ?*/ false /*: (editor->autoCompletionStyle() | TpEditor::AiClosing))*/;

        SET_SETTINGS("Tools/Autoindentation/Style/Auto", isChecked);
        SET_SETTINGS("Tools/Autoindentation/Style/Maintain", isMaintain);
        SET_SETTINGS("Tools/Autoindentation/Style/Opening", isOpening);
        SET_SETTINGS("Tools/Autoindentation/Style/Closing", isClosing);

        m_menuBar->T_h_S_M->setChecked(isMaintain);
        m_menuBar->T_h_S_O->setChecked(isOpening);
        m_menuBar->T_h_S_C->setChecked(isClosing);
    }
}

void TpMainWindow::onAction_T_h_S_M(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        int sty = TpEditor::AiMaintain;
        if (m_menuBar->T_h_S_O->isChecked())
            sty |= TpEditor::AiOpening;
        if (m_menuBar->T_h_S_C->isChecked())
            sty |= TpEditor::AiClosing;

        editor->setAutoCompletionStyle(sty);
        SET_SETTINGS("Tools/Autoindentation/Style/Maintain", isChecked);
        SET_SETTINGS("Tools/Autoindentation/Style/Auto", false);
        m_menuBar->T_h_S_A->setChecked(false);
    }
}

void TpMainWindow::onAction_T_h_S_O(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        int sty = TpEditor::AiOpening;
        if (m_menuBar->T_h_S_M->isChecked())
            sty |= TpEditor::AiMaintain;
        if (m_menuBar->T_h_S_C->isChecked())
            sty |= TpEditor::AiClosing;

        editor->setAutoCompletionStyle(sty);
        SET_SETTINGS("Tools/Autoindentation/Style/Opening", isChecked);
        SET_SETTINGS("Tools/Autoindentation/Style/Auto", false);
        m_menuBar->T_h_S_A->setChecked(false);
    }
}

void TpMainWindow::onAction_T_h_S_C(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        int sty = TpEditor::AiClosing;
        if (m_menuBar->T_h_S_M->isChecked())
            sty |= TpEditor::AiMaintain;
        if (m_menuBar->T_h_S_C->isChecked())
            sty |= TpEditor::AiOpening;

        editor->setAutoCompletionStyle(sty);
        SET_SETTINGS("Tools/Autoindentation/Style/Closing", isChecked);
        SET_SETTINGS("Tools/Autoindentation/Style/Auto", false);
        m_menuBar->T_h_S_A->setChecked(false);
    }
}

void TpMainWindow::onAction_T_B_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setBraceMatching(TpEditor::BraceMatch::NoBraceMatch);
        SET_SETTINGS("Tools/BraceMatching/NoBraceMatching", true);
        SET_SETTINGS("Tools/BraceMatching/SloppyBraceMatch", false);
        SET_SETTINGS("Tools/BraceMatching/StrictBraceMatch", false);
    }
}

void TpMainWindow::onAction_T_B_S(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setBraceMatching(TpEditor::BraceMatch::SloppyBraceMatch);
        SET_SETTINGS("Tools/BraceMatching/NoBraceMatching", false);
        SET_SETTINGS("Tools/BraceMatching/SloppyBraceMatch", true);
        SET_SETTINGS("Tools/BraceMatching/StrictBraceMatch", false);
    }
}

void TpMainWindow::onAction_T_B_B(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setBraceMatching(TpEditor::BraceMatch::StrictBraceMatch);
        SET_SETTINGS("Tools/BraceMatching/NoBraceMatching", false);
        SET_SETTINGS("Tools/BraceMatching/SloppyBraceMatch", false);
        SET_SETTINGS("Tools/BraceMatching/StrictBraceMatch", true);
    }
}

void TpMainWindow::onAction_T_C_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->callTip();
    }
}

void TpMainWindow::onAction_T_C_P_B(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setCallTipsPosition(TpEditor::CallTipsPosition::CallTipsBelowText);
        SET_SETTINGS("Tools/CallTips/Position/BelowText", true);
        SET_SETTINGS("Tools/CallTips/Position/AboveText", false);
    }
}

void TpMainWindow::onAction_T_C_P_A(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setCallTipsPosition(TpEditor::CallTipsPosition::CallTipsAboveText);
        SET_SETTINGS("Tools/CallTips/Position/BelowText", false);
        SET_SETTINGS("Tools/CallTips/Position/AboveText", true);
    }
}

void TpMainWindow::onAction_T_C_S_D(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setCallTipsStyle(TpEditor::CallTipsStyle::CallTipsNone);
        SET_SETTINGS("Tools/CallTips/Style/DisableCallTips", true);
        SET_SETTINGS("Tools/CallTips/Style/NoContextOrScope", false);
        SET_SETTINGS("Tools/CallTips/Style/NoAutocompletionContext", false);
        SET_SETTINGS("Tools/CallTips/Style/WithAllContext", false);
    }
}

void TpMainWindow::onAction_T_C_S_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setCallTipsStyle(TpEditor::CallTipsStyle::CallTipsNoContext);
        SET_SETTINGS("Tools/CallTips/Style/DisableCallTips", false);
        SET_SETTINGS("Tools/CallTips/Style/NoContextOrScope", true);
        SET_SETTINGS("Tools/CallTips/Style/NoAutocompletionContext", false);
        SET_SETTINGS("Tools/CallTips/Style/WithAllContext", false);
    }
}

void TpMainWindow::onAction_T_C_S_A(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setCallTipsStyle(TpEditor::CallTipsStyle::CallTipsNoAutoCompletionContext);
        SET_SETTINGS("Tools/CallTips/Style/DisableCallTips", false);
        SET_SETTINGS("Tools/CallTips/Style/NoContextOrScope", false);
        SET_SETTINGS("Tools/CallTips/Style/NoAutocompletionContext", true);
        SET_SETTINGS("Tools/CallTips/Style/WithAllContext", false);
    }
}

void TpMainWindow::onAction_T_C_S_W(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setCallTipsStyle(TpEditor::CallTipsStyle::CallTipsContext);
        SET_SETTINGS("Tools/CallTips/Style/DisableCallTips", false);
        SET_SETTINGS("Tools/CallTips/Style/NoContextOrScope", false);
        SET_SETTINGS("Tools/CallTips/Style/NoAutocompletionContext", false);
        SET_SETTINGS("Tools/CallTips/Style/WithAllContext", true);
    }
}

void TpMainWindow::onAction_T_E_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEdgeMode(TpEditor::EdgeMode::EdgeNone);
        SET_SETTINGS("Tools/EdgeMode/None", true);
        SET_SETTINGS("Tools/EdgeMode/Line", false);
        SET_SETTINGS("Tools/EdgeMode/Background", false);
    }
}

void TpMainWindow::onAction_T_E_L(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEdgeMode(TpEditor::EdgeMode::EdgeLine);
        SET_SETTINGS("Tools/EdgeMode/None", false);
        SET_SETTINGS("Tools/EdgeMode/Line", true);
        SET_SETTINGS("Tools/EdgeMode/Background", false);
    }
}

void TpMainWindow::onAction_T_E_B(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEdgeMode(TpEditor::EdgeMode::EdgeBackground);
        SET_SETTINGS("Tools/EdgeMode/None", false);
        SET_SETTINGS("Tools/EdgeMode/Line", false);
        SET_SETTINGS("Tools/EdgeMode/Background", true);
    }
}

void TpMainWindow::onAction_T_V_S(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setSelectionToEol(isChecked);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/SelectionTillBorder", isChecked);
    }
}

void TpMainWindow::onAction_T_V_M(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETMULTIPLESELECTION, isChecked);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/MultipleSelection", isChecked);
    }
}

void TpMainWindow::onAction_T_V_A(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETADDITIONALSELECTIONTYPING, isChecked);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/AdditionalSelectionTyping", isChecked);
    }
}

void TpMainWindow::onAction_T_V_P(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETMULTIPASTE, isChecked);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/MultiplePaste", isChecked);
    }
}

void TpMainWindow::onAction_T_V_V_D(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETVIRTUALSPACEOPTIONS, 0);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/Disabled", true);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/OnRectangularSelections", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/UsersAccessible", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/NoWrapLineStart", false);
    }
}

void TpMainWindow::onAction_T_V_V_R(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETVIRTUALSPACEOPTIONS, 1);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/Disabled", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/OnRectangularSelections", true);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/UsersAccessible", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/NoWrapLineStart", false);
    }
}

void TpMainWindow::onAction_T_V_V_U(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETVIRTUALSPACEOPTIONS, 2);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/Disabled", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/OnRectangularSelections", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/UsersAccessible", true);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/NoWrapLineStart", false);
    }
}

void TpMainWindow::onAction_T_V_V_W(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETVIRTUALSPACEOPTIONS, 4);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/Disabled", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/OnRectangularSelections", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/UsersAccessible", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/NoWrapLineStart", true);
    }
}

void TpMainWindow::onAction_T_V_R_C(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETRECTANGULARSELECTIONMODIFIER, 2);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/RectangularSelectionModifier/CTRL", true);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/RectangularSelectionModifier/ALT", false);
    }
}

void TpMainWindow::onAction_T_V_R_A(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETRECTANGULARSELECTIONMODIFIER, 4);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/RectangularSelectionModifier/CTRL", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/RectangularSelectionModifier/ALT", true);
    }
}

void TpMainWindow::onAction_T_V_C_O(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETCARETSTICKY, 0);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/Off", true);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/On", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/WithWhitespacesOnly", false);
    }
}

void TpMainWindow::onAction_T_V_C_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETCARETSTICKY, 1);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/Off", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/On", true);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/WithWhitespacesOnly", false);
    }
}

void TpMainWindow::onAction_T_V_C_W(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETCARETSTICKY, 2);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/Off", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/On", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/WithWhitespacesOnly", true);
    }
}

void TpMainWindow::onAction_T_V_L(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setCaretLineVisible(isChecked);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretLineVisible", isChecked);
    }
}

void TpMainWindow::onAction_T_S_R_N(bool)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkSimpleRegex->setChecked(false);
            container->m_checkPosixRegex->setChecked(false);
            container->m_checkCppRegex->setChecked(false);

            SET_SETTINGS("Tools/Search/RegularExpression/No", true);
            SET_SETTINGS("Tools/Search/RegularExpression/Simple", false);
            SET_SETTINGS("Tools/Search/RegularExpression/POSIX", false);
            SET_SETTINGS("Tools/Search/RegularExpression/C++", false);
        }
    }
}

void TpMainWindow::onAction_T_S_R_S(bool)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkSimpleRegex->setChecked(true);
            container->m_checkPosixRegex->setChecked(false);
            container->m_checkCppRegex->setChecked(false);

            SET_SETTINGS("Tools/Search/RegularExpression/No", false);
            SET_SETTINGS("Tools/Search/RegularExpression/Simple", true);
            SET_SETTINGS("Tools/Search/RegularExpression/POSIX", false);
            SET_SETTINGS("Tools/Search/RegularExpression/C++", false);
        }
    }
}

void TpMainWindow::onAction_T_S_R_P(bool)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkSimpleRegex->setChecked(false);
            container->m_checkPosixRegex->setChecked(true);
            container->m_checkCppRegex->setChecked(false);

            SET_SETTINGS("Tools/Search/RegularExpression/No", false);
            SET_SETTINGS("Tools/Search/RegularExpression/Simple", false);
            SET_SETTINGS("Tools/Search/RegularExpression/POSIX", true);
            SET_SETTINGS("Tools/Search/RegularExpression/C++", false);
        }
    }
}

void TpMainWindow::onAction_T_S_R_pl(bool)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkSimpleRegex->setChecked(false);
            container->m_checkPosixRegex->setChecked(false);
            container->m_checkCppRegex->setChecked(true);

            SET_SETTINGS("Tools/Search/RegularExpression/No", false);
            SET_SETTINGS("Tools/Search/RegularExpression/Simple", false);
            SET_SETTINGS("Tools/Search/RegularExpression/POSIX", false);
            SET_SETTINGS("Tools/Search/RegularExpression/C++", true);
        }
    }
}

void TpMainWindow::onAction_T_S_C(bool isChecked)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkCase->setChecked(isChecked);
            SET_SETTINGS("Tools/Search/Casesensitive", isChecked);
        }
    }
}

void TpMainWindow::onAction_T_S_O(bool isChecked)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkWord->setChecked(isChecked);
            SET_SETTINGS("Tools/Search/WholeWordOnly", isChecked);
        }
    }
}

void TpMainWindow::onAction_T_S_W(bool isChecked)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkWrap->setChecked(isChecked);
            SET_SETTINGS("Tools/Search/WordWrap", isChecked);
        }
    }
}

void TpMainWindow::onAction_T_S_S(bool isChecked)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkShow->setChecked(isChecked);
            SET_SETTINGS("Tools/Search/Show", isChecked);
        }
    }
}

void TpMainWindow::onAction_T_S_G(bool isChecked)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkPrevious->setChecked(isChecked);
            SET_SETTINGS("Tools/Search/GoPrevious", isChecked);
        }
    }
}

void TpMainWindow::onAction_T_W_I_P(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapIndentMode(TpEditor::WrapIndentMode::WrapIndentFixed);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Predefined", true);
        SET_SETTINGS("Tools/WrappingTools/Indentation/SameAsFirstSubline", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Indented", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Doubleindented", false);
    }
}

void TpMainWindow::onAction_T_W_I_S(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapIndentMode(TpEditor::WrapIndentMode::WrapIndentSame);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Predefined", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/SameAsFirstSubline", true);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Indented", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Doubleindented", false);
    }
}

void TpMainWindow::onAction_T_W_I_I(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapIndentMode(TpEditor::WrapIndentMode::WrapIndentIndented);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Predefined", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/SameAsFirstSubline", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Indented", true);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Doubleindented", false);
    }
}

void TpMainWindow::onAction_T_W_I_D(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapIndentMode(TpEditor::WrapIndentMode::WrapIndentDeeplyIndented);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Predefined", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/SameAsFirstSubline", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Indented", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Doubleindented", true);
    }
}

void TpMainWindow::onAction_T_W_S_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setStartFlag(TpEditor::WrapVisualFlag::WrapFlagNone);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/None", true);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByText", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByBorder", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/InMargin", false);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_W_S_T(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setStartFlag(TpEditor::WrapVisualFlag::WrapFlagByText);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/None", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByText", true);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByBorder", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/InMargin", false);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_W_S_B(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setStartFlag(TpEditor::WrapVisualFlag::WrapFlagByBorder);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/None", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByText", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByBorder", true);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/InMargin", false);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_W_S_M(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setStartFlag(TpEditor::WrapVisualFlag::WrapFlagInMargin);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/None", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByText", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByBorder", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/InMargin", true);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_W_E_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEndFlag(TpEditor::WrapVisualFlag::WrapFlagNone);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/None", true);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByText", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByBorder", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/InMargin", false);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_W_E_T(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEndFlag(TpEditor::WrapVisualFlag::WrapFlagByText);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/None", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByText", true);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByBorder", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/InMargin", false);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_W_E_B(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEndFlag(TpEditor::WrapVisualFlag::WrapFlagByBorder);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/None", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByText", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByBorder", true);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/InMargin", false);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_W_E_M(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEndFlag(TpEditor::WrapVisualFlag::WrapFlagInMargin);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/None", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByText", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByBorder", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/InMargin", true);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_M_B(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETBUFFEREDDRAW, isChecked);
        SET_SETTINGS("Tools/Miscellaneous/BufferedDraw", isChecked);
    }
}

void TpMainWindow::onAction_T_M_P_O(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETPHASESDRAW, 0);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseOne", true);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseTwo", false);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseMultiple", false);
    }
}

void TpMainWindow::onAction_T_M_P_T(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETPHASESDRAW, 1);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseOne", false);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseTwo", true);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseMultiple", false);
    }
}

void TpMainWindow::onAction_T_M_P_M(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETPHASESDRAW, 2);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseOne", false);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseTwo", false);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseMultiple", true);
    }
}

void TpMainWindow::onAction_T_M_Q_D(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETFONTQUALITY, 0);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Default", true);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Nonantialized", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Antialized", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/LCDOptimized", false);
    }
}

void TpMainWindow::onAction_T_M_Q_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETFONTQUALITY, 1);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Default", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Nonantialized", true);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Antialized", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/LCDOptimized", false);
    }
}

void TpMainWindow::onAction_T_M_Q_A(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETFONTQUALITY, 2);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Default", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Nonantialized", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Antialized", true);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/LCDOptimized", false);
    }
}

void TpMainWindow::onAction_T_M_Q_L(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETFONTQUALITY, 3);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Default", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Nonantialized", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Antialized", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/LCDOptimized", true);
    }
}

void TpMainWindow::onAction_W_F(bool isChecked)
{
    m_fileDock->setVisible(isChecked);
}

void TpMainWindow::onAction_W_L(bool isChecked)
{
    m_documentDock->setVisible(isChecked);
}

void TpMainWindow::onAction_W_B(bool isChecked)
{
    m_bookmarkDock->setVisible(isChecked);
}

void TpMainWindow::onAction_W_D(bool isChecked)
{
    m_findDock->setVisible(isChecked);
}

void TpMainWindow::onAction_W_I(bool isChecked)
{
    m_findInFilesDock->setVisible(isChecked);
}

void TpMainWindow::onEditorFileNameChanged(const QString &path, const QString &name)
{
    (void) path;
    (void) name;

    updateDocumentDock();
}

void TpMainWindow::onEditorCheckBoxChecked(bool)
{
    DEF_SETTINGS;
    bool noRe, simpleRe, posixRe, cppRe, cs, wo, wrap, show, prev;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            simpleRe = container->m_checkSimpleRegex->isChecked();
            posixRe = container->m_checkPosixRegex->isChecked();
            cppRe = container->m_checkCppRegex->isChecked();
            noRe = !(simpleRe) && !(posixRe) && !(cppRe);
            cs = container->m_checkCase->isChecked();
            wo = container->m_checkWord->isChecked();
            wrap = container->m_checkWrap->isChecked();
            show = container->m_checkShow->isChecked();
            prev = container->m_checkPrevious->isChecked();

            m_menuBar->T_S_R_N->setChecked(noRe);
            m_menuBar->T_S_R_S->setChecked(simpleRe);
            m_menuBar->T_S_R_P->setChecked(posixRe);
            m_menuBar->T_S_R_pl->setChecked(cppRe);
            m_menuBar->T_S_C->setChecked(cs);
            m_menuBar->T_S_O->setChecked(wo);
            m_menuBar->T_S_W->setChecked(wrap);
            m_menuBar->T_S_S->setChecked(show);
            m_menuBar->T_S_G->setChecked(prev);

            SET_SETTINGS("Tools/Search/RegularExpression/No", noRe);
            SET_SETTINGS("Tools/Search/RegularExpression/Simple", simpleRe);
            SET_SETTINGS("Tools/Search/RegularExpression/POSIX", posixRe);
            SET_SETTINGS("Tools/Search/RegularExpression/C++", cppRe);
            SET_SETTINGS("Tools/Search/Casesensitive", cs);
            SET_SETTINGS("Tools/Search/WholeWordOnly", wo);
            SET_SETTINGS("Tools/Search/WordWrap", wrap);
            SET_SETTINGS("Tools/Search/Show", show);
            SET_SETTINGS("Tools/Search/GoPrevious", prev);
        }
    }
}

void TpMainWindow::onEditorSelectionChanged()
{
    const QString &selectedText = m_widget->tabs()->tab()->tab()->selectedText();
    updateIncrementalSearch(selectedText);

    m_widget->tabs()->tab()->tab()->adjustBookmarks();

    int line = 0;
    int index = 0;

    m_widget->tabs()->tab()->tab()->lineIndexFromPosition(m_widget->tabs()->tab()->tab()->getPosition(), &line, &index);
    onEditorPositionChanged(m_widget->tabs()->tab()->tab()->getPosition(), line, index);
}

void TpMainWindow::onEditorPositionChanged(int position, int line, int index)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    m_menuBar->E_B_T->setChecked(editor->markersAtLine(line) & (editor->m_bookmarkMarker + 1));

    m_statusBar->m_labelStats
        ->setText(tr("Length: %1, Lines: %2").arg(m_widget->tabs()->tab()->tab()->getLength())
            .arg(m_widget->tabs()->tab()->tab()->lines()));
    m_statusBar->m_labelPosition->setText(tr("Position: %1").arg(position + 1));
    m_statusBar->m_labelLineAndColumn->setText(tr("Line: %1, Column: %2").arg(line + 1).arg(index + 1));
}

void TpMainWindow::onEditorPunctuation()
{
    updateEditorsMap();
}

void TpMainWindow::onTabChanged(TpTabWidget *tab, int index)
{
    if (tab)
    {
        m_menuBar->updateGeneralAccessibility(tab->hasTab(), (tab->hasTab() ? (tab->tab()->filePath() != "") : false));
        m_menuBar->updateCheckability(tab);
        m_statusBar->updateAccessibility(tab->hasTab());

        if (tab->tab())
        {
            int line = 0;
            int index = 0;

            tab->tab()->lineIndexFromPosition(tab->tab()->getPosition(), &line, &index);
            onEditorPositionChanged(tab->tab()->getPosition(), line, index);

            m_statusBar->m_spinBoxTabWidth->setValue(tab->tab()->indentationWidth());
            m_statusBar->m_comboBoxLang->setCurrentText(m_statusBar->iteratedLangMap[tab->tab()->currentLexer()]);
            m_statusBar->m_comboBoxNewLine->setCurrentText(m_statusBar->comboBoxNewLineItems[tab->tab()->eolMode()]);

            updateEditorsMap();

            m_bookmarkDock->setView(tab->tab()->m_bookmarkView);
            m_findDock->setContainer(tab->tab()->m_findContainer);
        }

        else
        {
            m_statusBar->m_labelStats->setText("");
            m_statusBar->m_labelPosition->setText("");
            m_statusBar->m_labelLineAndColumn->setText("");
            m_bookmarkDock->setView(nullptr);
            m_findDock->setContainer(nullptr);
        }
    }
}

void TpMainWindow::onTabCloseRequested(TpTabWidget *tab, int index)
{
    if (tab)
    {
        onAction_F_C(false);
    }
}

void TpMainWindow::onTabNameChanged()
{
    onTabChanged(m_widget->tabs()->tab(), m_widget->tabs()->tab()->currentIndex());
    updateDocumentDock();
}

void TpMainWindow::onWrapVisualFlagChanged()
{
    DEF_SETTINGS;

    if (GET_SETTINGS("Tools/WrappingTools/StartFlag/None", bool)
        || (GET_SETTINGS("Tools/WrappingTools/EndFlag/None", bool)))
    {
        m_menuBar->V_Y_W->setChecked(false);
        SET_SETTINGS("View/ShowSymbols/WrapVisualFlags", false);
    }

    else
    {
        m_menuBar->V_Y_W->setChecked(true);
        SET_SETTINGS("View/ShowSymbols/WrapVisualFlags", true);
    }
}

void TpMainWindow::onFileDockVisibilityChanged(bool isVisible)
{
    DEF_SETTINGS;
    m_menuBar->W_F->setChecked(isVisible);
    SET_SETTINGS("Windows/FileBrowser", isVisible);
}

void TpMainWindow::onFileDockDoubleClicked(const QString &path)
{
    TpOpenAssistant *assistant = new TpOpenAssistant(this);
    assistant->openFile(path);
}

void TpMainWindow::onDocumentDockVisibilityChanged(bool isVisible)
{
    DEF_SETTINGS;
    m_menuBar->W_L->setChecked(isVisible);
    SET_SETTINGS("Windows/DocumentList", isVisible);
}

void TpMainWindow::onDocumentDockDoubleClicked(TpTabWidget *tab, const QString &path)
{
    for (int tabs = 0; tabs < m_widget->tabs()->m_tabs.count(); tabs++)
    {
        for (int index = 0; index < m_widget->tabs()->m_tabs.at(tabs)->count(); index++)
        {
            if (m_widget->tabs()->m_tabs.at(tabs)->tabToolTip(index) == path)
            {
                m_widget->tabs()->m_tabs.at(tabs)->setCurrentIndex(index);
                m_widget->tabs()->m_tabs.at(tabs)->tab()->setFocus();
                break;
            }
        }
    }
}

void TpMainWindow::onBookmarkDockVisibilityChanged(bool isVisible)
{
    DEF_SETTINGS;
    m_menuBar->W_B->setChecked(isVisible);
    SET_SETTINGS("Windows/Bookmarks", isVisible);
}

void TpMainWindow::onFindDockVisibilityChanged(bool isVisible)
{
    DEF_SETTINGS;
    m_menuBar->W_D->setChecked(isVisible);
    SET_SETTINGS("Windows/FindDock", isVisible);

    if (tabifiedDockWidgets(m_findDock).contains(m_findInFilesDock) && isVisible)
        m_findInFilesDock->setVisible(isVisible);
}

void TpMainWindow::onFindInFilesDockVisibilityChanged(bool isVisible)
{
    DEF_SETTINGS;
    m_menuBar->W_I->setChecked(isVisible);
    SET_SETTINGS("Windows/FindInFilesDock", isVisible);

    if (tabifiedDockWidgets(m_findInFilesDock).contains(m_findDock) && isVisible)
        m_findDock->setVisible(isVisible);
}

void TpMainWindow::onFindInFilesDockDoubleClicked(const QString &path, int position)
{
    TpOpenAssistant *assistant = new TpOpenAssistant(this);
    assistant->openFile(path);

    if (m_widget->tabs()->tab()->tab())
    {
        if (m_widget->tabs()->tab()->tab()->m_filePath == path)
        {
            int line = 0;
            int index = 0;
            m_widget->tabs()->tab()->tab()->lineIndexFromPosition(position, &line, &index);
            m_widget->tabs()->tab()->tab()->setCursorPosition(line, index);
        }
    }
}

void TpMainWindow::onFindToolBarTextChanged(const QString &text)
{
    if (m_widget->tabs()->tab()->hasTab())
        updateIncrementalSearch(text);
}

void TpMainWindow::onStatusBarSpinBoxTabWidthChanged(int value)
{
    DEF_SETTINGS;

    if (TpEditor *editor = m_widget->tabs()->tab()->tab())
    {
        editor->setTabWidth(value);
        editor->setIndentationWidth(value);
    }

    SET_SETTINGS("Editor/Values/TabWidth", value);
}

void TpMainWindow::onStatusBarComboBoxLangIndexChanged(int index)
{
    Languages newLang = m_statusBar->languagesMap[m_statusBar->m_comboBoxLang->itemText(index)];
    if (TpEditor *editor = m_widget->tabs()->tab()->tab())
        editor->setCurrentLexer(newLang);
    onTabChanged(m_widget->tabs()->tab(), m_widget->tabs()->tab()->currentIndex());
}

void TpMainWindow::onStatusBarComboBoxNewLineIndexChanged(int index)
{
    TpEditor::EolMode eolMode = static_cast<TpEditor::EolMode>(index);
    if (TpEditor *editor = m_widget->tabs()->tab()->tab())
        editor->setEolMode(eolMode);
    onTabChanged(m_widget->tabs()->tab(), m_widget->tabs()->tab()->currentIndex());
}

void TpMainWindow::clearDocumentDock(QTreeWidgetItem *item)
{
    TpDocumentView *view = m_documentDock->documentView();

    for (int index = 0; index < item->childCount(); index++)
        clearDocumentDock(item->child(index));

    if (!(item == view->invisibleRootItem()))
    {
        view->removeItemWidget(item, 0);
        delete item;
    }
}

void TpMainWindow::updateDocumentDock()
{
    TpDocumentView *view = m_documentDock->documentView();

    // clearDocumentDock(view->invisibleRootItem());
    view->clear();

    for (int index = 0; index < m_widget->tabs()->m_tabs.count(); index++)
    {
        TpTabWidget *tab = m_widget->tabs()->m_tabs.at(index);

        if (tab)
        {
            TpDocumentItem *tabItem = view->addTab(tab);

            for (int editor = 0; editor < tab->count(); editor++)
            {
                TpEditor *ed = tab->tabAt(editor);

                if (ed)
                {
                    // view->addFile(tab, ed->m_filePath, ((ed->m_filePath.isEmpty())
                    //     ? tr("Untitled %1").arg(ed->m_untitled) : QFileInfo(QFile(ed->m_filePath)).fileName()));

                    QTreeWidgetItem *fileItem = new QTreeWidgetItem(tabItem, TpDocumentItem::ItemType::File);
                    fileItem->setToolTip(0, ed->m_filePath);

                    if (ed->m_filePath.isEmpty())
                        fileItem->setText(0, tab->tabText(tab->indexOf(ed)));
                    else
                        fileItem->setText(0, QFileInfo(QFile(ed->m_filePath)).fileName());

                    tabItem->addChild(fileItem);
                }
            }
        }
    }
}

void TpMainWindow::updateRecentFiles()
{
    DEF_SETTINGS;

    QStringList recentFilePaths = GET_SETTINGS("App/RecentFiles", QStringList);

    auto iteratorEnd = 0u;

    if (recentFilePaths.size() <= maximumRecentFiles)
        iteratorEnd = recentFilePaths.size();
    else
        iteratorEnd = maximumRecentFiles;

    for (auto i = 0u; i < iteratorEnd; i++)
    {
        QString strippedName = QFileInfo(recentFilePaths.at(i)).fileName();
        m_menuBar->m_recentFileActions.at(i)->setText(tr("&%1. %2").arg(i + 1).arg(strippedName));
        m_menuBar->m_recentFileActions.at(i)->setData(recentFilePaths.at(i));
        m_menuBar->m_recentFileActions.at(i)->setVisible(true);
    }

    for (auto i = iteratorEnd; i < maximumRecentFiles; i++)
        m_menuBar->m_recentFileActions.at(i)->setVisible(false);
}

void TpMainWindow::updateIncrementalSearch(const QString &text)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    const QString &content = editor->text();
    int indic = editor->incrementalIndicator();
    int clearLineTo = 0;
    int clearIndexTo = 0;
    editor->lineIndexFromPosition(editor->getLength(), &clearLineTo, &clearIndexTo);
    editor->clearIndicatorRange(0, 0, clearLineTo, clearIndexTo, indic);

    if (text.isEmpty())
        return;

    int indexOf = 0;

    while ((indexOf = content.indexOf(text, indexOf)) != -1)
    {
        int lineFrom;
        int indexFrom;
        int lineTo;
        int indexTo;

        lineFrom = indexFrom = lineTo = indexTo = 0;

        editor->lineIndexFromPosition(indexOf, &lineFrom, &indexFrom);
        editor->lineIndexFromPosition(indexOf + text.length(), &lineTo, &indexTo);

        editor->fillIndicatorRange(lineFrom, indexFrom, lineTo, indexTo, indic);

        indexOf++;
    }
}

void TpMainWindow::updateEditorsMap()
{
    DEF_SETTINGS;

    QMap<QString, QVariant> map = qvariant_cast<QMap<QString, QVariant>>(settings.value("App/Editors"));
    QMap<QString, QVariant> settingsMap = qvariant_cast<QMap<QString, QVariant>>(settings.value("App/EditorSettings"));

    if (TpEditor *editor = m_widget->tabs()->tab()->tab())
    {
        map[(editor->filePath() == "") ? tr("Untitled %1").arg(editor->m_untitled) : editor->filePath()] =
            editor->text();
        settingsMap[(editor->filePath() == "") ? tr("Untitled %1").arg(editor->m_untitled) : editor->filePath()] =
            editor->toMap();
    }


    SET_SETTINGS("App/Editors", map);
    SET_SETTINGS("App/EditorSettings", settingsMap);
}

void TpMainWindow::updateLexerComboBox()
{
    m_statusBar->m_comboBoxLang
        ->setCurrentText(m_statusBar->iteratedLangMap[m_widget->tabs()->tab()->tab()->currentLexer()]);
}

void TpMainWindow::updateNewLineComboBox()
{
    m_statusBar->m_comboBoxNewLine
        ->setCurrentText(m_statusBar->comboBoxNewLineItems[m_widget->tabs()->tab()->tab()->eolMode()]);
}

TP_END_NAMESPACE
