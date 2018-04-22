#ifndef HOME_CONTROLLER_H_
#define HOME_CONTROLLER_H_

#include "PageController.h"
#include "HomeContent.h"

class HomeController : public PageController {
public:
	
	HomeController(cppcms::service& srv);

	virtual void display();

};

#endif