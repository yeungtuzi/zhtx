//NPC:/d/suzhou/npc/fighter5.c 
//by dwolf
//97.11.4
//changed by tlang
         
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(MAG"趟子手"NOR, ({ "tangzi shou", "shou", "fighter" }));
	set("age", 18);
	set("gender", "女性");
	set("long", "她是镖局的弟子，武功虽然不太高，但对付一般土匪绰绰有余。\n");
	set("attitude", "peacefully");

	set("str", 20);
	set("dex", 26);
	set("max_kee",500);
	set("combat_exp", 50000);
	set("shen_type", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_skill("force", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 50);


        set("chat_chance", 2);
	set("chat_msg", ({
		"师傅，这招该怎么理解？\n",
		"师姐，看来我们的功夫又有进步了。\n",
	}));

	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

