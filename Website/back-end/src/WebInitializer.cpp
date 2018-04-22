#include "WebInitializer.h"
#include "HomeController.h"

WebInitializer::WebInitializer(cppcms::service& srv) : cppcms::application(srv) {
	
	//e.g localhost:8080/  
	dispatcher().assign("", &WebInitializer::defaultPage, this);
	mapper().assign("");

	//localhost:8080/home/
	attach(new HomeController(srv),
		"home", "/home{1}", // mapping  
		"/home(.*)", 1);   // dispatching  
}

void WebInitializer::defaultPage()
{
	//e.g localhost:8080/ -> localhost:8080/home/
	response().set_redirect_header(url("home"));
	response().out();
}
