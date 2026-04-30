//《侠客行》
//by tlang

#include <ansi.h>
inherit NPC;

string ask_xiaolin();
string ask_lucy();

void create()
{
	set_name(HIC"冰雪儿"NOR, ({ "ice girl","snower","xue er"}) );
	set("gender", "女性" );
	set("age", 17);
        set("long","一位漂亮的小美眉，是小霖的未婚妻。\n");
	set("per",30);
	set("int",30);

	set("combat_exp", 1000000); 
	set("attitude", "friendly");
		
	set("max_force",1000);
	set("force",1000);
	set("max_mana",800);
	set("mana",800);
	set("max_atman",800);
	set("atman",800);
	
	set_skill("literate",200);
	set_skill("music",150);

	set_skill("dodge",150);
	set_skill("finger",150);
	set_skill("parry",150);
	set_skill("force",150);
	set_skill("shaolin-shenfa",120);
	set_skill("nianhua-zhi",120);
	set_skill("hunyuan-yiqi",120);	
	map_skill("dodge","shaolin-shenfa");
	map_skill("finger","nianhua-zhi");
	map_skill("parry","nianhua-zhi");
	map_skill("force","hunyuan-yiqi");

	set("inquiry",([
	"小霖" : (: ask_xiaolin :),
	"xiaolin" : (: ask_xiaolin :),
	"露露" : (: ask_lucy :),
	"lucy" : (: ask_lucy :),
	]));

	set("count",1);

	setup();
	carry_object("/d/suzhou/npc/obj/bjcloth.c")->wear(); 
}

string ask_xiaolin()
{
	// 2026-04-30: unused variable commented out
	// object me=this_object();
	object ob=this_player();

	if(query("count")<1)
	{
		command("? "+ob->query("id"));
		return "你老问这干嘛？。。。。。pp\n";
	}
	add("count",-1);
	command("smile "+ob->query("id"));
		return "小霖是我的未婚夫，他就爱喝酒。\n";
}

string ask_lucy()
{
	object obj;
	obj=new("/d/hangzhou/npc/obj/book14");
	obj->move(this_player());
	return "她是一个可怜的女孩子，就在这儿，你能帮助她就好了。\n
		这本书就算是送给你作为奖励了。\n";
}

