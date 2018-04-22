#include "MainController.h"
#include "HomeContent.h"

void MainController::main(std::string /*url*/)
{
	HomeContent::message c;
	c.text = ">>>Hello<<<";
	render("message", c);
}