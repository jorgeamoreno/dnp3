//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
// 
// This file is auto-generated. Do not edit manually
// 
// Copyright 2016 Automatak LLC
// 
// Automatak LLC (www.automatak.com) licenses this file
// to you under the the Apache License Version 2.0 (the "License"):
// 
// http://www.apache.org/licenses/LICENSE-2.0.html
//

#include "JNIMasterConfig.h"

#include "JNI.h"
#include <assert.h>

namespace jni
{
    bool MasterConfig::init(JNIEnv* env)
    {

        this->clazz = env->FindClass("Lcom/automatak/dnp3/MasterConfig;");
        if(!this->clazz) return false;

        this->responseTimeoutField = env->GetFieldID(this->clazz, "responseTimeout", "Ljava/time/Duration;");
        if(!this->responseTimeoutField) return false;

        this->timeSyncModeField = env->GetFieldID(this->clazz, "timeSyncMode", "Lcom/automatak/dnp3/enums/TimeSyncMode;");
        if(!this->timeSyncModeField) return false;

        this->disableUnsolOnStartupField = env->GetFieldID(this->clazz, "disableUnsolOnStartup", "Z");
        if(!this->disableUnsolOnStartupField) return false;

        this->ignoreRestartIINField = env->GetFieldID(this->clazz, "ignoreRestartIIN", "Z");
        if(!this->ignoreRestartIINField) return false;

        this->unsolClassMaskField = env->GetFieldID(this->clazz, "unsolClassMask", "Lcom/automatak/dnp3/ClassField;");
        if(!this->unsolClassMaskField) return false;

        this->startupIntegrityClassMaskField = env->GetFieldID(this->clazz, "startupIntegrityClassMask", "Lcom/automatak/dnp3/ClassField;");
        if(!this->startupIntegrityClassMaskField) return false;

        this->integrityOnEventOverflowIINField = env->GetFieldID(this->clazz, "integrityOnEventOverflowIIN", "Z");
        if(!this->integrityOnEventOverflowIINField) return false;

        this->eventScanOnEventsAvailableClassMaskField = env->GetFieldID(this->clazz, "eventScanOnEventsAvailableClassMask", "Lcom/automatak/dnp3/ClassField;");
        if(!this->eventScanOnEventsAvailableClassMaskField) return false;

        this->taskRetryPeriodField = env->GetFieldID(this->clazz, "taskRetryPeriod", "Ljava/time/Duration;");
        if(!this->taskRetryPeriodField) return false;

        this->taskStartTimeoutField = env->GetFieldID(this->clazz, "taskStartTimeout", "Ljava/time/Duration;");
        if(!this->taskStartTimeoutField) return false;

        this->maxTxFragSizeField = env->GetFieldID(this->clazz, "maxTxFragSize", "I");
        if(!this->maxTxFragSizeField) return false;

        this->maxRxFragSizeField = env->GetFieldID(this->clazz, "maxRxFragSize", "I");
        if(!this->maxRxFragSizeField) return false;

        return true;
    }

    jobject MasterConfig::getresponseTimeout(JNIEnv* env, jobject instance)
    {
        return env->GetObjectField(instance, this->responseTimeoutField);
    }

    jobject MasterConfig::gettimeSyncMode(JNIEnv* env, jobject instance)
    {
        return env->GetObjectField(instance, this->timeSyncModeField);
    }

    jboolean MasterConfig::getdisableUnsolOnStartup(JNIEnv* env, jobject instance)
    {
        return env->GetBooleanField(instance, this->disableUnsolOnStartupField);
    }

    jboolean MasterConfig::getignoreRestartIIN(JNIEnv* env, jobject instance)
    {
        return env->GetBooleanField(instance, this->ignoreRestartIINField);
    }

    jobject MasterConfig::getunsolClassMask(JNIEnv* env, jobject instance)
    {
        return env->GetObjectField(instance, this->unsolClassMaskField);
    }

    jobject MasterConfig::getstartupIntegrityClassMask(JNIEnv* env, jobject instance)
    {
        return env->GetObjectField(instance, this->startupIntegrityClassMaskField);
    }

    jboolean MasterConfig::getintegrityOnEventOverflowIIN(JNIEnv* env, jobject instance)
    {
        return env->GetBooleanField(instance, this->integrityOnEventOverflowIINField);
    }

    jobject MasterConfig::geteventScanOnEventsAvailableClassMask(JNIEnv* env, jobject instance)
    {
        return env->GetObjectField(instance, this->eventScanOnEventsAvailableClassMaskField);
    }

    jobject MasterConfig::gettaskRetryPeriod(JNIEnv* env, jobject instance)
    {
        return env->GetObjectField(instance, this->taskRetryPeriodField);
    }

    jobject MasterConfig::gettaskStartTimeout(JNIEnv* env, jobject instance)
    {
        return env->GetObjectField(instance, this->taskStartTimeoutField);
    }

    jint MasterConfig::getmaxTxFragSize(JNIEnv* env, jobject instance)
    {
        return env->GetIntField(instance, this->maxTxFragSizeField);
    }

    jint MasterConfig::getmaxRxFragSize(JNIEnv* env, jobject instance)
    {
        return env->GetIntField(instance, this->maxRxFragSizeField);
    }
}