#include <ansi.h>

inherit "/std/char/doomnpc";

string use_cast();
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int query_mana_imp()
{
	return 16;
}

void create()
{
        set_name(GRN"风吹雨"NOR, ({ "feng chuiyu", "feng", "rainblow" }) );
        set("title", YEL"忘情天师"NOR);
        set("gender", "男性");
        set("age", 27);
        set("long",
                "他看起来似乎十分的面熟，可一时却无法辨认他的真面目。\n"
	);
        set("combat_exp", 10000000);
        set("score", -2000000);

        set("class", "taoist");

        set("int", 100);
        set("cps", 100);
        set("spi", 100);


        set("force", 2000);
        set("max_force", 1000);
        set("force_factor", 50);

        set("atman", 2000);
        set("max_atman", 2000);

        set("mana", 4000);
        set("max_mana", 2000);
        set("mana_factor", 81);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: use_cast :),
        }) );

        set_skill("literate", 90);
        set_skill("magic", 100);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("cuff", 70);
        set_skill("sword", 130);
        set_skill("parry", 130);
        set_skill("dodge", 100);
        set_skill("move", 100);
        set_skill("move", 100);
        set_skill("qingcheng-steps", 800);

        set_skill("gouyee", 150);
        set_skill("taosword", 150);
        set_skill("taoism", 200);
        set_skill("necromancy", 150);

        map_skill("spells", "necromancy");
        map_skill("sword", "taosword");
        map_skill("parry", "taosword");
        map_skill("dodge", "qingcheng-steps");
        map_skill("move", "qingcheng-steps");

        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
	set_temp("manashield",1);

        setup();
        if(random(10)>2) carry_rnd_equip(2,4);	
        carry_object("/d/xanadu/dynamic/npc/obj/spiritring");
}

string use_cast()
{
	object enemy;

	enemy = offensive_target(this_object());
	if( enemy )
	{
		if( enemy->is_ghost() )
		{
			command("cast thunderbolt");
			return " ";
		}
		switch(random(6))
		{
			case 0:
			case 1: command("cast drainerbolt");
				break;
			case 2: command("cast feeblebolt");
				break;
			case 3:
			case 4: command("cast netherbolt");
				break;
		}
	}
	return " ";
}
