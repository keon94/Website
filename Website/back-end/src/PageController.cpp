#include "PageController.h"
#include <fstream>

PageController::PageController(cppcms::service& srv) : cppcms::application(srv) {
	dispatcher().assign("", &PageController::redirect, this); //e.g /home
	mapper().assign("");	
	dispatcher().assign("/", &PageController::display, this); //e.g /home/
	mapper().assign("/");   
	dispatcher().assign("(/[A-Za-z_0-9\\.]+\\.css)", &PageController::applyCss, this, 1); //applies it to {1} : e.g /home/X.css <- /X.css
}

void PageController::applyCss(std::string cssFileName) {
	std::ifstream fReader(("../resource/css/" + cssFileName).c_str());
	if (!fReader) {
		response().status(404);
	}
	else {
		response().content_type("text/css");
		response().out() << fReader.rdbuf();
	}
}

void PageController::redirect()
{
	response().set_redirect_header(url(".")); //e.g /home -> /home/
	response().out();
}
