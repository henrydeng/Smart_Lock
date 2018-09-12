
/**
 * @file qapi_ble_ndcs.h
 *
 * @brief
 * QCA QAPI for Bluetopia Bluetooth Next DST Change Service (NDCS)
 * (GATT based) API Type Definitions, Constants, and Prototypes.
 *
 * @details
 * The Next DST Change Service programming interface defines the protocols and
 * procedures to be used to implement the Next DST Change Service
 * capabilities.
 */

#ifndef __QAPI_BLE_NDCS_H__
#define __QAPI_BLE_NDCS_H__

#include "./qapi_ble_btapityp.h"  /* Bluetooth API Type Definitions.          */
#include "./qapi_ble_bttypes.h"   /* Bluetooth Type Definitions/Constants.    */
#include "./qapi_ble_gatt.h"      /* QAPI GATT prototypes.                    */
#include "./qapi_ble_ndcstypes.h" /* QAPI NDCS prototypes.                    */

/**
 * @addtogroup qapi_ble_services
 * @{
 */

   /* Error Return Codes.                                               */

   /* Error Codes that are smaller than these (less than -1000) are     */
   /* related to the Bluetooth Protocol Stack itself (see               */
   /* qapi_ble_errors.h).                                               */
#define QAPI_BLE_NDCS_ERROR_INVALID_PARAMETER            (-1000)
/**< Invalid parameter. */
#define QAPI_BLE_NDCS_ERROR_INVALID_BLUETOOTH_STACK_ID   (-1001)
/**< Invalid Bluetooth Stack ID. */
#define QAPI_BLE_NDCS_ERROR_INSUFFICIENT_RESOURCES       (-1002)
/**< Insufficient resources. */
#define QAPI_BLE_NDCS_ERROR_SERVICE_ALREADY_REGISTERED   (-1003)
/**< Service is already registered. */
#define QAPI_BLE_NDCS_ERROR_INVALID_INSTANCE_ID          (-1004)
/**< Invalid service instance ID. */
#define QAPI_BLE_NDCS_ERROR_MALFORMATTED_DATA            (-1005)
/**< Malformatted data. */
#define QAPI_BLE_NDCS_ERROR_UNKNOWN_ERROR                (-1006)
/**< Unknown error. */

/**
 * Structure that represents the Date/Time data for NDCS.
 */
typedef struct qapi_BLE_NDCS_Date_Time_Data_s
{
   /**
    * Year.
    */
   uint16_t Year;

   /**
    * Month.
    */
   uint8_t  Month;

   /**
    * Day.
    */
   uint8_t  Day;

   /**
    * Hour.
    */
   uint8_t  Hours;

   /**
    * Minutes.
    */
   uint8_t  Minutes;

   /**
    * Seconds.
    */
   uint8_t  Seconds;
} qapi_BLE_NDCS_Date_Time_Data_t;

#define QAPI_BLE_NDCS_DATE_TIME_DATA_SIZE                (sizeof(qapi_BLE_NDCS_Date_Time_Data_t))
/**<
 * Size of the #qapi_BLE_NDCS_Date_Time_Data_t structure.
 */

/**
 * Structure that represents the NDCS Date/Time data with Daylight
 * Savings Time (DST) offset.
 */
typedef struct qapi_BLE_NDCS_Time_With_Dst_Data_s
{
   /**
    * Data/time data.
    */
   qapi_BLE_NDCS_Date_Time_Data_t Date_Time;

   /**
    * DST offset.
    */
   uint8_t                        Dst_Offset;
} qapi_BLE_NDCS_Time_With_Dst_Data_t;

#define QAPI_BLE_NDCS_TIME_WITH_DST_DATA_SIZE            (sizeof(qapi_BLE_NDCS_Time_With_Dst_Data_t))
/**<
 * Size of the #qapi_BLE_NDCS_Time_With_Dst_Data_t structure.
 */

/**
 * Enumeration that represents all the events generated by the NDCS
 * Service.These are used to determine the type of each event generated,
 * and to ensure the proper union element is accessed for the
 * #qapi_BLE_NDCS_Event_Data_t structure.
 */
typedef enum
{
   QAPI_BLE_ET_NDCS_SERVER_READ_CURRENT_TIME_REQUEST_E
   /**< Read Current Time request event. */
} qapi_BLE_NDCS_Event_Type_t;

/**
 * Structure that represents the format for the data that is dispatched
 * to a NDCS server when a NDCS client has sent a request to read the
 * Time with DST Characteristic.
 *
 * Some of this structures fields will be required when responding to a
 * request using the qapi_BLE_NDCS_Time_With_DST_Read_Request_Response()
 * or qapi_BLE_NDCS_Time_With_DST_Read_Request_Error_Response()
 * functions.
 */
typedef struct qapi_BLE_NDCS_Read_Time_With_DST_Request_Data_s
{
   /**
    * NDCS instance that dispatched the event.
    */
   uint32_t                        InstanceID;

   /**
    * GATT connection ID for the connection with the NDCS client
    * that made the request.
    */
   uint32_t                        ConnectionID;

   /**
    * GATT transaction ID for the request.
    */
   uint32_t                        TransactionID;

   /**
    * GATT connection type, which identifies the transport used for
    * the connection with the NDCS client.
    */
   qapi_BLE_GATT_Connection_Type_t ConnectionType;

   /**
    * Bluetooth address of the NDCS client that made the request.
    */
   qapi_BLE_BD_ADDR_t              RemoteDevice;
} qapi_BLE_NDCS_Read_Time_With_DST_Request_Data_t;

#define QAPI_BLE_NDCS_READ_TIME_WITH_DST_REQUEST_DATA_SIZE  (sizeof(qapi_BLE_NDCS_Read_Time_With_DST_Request_Data_t))
/**<
 * Size of the #qapi_BLE_NDCS_Read_Time_With_DST_Request_Data_t structure.
 */

/**
 * Structure that represents the container structure for holding all the
 * event data for a NDCS instance.
 */
typedef struct qapi_BLE_NDCS_Event_Data_s
{
   /**
    * Event type used to determine the appropriate union member of
    * the Event_Data field to access.
    */
   qapi_BLE_NDCS_Event_Type_t Event_Data_Type;

   /**
    * Total size of the data contained in the event.
    */
   uint16_t                   Event_Data_Size;
   union
   {
      /**
       * NDCS Read Time with DST Request event data.
       */
      qapi_BLE_NDCS_Read_Time_With_DST_Request_Data_t *NDCS_Read_Time_With_DST_Request_Data;
   }
   /**
    * Event data. @newpagetable
    */
   Event_Data;
} qapi_BLE_NDCS_Event_Data_t;

#define QAPI_BLE_NDCS_EVENT_DATA_SIZE                    (sizeof(qapi_BLE_NDCS_Event_Data_t))
/**<
 * Size of the #qapi_BLE_NDCS_Event_Data_t structure.
 */

/**
 * Structure that represents the attribute handles that will need to be
 * cached by a NDCS client in order to only do service discovery once.
 */
typedef struct qapi_BLE_NDCS_Client_Information_s
{
   /**
    * Time with DST.
    */
   uint16_t Time_With_Dst;
} qapi_BLE_NDCS_Client_Information_t;

#define QAPI_BLE_NDCS_CLIENT_INFORMATION_DATA_SIZE                (sizeof(qapi_BLE_NDCS_Client_Information_t))
/**<
 * Size of the #qapi_BLE_NDCS_Client_Information_t structure.
 */

/**
 * Structure that represents the attribute handles that will need to be
 * cached by a NDCS server in order to only do service discovery once.
 */
typedef struct qapi_BLE_NDCS_Server_Information_s
{
   /**
    * Time with DST.
    */
   uint16_t Time_With_Dst;
} qapi_BLE_NDCS_Server_Information_t;

#define QAPI_BLE_NDCS_SERVER_INFORMATION_DATA_SIZE                (sizeof(qapi_BLE_NDCS_Server_Information_t))
/**<
 * Size of the #qapi_BLE_NDCS_Server_Information_t structure.
 */

/**
 * @brief
 * This declared type represents the Prototype Function for an
 * NDCS Event Callback. This function will be called whenever a define
 * NDCS Event occurs within the Bluetooth Protocol Stack that is
 * specified with the specified Bluetooth Stack ID.
 *
 * @details
 * The event information is passed to the user in an #qapi_BLE_NDCS_Event_Data_t
 * structure. This structure contains all the information about the
 * event that occurred.
 *
 * The caller should use the contents of the NDCS Event Data
 * only in the context of this callback. If the caller requires
 * the data for a longer period of time, the callback function
 * must copy the data into another data buffer.
 *
 * This function is guaranteed not to be invoked more than once
 * simultaneously for the specified installed callback (i.e., this
 * function does not have be reentrant). It should be noted, however,
 * that if the same callback is installed more than once, the
 * callbacks will be called serially. Because of this, the processing
 * in this function should be as efficient as possible.
 *
 * It should also be noted that this function is called in the Thread
 * Context of a Thread that the user does not own. Therefore, processing
 * in this function should be as efficient as possible (this argument holds
 * anyway because another NDCS Event will not be processed while this
 * function call is outstanding).
 *
 * @note1hang
 * This function must not block and wait for events that can only be
 * satisfied by receiving other Bluetooth Stack Events. A Deadlock
 * will occur because other callbacks might not be issued while
 * this function is currently outstanding.
 *
 * @param[in]  BluetoothStackID      Unique identifier assigned to this
 *                                   Bluetooth Protocol Stack on which the
 *                                   event occurred.
 *
 * @param[in]  NDCS_Event_Data       Pointer to a structure that contains
 *                                   information about the event that has
 *                                   occurred.
 *
 * @param[in]  CallbackParameter     User-defined value that will be
 *                                   received with the NDCS Event data.
 *
 * @return None.
 */
typedef void (QAPI_BLE_BTPSAPI *qapi_BLE_NDCS_Event_Callback_t)(uint32_t BluetoothStackID, qapi_BLE_NDCS_Event_Data_t *NDCS_Event_Data, uint32_t CallbackParameter);

   /* NDCS server API.                                                  */

/**
 * @brief
 * Initializes an NDCS server on a specified Bluetooth Stack.
 *
 * @details
 * Only one NDCS server may be open at a time, per the Bluetooth Stack ID.
 *
 * @param[in]  BluetoothStackID     Unique identifier assigned to this
 *                                  Bluetooth Protocol Stack via a
 *                                  call to qapi_BLE_BSC_Initialize().
 *
 * @param[in]  EventCallback        NDCS Event Callback that will
 *                                  receive NDCS server events.
 *
 * @param[in]  CallbackParameter    User-defined value that will be
 *                                  received with the specified
 *                                  EventCallback parameter.
 *
 * @param[out]  ServiceID           Unique GATT service ID of the
 *                                  registered NDCS service returned from
 *                                  qapi_BLE_GATT_Register_Service() API.
 *
 * @return      Positive, nonzero if successful. The return value will
 *              be the Service Instance ID of NDCS server that was successfully
 *              opened on the specified Bluetooth Stack ID. This is the value
 *              that should be used in all subsequent function calls that
 *              require Instance ID.
 *
 * @return      An error code if negative; one of the following values:
 *              @par
 *                 QAPI_BLE_NDCS_ERROR_INSUFFICIENT_RESOURCES \n
 *                 QAPI_BLE_NDCS_ERROR_INVALID_PARAMETER \n
 *                 QAPI_BLE_BTGATT_ERROR_INVALID_SERVICE_TABLE_FORMAT \n
 *                 QAPI_BLE_BTGATT_ERROR_INSUFFICIENT_RESOURCES \n
 *                 QAPI_BLE_BTGATT_ERROR_INVALID_PARAMETER \n
 *                 QAPI_BLE_BTGATT_ERROR_INVALID_BLUETOOTH_STACK_ID \n
 *                 QAPI_BLE_BTGATT_ERROR_NOT_INITIALIZED
 */
QAPI_BLE_DECLARATION int QAPI_BLE_BTPSAPI qapi_BLE_NDCS_Initialize_Service(uint32_t BluetoothStackID, qapi_BLE_NDCS_Event_Callback_t EventCallback, uint32_t CallbackParameter, uint32_t *ServiceID);

/**
 * @brief
 * Initializes an NDCS server on a specified Bluetooth Stack.
 *
 * @details
 * Unlike qapi_BLE_CTS_Initialize_Service(), this function allows the
 * application to select a handle range in GATT to store the service.
 *
 * Only one NDCS server may be open at a time, per the Bluetooth Stack ID.
 *
 * @param[in]  BluetoothStackID     Unique identifier assigned to this
 *                                  Bluetooth Protocol Stack via a
 *                                  call to qapi_BLE_BSC_Initialize().
 *
 * @param[in]  EventCallback        NDCS Event Callback that will
 *                                  receive NDCS server events.
 *
 * @param[in]  CallbackParameter    User-defined value that will be
 *                                  received with the specified
 *                                  EventCallback parameter.
 *
 * @param[out]  ServiceID           Unique GATT service ID of the
 *                                  registered NDCS service returned from
 *                                  qapi_BLE_GATT_Register_Service() API.
 *
 * @param[in,out]  ServiceHandleRange    Pointer that, on input, holds
 *                                       the handle range to store the
 *                                       service in GATT, and on output,
 *                                       contains the handle range for
 *                                       where the service is stored in
 *                                       GATT.
 *
 * @return      Positive, nonzero if successful. The return value will
 *              be the Service Instance ID of NDCS server that was successfully
 *              opened on the specified Bluetooth Stack ID. This is the value
 *              that should be used in all subsequent function calls that
 *              require Instance ID.
 *
 * @return      An error code if negative; one of the following values:
 *              @par
 *                 QAPI_BLE_NDCS_ERROR_INSUFFICIENT_RESOURCES \n
 *                 QAPI_BLE_NDCS_ERROR_INVALID_PARAMETER \n
 *                 QAPI_BLE_BTGATT_ERROR_INVALID_SERVICE_TABLE_FORMAT \n
 *                 QAPI_BLE_BTGATT_ERROR_INSUFFICIENT_RESOURCES \n
 *                 QAPI_BLE_BTGATT_ERROR_INVALID_PARAMETER \n
 *                 QAPI_BLE_BTGATT_ERROR_INVALID_BLUETOOTH_STACK_ID \n
 *                 QAPI_BLE_BTGATT_ERROR_NOT_INITIALIZED
 */
QAPI_BLE_DECLARATION int QAPI_BLE_BTPSAPI qapi_BLE_NDCS_Initialize_Service_Handle_Range(uint32_t BluetoothStackID, qapi_BLE_NDCS_Event_Callback_t EventCallback, uint32_t CallbackParameter, uint32_t *ServiceID, qapi_BLE_GATT_Attribute_Handle_Group_t *ServiceHandleRange);

/**
 * @brief
 * Cleans up and frees all resources
 * associated with the Next DST Change Service (NDCS) Instance.
 *
 * @details
 * After this function is called, no other Device Information Service
 * function can be called until after a successful call to either of the
 * qapi_BLE_NDCS_Initialize_XXX() functions are performed.
 *
 * @param[in]  BluetoothStackID    Unique identifier assigned to this
 *                                 Bluetooth Protocol Stack via a
 *                                 call to qapi_BLE_BSC_Initialize().
 *
 * @param[in]  InstanceID          Service instance ID to close.
 *                                 This is the value that was returned
 *                                 from either of the qapi_BLE_NDCS_Initialize_XXX()
 *                                 functions.
 *
 * @return      Zero if successful.
 *
 * @return      An error code if negative; one of the following values:
 *              @par
 *                 QAPI_BLE_NDCS_ERROR_INVALID_PARAMETER \n
 *                 QAPI_BLE_NDCS_ERROR_INVALID_INSTANCE_ID
 */
QAPI_BLE_DECLARATION int QAPI_BLE_BTPSAPI qapi_BLE_NDCS_Cleanup_Service(uint32_t BluetoothStackID, uint32_t InstanceID);

/**
 * @brief
 * Queries the number of attributes
 * that are contained in the NDCS service that is registered with a
 * call to either the qapi_BLE_NDCS_Initialize_Service() or the
 * qapi_BLE_NDCS_Initialize_Service_Handle_Range() function.
 *
 * @return      Positive nonzero if successful (represents the number of attributes
 *              for NDCS).
 *
 * @return      Zero for failure.
 */
QAPI_BLE_DECLARATION unsigned int QAPI_BLE_BTPSAPI qapi_BLE_NDCS_Query_Number_Attributes(void);

/**
 * @brief
 * Responds to a
 * successful read request from an NDCS client for the NDCS Next DST
 * Change Time Characteristic.
 *
 * @details
 * The ErrorCode parameter must be a valid value of the form
 * QPAI_BLE_ATT_PROTOCOL_ERROR_CODE_XXX from qapi_ble_atttypes.h.
 *
 * @param[in]  BluetoothStackID    Unique identifier assigned to this
 *                                 Bluetooth Protocol Stack via a
 *                                 call to qapi_BLE_BSC_Initialize().
 *
 * @param[in]  TransactionID       GATT transaction ID for the
 *                                 request.
 *
 * @param[in]  Next_Dst_Change_Time   Pointer to the Next DST
 *                                    Change Time to send in the
 *                                    response to the NDCS client.
 *
 * @return      Zero if successful.
 *
 * @return      An error code if negative; one of the following values:
 *              @par
 *                 QAPI_BLE_NDCS_ERROR_INVALID_PARAMETER \n
 *                 QAPI_BLE_GATT_ERROR_INVALID_TRANSACTION_ID
 */
QAPI_BLE_DECLARATION int QAPI_BLE_BTPSAPI qapi_BLE_NDCS_Time_With_DST_Read_Request_Response(uint32_t BluetoothStackID, uint32_t TransactionID, qapi_BLE_NDCS_Time_With_Dst_Data_t *Next_Dst_Change_Time);

/**
 * @brief
 * Responds to a read
 * request from an NDCS client for the NDCS Current Time Characteristic
 * that resulted in an error.
 *
 * @param[in]  BluetoothStackID    Unique identifier assigned to this
 *                                 Bluetooth Protocol Stack via a
 *                                 call to qapi_BLE_BSC_Initialize().
 *
 * @param[in]  TransactionID       GATT transaction ID for the
 *                                 request.
 *
 * @param[in]  ErrorCode           Error code for the request, which
 *                                 indicates the error that has
 *                                 occured.
 *
 * @return      Zero if successful.
 *
 * @return      An error code if negative; one of the following values:
 *              @par
 *                 QAPI_BLE_NDCS_ERROR_INVALID_PARAMETER \n
 *                 QAPI_BLE_GATT_ERROR_INVALID_TRANSACTION_ID
 */
QAPI_BLE_DECLARATION int QAPI_BLE_BTPSAPI qapi_BLE_NDCS_Time_With_DST_Read_Request_Error_Response(uint32_t BluetoothStackID, uint32_t TransactionID, uint8_t ErrorCode);

   /* NDCS client API.                                                  */

/**
 * @brief
 * Parses a value received from a
 * remote NDCS server interpreting it as the NDCS Next DST Change Time
 * Characteristic.
 *
 * @details
 * This function should be used to decode the NDCS Next DST Change Time
 * Characteristic received in a GATT Read response.
 *
 * @param[in]  ValueLength    Length of the value received from the
 *                            NDCS server.
 *
 * @param[in]  Value          Value received from the
 *                            NDCS server.
 *
 * @param[out]  Next_Dst_Change_Time    Pointer that will hold the
 *                                      Next DST Change Time if this function
 *                                      returns success.
 *
 * @return      Zero if successful.
 *
 * @return      An error code if negative; one of the following values:
 *              @par
 *                 QAPI_BLE_NDCS_ERROR_INVALID_PARAMETER
 */
QAPI_BLE_DECLARATION int QAPI_BLE_BTPSAPI qapi_BLE_NDCS_Decode_Time_With_Dst(uint32_t ValueLength, uint8_t *Value, qapi_BLE_NDCS_Time_With_Dst_Data_t *Next_Dst_Change_Time);

/**
 * @}
 */

#endif

