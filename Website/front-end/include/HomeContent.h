#ifndef ENTRY_CONTENT_H
#define ENTRY_CONTENT_H

#pragma warning(push)  
#pragma warning(disable : 4250)  

#include <cppcms/view.h>  

#pragma warning(pop)  

#include <string> 

namespace HomeContent {
	struct message : public cppcms::base_content {
		std::string text;
	};
}

#endif
