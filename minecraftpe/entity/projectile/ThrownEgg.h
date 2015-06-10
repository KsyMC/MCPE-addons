#pragma once

class ThrownEgg : public Throwable
{
public:
	virtual void ~ThrownEgg();
	virtual void getEntityTypeId() const;
	virtual void onHit(const HitResult &);
};
