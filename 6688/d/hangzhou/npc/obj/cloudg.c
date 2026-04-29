//by tlang

#include <ansi.h>
inherit NPC;

string ask_eagler();

void create()
{
	set_name(HIC"白云飞"NOR, ({ "cloud eagler","eagler"}) );
	set("gender", "男性" );
	set("age", 20+random(4));
        set("long","一个面目清秀无比的少年。\n");
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
	"女扮男装" : (: ask_eagler :),
	"cloudgirl" : (: ask_eagler :),
	]));

	set("count",1);

	setup();
	carry_object("/d/suzhou/npc/obj/baishan.c")->wear(); 
}

string ask_eagler()
{
	object me=this_object();
	object ob=this_player();

	if(query("count")<1)
	{
		command("? "+ob->query("id"));
		return "你没有发烧吧？\n";
	}
	add("count",-1);
	command("smile "+ob->query("id"));
	command("say 想不到"+RANK_D->query_respect(ob)+"眼光如此犀利。\n");
	tell_object(environment(me),"只见白云飞把头巾一摘，长发如漆黑的瀑
	布般垂在背后，果然是个绝色的美女。\n");
	me->set("gender","女性");
		return "我就给你一点东西吧。\n";
}