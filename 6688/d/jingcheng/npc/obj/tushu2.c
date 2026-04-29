// tushu2.c  
#include <ansi.h>

inherit ITEM;

string* titles = ({
	HIM"老子"NOR,
});

void create()
{
	int i = random(sizeof(titles));

    set_name(titles[i], ({ "lao zi", "tushu2" }));
	set_weight(200);
	set("unit", "册");
	set("long", "这是一册" + titles[i] + "\n");
    set("value",1000000);
        set("unpawnable",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_give",1);
        set("no_put",1);
        set("no_paimai",1);
        set("no_sell",1);
	set("material", "paper");
	set("skill", ([
			"name":	"literate",	// name of the skill
			"sen_cost": 50+random(20),// jing cost every time study this
			"difficulty":	50,	// the base int to learn this skill
			"max_skill":	200	// the maximum level you can learn
    ]) );
}
