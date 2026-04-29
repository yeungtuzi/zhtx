//storm cloth
//by tlang

#include <ansi.h>
#include <armor.h>

inherit CLOTH;
//inherit F_UNIQUE;

void create()
{
	set_name(HIM"风雪之衣"NOR, ({ "storm cloth","cloth" }) );
	set_weight(3000);
	set("cloth/saver",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",YEL"这是一件用千年雪蚕吐的丝做成的衣服，上面有各种美丽的美妹图。由于它是\n"
	"大虾风雪最先发现的，所以名为风雪之衣。\n"NOR);
		set("unit", "件");
		set("material", "silk");
		set("armor_prop/armor", 20);
		set("armor_prop/courage", 2);
                set("armor_prop/intelligence", 2);
                set("armor_prop/personality", 3);

		set("value",10000);
	}
	setup();
}
