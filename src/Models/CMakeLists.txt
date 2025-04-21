set(TROPIC_AT_WHERE "")

set(TROPIC_AT_WHERE
    "At 'models', of '{CMAKE_CURRENT_LIST_DIR}'"
    PARENT_SCOPE
)

set(TROPIC_SOURCES_MODELS
    ${TROPIC_SOURCES_MODELS}
    ${CMAKE_CURRENT_LIST_DIR}/TpBookmarkItem
    ${CMAKE_CURRENT_LIST_DIR}/tpbookmarkitem.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpbookmarkitem.h
    ${CMAKE_CURRENT_LIST_DIR}/TpDocumentItem
    ${CMAKE_CURRENT_LIST_DIR}/tpdocumentitem.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpdocumentitem.h
    ${CMAKE_CURRENT_LIST_DIR}/TpFileModel
    ${CMAKE_CURRENT_LIST_DIR}/tpfilemodel.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpfilemodel.h
    ${CMAKE_CURRENT_LIST_DIR}/TpHtmlDelegate
    ${CMAKE_CURRENT_LIST_DIR}/tphtmldelegate.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tphtmldelegate.h
    PARENT_SCOPE
)
