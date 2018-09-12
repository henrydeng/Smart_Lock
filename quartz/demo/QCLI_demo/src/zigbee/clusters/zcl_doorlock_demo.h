/*
 * Copyright (c) 2016-2017 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#ifndef __ZCL_DOORLOCK_DEMO_H__
#define __ZCL_DOORLOCK_DEMO_H__

/**
   @brief Initializes the ZCL door lock demo.

   @param ZigBee_QCLI_Handle is the parent QCLI handle for the Doorlock demo.

   @return true if the ZigBee light demo initialized successfully, false
           otherwise.
*/
qbool_t Initialize_ZCL_DoorLock_Demo(QCLI_Group_Handle_t ZigBee_QCLI_Handle);

/**
   @brief Creates an door lock server cluster.

   @param Endpoint is the endpoint the cluster will be part of.
   @param PrivData is a pointer to the private data for the cluster demo.  This
                   will be initaialized to NULL before the create function is
                   called so can be ignored if the demo has no private data.

   @return The handle for the newly created function or NULL if there was an
           error.
*/
qapi_ZB_Cluster_t ZCL_DoorLock_Demo_Create_Server(uint8_t Endpoint, void **PrivData);

/**
   @brief Creates an door lock client cluster.

   @param Endpoint is the endpoint the cluster will be part of.
   @param PrivData is a pointer to the private data for the cluster demo.  This
                   will be initaialized to NULL before the create function is
                   called so can be ignored if the demo has no private data.

   @return The handle for the newly created function or NULL if there was an
           error.
*/
qapi_ZB_Cluster_t ZCL_DoorLock_Demo_Create_Client(uint8_t Endpoint, void **PrivData);

#endif


