#pragma once
#include "IStream.h"

class TextFormatter: public IStream
{
public:
	void Save(vector<Human> v) override;
	vector<Human>Load() override;
};
