SET(TROPIC_AT_WHERE "")

set(TROPIC_SOURCES_DIALOGS "")
set(TROPIC_SOURCES_LEXERS "")
set(TROPIC_SOURCES_MODELS "")
set(TROPIC_SOURCES_UTILITIES "")
set(TROPIC_SOURCES_VIEWS "")
set(TROPIC_SOURCES_WIDGETS "")

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Dialogs)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Lexers)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Models)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Utilities)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Views)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Widgets)

set(TROPIC_AT_WHERE
    "At 'src', of '{CMAKE_CURRENT_LIST_DIR}'"
    PARENT_SCOPE
)

set(TROPIC_SOURCES
    ${TROPIC_SOURCES}
    ${TROPIC_SOURCES_DIALOGS}
    ${TROPIC_SOURCES_LEXERS}
    ${TROPIC_SOURCES_MODELS}
    ${TROPIC_SOURCES_UTILITIES}
    ${TROPIC_SOURCES_VIEWS}
    ${TROPIC_SOURCES_WIDGETS}
    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/TpAppConnectionInfo
    ${CMAKE_CURRENT_LIST_DIR}/tpappconnectioninfo.h
    ${CMAKE_CURRENT_LIST_DIR}/TpAppInstanceInfo
    ${CMAKE_CURRENT_LIST_DIR}/tpappinstanceinfo.h
    ${CMAKE_CURRENT_LIST_DIR}/TpApplication
    ${CMAKE_CURRENT_LIST_DIR}/tpapplication.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpapplication.h
    ${CMAKE_CURRENT_LIST_DIR}/TpColorScheme
    ${CMAKE_CURRENT_LIST_DIR}/tpcolorscheme.h
    ${CMAKE_CURRENT_LIST_DIR}/TpEditor
    ${CMAKE_CURRENT_LIST_DIR}/tpeditor.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpeditor.h
    ${CMAKE_CURRENT_LIST_DIR}/TpFontScheme
    ${CMAKE_CURRENT_LIST_DIR}/tpfontscheme.h
    ${CMAKE_CURRENT_LIST_DIR}/TpGeneralAction
    ${CMAKE_CURRENT_LIST_DIR}/tpgeneralaction.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpgeneralaction.h
    ${CMAKE_CURRENT_LIST_DIR}/TpGeneralActionGroup
    ${CMAKE_CURRENT_LIST_DIR}/tpgeneralactiongroup.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpgeneralactiongroup.h
    ${CMAKE_CURRENT_LIST_DIR}/TpGeneralMenu
    ${CMAKE_CURRENT_LIST_DIR}/tpgeneralmenu.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpgeneralmenu.h
    ${CMAKE_CURRENT_LIST_DIR}/TpGeneralToolBar
    ${CMAKE_CURRENT_LIST_DIR}/tpgeneraltoolbar.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpgeneraltoolbar.h
    ${CMAKE_CURRENT_LIST_DIR}/TpGlobals
    ${CMAKE_CURRENT_LIST_DIR}/tpglobals.h
    ${CMAKE_CURRENT_LIST_DIR}/TpMainWindow
    ${CMAKE_CURRENT_LIST_DIR}/tpmainwindow.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpmainwindow.h
    ${CMAKE_CURRENT_LIST_DIR}/TpMenuBar
    ${CMAKE_CURRENT_LIST_DIR}/tpmenubar.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpmenubar.h
    ${CMAKE_CURRENT_LIST_DIR}/TpSingleApplication
    ${CMAKE_CURRENT_LIST_DIR}/tpsingleapplication.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpsingleapplication.h
    ${CMAKE_CURRENT_LIST_DIR}/TpStackedWidget
    ${CMAKE_CURRENT_LIST_DIR}/tpstackedwidget.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpstackedwidget.h
    ${CMAKE_CURRENT_LIST_DIR}/TpStatusBar
    ${CMAKE_CURRENT_LIST_DIR}/tpstatusbar.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpstatusbar.h
    ${CMAKE_CURRENT_LIST_DIR}/TpTabBar
    ${CMAKE_CURRENT_LIST_DIR}/tptabbar.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tptabbar.h
    ${CMAKE_CURRENT_LIST_DIR}/TpTabSplitter
    ${CMAKE_CURRENT_LIST_DIR}/tptabsplitter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tptabsplitter.h
    ${CMAKE_CURRENT_LIST_DIR}/TpTabWidget
    ${CMAKE_CURRENT_LIST_DIR}/tptabwidget.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tptabwidget.h
    ${CMAKE_CURRENT_LIST_DIR}/TpWelcomeLabel
    ${CMAKE_CURRENT_LIST_DIR}/tpwelcomelabel.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpwelcomelabel.h
    PARENT_SCOPE
)
