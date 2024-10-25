// Copyright (c) 2007-2010 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
// Example CTestStep derived implementation
//


/**
 @file te_tracecontroldefaultconfig.cpp
 @internalTechnology
 */
#ifndef OST_TRACE_COMPILER_IN_USE
#define OST_TRACE_COMPILER_IN_USE
#endif //OST_TRACE_COMPILER_IN_USE
#include <opensystemtrace.h>


#include "te_ostv2tracetestwrapper.h"
#include "te_ostv2tracetestwrapperTraces.h"

const TUint32 KTestTInt1 = 0x123;
const TUint32 KTestTInt2 = 0x456;
_LIT(KTestDuplicates, "TestDuplicates");

_LIT(KTestOstDebugOnlyWrap, "TestOstDebugOnlyWrap");

_LIT(KTestOstCompileTimeMacro, "TestOstCompileTimeMacro");

//macro wrapper that works only in _DEBUG mode
#ifndef OST_DEBUG_ONLY
#ifdef _DEBUG
#define OST_DEBUG_ONLY(x) x
#else
#define OST_DEBUG_ONLY(x)
#endif
#endif //ifndef OST_DEBUG_ONLY

using namespace Ulogger;
/**
 * Destructor
 */
CTOstv2TraceTestWrapper::~CTOstv2TraceTestWrapper()
    {
    }

/**
 * Constructor
 */
CTOstv2TraceTestWrapper::CTOstv2TraceTestWrapper()
    {
    }

CTOstv2TraceTestWrapper* CTOstv2TraceTestWrapper::NewLC()
    {
    CTOstv2TraceTestWrapper* self = new (ELeave) CTOstv2TraceTestWrapper();
    CleanupStack::PushL(self);
    self->ConstructL();
    return self;
    }

CTOstv2TraceTestWrapper* CTOstv2TraceTestWrapper::NewL()
    {
    CTOstv2TraceTestWrapper* self = CTOstv2TraceTestWrapper::NewLC();
    CleanupStack::Pop(); // self;
    return self;
    }

void CTOstv2TraceTestWrapper::ConstructL()
    {
    }

TAny* CTOstv2TraceTestWrapper::GetObject()
    {
    return NULL;
    }
TBool CTOstv2TraceTestWrapper::DoCommandL(const TTEFFunction& aCommand,
        const TTEFSectionName& /*aSection*/, const TInt /*aAsyncErrorIndex*/)
    {

    TBool ret = ETrue;
    
    if (aCommand == KTestDuplicates())
        {
        TestDuplicatesL();
        }
    else if (aCommand == KTestOstDebugOnlyWrap())
        {
        TestOstDebugOnlyWrapL();
        }
    else if (aCommand == KTestOstCompileTimeMacro())
        {
        TestOstCompileTimeMacroL();
        }
    else
        {
        ret = EFalse;
        }
    
    return ret;
    }


TInt CTOstv2TraceTestWrapper::OpenUlogger(RULogger& aLogger)
    {

    INFO_PRINTF1(_L("Opening Ulogger connection"));
    TInt result = aLogger.Connect();
      INFO_PRINTF2(_L("Connection to Ulogger: %d, attempt: 1"), result);
      if (result != KErrNone)
          {
          INFO_PRINTF1(_L("Connection to Ulogger failed. Will try to connect max. 10 times"));
          for (TInt i = 2; i < 12; i++)
              {
              User::After(1000);
              result = aLogger.Connect();
              INFO_PRINTF3(_L("Connection to Ulogger: %d, attempt: %d"), result, i);
              if (result == KErrNone)
                  {
                  break;
                  }
              }
          }
      
      if(result != KErrNone)
          {
          ERR_PRINTF2(_L("Failed to open Ulogger: error (%d)"), result);
          }
      
      return result;
    }

void CTOstv2TraceTestWrapper::TestDuplicatesL()
    {

    INFO_PRINTF1(_L("CTOstv2TraceTestWrapper::TestDuplicates"));

    RULogger logger;

    
    User::LeaveIfError(OpenUlogger(logger));
    // clear the config file
    CClearConfig configIni;
    configIni.ClearL(logger);

    // extract the user ids from the values generated by tracecompiler
    const TUint8 USER_DEFINED_GID_1 = TEST_OSTTRACEWRAPPER7 >> 16;
    const TUint8 USER_DEFINED_GID_2 = TEST_OSTTRACEWRAPPER8 >> 16;

    // switch on primary filtering mechanism
    CArrayFixFlat<TUint8> *setprimfilter =
            new (ELeave) CArrayFixFlat<TUint8> (22);
    setprimfilter->AppendL(KGroupId);
    setprimfilter->AppendL(TRACE_FATAL);
    setprimfilter->AppendL(TRACE_DUMP);
    setprimfilter->AppendL(TRACE_DUMP);
    setprimfilter->AppendL(USER_DEFINED_GID_1);
    setprimfilter->AppendL(USER_DEFINED_GID_2);

    TInt result = logger.SetPrimaryFiltersEnabled(*setprimfilter, ETrue);

    if (result != KErrNone)
        {
        ERR_PRINTF2(_L("Failed to set Ulogger primary filters result(%d"), result);
        SetBlockResult(EFail);
        }

    // switch off secondary filtering
    result = logger.SetSecondaryFilteringEnabled(EFalse);
    if (result != KErrNone)
        {
        ERR_PRINTF2(_L("Failed to set Ulogger secondary filters result(%d"), result);
        SetBlockResult(EFail);
        }

    delete setprimfilter;
    setprimfilter = NULL;
    // setup output file
    _LIT(KLogFilename, "C:\\logs\\duplicate_trace_test.utf");
    EmptyFile(KLogFilename);
    // setup ulogger to write to the file using its output plugin
    _LIT8(KTextmedia,"uloggerfileplugin");
    TPtrC8 mediaptr(KTextmedia);
    result = logger.ActivateOutputPlugin(mediaptr);
    if (result == KErrNone)
        {
        INFO_PRINTF1(_L("file set as active output plugin ok"));
        TPluginConfiguration pluginConfig;
        _LIT(KTextsetting, "output_path");
        pluginConfig.SetKey(KTextsetting);
        pluginConfig.SetValue(KLogFilename());
        result = logger.SetPluginConfigurations(mediaptr, pluginConfig);
        if (result == KErrNone)
            {
            INFO_PRINTF1(_L("output plugin settings set ok"));

            result = logger.Start();
            if (result == KErrNone)
                {
                // add some traces TRACE_DUMP & TRACE_DUMP equate to the same numeric value

                AddTraceHelper((TGroupId) TRACE_FATAL,
                        (TTraceId) TEST_OSTTRACEWRAPPER1, KTestTInt1);
                OstTrace1(TRACE_FATAL, TEST_OSTTRACEWRAPPER1, "CTOstv2TraceTestWrapper TRACE_FATAL test 1 KTestTInt1 (%d)" , KTestTInt1);

                AddTraceHelper((TGroupId) TRACE_DUMP,
                        (TTraceId) TEST_OSTTRACEWRAPPER2, KTestTInt1);
                OstTrace1(TRACE_DUMP, TEST_OSTTRACEWRAPPER2, "CTOstv2TraceTestWrapper TRACE_DUMP test 1 KTestTInt1 (%d)" , KTestTInt1);

                AddTraceHelper((TGroupId) TRACE_DUMP,
                        (TTraceId) TEST_OSTTRACEWRAPPER3, KTestTInt1);
                OstTrace1(TRACE_DUMP, TEST_OSTTRACEWRAPPER3, "CTOstv2TraceTestWrapper TRACE_DUMP  test 1 KTestTInt1 (%d)" , KTestTInt1);

                AddTraceHelper((TGroupId) TRACE_FATAL,
                        (TTraceId) TEST_OSTTRACEWRAPPER4, KTestTInt2);
                OstTrace1(TRACE_FATAL, TEST_OSTTRACEWRAPPER4, "CTOstv2TraceTestWrapper TRACE_FATAL test 2 KTestTInt2 (%d)" , KTestTInt2);

                AddTraceHelper((TGroupId) TRACE_DUMP,
                        (TTraceId) TEST_OSTTRACEWRAPPER5, KTestTInt2);
                OstTrace1(TRACE_DUMP, TEST_OSTTRACEWRAPPER5, "CTOstv2TraceTestWrapper TRACE_DUMP test 2 KTestTInt2 (%d)" , KTestTInt2);

                AddTraceHelper((TGroupId) TRACE_DUMP,
                        (TTraceId) TEST_OSTTRACEWRAPPER6, KTestTInt2);
                OstTrace1(TRACE_DUMP, TEST_OSTTRACEWRAPPER6, "CTOstv2TraceTestWrapper TRACE_DUMP  test 2 KTestTInt2 (%d)" , KTestTInt2);

                AddTraceHelper((TGroupId) USER_DEFINED_GID_1,
                        (TTraceId) TEST_OSTTRACEWRAPPER7, KTestTInt1);
                OstTrace1(USER_DEFINED_GID_1, TEST_OSTTRACEWRAPPER7, "CTOstv2TraceTestWrapper USER_DEFINED_GID_1  test 2 KTestTInt2 (%d)" , KTestTInt1);

                AddTraceHelper((TGroupId) USER_DEFINED_GID_2,
                        (TTraceId) TEST_OSTTRACEWRAPPER8, KTestTInt2);
                OstTrace1(USER_DEFINED_GID_2, TEST_OSTTRACEWRAPPER8, "CTOstv2TraceTestWrapper USER_DEFINED_GID_1  test 2 KTestTInt2 (%d)" , KTestTInt2);
                
                result = logger.Stop();

                if (result == KErrNone)
                    {
                    SetBlockResult(
                            CheckResults(KLogFilename()) == KErrNone
                                                                     ? EPass
                                                                        : EFail);
                    }
                }
            else
                {
                INFO_PRINTF2(_L("ulogger start returns error %d"), result);
                }
            }
        else
            {
            INFO_PRINTF2(_L("setting output plugin settings failed with err %d"), result);
            }
        }
    else
        {
        INFO_PRINTF2(_L("add file as output plugin failed with err %d"), result);
        }
    }


void CTOstv2TraceTestWrapper::TestOstDebugOnlyWrapL()
    {
    INFO_PRINTF1(_L("CTOstv2TraceTestWrapper::TestOstDebugOnlyWrap"));

    RULogger logger;

    
    User::LeaveIfError(OpenUlogger(logger));
    // clear the config file
    CClearConfig configIni;
    configIni.ClearL(logger);

    // extract the user ids from the values generated by tracecompiler
    const TUint8 USER_DEFINED_GID_1w = TEST_OSTTRACEWRAPPER7w >> 16;
    const TUint8 USER_DEFINED_GID_2w = TEST_OSTTRACEWRAPPER8w >> 16;

    // switch on primary filtering mechanism
    CArrayFixFlat<TUint8> *setprimfilter =
            new (ELeave) CArrayFixFlat<TUint8> (22);
    setprimfilter->AppendL(KGroupId);
    setprimfilter->AppendL(TRACE_FATAL);
    setprimfilter->AppendL(TRACE_DUMP);
    setprimfilter->AppendL(TRACE_DUMP);
    setprimfilter->AppendL(USER_DEFINED_GID_1w);
    setprimfilter->AppendL(USER_DEFINED_GID_2w);

    TInt result = logger.SetPrimaryFiltersEnabled(*setprimfilter, ETrue);

    if (result != KErrNone)
        {
        ERR_PRINTF2(_L("Failed to set Ulogger primary filters result(%d"), result);
        SetBlockResult(EFail);
        }

    // switch off secondary filtering
    result = logger.SetSecondaryFilteringEnabled(EFalse);
    if (result != KErrNone)
        {
        ERR_PRINTF2(_L("Failed to set Ulogger secondary filters result(%d"), result);
        SetBlockResult(EFail);
        }

    delete setprimfilter;
    setprimfilter = NULL;
    // setup output file
    _LIT(KLogFilename, "C:\\logs\\duplicate_trace_test.utf");
    EmptyFile(KLogFilename);
    // setup ulogger to write to the file using its output plugin
    _LIT8(KTextmedia,"uloggerfileplugin");
    TPtrC8 mediaptr(KTextmedia);
    result = logger.ActivateOutputPlugin(mediaptr);
    if (result == KErrNone)
        {
        INFO_PRINTF1(_L("file set as active output plugin ok"));
        TPluginConfiguration pluginConfig;
        _LIT(KTextsetting, "output_path");
        pluginConfig.SetKey(KTextsetting);
        pluginConfig.SetValue(KLogFilename());
        result = logger.SetPluginConfigurations(mediaptr, pluginConfig);
        if (result == KErrNone)
            {
            INFO_PRINTF1(_L("output plugin settings set ok"));

            result = logger.Start();
            if (result == KErrNone)
                {
                // now try the same traces again but with the OST_DEBUG_ONLY wrapper
                OST_DEBUG_ONLY(AddTraceHelper((TGroupId) TRACE_FATAL,
                        (TTraceId) TEST_OSTTRACEWRAPPER1w, KTestTInt1));
                OST_DEBUG_ONLY(OstTrace1(TRACE_FATAL, TEST_OSTTRACEWRAPPER1w, "CTOstv2TraceTestWrapper TRACE_FATAL test 1 KTestTInt1 (%d)" , KTestTInt1));

                OST_DEBUG_ONLY(AddTraceHelper((TGroupId) TRACE_DUMP,
                        (TTraceId) TEST_OSTTRACEWRAPPER2w, KTestTInt1));
                OST_DEBUG_ONLY(OstTrace1(TRACE_DUMP, TEST_OSTTRACEWRAPPER2w, "CTOstv2TraceTestWrapper TRACE_DUMP test 1 KTestTInt1 (%d)" , KTestTInt1));

                OST_DEBUG_ONLY(AddTraceHelper((TGroupId) TRACE_DUMP,
                        (TTraceId) TEST_OSTTRACEWRAPPER3w, KTestTInt1));
                OST_DEBUG_ONLY(OstTrace1(TRACE_DUMP, TEST_OSTTRACEWRAPPER3w, "CTOstv2TraceTestWrapper TRACE_DUMP  test 1 KTestTInt1 (%d)" , KTestTInt1));

                OST_DEBUG_ONLY(AddTraceHelper((TGroupId) TRACE_FATAL,
                        (TTraceId) TEST_OSTTRACEWRAPPER4w, KTestTInt2));
                OST_DEBUG_ONLY(OstTrace1(TRACE_FATAL, TEST_OSTTRACEWRAPPER4w, "CTOstv2TraceTestWrapper TRACE_FATAL test 2 KTestTInt2 (%d)" , KTestTInt2));

                OST_DEBUG_ONLY(AddTraceHelper((TGroupId) TRACE_DUMP,
                        (TTraceId) TEST_OSTTRACEWRAPPER5w, KTestTInt2));
                OST_DEBUG_ONLY(OstTrace1(TRACE_DUMP, TEST_OSTTRACEWRAPPER5w, "CTOstv2TraceTestWrapper TRACE_DUMP test 2 KTestTInt2 (%d)" , KTestTInt2));

                OST_DEBUG_ONLY(AddTraceHelper((TGroupId) TRACE_DUMP,
                        (TTraceId) TEST_OSTTRACEWRAPPER6w, KTestTInt2));
                OST_DEBUG_ONLY(OstTrace1(TRACE_DUMP, TEST_OSTTRACEWRAPPER6w, "CTOstv2TraceTestWrapper TRACE_DUMP  test 2 KTestTInt2 (%d)" , KTestTInt2));

                OST_DEBUG_ONLY(AddTraceHelper((TGroupId) USER_DEFINED_GID_1w,
                        (TTraceId) TEST_OSTTRACEWRAPPER7w, KTestTInt1));
                OST_DEBUG_ONLY(OstTrace1(USER_DEFINED_GID_1, TEST_OSTTRACEWRAPPER7w, "CTOstv2TraceTestWrapper USER_DEFINED_GID_1  test 2 KTestTInt2 (%d)" , KTestTInt1));

                OST_DEBUG_ONLY(AddTraceHelper((TGroupId) USER_DEFINED_GID_2w,
                        (TTraceId) TEST_OSTTRACEWRAPPER8w, KTestTInt2));
                OST_DEBUG_ONLY(OstTrace1(USER_DEFINED_GID_2, TEST_OSTTRACEWRAPPER8w, "CTOstv2TraceTestWrapper USER_DEFINED_GID_1  test 2 KTestTInt2 (%d)" , KTestTInt2));

                                
                result = logger.Stop();

                if (result == KErrNone)
                    {
                    SetBlockResult(
                            CheckResults(KLogFilename()) == KErrNone
                                                                     ? EPass
                                                                        : EFail);
                    }
                }
            else
                {
                INFO_PRINTF2(_L("ulogger start returns error %d"), result);
                }
            }
        else
            {
            INFO_PRINTF2(_L("setting output plugin settings failed with err %d"), result);
            }
        }
    else
        {
        INFO_PRINTF2(_L("add file as output plugin failed with err %d"), result);
        }
    }


void CTOstv2TraceTestWrapper::TestOstCompileTimeMacroL()
    {
    INFO_PRINTF1(_L("CTOstv2TraceTestWrapper::TestOstCompileTimeMacro"));

    RULogger logger;

    
    User::LeaveIfError(OpenUlogger(logger));
    // clear the config file
    CClearConfig configIni;
    configIni.ClearL(logger);

    // switch on primary filtering mechanism
    CArrayFixFlat<TUint8> *setprimfilter =
            new (ELeave) CArrayFixFlat<TUint8> (22);
    setprimfilter->AppendL(KGroupId);
    setprimfilter->AppendL(TRACE_NORMAL);
    TInt result = logger.SetPrimaryFiltersEnabled(*setprimfilter, ETrue);

    if (result != KErrNone)
        {
        ERR_PRINTF2(_L("Failed to set Ulogger primary filters result(%d"), result);
        SetBlockResult(EFail);
        }

    // switch off secondary filtering
    result = logger.SetSecondaryFilteringEnabled(EFalse);
    if (result != KErrNone)
        {
        ERR_PRINTF2(_L("Failed to set Ulogger secondary filters result(%d"), result);
        SetBlockResult(EFail);
        }

    delete setprimfilter;
    setprimfilter = NULL;
    // setup output file
    _LIT(KLogFilename, "C:\\logs\\macro_trace_test.utf");
    EmptyFile(KLogFilename);
    // setup ulogger to write to the file using its output plugin
    _LIT8(KTextmedia,"uloggerfileplugin");
    TPtrC8 mediaptr(KTextmedia);
    result = logger.ActivateOutputPlugin(mediaptr);
    if (result == KErrNone)
        {
        INFO_PRINTF1(_L("file set as active output plugin ok"));
        TPluginConfiguration pluginConfig;
        _LIT(KTextsetting, "output_path");
        pluginConfig.SetKey(KTextsetting);
        pluginConfig.SetValue(KLogFilename());
        result = logger.SetPluginConfigurations(mediaptr, pluginConfig);
        if (result == KErrNone)
            {
            INFO_PRINTF1(_L("output plugin settings set ok"));

            result = logger.Start();
            if (result == KErrNone)
                {
                // now try some traces with compile time Macros
                //OST_TRACE_CATEGORY_DEBUG
                #if (OST_TRACE_CATEGORY & OST_TRACE_CATEGORY_DEBUG)
                AddTraceHelper((TGroupId) TRACE_NORMAL, (TTraceId) TEST_OSTTRACEWRAPPER1m, 0); // should be in UDEB only
                #endif
                OstTraceDef0(OST_TRACE_CATEGORY_DEBUG, TRACE_NORMAL, TEST_OSTTRACEWRAPPER1m, "Foo");
                
                #ifdef _DEBUG
                AddTraceHelper((TGroupId) TRACE_NORMAL, (TTraceId) TEST_OSTTRACEWRAPPER2m, 0);
                #endif
                OstTraceDef0(OST_TRACE_CATEGORY_DEBUG, TRACE_NORMAL, TEST_OSTTRACEWRAPPER2m, "Foo"); // should be in UBED only
                
                
                //OST_TRACE_CATEGORY_PRODUCTION
                #if (OST_TRACE_CATEGORY & OST_TRACE_CATEGORY_PRODUCTION)
                AddTraceHelper((TGroupId) TRACE_NORMAL, (TTraceId) TEST_OSTTRACEWRAPPER3m, 0);
                #endif
                OstTraceDef0(OST_TRACE_CATEGORY_PRODUCTION, TRACE_NORMAL, TEST_OSTTRACEWRAPPER3m, "Foo"); // should be in UREL and UDEB
                
                //OST_TRACE_CATEGORY_RND
                #if (OST_TRACE_CATEGORY & OST_TRACE_CATEGORY_RND)
                AddTraceHelper((TGroupId) TRACE_NORMAL, (TTraceId) TEST_OSTTRACEWRAPPER4m, 0);
                #endif
                OstTraceDef0(OST_TRACE_CATEGORY_RND, TRACE_NORMAL, TEST_OSTTRACEWRAPPER4m, "Foo"); // should be in UREL and UDEB
                
                #if (OST_TRACE_CATEGORY & OST_TRACE_CATEGORY_PERFORMANCE_MEASUREMENT)
                AddTraceHelper((TGroupId) TRACE_NORMAL, (TTraceId) TEST_OSTTRACEWRAPPER5m, 0);
                #endif
                OstTraceDef0(OST_TRACE_CATEGORY_PERFORMANCE_MEASUREMENT, TRACE_NORMAL, TEST_OSTTRACEWRAPPER5m, "Foo"); // should be in neither UREL nor UDEB
                             
                #if (OST_TRACE_CATEGORY & OST_TRACE_CATEGORY_NONE)
                AddTraceHelper((TGroupId) TRACE_NORMAL, (TTraceId) TEST_OSTTRACEWRAPPER6m, 0);
                #endif            
                OstTraceDef0(OST_TRACE_CATEGORY_NONE, TRACE_NORMAL, TEST_OSTTRACEWRAPPER6m, "Foo"); // should be in neither UREL nor UDEB
                
                #if (OST_TRACE_CATEGORY & OST_TRACE_CATEGORY_ALL)
                AddTraceHelper((TGroupId) TRACE_NORMAL, (TTraceId) TEST_OSTTRACEWRAPPER7m, 0);
                #endif
                OstTraceDef0(OST_TRACE_CATEGORY_ALL, TRACE_NORMAL, TEST_OSTTRACEWRAPPER7m, "Foo"); // should be in UREL and UDEB
                
                #if (OST_TRACE_CATEGORY & (OST_TRACE_CATEGORY_PRODUCTION | OST_TRACE_CATEGORY_DEBUG))
                AddTraceHelper((TGroupId) TRACE_NORMAL, (TTraceId) TEST_OSTTRACEWRAPPER8m, 0);
                #endif
                OstTraceDef0(OST_TRACE_CATEGORY_PRODUCTION | OST_TRACE_CATEGORY_DEBUG, TRACE_NORMAL, TEST_OSTTRACEWRAPPER8m, "Foo"); // should be in UREL and UDEB

                #if (OST_TRACE_CATEGORY & (OST_TRACE_CATEGORY_PRODUCTION)) || defined (_DEBUG)
                AddTraceHelper((TGroupId) TRACE_NORMAL, (TTraceId) TEST_OSTTRACEWRAPPER9m, 0);
                #endif
                OstTraceDef0(OST_TRACE_CATEGORY_PRODUCTION | OST_TRACE_CATEGORY_DEBUG, TRACE_NORMAL, TEST_OSTTRACEWRAPPER9m, "Foo"); // should be in UREL and UDEB
              
                                
                result = logger.Stop();

                if (result == KErrNone)
                    {
                    SetBlockResult(
                            CheckResults(KLogFilename()) == KErrNone
                                                                     ? EPass
                                                                        : EFail);
                    }
                }
            else
                {
                INFO_PRINTF2(_L("ulogger start returns error %d"), result);
                }
            }
        else
            {
            INFO_PRINTF2(_L("setting output plugin settings failed with err %d"), result);
            }
        }
    else
        {
        INFO_PRINTF2(_L("add file as output plugin failed with err %d"), result);
        }
    }


TInt CTOstv2TraceTestWrapper::CheckResults(const TDesC& aLogFilename)
    {
    // read the logged traces from the log file	
    TInt err = ReadFromLogFile(aLogFilename);
    if (err == KErrNone)
        {
        err = CompareTraces();
        if (err == KErrNone)
            {

            }
        else
            {
            ERR_PRINTF2(_L("CompareTraces returned err (%d)"), err);
            }
        }
    else
        {
        ERR_PRINTF2(_L("ReadFromLogFile returned err (%d)"), err);
        }

    return err;
    }

void CTOstv2TraceTestWrapper::CTOstv2TraceTestWrapper::AddTraceHelper(
        const TGroupId aGroupId, const TTraceId aTraceId, TUint32 aValue)
    {
    if (CreateTraceObject(KOstTraceComponentID, aGroupId,
            EAddThreadIdentification, ENoProgramCounter, iSentTraces))
        {
        TTraceConfigs& config = *iSentTraces[iSentTraces.Count() - 1];
        TTraceConfigsOperator::SetData(config, aValue);
        TTraceConfigsOperator::SetHeader(config, aGroupId,
                KOstTraceComponentID, EAddThreadIdentification,
                ENoProgramCounter, aTraceId);
        }
    else
        {
        ERR_PRINTF2(_L("CreateTraceObject failed with for traceid (%d)"), aTraceId);
        SetBlockResult(EFail);
        }
    }



