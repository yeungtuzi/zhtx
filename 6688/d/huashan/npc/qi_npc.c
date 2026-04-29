#include <ansi.h>

inherit NPC;

void create()
{
	    setup();
}


int accept_fight(object ob)
{
    command("peace "+ob->query("id"));
	command("say 师傅吩咐我们不能跟别人动手");
	return 0;
}

void die()
{
        object killer;

        if( killer = this_object()->query("last_damage_from"))
		{
			if( killer->query("family/family_name")=="华山派剑宗"
			&& userp(killer))
			{
			if(killer->query("hatred/华山派气宗")<20000)
				killer->add("hatred/华山派气宗",50);
			if(killer->query("shen")<1000000)
				killer->add("shen",10000);	
			}
		}
        ::die();
} 
