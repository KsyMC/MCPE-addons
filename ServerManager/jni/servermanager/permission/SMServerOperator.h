#pragma once

class SMServerOperator
{
public:
	virtual ~SMServerOperator() {};

	virtual bool isOp() const = 0;

	virtual void setOp(bool value) = 0;
};
