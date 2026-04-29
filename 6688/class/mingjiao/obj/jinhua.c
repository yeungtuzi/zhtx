
#include <weapon.h>

inherit THROWING;
#include <ansi.h>
void create()
{
	set_name(HIY"纯金梅花"NOR, ({ "Golden flower","flower","jinhua" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"金花婆婆的独门暗器，威名远扬。\n");
		set("unit", "堆");
		set("base_unit", "朵");
              set("value",0);
		set("base_weight", 1);
		set("base_value", 1);
	}
      set_amount(100);
	init_throwing(99);
	setup();
}
