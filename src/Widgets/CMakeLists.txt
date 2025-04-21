set(TROPIC_AT_WHERE "")

set(TROPIC_AT_WHERE
    "At 'widgets', of '{CMAKE_CURRENT_LIST_DIR}'"
    PARENT_SCOPE
)

set(TROPIC_SOURCES_WIDGETS
    ${TROPIC_SOURCES_WIDGETS}
    ${CMAKE_CURRENT_LIST_DIR}/TpBookmarkDock
    ${CMAKE_CURRENT_LIST_DIR}/tpbookmarkdock.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpbookmarkdock.h
    ${CMAKE_CURRENT_LIST_DIR}/TpDocumentDock
    ${CMAKE_CURRENT_LIST_DIR}/tpdocumentdock.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpdocumentdock.h
    ${CMAKE_CURRENT_LIST_DIR}/TpFileDock
    ${CMAKE_CURRENT_LIST_DIR}/tpfiledock.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpfiledock.h
    ${CMAKE_CURRENT_LIST_DIR}/TpFindContainer
    ${CMAKE_CURRENT_LIST_DIR}/tpfindcontainer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpfindcontainer.h
    ${CMAKE_CURRENT_LIST_DIR}/TpFindDock
    ${CMAKE_CURRENT_LIST_DIR}/tpfinddock.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpfinddock.h
    ${CMAKE_CURRENT_LIST_DIR}/TpFindInFilesContainer
    ${CMAKE_CURRENT_LIST_DIR}/tpfindinfilescontainer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpfindinfilescontainer.h
    ${CMAKE_CURRENT_LIST_DIR}/TpFindInFilesDock
    ${CMAKE_CURRENT_LIST_DIR}/tpfindinfilesdock.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpfindinfilesdock.h
    ${CMAKE_CURRENT_LIST_DIR}/TpFindToolBar
    ${CMAKE_CURRENT_LIST_DIR}/tpfindtoolbar.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpfindtoolbar.h
    ${CMAKE_CURRENT_LIST_DIR}/TpGeneralComboBox
    ${CMAKE_CURRENT_LIST_DIR}/tpgeneralcombobox.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpgeneralcombobox.h
    ${CMAKE_CURRENT_LIST_DIR}/TpGeneralLineEdit
    ${CMAKE_CURRENT_LIST_DIR}/tpgenerallineedit.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpgenerallineedit.h
    ${CMAKE_CURRENT_LIST_DIR}/TpGeneralToolButton
    ${CMAKE_CURRENT_LIST_DIR}/tpgeneraltoolbutton.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpgeneraltoolbutton.h
    PARENT_SCOPE
)
