#pragma once

class payment_method {
public:
	virtual void pay(float total) = 0;
};