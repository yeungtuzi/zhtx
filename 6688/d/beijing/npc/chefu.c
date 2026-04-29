

#include <ansi.h>

inherit NPC;
                                    
void create()
{
	set_name("李长庚", ({ "li changgeng","li"  }) );
	set("title", "驿站车夫");
	set("gender", "男性" );
	set("shen_type", 1);
	set("age", 30);
	set("str", 30);
	set("con", 30);
	set("int", 30);


	set("no_clean_up",1);

	set("long",
		"一个赶车的车老版，薪金虽然不多，但生活却也过得自在。\n" );

	set("combat_exp", 50000);
	set("attitude", "peaceful");
	set("chat_chance", 1);
	set("chat_msg", ({
		"李长庚说道: 这位客官，以车代步多好哇，不用赶路那么辛苦。\n",
	}) );

	set("max_kee", 300);
	set("max_gin", 200);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 10);
                              
	set_skill("force", 30); 
	set_skill("unarmed", 30);
        set_skill("dodge", 30);
	set_skill("parry", 30);
	
	setup();
	

	carry_object("/obj/cloth")->wear();
}


int accept_object(object who, object ob)
{	

	if (ob->query("money_id") && ob->value() >= 1000) 
	{
		tell_object(who, "车夫笑眯眯地说道:请稍等一会,我这就为你准备马车。\n");
		who->set_temp("shangche",1);
		return 1;
	}

	return 0;
}

