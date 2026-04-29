inherit NPC;
#include <ansi.h>
#include "/u/z/zephyr/randomname.h"

void die()
{
	object ob;
	int flag=0;
	object killer = query_temp("last_damage_from");
	if( !objectp(killer) )
	{
		::die();
		return;
	}

	killer->add("killed_master",1);
	if (killer->query("combat_exp") > 8000000 && random(2) )
	{
		flag=1;
		if ( random(100)<1 )
		{
			killer->set("killed_master",0);
			if (wizardp(killer)) tell_object("复仇者参数被重置零。\n");		
		}
	}
	if ( killer->query("combat_exp") < 8000000 && killer->query("killed_master") > 50 && random(2) )
	{
		flag=1;
		if ( random(2))
		{
			killer->set("killed_master",0);
			if (wizardp(killer)) tell_object("复仇者参数被重置零。\n");		
		}
	}
	if ( flag )
	{
		command("chat " + HIR + killer->query("name") + "你这" + RANK_D->query_rude(killer) + "！我" + query("family")["family_name"] + "的弟子们，要给我报仇啊！！！\n"NOR);
		tell_object(killer,HIR"最近行走江湖小心为妙！！！\n"NOR);
		if ( random(2) )
		{
			ob=new("/u/z/zephyr/revenger.c");
			ob->revenge(killer, this_object());
		}
	}
	::die();
}
