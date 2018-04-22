#ifndef MAIN_CONTROLLER_H_
#define MAIN_CONTROLLER_H_

#pragma warning(push)  
#pragma warning(disable : 4101)  
#pragma warning(disable : 4250)  
#pragma warning(disable : 4267) 

#include <cppcms/application.h>  
#include <cppcms/applications_pool.h>  
#include <cppcms/service.h>  
#include <cppcms/http_response.h>  

#pragma warning(pop)  

#include <iostream> 

class MainController : public cppcms::application {
public:
	MainController(cppcms::service &srv) : cppcms::application(srv) {}

	virtual void main(std::string url);
};

#endif