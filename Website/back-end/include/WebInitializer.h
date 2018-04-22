#ifndef WEB_INITIALIZER_H_
#define WEB_INITIALIZER_H_

#pragma warning(push)  
#pragma warning(disable : 4101)  
#pragma warning(disable : 4250)  
#pragma warning(disable : 4267) 

#include <cppcms/application.h>  
#include <cppcms/applications_pool.h>  
#include <cppcms/service.h>  
#include <cppcms/http_response.h>  

#pragma warning(pop)  


class WebInitializer : public cppcms::application {

public:
	
	WebInitializer(cppcms::service &srv);

	void defaultPage();
};

#endif