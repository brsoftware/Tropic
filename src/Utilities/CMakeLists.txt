set(TROPIC_AT_WHERE "")

set(TROPIC_AT_WHERE
    "At 'utilities', of '{CMAKE_CURRENT_LIST_DIR}'"
    PARENT_SCOPE
)

set(TROPIC_SOURCES_UTILITIES
    ${TROPIC_SOURCES_UTILITIES}
    ${CMAKE_CURRENT_LIST_DIR}/TpFileSystemAssistants
    ${CMAKE_CURRENT_LIST_DIR}/tpfilesystemassistants.h
    ${CMAKE_CURRENT_LIST_DIR}/TpOpenAssistant
    ${CMAKE_CURRENT_LIST_DIR}/tpopenassistant.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpopenassistant.h
    ${CMAKE_CURRENT_LIST_DIR}/TpSaveAssistant
    ${CMAKE_CURRENT_LIST_DIR}/tpsaveassistant.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpsaveassistant.h
    ${CMAKE_CURRENT_LIST_DIR}/TpSaveCopyAssistant
    ${CMAKE_CURRENT_LIST_DIR}/tpsavecopyassistant.cpp
    ${CMAKE_CURRENT_LIST_DIR}/tpsavecopyassistant.h
    PARENT_SCOPE
)
