#pragma once

class Cancellable
{
public:
	virtual ~Cancellable();

	virtual bool isCancelled() const = 0;
	virtual void setCancelled(bool cancel) = 0;

	virtual bool isCancellable() const;
};
