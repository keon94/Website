#include "HomeController.h"

HomeController::HomeController(cppcms::service& srv) : PageController(srv) {}

void HomeController::display()
{
	HomeContent::message c;
	c.text = "Hello";
	render("message", c);
}

