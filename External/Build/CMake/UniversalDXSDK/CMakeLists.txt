SET(DXSDK_DIR "${EXTERNAL_PROJECT_DIR}/UniversalDXSDK")

SET(D3DCOMPILER_NAME "d3dcompiler_47.dll")
SET(REL_PATH "External/Downloads/UniversalDXSDK.7z")
SET(PACKAGE_FILE_ID "5CEF994F25BC475F25ED746CD9A687C494207FCB")

DOWNLOAD_PACKAGE("UniversalDXSDK" ${REL_PATH} ${PACKAGE_FILE_ID} "${DXSDK_DIR}/README.md")

IF(KLAYGE_PLATFORM_WINDOWS)
	SET(D3DCOMPILER_ARCH_NAME ${KLAYGE_ARCH_NAME})
ELSE()
	SET(D3DCOMPILER_ARCH_NAME "x86")
ENDIF()
SET(SRC_PATH "${DXSDK_DIR}/Redist/${D3DCOMPILER_ARCH_NAME}/${D3DCOMPILER_NAME}")
SET(REDIST_PATH "${KLAYGE_BIN_DIR}/${D3DCOMPILER_NAME}")
ADD_CUSTOM_COMMAND(OUTPUT ${REDIST_PATH}
	COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SRC_PATH} ${REDIST_PATH})
ADD_CUSTOM_TARGET(UniversalDXSDKRedist ALL DEPENDS ${REDIST_PATH})

set_target_properties(UniversalDXSDKRedist PROPERTIES FOLDER "${EXTERNAL_VS_FOLDER_PREFIX}/UniversalDXSDK")
