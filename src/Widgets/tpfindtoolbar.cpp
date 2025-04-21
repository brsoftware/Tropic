#include <Widgets/TpFindToolBar>
#include <TpMainWindow>

TP_NAMESPACE

TpFindToolBar::TpFindToolBar(TpMainWindow *parent)
    : TpGeneralToolBar(parent, tr("Light Search")),
    m_parent(parent)
{
    setAllowedAreas(Qt::ToolBarArea::BottomToolBarArea);
    setObjectName("findToolBar");

    m_findEdit = new TpGeneralLineEdit(this);
    addWidget(m_findEdit);

    addAction(parent->m_menuBar->E_E_N);
    addAction(parent->m_menuBar->E_E_P);

    m_exit = new TpGeneralAction(this, tr("&Quit"), QKeySequence(Qt::Key::Key_Escape));

    connect(m_findEdit,
            &TpGeneralLineEdit::returnPressed,
            this,
            &TpFindToolBar::on_ReturnPressed);
    connect(m_exit,
            &TpGeneralAction::triggered,
            this,
            &TpFindToolBar::on_Exit);
    connect(m_findEdit,
            &TpGeneralLineEdit::textChanged,
            this,
            &TpFindToolBar::textChanged);
}

void TpFindToolBar::on_Exit(bool)
{
    setVisible(false);
}

void TpFindToolBar::on_ReturnPressed()
{
    m_parent->m_menuBar->E_E_N->trigger();
}

TP_END_NAMESPACE
