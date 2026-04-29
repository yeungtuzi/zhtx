
#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("烟袋锅", ({ "yandai guo","guo" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"偷王之王范良极的随身家伙，妙用无穷。\n");
		set("value", 0);
	}
	init_dagger(120);
	setup();
}
