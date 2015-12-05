#pragma once

// Size : 16
class SynchedEntityData
{
public:
	char filler1[16];	// 0

public:
	SynchedEntityData();
	SynchedEntityData(SynchedEntityData &&);
	~SynchedEntityData();
};
