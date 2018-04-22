#line 1 "EntrySkin.tmpl"
#include "EntryContent.h" 
#line 2 "EntrySkin.tmpl"
namespace EntrySkin {
	#line 3 "EntrySkin.tmpl"
	struct  message :public cppcms::base_view
	#line 3 "EntrySkin.tmpl"
	{
	#line 3 "EntrySkin.tmpl"
		EntryContent::message &content;
	#line 3 "EntrySkin.tmpl"
		message(std::ostream &_s,EntryContent::message &_content): cppcms::base_view(_s),content(_content),_domain_id(0)
	#line 3 "EntrySkin.tmpl"
		{
	#line 3 "EntrySkin.tmpl"
			_domain_id=booster::locale::ios_info::get(_s).domain_id();
	#line 3 "EntrySkin.tmpl"
		}
		#line 4 "EntrySkin.tmpl"
		virtual void render() {
		#line 4 "EntrySkin.tmpl"
			cppcms::translation_domain_scope _trs(out(),_domain_id);

			#line 7 "EntrySkin.tmpl"
			out()<<"  \n"
				"<html>  \n"
				"  <body>  \n"
				"    <h1>";
			#line 7 "EntrySkin.tmpl"
			out()<<cppcms::filters::escape(content.text);
			#line 10 "EntrySkin.tmpl"
			out()<<" World!</h1>  \n"
				"  </body>  \n"
				"</html>  \n"
				"";
		#line 10 "EntrySkin.tmpl"
		} // end of template render
	#line 11 "EntrySkin.tmpl"
	private:
	#line 11 "EntrySkin.tmpl"
		int _domain_id;
	#line 11 "EntrySkin.tmpl"
	}; // end of class message
#line 12 "EntrySkin.tmpl"
} // end of namespace EntrySkin
#line 2 "EntrySkin.tmpl"
namespace EntrySkin {
#line 12 "EntrySkin.tmpl"
} // end of namespace EntrySkin
#line 12 "EntrySkin.tmpl"
namespace {
#line 12 "EntrySkin.tmpl"
 cppcms::views::generator my_generator; 
#line 12 "EntrySkin.tmpl"
 struct loader { 
#line 12 "EntrySkin.tmpl"
  loader() { 
#line 12 "EntrySkin.tmpl"
   my_generator.name("EntrySkin");
#line 12 "EntrySkin.tmpl"
   my_generator.add_view<EntrySkin::message,EntryContent::message>("message",true);
#line 12 "EntrySkin.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 12 "EntrySkin.tmpl"
 }
#line 12 "EntrySkin.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 12 "EntrySkin.tmpl"
} a_loader;
#line 12 "EntrySkin.tmpl"
} // anon 
