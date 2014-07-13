/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */
#ifndef __MOCK_OUTSTATION_APPLICATION_H_
#define __MOCK_OUTSTATION_APPLICATION_H_

#include <opendnp3/outstation/IOutstationApplication.h>

#include <deque>

namespace opendnp3
{

class MockOutstationApplication : public IOutstationApplication
{
public:
	
	MockOutstationApplication() :		
		supportsTimeWrite(true),
		allowTimeWrite(true),
		warmRestartSupport(RestartMode::UNSUPPORTED),
		coldRestartSupport(RestartMode::UNSUPPORTED),
		warmRestartTimeDelay(0),
		coldRestartTimeDelay(0)
	{}

	virtual bool SupportsWriteAbsoluteTime() override final
	{
		return supportsTimeWrite;
	}

	virtual bool WriteAbsoluteTime(const openpal::UTCTimestamp& timestamp) override final
	{
		if (allowTimeWrite)
		{
			timestamps.push_back(timestamp);
			return true;
		}
		else
		{
			return false;
		}		
	}

	virtual ApplicationIIN GetApplicationIIN() const override final
	{
		return appIIN;
	}
	
	virtual RestartMode ColdRestartSupport() const override final
	{
		return coldRestartSupport;
	}
	
	virtual RestartMode WarmRestartSupport() const override final
	{
		return warmRestartSupport;
	}
	
	virtual uint16_t ColdRestart() override final
	{
		return coldRestartTimeDelay;
	}
	
	virtual uint16_t WarmRestart() override final
	{
		return warmRestartTimeDelay;
	}
	
	bool supportsTimeWrite;
	bool allowTimeWrite;

	RestartMode warmRestartSupport;
	RestartMode coldRestartSupport;

	uint16_t warmRestartTimeDelay;
	uint16_t coldRestartTimeDelay;

	ApplicationIIN appIIN;

	std::deque<openpal::UTCTimestamp> timestamps;


};

}

#endif

