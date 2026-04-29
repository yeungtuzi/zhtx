// tailor.c
#include <ansi.h>
inherit NPC;
void ask_me(object who)
{         who=this_player();
	  command("say 那得十两银子。\n");
	  who->set_temp("marks/askgai",1);	
	
}


void create()
{
        set_name("裁缝", ({ "tailor" }) );
        set("title", HIC"裁衣店"NOR);
        set("gender", "男性" );
        set("age", 42);
        set("long", "一位看上去很和蔼的裁缝，正在替宫中的公公缝制太监服。\n");
	set("str", 12);
	set("int", 24);
        set("combat_exp", 500);
        set("attitude", "friendly");
        set_skill("sword", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);

        set("inquiry", ([
		"太监服" : "据说穿上太监服就可以随便出入皇宫了。你要改一件太监服试试么？", 
		"改衣服" : "这个我最拿手了，你要改一件太监服试试么？",
		"改太监服":(: ask_me :),
	        ]) );

	set("shen_type",1);
	setup();
	add_money("silver", 2);
	add_money("coin", 50);
        carry_object("/obj/cloth")->wear();

}
int accept_object(object who, object ob)
{	object *inv;
	int i;
	string name;
	who=this_player();
	inv=all_inventory(who);
	if(!who->query_temp("marks/askgai"))        
	 {  command("say 这是您老打赏给我的么？");
	    command("thank "+who->query("id"));
	    return 1;
	 }
	else
	{ if(ob->query("money_id")&& ob->value() <1000)
	      return notify_fail("老裁缝说：“这。。。这似乎少了点。”\n");
	else 
	  {  for(i=0;i<sizeof(inv);i++)
	      {name=inv[i]->query("id");
		if(name=="taijianfu") 
		  {inv[i]->set_name(HIC"太监服"NOR,({"taijian fu"}));
		   command("say 好了。\n");
		   who->set_temp("marks/askgai",0);
		   return 1;
		  }
		else return notify_fail("你没有太监服可以改。\n");
	      }	
	     return 1;
	   }
	}

}
