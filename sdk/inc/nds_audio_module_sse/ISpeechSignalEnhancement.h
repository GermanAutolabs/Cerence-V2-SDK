/*--------------------------COPYRIGHT INFORMATION----------------------------+
 |                                                                           |
 | This program contains proprietary information that is a trade secret      |
 | of Cerence, Inc. and also is protected as an unpublished                  |
 | work under applicable Copyright laws. Recipient is to retain this         |
 | program in confidence and is not permitted to use or make copies          |
 | thereof other than as permitted in a prior written agreement with         |
 | Cerence, Inc. or its affiliates.                                          |
 |                                                                           |
 | Copyright (c) 2020 Cerence, Inc.                                          |
 | All rights reserved. Company confidential.                                |
 |                                                                           |
 +---------------------------------------------------------------------------*/

/**
 *  Declaration of nuance_audio_ISpeechSignalEnhancement class
 *  Automatically generated source code! Do not edit manually!
 *
 */

/**
 *  @addtogroup nuance_audio  nuance_audio
 *  @{
 *  @addtogroup ISpeechSignalEnhancement
 *  @{
 *  @file ISpeechSignalEnhancement.h
 *
 *  @brief  Interface of the 'SpeechSignalEnhancement' audio module. <p>
 *
 *  The SpeechSignalEnhancement (abbr.'SSE') module integrates the sse core component into the audio backbone.
 */

#ifndef NUANCE_AUDIO_ISPEECHSIGNALENHANCEMENT_H
#define NUANCE_AUDIO_ISPEECHSIGNALENHANCEMENT_H

#ifdef __cplusplus
extern "C" {
#endif


/*** Declare class handle *********************************************************************************************/

/**
 *  @brief  Interface of the 'SpeechSignalEnhancement' audio module. <p>
 *
 *  The SpeechSignalEnhancement (abbr.'SSE') module integrates the sse core component into the audio backbone.
 */
struct _nuance_audio_ISpeechSignalEnhancement;
/**
 *  @brief  Interface of the 'SpeechSignalEnhancement' audio module. <p>
 *
 *  The SpeechSignalEnhancement (abbr.'SSE') module integrates the sse core component into the audio backbone.
 */
typedef struct _nuance_audio_ISpeechSignalEnhancement nuance_audio_ISpeechSignalEnhancement;


/*** Includes *********************************************************************************************************/

/* PAL types */
#include "lh_types.h"

#include "audio_api_defs.h"

/* API types */
#include "IAudioManager.h"
#include "IAudioModule.h"
#include "IConfiguration.h"
#include "ISpeechSignalEnhancementListener.h"
#include "IntList.h"
#include "ResultCode.h"
#include "StringList.h"
#include "nuance_String.h"


/*** Methods **********************************************************************************************************/


/**
 *  @brief  enables the implicit creation feature for this module at the handed audio manager instance. <p>
 *
 *  This method enables the implicit creation feature for this module at the handed audio manager instance.
 *  It takes care of all necessary internal steps to do that, including the creation of the needed factory
 *  as well as the registration of that factory object at the audio manager.
 *
 *  The ownership of the factory object is handed to the audio manager by calling this method.
 *  It will be destroyed once the audio manager is destroyed.
 *
 *  This feature can be activated only once and stays active as long as the handed audio manager instance is available.
 *  Trying to activate that feature a second time will result in an error.
 *
 *  @param[in]     audioManager   Audio manager instance.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISpeechSignalEnhancement_registerFactory(nuance_audio_IAudioManager *audioManager);


/**
 *  Creates an 'SpeechSignalEnhancement' audio module.
 *
 *  @param[in]     name                      Name of the module instance to be created.
 *  @param[in]     audioManager              Audio manager instance.
 *  @param[in]     config                    Configuration object.
 *  @param[in]     moduleListener            Listener that is informed about module changes (e.g creation finished)
 *  @param[out]    speechSignalEnhancement   User interface of the created audio module instance.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISpeechSignalEnhancement_create
(
    const LH_CHAR *name,
    nuance_audio_IAudioManager *audioManager,
    const nuance_common_IConfiguration *config,
    nuance_audio_ISpeechSignalEnhancementListener *moduleListener,
    nuance_audio_ISpeechSignalEnhancement **speechSignalEnhancement
);


/**
 *  @brief  Returns the version of this audio module. <p>
 *
 *  The SSE module contains the sse core-engine.
 *  Therefore this method will return the version information of all sse core libraries loaded so far.
 *
 *  @param[out]    version   Version of the module.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISpeechSignalEnhancement_getVersion(nuance_common_String **version);


/**
 *  Set an integer sse core value.
 *
 *  The method will return immediately, indicating that the asynchronous request was accepted.
 *
 *  IBackgroundOperation::waitForCompletion() can be used to wait until the operation is done and to retrieve the error code.
 *
 *  Disclaimer: Setting sse core values directly is not recommended.
 *  It may decrease the quality of the processed audio.
 *
 *  If it is planned to use this interface please contact the acoustic expert team via your account manager.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     dataId    sse core data descriptor, which should be set
 *  @param[in]     channel   channel the desired value should be set for
 *  @param[in]     value     integer value which should be set
 *  @param[in]     nvalue    Number of elements in value
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISpeechSignalEnhancement_setData
(
    nuance_audio_ISpeechSignalEnhancement *instance,
    LH_S32 dataId,
    LH_S32 channel,
    LH_S32  const *value, LH_S32 nvalue
);


/**
 *  Get an integer sse core value.
 *
 *  The method will return immediately, indicating that the asynchronous request was accepted.
 *
 *  IBackgroundOperation::waitForCompletion() can be used to wait until the operation is done and to retrieve the error code.
 *
 *  The expected result value is returned via the ISpeechSignalEnhancementListener passed on module creation.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     dataId    sse core data descriptor, which should be got
 *  @param[in]     channel   channel the desired value should be got for
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISpeechSignalEnhancement_getData
(
    nuance_audio_ISpeechSignalEnhancement *instance,
    LH_S32 dataId,
    LH_S32 channel
);


/**
 *  @brief  Returns the sink and source pad name(s) of this SDK audio module. <p>
 *
 *  The pad names are given in the configuration of this audio module.
 *  In case this audio module does only have one single sink respectively source pad the pad name is equal to the instance name of this module.
 *  The pad names have to be unambiguous as they are used as identifier of a specific pad.
 *  They are used in conjunction with the instance name to establish/abolish pad connections.
 *  The pad name order in the list corresponds the descending order of the sink resp. source pads of this audio module.
 *
 *  This method is thread safe.
 *
 *  @param[in,out] instance     The instance pointer
 *  @param[out]    sinkPads     Sink pad name list of this audio module.
 *  @param[out]    sourcePads   Source pad name list of this audio module.
 *
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISpeechSignalEnhancement_getPadNames
(
    const nuance_audio_ISpeechSignalEnhancement *instance,
    nuance_common_StringList **sinkPads,
    nuance_common_StringList **sourcePads
);


/**
 *  @brief  Returns the instance name of this SDK module. <p>
 *
 *  The instance name is given as parameter to the create call of this SDK module.
 *  The name has to be unambiguous as it is used as identifier of this SDK module instance.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Name of this SDK module instance.
 */
AUDIO_C_EXPORT nuance_common_String *nuance_audio_ISpeechSignalEnhancement_getName(const nuance_audio_ISpeechSignalEnhancement *instance);


/**
 *  Returns the status of the background operation
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   Background operation status
 *
 *  @return Result code
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISpeechSignalEnhancement_getStatus
(
    nuance_audio_ISpeechSignalEnhancement *instance,
    nuance_common_IBackgroundOperation_Status *status
);


/**
 *  Waits until the background operation is finished.
 *  If the worker thread supports queueing of background operations (e.g. nuance::prompter::IPrompter::activateUseCase() ..
 *  nuance::prompter::IPrompter::playString()), this method waits until all operations which are in the
 *  queue finish or until timeout expires, providing the timeout value is positive. If timeout value is
 *  negative or 0 (undefined) then it waits until all operations finish.
 *
 *  @param[in,out] instance  The instance pointer
 *  @param[in]     timeout   Timeout in milliseconds after which the method should return even if the background operation is not yet finished
 *  @param[out]    status    The state of the background operation, either RUNNING (if returned due to timeout), COMPLETED (on success), FAILED (on error) or FAILED_FATAL (on fatal error)
 *
 *  @return The result code of the execution
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISpeechSignalEnhancement_waitForCompletionWithTimeout
(
    nuance_audio_ISpeechSignalEnhancement *instance,
    LH_S32 timeout,
    nuance_common_IBackgroundOperation_Status *status
);


/**
 *  Waits until the background operation is finished.
 *  If the worker thread supports queueing of background operations (e.g. nuance::prompter::IPrompter::activateUseCase() ..
 *  nuance::prompter::IPrompter::playString()), this method waits until all operations are
 *  finished, which are in the queue when waitForCompletion() was called.
 *
 *  @param[in,out] instance The instance pointer
 *  @param[out]    status   The state of the background operation, either COMPLETED (on success), FAILED (on error) or FAILED_FATAL (on fatal error)
 *
 *  @return Result code
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISpeechSignalEnhancement_waitForCompletion
(
    nuance_audio_ISpeechSignalEnhancement *instance,
    nuance_common_IBackgroundOperation_Status *status
);


/**
 *  Returns directly and triggers an internal wait for the background operation to finish.
 *  If the worker thread supports queueing of background operations (e.g. nuance::prompter::IPrompter::activateUseCase() ..
 *  nuance::prompter::IPrompter::playString()), the listener is called once all operations are finished that were in the
 *  queue when waitForCompletion() was called.
 *
 *  Note: This method is intended for DragonDriveFramework use only.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     listener   An IBackgroundListener instance.
 *
 *  @return Result code
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISpeechSignalEnhancement_waitForCompletionAsync
(
    nuance_audio_ISpeechSignalEnhancement *instance,
    nuance_common_IBackgroundListener *listener
);


/**
 *  Returns directly and triggers an internal wait for the background operation to finish.
 *  If the worker thread supports queueing of background operations (e.g. nuance::prompter::IPrompter::activateUseCase() ..
 *  nuance::prompter::IPrompter::playString()), the listener is called once all operations are finished or the timeout expired.
 *  If the timeout value is negative or 0 (undefined) it waits until all operations are finished.
 *
 *  Note: This method is intended for DragonDriveFramework use only.
 *
 *  @param[in,out] instance   The instance pointer
 *  @param[in]     timeout    Timeout in milliseconds after which the method should return even if the background operation is not yet finished
 *  @param[in]     listener   An IBackgroundListener instance.
 *
 *  @return The result code of the execution
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISpeechSignalEnhancement_waitForCompletionWithTimeoutAsync
(
    nuance_audio_ISpeechSignalEnhancement *instance,
    LH_S32 timeout,
    nuance_common_IBackgroundListener *listener
);


/**
 *  Aborts the current background operation, if other tasks are queued these are removed, too.
 *  The worker thread status is switched to ABORTING and the method returns immediately.
 *  If there's no active background operation, this method does nothing.
 *
 *  @param[in,out] instance The instance pointer
 *
 *  @return Result code
 */
AUDIO_C_EXPORT nuance_common_ResultCode nuance_audio_ISpeechSignalEnhancement_abortOperation(nuance_audio_ISpeechSignalEnhancement *instance);


/**
 *  Destructor
 */
AUDIO_C_EXPORT void nuance_audio_ISpeechSignalEnhancement_destroy(nuance_audio_ISpeechSignalEnhancement *);


AUDIO_C_EXPORT nuance_audio_IAudioModule *nuance_audio_ISpeechSignalEnhancement_as_nuance_audio_IAudioModule(nuance_audio_ISpeechSignalEnhancement *obj);

AUDIO_C_EXPORT nuance_common_IModule *nuance_audio_ISpeechSignalEnhancement_as_nuance_common_IModule(nuance_audio_ISpeechSignalEnhancement *obj);

AUDIO_C_EXPORT nuance_common_IBackgroundOperation *nuance_audio_ISpeechSignalEnhancement_as_nuance_common_IBackgroundOperation(nuance_audio_ISpeechSignalEnhancement *obj);


#ifdef __cplusplus
}
#endif

#endif /* NUANCE_AUDIO_ISPEECHSIGNALENHANCEMENT_H */

/** @} */
/** @} */

/**********************************************************************************************************************/