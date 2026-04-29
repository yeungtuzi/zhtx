// shi2.c
#include <ansi.h>

inherit ITEM;

string* titles = ({
	GRN"杜甫"NOR YEL"诗集"NOR,
});

void create()
{
	int i = random(sizeof(titles));

    set_name(titles[i], ({ "dufu shiji", "shi2" }));
	set_weight(200);
	set("unit", "册");
	set("long", "这是一册" + titles[i] + "\n");
    set("value",625000);
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
			"sen_cost": 40+random(20),// jing cost every time study this
			"difficulty":	40,	// the base int to learn this skill
			"max_skill":	170	// the maximum level you can learn
    ]) );
}
