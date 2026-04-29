//fairy cloth
//by tlang

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIM"霓虹羽衣"NOR, ({ "fairy cloth","cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",HIW"这是一件用霓虹色的孔雀羽毛做材料，由美丽的\n"
	"七仙女美眉织成的。由于只有仙子才配穿，故名为霓虹羽衣。\n"NOR);
		set("unit", "件");
		set("material", "silk");
		set("armor_prop/armor", 20);
		set("armor_prop/courage", 5);
                set("armor_prop/intelligence", 10);
                set("armor_prop/personality", 15);

		set("value",50000);
	}
	setup();
}
