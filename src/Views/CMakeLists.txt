set(TROPIC_AT_WHERE "")

set(TROPIC_AT_WHERE
    "At 'views', of '{CMAKE_CURRENT_LIST_DIR}'"
    PARENT_SCOPE
)

set(TROPIC_SOURCES_VIEWS
    ${TROPIC_SOURCES_VIEWS}
    ${CMAKE_CURRENT_LIST_DIR}/TpBookmarkView
    ${CMAKE_CURRENT_LIST_DIR}/tpbookmarkview.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpbookmarkview.h
    ${CMAKE_CURRENT_LIST_DIR}/TpDocumentView
    ${CMAKE_CURRENT_LIST_DIR}/tpdocumentview.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpdocumentview.h
    ${CMAKE_CURRENT_LIST_DIR}/TpFileView
    ${CMAKE_CURRENT_LIST_DIR}/tpfileview.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpfileview.h
    PARENT_SCOPE
)
