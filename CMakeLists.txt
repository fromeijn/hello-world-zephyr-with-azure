# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hello_world)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake-modules")
include(AddAzureSDKforC)

# Include Azure SDK for C headers to app
target_include_directories(app PRIVATE ${azuresdkforc_SOURCE_DIR}/sdk/inc)

# Let Zephyr build all 3rd party libs with app. Merge all into one
target_sources(app PRIVATE
    # Azure SDK for C - CORE lib
    ${azuresdkforc_SOURCE_DIR}/sdk/src/azure/core/az_context.c
    ${azuresdkforc_SOURCE_DIR}/sdk/src/azure/core/az_http_pipeline.c
    ${azuresdkforc_SOURCE_DIR}/sdk/src/azure/core/az_http_policy.c
    ${azuresdkforc_SOURCE_DIR}/sdk/src/azure/core/az_http_policy_logging.c
    ${azuresdkforc_SOURCE_DIR}/sdk/src/azure/core/az_http_policy_retry.c
    ${azuresdkforc_SOURCE_DIR}/sdk/src/azure/core/az_http_request.c
    ${azuresdkforc_SOURCE_DIR}/sdk/src/azure/core/az_http_response.c
    ${azuresdkforc_SOURCE_DIR}/sdk/src/azure/core/az_json_reader.c
    ${azuresdkforc_SOURCE_DIR}/sdk/src/azure/core/az_json_token.c
    ${azuresdkforc_SOURCE_DIR}/sdk/src/azure/core/az_json_writer.c
    ${azuresdkforc_SOURCE_DIR}/sdk/src/azure/core/az_log.c
    ${azuresdkforc_SOURCE_DIR}/sdk/src/azure/core/az_precondition.c
    ${azuresdkforc_SOURCE_DIR}/sdk/src/azure/core/az_span.c
    # Application sources
    src/main.c)
    