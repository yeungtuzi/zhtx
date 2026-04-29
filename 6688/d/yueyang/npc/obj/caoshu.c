// shiji4.c

inherit ITEM;

string* titles = ({
	"率意帖",
});

void create()
{
	int i = random(sizeof(titles));

    set_name(titles[i], ({ "shu", "shu ji" }));
	set_weight(200);
	set("unit", "册");
	set("long", "这是一册" + titles[i] + "\n");
      	set("value",100000);
	set("material", "paper");
	set("skill", ([
			"name":	"caoshu",	// name of the skill
	                "base_skill": 30,
			"sen_cost": 30+random(20),// jing cost every time study this
			"difficulty":	40,	// the base int to learn this skill
			"max_skill":	150	// the maximum level you can learn
    ]) );
}
