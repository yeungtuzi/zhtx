//book-parry.c

inherit ITEM;

void create()
{

        set_name("过招要旨", ({ "huashan parry", "book" }));
        set_weight(200);
        set("unit", "本");
        set("long", "这是华山派的过招要旨\n");
		set("value", 500);
        set("material", "paper");
        set("skill", ([
                        "name": "parry",      // name of the skill
                        "exp_required": 10000,  // minimum combat experience required
                        "sen_cost": 15+random(30),// jing cost every time study this skill
                        "difficulty":   25,     // the base int to learn this skill
                        "max_skill":    100      // the maximum level you can learn
                      ]) );
}
