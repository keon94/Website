#ifndef PAGE_CONTROLLER_H_
#define PAGE_CONTROLLER_H_

#pragma warning(push)  
#pragma warning(disable : 4101)  
#pragma warning(disable : 4250)  
#pragma warning(disable : 4267) 

#include <cppcms/application.h>  
#include <cppcms/service.h>  
#include <cppcms/http_response.h>  
#include <cppcms/url_dispatcher.h>  
#include <cppcms/url_mapper.h>  
#include <cppcms/applications_pool.h> 

#pragma warning(pop)  

class PageController : public cppcms::application {

public:
	
	PageController(cppcms::service& srv);

	virtual void applyCss(std::string cssFileName);

	virtual void redirect();

	virtual void display() = 0;

protected:
	
	std::string _page_address;
};

#endif