#pragma once

#include "public.sdk/source/vst/vsteditcontroller.h"

#include "AudioPlugSharpEditor.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

class AudioPlugSharpController : public EditController
{
public:
	AudioPlugSharpController(void);

	static FUID AudioPlugSharpControllerUID;

	static FUnknown* createInstance(void* context)
	{
		return (IEditController*) new AudioPlugSharpController;
	}

	tresult PLUGIN_API initialize(FUnknown* context) SMTG_OVERRIDE;
	tresult PLUGIN_API terminate() SMTG_OVERRIDE;

	tresult PLUGIN_API setComponentState(IBStream* state) SMTG_OVERRIDE;

	tresult PLUGIN_API getParamStringByValue(ParamID tag, ParamValue valueNormalized, String128 string) SMTG_OVERRIDE;
	tresult PLUGIN_API setParamNormalized(ParamID tag, ParamValue value) SMTG_OVERRIDE;
	ParamValue PLUGIN_API getParamNormalized(ParamID tag) SMTG_OVERRIDE;

	// Uncomment to add a GUI
	 IPlugView * PLUGIN_API createView (const char * name) SMTG_OVERRIDE;

	// Uncomment to override default EditController behavior
	// tresult PLUGIN_API setState(IBStream* state) SMTG_OVERRIDE;
	// tresult PLUGIN_API getState(IBStream* state) SMTG_OVERRIDE;
	// tresult PLUGIN_API getParamValueByString(ParamID tag, TChar* string, ParamValue& valueNormalized) SMTG_OVERRIDE;

	~AudioPlugSharpController(void);

private:
	AudioPlugSharpEditor* editor = nullptr;

};
