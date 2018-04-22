#line 1 "resource/tmpl/Home.tmpl"
#include "HomeContent.h" 
#line 2 "resource/tmpl/Home.tmpl"
namespace web_skin {
	#line 3 "resource/tmpl/Home.tmpl"
	struct  message :public cppcms::base_view
	#line 3 "resource/tmpl/Home.tmpl"
	{
	#line 3 "resource/tmpl/Home.tmpl"
		HomeContent::message &content;
	#line 3 "resource/tmpl/Home.tmpl"
		message(std::ostream &_s,HomeContent::message &_content): cppcms::base_view(_s),content(_content),_domain_id(0)
	#line 3 "resource/tmpl/Home.tmpl"
		{
	#line 3 "resource/tmpl/Home.tmpl"
			_domain_id=booster::locale::ios_info::get(_s).domain_id();
	#line 3 "resource/tmpl/Home.tmpl"
		}
		#line 4 "resource/tmpl/Home.tmpl"
		virtual void render() {
		#line 4 "resource/tmpl/Home.tmpl"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 10 "resource/tmpl/Home.tmpl"
			out()<<"  \n"
				"<html>  \n"
				"\t<head>\n"
				"\t\t<link rel=\"stylesheet\" href=\"Home.css\">\n"
				"\t</head>\n"
				"\t<body>  \n"
				"\t\t<h1>";
			#line 10 "resource/tmpl/Home.tmpl"
			out()<<cppcms::filters::escape(content.text);
			#line 13 "resource/tmpl/Home.tmpl"
			out()<<" World!</h1>  \n"
				"\t</body>  \n"
				"</html>  \n"
				"";
		#line 13 "resource/tmpl/Home.tmpl"
		} // end of template render
	#line 14 "resource/tmpl/Home.tmpl"
	private:
	#line 14 "resource/tmpl/Home.tmpl"
		int _domain_id;
	#line 14 "resource/tmpl/Home.tmpl"
	}; // end of class message
#line 15 "resource/tmpl/Home.tmpl"
} // end of namespace web_skin
#line 2 "resource/tmpl/Home.tmpl"
namespace web_skin {
#line 15 "resource/tmpl/Home.tmpl"
} // end of namespace web_skin
#line 15 "resource/tmpl/Home.tmpl"
namespace {
#line 15 "resource/tmpl/Home.tmpl"
 cppcms::views::generator my_generator; 
#line 15 "resource/tmpl/Home.tmpl"
 struct loader { 
#line 15 "resource/tmpl/Home.tmpl"
  loader() { 
#line 15 "resource/tmpl/Home.tmpl"
   my_generator.name("web_skin");
#line 15 "resource/tmpl/Home.tmpl"
   my_generator.add_view<web_skin::message,HomeContent::message>("message",true);
#line 15 "resource/tmpl/Home.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 15 "resource/tmpl/Home.tmpl"
 }
#line 15 "resource/tmpl/Home.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 15 "resource/tmpl/Home.tmpl"
} a_loader;
#line 15 "resource/tmpl/Home.tmpl"
} // anon 
