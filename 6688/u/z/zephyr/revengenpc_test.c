inherit NPC;
#include <ansi.h>
#include "/u/z/zephyr/randomname.h"

void init()
{
   object ob, ct_traitor, qiankun_master;

   ::init();

    if ( !query("family/family_name") )
	{
		set("have_traitor",1);
		set("have_ct_traitor",1);
	}

   if ( query("name")=="渡肉长老" && random(100)>98 )
   {
		set("have_traitor",1);
   }
   if ( query("name")=="苏星河" && random(100)>95 )
   {
		set("have_traitor",1);
   }

   if ( query("id")=="yuan shuai" && random(10000)<50000  )
   {
	   if (random(2))
	   {
			qiankun_master = find_living("shangguan ren");
	   }
	   else	qiankun_master = find_living("zhao wuji");
		
		ct_traitor = find_living("ct_traitor");
		if ( objectp(ct_traitor) )
		{
      		CHANNEL_D->do_channel(this_object(),"sys","无法产生大内奸细。原因：已经存在"+ ct_traitor->query("title") + ct_traitor->name() + "。\n");	
			return;
		}
		if ( !objectp(qiankun_master) )
		{
      		CHANNEL_D->do_channel(this_object(),"sys","无法产生大内奸细。原因：对象"+ qiankun_master->name() +"不存在。\n");	
			return;
		}
		ob=new("/u/z/zephyr/ct_traitor.c");
		ob->betray(qiankun_master);
   		CHANNEL_D->do_channel(this_object(),"sys","由对象"+qiankun_master->name()+"生成大内奸细："+ ob->query("title") + ob->name() + "。\n");	
   }

	if ( random(10000)<100 && !query("have_traitor") ) 
	{
		set("have_traitor",1);
		ob=new("/u/z/zephyr/traitor.c");
		ob->betray(this_object());
   		CHANNEL_D->do_channel(this_object(),"sys","生成门派叛徒："+ ob->query("title") + ob->name() + "。\n");	
	}

	if ( random(10000)<50 && !query("have_ct_traitor") ) 
	{
		ct_traitor = find_living("ct_traitor");
		if ( objectp(ct_traitor) )
		{
      		CHANNEL_D->do_channel(this_object(),"sys","无法产生大内奸细。原因：已经存在"+ ct_traitor->query("title") + ct_traitor->name() + "。\n");	
			return;
		}
		set("have_ct_traitor",1);
		ob=new("/u/z/zephyr/ct_traitor.c");
		ob->betray(this_object());
   		CHANNEL_D->do_channel(this_object(),"sys","生成大内奸细："+ ob->query("title") + ob->name() + "。\n");	
	}
}

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

    if ( !query("family/family_name") )
	{
		::die();
		return;
	}

	if( !userp(killer) )
	{
		::die();
		return;
	}

	if ( killer->query("traitor") )
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
		if ( random(2) && userp(killer) )
		{
			ob=new("/u/z/zephyr/revenger.c");
			ob->revenge(killer, this_object());
		}
	}
	::die();
}
