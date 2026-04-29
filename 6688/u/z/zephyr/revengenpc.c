//现在是用init()来激活traitor，实在有不妥，眼下先这么实现。等明年有空了再改。
//zephyr
inherit NPC;
#include <ansi.h>
#include "/u/z/zephyr/randomname.h"

void init()
{
   object ob, ct_traitor, qiankun_master, where;
	int i;
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
   if ( query("name")=="林忌" )
   {
		set("have_traitor",1);
   }
   if ( query("name")=="苏星河" && random(100)>90 )
   {
		set("have_traitor",1);
   }

   if ( query("name")=="无涯子" && random(100)>90 )
   {
		set("have_traitor",1);
   }

   if ( query("id")=="yuan shuai" && random(10000)<30  )
   {
	   i = random(100);
	   if ( i > 80 ) qiankun_master=new("/d/qiankun/npc/master");
	   else if ( i > 60 ) qiankun_master=new("/d/qiankun/npc/shangguanren");
	   else qiankun_master=new("/d/qiankun/npc/zhaowuji");

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
		//是不是临时生成的对象？如果是，清除
		where = environment(qiankun_master);
		if (!where) destruct(qiankun_master);
   }

	if ( random(10000)<100 && !query("have_traitor") ) 
	{
		set("have_traitor",1);
		ob=new("/u/z/zephyr/traitor.c");
		ob->betray(this_object());
   		CHANNEL_D->do_channel(this_object(),"sys","生成门派叛徒："+ ob->query("title") + ob->name() + "。\n");	
	}

	if ( random(10000)<10 && !query("have_ct_traitor") ) 
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
			CHANNEL_D->do_channel(this_object(),"sys", killer->name() +"复仇者参数被重置。\n");			
		}
	}
	if ( killer->query("combat_exp") < 8000000 && killer->query("killed_master") > 50 && random(2) )
	{
		flag=1;
		if ( random(2))
		{
			killer->set("killed_master",1);
			CHANNEL_D->do_channel(this_object(),"sys", killer->name() +"复仇者参数被重置。\n");			
		}
	}

	if ( flag && objectp(killer) )
	{
		command("chat " + killer->query("name") + "你这" + RANK_D->query_rude(killer) + "！我" + query("family/family_name") + "的弟子们，要给我报仇啊！！！\n");
		tell_object(killer,HIR"最近行走江湖小心为妙！！！\n"NOR);
		if ( random(2) && userp(killer) )
		{
			ob=new("/u/z/zephyr/revenger.c");
			ob->revenge(killer, this_object());
	   		CHANNEL_D->do_channel(this_object(),"sys","生成复仇者："+ ob->query("title") + ob->name() + "，准备向"+killer->name()+"寻仇。\n");	
		}
	}
	::die();
}
