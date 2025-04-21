set(TROPIC_AT_WHERE "")

set(TROPIC_AT_WHERE
    "At 'dialog', of '{CMAKE_CURRENT_LIST_DIR}'"
    PARENT_SCOPE
)

set(TROPIC_SOURCES_DIALOGS
    ${TROPIC_SOURCES_DIALOGS}
    ${CMAKE_CURRENT_LIST_DIR}/TpDialogOpen
    ${CMAKE_CURRENT_LIST_DIR}/tpdialogopen.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpdialogopen.h
    ${CMAKE_CURRENT_LIST_DIR}/TpDialogOpenDir
    ${CMAKE_CURRENT_LIST_DIR}/tpdialogopendir.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpdialogopendir.h
    ${CMAKE_CURRENT_LIST_DIR}/TpDialogSave
    ${CMAKE_CURRENT_LIST_DIR}/tpdialogsave.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpdialogsave.h
    ${CMAKE_CURRENT_LIST_DIR}/TpDialogSaveCopyTo
    ${CMAKE_CURRENT_LIST_DIR}/tpdialogsavecopyto.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpdialogsavecopyto.h
    ${CMAKE_CURRENT_LIST_DIR}/TpMessageConfirmClose
    ${CMAKE_CURRENT_LIST_DIR}/tpmessageconfirmclose.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpmessageconfirmclose.h
    ${CMAKE_CURRENT_LIST_DIR}/TpMessageCritical
    ${CMAKE_CURRENT_LIST_DIR}/tpmessagecritical.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpmessagecritical.h
    PARENT_SCOPE
)
